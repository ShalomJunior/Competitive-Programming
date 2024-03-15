#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

#include <list>
#include <vector>
using namespace std;

class Graph
{
public:
    //n is the number of vertices
    //edges is a list of pairs representing the edges (default = empty list)
    Graph(int n, const list< pair<int, int> >& edges = list< pair<int, int> >());

    //Default constructor creates an empty graph
    Graph() : n(0), m(0) {};

    //Returns the number of vertices
    int GetNumVertices() const { return n; };
    //Returns the number of edges
    int GetNumEdges() const { return m; };

    //Given the edge's index, returns its endpoints as a pair
    pair<int, int> GetEdge(int e) const;
    //Given the endpoints, returns the index
    int GetEdgeIndex(int u, int v) const;

    //Adds a new vertex to the graph
    void AddVertex();
    //Adds a new edge to the graph
    void AddEdge(int u, int v);

    //Returns the adjacency list of a vertex
    const list<int>& AdjList(int v) const;

    //Returns the graph's adjacency matrix
    const vector< vector<bool> >& AdjMat() const;
private:
    //Number of vertices
    int n;
    //Number of edges
    int m;

    //Adjacency matrix
    vector< vector<bool> > adjMat;

    //Adjacency lists
    vector< list<int> > adjList;

    //Array of edges
    vector< pair<int, int> > edges;

    //Indices of the edges
    vector< vector<int> > edgeIndex;
};


class Matching
{
public:
    //Parametric constructor receives a graph instance
    Matching(const Graph& G);

    //Solves the minimum cost perfect matching problem
    //Receives the a vector whose position i has the cost of the edge with index i
    //If the graph doest not have a perfect matching, a const char * exception will be raised
    //Returns a pair
    //the first element of the pair is a list of the indices of the edges in the matching
    //the second is the cost of the matching
    pair< list<int>, double > SolveMinimumCostPerfectMatching(const vector<double>& cost);

    //Solves the maximum cardinality matching problem
    //Returns a list with the indices of the edges in the matching
    list<int> SolveMaximumMatching();

private:
    //Grows an alternating forest
    void Grow();
    //Expands a blossom u
    //If expandBlocked is true, the blossom will be expanded even if it is blocked
    void Expand(int u, bool expandBlocked);
    //Augments the matching using the path from u to v in the alternating forest
    void Augment(int u, int v);
    //Resets the alternating forest
    void Reset();
    //Creates a blossom where the tip is the first common vertex in the paths from u and v in the hungarian forest
    int Blossom(int u, int v);
    void UpdateDualCosts();
    //Resets all data structures 
    void Clear();
    void DestroyBlossom(int t);
    //Uses an heuristic algorithm to find the maximum matching of the graph
    void Heuristic();
    //Modifies the costs of the graph so the all edges have positive costs
    void PositiveCosts();
    list<int> RetrieveMatching();

    int GetFreeBlossomIndex();
    void AddFreeBlossomIndex(int i);
    void ClearBlossomIndices();

    //An edge might be blocked due to the dual costs
    bool IsEdgeBlocked(int u, int v);
    bool IsEdgeBlocked(int e);
    //Returns true if u and v are adjacent in G and not blocked
    bool IsAdjacent(int u, int v);

    const Graph& G;

    list<int> free;//List of free blossom indices

    vector<int> outer;//outer[v] gives the index of the outermost blossom that contains v, outer[v] = v if v is not contained in any blossom
    vector< list<int> > deep;//deep[v] is a list of all the original vertices contained inside v, deep[v] = v if v is an original vertex
    vector< list<int> > shallow;//shallow[v] is a list of the vertices immediately contained inside v, shallow[v] is empty is the default
    vector<int> tip;//tip[v] is the tip of blossom v
    vector<bool> active;//true if a blossom is being used

    vector<int> type;//Even, odd, neither (2, 1, 0)
    vector<int> forest;//forest[v] gives the father of v in the alternating forest
    vector<int> root;//root[v] gives the root of v in the alternating forest 

    vector<bool> blocked;//A blossom can be blocked due to dual costs, this means that it behaves as if it were an original vertex and cannot be expanded
    vector<double> dual;//dual multipliers associated to the blossoms, if dual[v] > 0, the blossom is blocked and full
    vector<double> slack;//slack associated to each edge, if slack[e] > 0, the edge cannot be used
    vector<int> mate;//mate[v] gives the mate of v

    int m, n;

    bool perfect;

    list<int> forestList;
    vector<int> visited;
};

Graph::Graph(int n, const list< pair<int, int> >& edges) :
    n(n),
    m(edges.size()),
    adjMat(n, vector<bool>(n, false)),
    adjList(n),
    edges(),
    edgeIndex(n, vector<int>(n, -1))
{
    for (list< pair<int, int> >::const_iterator it = edges.begin(); it != edges.end(); it++)
    {
        int u = (*it).first;
        int v = (*it).second;

        AddEdge(u, v);
    }
}

pair<int, int> Graph::GetEdge(int e) const
{
    if (e > (int)edges.size())
        throw "Error: edge does not exist";

    return edges[e];
}

int Graph::GetEdgeIndex(int u, int v) const
{
    if (u > n or
        v > n)
        throw "Error: vertex does not exist";

    if (edgeIndex[u][v] == -1)
        throw "Error: edge does not exist";

    return edgeIndex[u][v];
}

void Graph::AddVertex()
{
    for (int i = 0; i < n; i++)
    {
        adjMat[i].push_back(false);
        edgeIndex[i].push_back(-1);
    }
    n++;
    adjMat.push_back(vector<bool>(n, false));
    edgeIndex.push_back(vector<int>(n, -1));
    adjList.push_back(list<int>());
}

void Graph::AddEdge(int u, int v)
{
    if (u > n or
        v > n)
        throw "Error: vertex does not exist";

    if (adjMat[u][v]) return;

    adjMat[u][v] = adjMat[v][u] = true;
    adjList[u].push_back(v);
    adjList[v].push_back(u);

    edges.push_back(pair<int, int>(u, v));
    edgeIndex[u][v] = edgeIndex[v][u] = m++;
}

const list<int>& Graph::AdjList(int v) const
{
    if (v > n)
        throw "Error: vertex does not exist";

    return adjList[v];
}

const vector< vector<bool> >& Graph::AdjMat() const
{
    return adjMat;
}

auto MinimumCostPerfectMatchingExample(Graph G, vector<double> cost)
{

    //Create a Matching instance passing the graph
    Matching M(G);

    //Pass the costs to solve the problem
    pair< list<int>, double > solution = M.SolveMinimumCostPerfectMatching(cost);

    return solution;
    list<int> matching = solution.first;
    double obj = solution.second;

    cout << "Optimal matching cost: " << obj << endl;
    cout << "Edges in the matching:" << endl;
    for (list<int>::iterator it = matching.begin(); it != matching.end(); it++)
    {
        pair<int, int> e = G.GetEdge(*it);

        cout << e.first << " " << e.second << endl;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>> edges(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
        edges[a][b] = w;
        edges[b][a] = w;
    }
    //cout << "here@" << endl;
    vector<vector<int>> dp(n, vector<int>(n, INF));
    function<void(int)> bfs = [&](int r) {
        priority_queue<pair<int, int>> pq;
        vector<bool> vis(n);
        pq.push({ 0, r });
        dp[r][r] = 0;
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (auto& [v, w] : adj[u]) {
                if (dp[r][u] + w < dp[r][v]) {
                    dp[r][v] = dp[r][u] + w;
                    pq.push({ -dp[r][v], v });
                }
            }
        }
        };
    cout << "here]" << endl;
    cout << "n = " << n << endl;
    for (int i = 0; i < n; i++) {
        //cout << "i = " << i << endl;
        bfs(i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> odds;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() % 2) odds.push_back(i);
    }
    int z = odds.size();
    Graph G(n);
    vector<double> cost(m);
    for (int i = 0; i < z; i++) {
        for (int j = i + 1; j < z; j++) {
            int x = odds[i];
            int y = odds[j];
            G.AddEdge(x, y);
            cost[G.GetEdgeIndex(x, y)] = dp[x][y];
        }
    }
    auto solution = MinimumCostPerfectMatchingExample(G, cost);
    list<int> matching = solution.first;
    double obj = solution.second;
    cout << "Optimal matching cost: " << obj << endl;
    cout << "Edges in the matching:" << endl;
    set<int> nodes(odds.begin(), odds.end());
    for (list<int>::iterator it = matching.begin(); it != matching.end(); it++)
    {
        pair<int, int> e = G.GetEdge(*it);
        int a = e.first, b = e.second;
        adj[a].push_back({ b, dp[a][b] });
        adj[b].push_back({ a, dp[b][a] });
        nodes.erase(a); nodes.erase(b);
        cout << e.first << " -> " << e.second << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
