#include <bits/stdc++.h>
using namespace std;

#define EVEN 2
#define ODD 1
#define UNLABELED 0

#define EPSILON 0.000001
#define INFINITO 1000000000.0
#define GREATER(A, B) ((A) - (B) > EPSILON)
#define LESS(A, B) ((B) - (A) > EPSILON)
#define EQUAL(A, B) (fabs((A) - (B)) < EPSILON)
#define GREATER_EQUAL(A, B) (GREATER((A),(B)) || EQUAL((A),(B)))
#define LESS_EQUAL(A, B) (LESS((A),(B)) || EQUAL((A),(B)))
#define MIN(A, B) (LESS((A),(B)) ? (A) : (B))
#define MAX(A, B) (LESS((A),(B)) ? (B) : (A))

/*
This is a binary heap for pairs of the type (double key, int satellite)
It is assumed that satellites are unique integers
This is the case with graph algorithms, in which satellites are vertex or edge indices
 */
class BinaryHeap
{
public:
    BinaryHeap() : satellite(1), size(0) {};

    //Inserts (key k, satellite s) in the heap
    void Insert(double k, int s);
    //Deletes the element with minimum key and returns its satellite information
    int DeleteMin();
    //Changes the key of the element with satellite s
    void ChangeKey(double k, int s);
    //Removes the element with satellite s
    void Remove(int s);
    //Returns the number of elements in the heap
    int Size();
    //Resets the structure
    void Clear();

private:
    vector<double> key;//Given the satellite, this is its key
    vector<int> pos;//Given the satellite, this is its position in the heap
    vector<int> satellite;//This is the heap!

    //Number of elements in the heap
    int size;
};



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

void BinaryHeap::Clear()
{
    key.clear();
    pos.clear();
    satellite.clear();
}

void BinaryHeap::Insert(double k, int s)
{
    //Ajust the structures to fit new data
    if (s >= (int)pos.size())
    {
        pos.resize(s + 1, -1);
        key.resize(s + 1);
        //Recall that position 0 of satellite is unused
        satellite.resize(s + 2);
    }
    //If satellite is already in the heap
    else if (pos[s] != -1)
    {
        throw "Error: satellite already in heap";
    }

    int i;
    for (i = ++size; i / 2 > 0 && GREATER(key[satellite[i / 2]], k); i /= 2)
    {
        satellite[i] = satellite[i / 2];
        pos[satellite[i]] = i;
    }
    satellite[i] = s;
    pos[s] = i;
    key[s] = k;
}

int BinaryHeap::Size()
{
    return size;
}

int BinaryHeap::DeleteMin()
{
    if (size == 0)
        throw "Error: empty heap";

    int min = satellite[1];
    int slast = satellite[size--];


    int child;
    int i;
    for (i = 1, child = 2; child <= size; i = child, child *= 2)
    {
        if (child < size && GREATER(key[satellite[child]], key[satellite[child + 1]]))
            child++;

        if (GREATER(key[slast], key[satellite[child]]))
        {
            satellite[i] = satellite[child];
            pos[satellite[child]] = i;
        }
        else
            break;
    }
    satellite[i] = slast;
    pos[slast] = i;

    pos[min] = -1;

    return min;
}

void BinaryHeap::ChangeKey(double k, int s)
{
    Remove(s);
    Insert(k, s);
}

void BinaryHeap::Remove(int s)
{
    int i;
    for (i = pos[s]; i / 2 > 0; i /= 2)
    {
        satellite[i] = satellite[i / 2];
        pos[satellite[i]] = i;
    }
    satellite[1] = s;
    pos[s] = 1;

    DeleteMin();
}




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




Matching::Matching(const Graph& G) :
    G(G),
    outer(2 * G.GetNumVertices()),
    deep(2 * G.GetNumVertices()),
    shallow(2 * G.GetNumVertices()),
    tip(2 * G.GetNumVertices()),
    active(2 * G.GetNumVertices()),
    type(2 * G.GetNumVertices()),
    forest(2 * G.GetNumVertices()),
    root(2 * G.GetNumVertices()),
    blocked(2 * G.GetNumVertices()),
    dual(2 * G.GetNumVertices()),
    slack(G.GetNumEdges()),
    mate(2 * G.GetNumVertices()),
    m(G.GetNumEdges()),
    n(G.GetNumVertices()),
    visited(2 * G.GetNumVertices())
{
}

void Matching::Grow()
{
    Reset();

    //All unmatched vertices will be roots in a forest that will be grown
    //The forest is grown by extending a unmatched vertex w through a matched edge u-v in a BFS fashion
    while (!forestList.empty())
    {
        int w = outer[forestList.front()];
        forestList.pop_front();

        //w might be a blossom
        //we have to explore all the connections from vertices inside the blossom to other vertices
        for (list<int>::iterator it = deep[w].begin(); it != deep[w].end(); it++)
        {
            int u = *it;

            int cont = false;
            for (list<int>::const_iterator jt = G.AdjList(u).begin(); jt != G.AdjList(u).end(); jt++)
            {
                int v = *jt;

                if (IsEdgeBlocked(u, v)) continue;

                //u is even and v is odd
                if (type[outer[v]] == ODD) continue;

                //if v is unlabeled
                if (type[outer[v]] != EVEN)
                {
                    //We grow the alternating forest
                    int vm = mate[outer[v]];

                    forest[outer[v]] = u;
                    type[outer[v]] = ODD;
                    root[outer[v]] = root[outer[u]];
                    forest[outer[vm]] = v;
                    type[outer[vm]] = EVEN;
                    root[outer[vm]] = root[outer[u]];

                    if (!visited[outer[vm]])
                    {
                        forestList.push_back(vm);
                        visited[outer[vm]] = true;
                    }
                }
                //If v is even and u and v are on different trees
                //we found an augmenting path
                else if (root[outer[v]] != root[outer[u]])
                {
                    Augment(u, v);
                    Reset();

                    cont = true;
                    break;
                }
                //If u and v are even and on the same tree
                //we found a blossom
                else if (outer[u] != outer[v])
                {
                    int b = Blossom(u, v);

                    forestList.push_front(b);
                    visited[b] = true;

                    cont = true;
                    break;
                }
            }
            if (cont) break;
        }
    }

    //Check whether the matching is perfect
    perfect = true;
    for (int i = 0; i < n; i++)
        if (mate[outer[i]] == -1)
            perfect = false;
}

bool Matching::IsAdjacent(int u, int v)
{
    return (G.AdjMat()[u][v] and not IsEdgeBlocked(u, v));
}

bool Matching::IsEdgeBlocked(int u, int v)
{
    return GREATER(slack[G.GetEdgeIndex(u, v)], 0);
}

bool Matching::IsEdgeBlocked(int e)
{
    return GREATER(slack[e], 0);
}

//Vertices will be selected in non-decreasing order of their degree
//Each time an unmatched vertex is selected, it is matched to its adjacent unmatched vertex of minimum degree
void Matching::Heuristic()
{
    vector<int> degree(n, 0);
    BinaryHeap B;

    for (int i = 0; i < m; i++)
    {
        if (IsEdgeBlocked(i)) continue;

        pair<int, int> p = G.GetEdge(i);
        int u = p.first;
        int v = p.second;

        degree[u]++;
        degree[v]++;
    }

    for (int i = 0; i < n; i++)
        B.Insert(degree[i], i);

    while (B.Size() > 0)
    {
        int u = B.DeleteMin();
        if (mate[outer[u]] == -1)
        {
            int min = -1;
            for (list<int>::const_iterator it = G.AdjList(u).begin(); it != G.AdjList(u).end(); it++)
            {
                int v = *it;

                if (IsEdgeBlocked(u, v) or
                    (outer[u] == outer[v]) or
                    (mate[outer[v]] != -1))
                    continue;

                if (min == -1 or degree[v] < degree[min])
                    min = v;
            }
            if (min != -1)
            {
                mate[outer[u]] = min;
                mate[outer[min]] = u;
            }
        }
    }
}

//Destroys a blossom recursively
void Matching::DestroyBlossom(int t)
{
    if ((t < n) or
        (blocked[t] and GREATER(dual[t], 0))) return;

    for (list<int>::iterator it = shallow[t].begin(); it != shallow[t].end(); it++)
    {
        int s = *it;
        outer[s] = s;
        for (list<int>::iterator jt = deep[s].begin(); jt != deep[s].end(); jt++)
            outer[*jt] = s;

        DestroyBlossom(s);
    }

    active[t] = false;
    blocked[t] = false;
    AddFreeBlossomIndex(t);
    mate[t] = -1;
}

void Matching::Expand(int u, bool expandBlocked = false)
{
    int v = outer[mate[u]];

    int index = m;
    int p = -1, q = -1;
    //Find the regular edge {p,q} of minimum index connecting u and its mate
    //We use the minimum index to grant that the two possible blossoms u and v will use the same edge for a mate
    for (list<int>::iterator it = deep[u].begin(); it != deep[u].end(); it++)
    {
        int di = *it;
        for (list<int>::iterator jt = deep[v].begin(); jt != deep[v].end(); jt++)
        {
            int dj = *jt;
            if (IsAdjacent(di, dj) and G.GetEdgeIndex(di, dj) < index)
            {
                index = G.GetEdgeIndex(di, dj);
                p = di;
                q = dj;
            }
        }
    }

    mate[u] = q;
    mate[v] = p;
    //If u is a regular vertex, we are done
    if (u < n or (blocked[u] and not expandBlocked)) return;

    bool found = false;
    //Find the position t of the new tip of the blossom
    for (list<int>::iterator it = shallow[u].begin(); it != shallow[u].end() and not found; )
    {
        int si = *it;
        for (list<int>::iterator jt = deep[si].begin(); jt != deep[si].end() and not found; jt++)
        {
            if (*jt == p)
                found = true;
        }
        it++;
        if (not found)
        {
            shallow[u].push_back(si);
            shallow[u].pop_front();
        }
    }

    list<int>::iterator it = shallow[u].begin();
    //Adjust the mate of the tip
    mate[*it] = mate[u];
    it++;
    //
    //Now we go through the odd circuit adjusting the new mates
    while (it != shallow[u].end())
    {
        list<int>::iterator itnext = it;
        itnext++;
        mate[*it] = *itnext;
        mate[*itnext] = *it;
        itnext++;
        it = itnext;
    }

    //We update the sets blossom, shallow, and outer since this blossom is being deactivated
    for (list<int>::iterator it = shallow[u].begin(); it != shallow[u].end(); it++)
    {
        int s = *it;
        outer[s] = s;
        for (list<int>::iterator jt = deep[s].begin(); jt != deep[s].end(); jt++)
            outer[*jt] = s;
    }
    active[u] = false;
    AddFreeBlossomIndex(u);

    //Expand the vertices in the blossom
    for (list<int>::iterator it = shallow[u].begin(); it != shallow[u].end(); it++)
        Expand(*it, expandBlocked);

}

//Augment the path root[u], ..., u, v, ..., root[v]
void Matching::Augment(int u, int v)
{
    //We go from u and v to its respective roots, alternating the matching
    int p = outer[u];
    int q = outer[v];
    int outv = q;
    int fp = forest[p];
    mate[p] = q;
    mate[q] = p;
    Expand(p);
    Expand(q);
    while (fp != -1)
    {
        q = outer[forest[p]];
        p = outer[forest[q]];
        fp = forest[p];

        mate[p] = q;
        mate[q] = p;
        Expand(p);
        Expand(q);
    }

    p = outv;
    fp = forest[p];
    while (fp != -1)
    {
        q = outer[forest[p]];
        p = outer[forest[q]];
        fp = forest[p];

        mate[p] = q;
        mate[q] = p;
        Expand(p);
        Expand(q);
    }
}

void Matching::Reset()
{
    for (int i = 0; i < 2 * n; i++)
    {
        forest[i] = -1;
        root[i] = i;

        if (i >= n and active[i] and outer[i] == i)
            DestroyBlossom(i);
    }

    visited.assign(2 * n, 0);
    forestList.clear();
    for (int i = 0; i < n; i++)
    {
        if (mate[outer[i]] == -1)
        {
            type[outer[i]] = 2;
            if (!visited[outer[i]])
                forestList.push_back(i);
            visited[outer[i]] = true;
        }
        else type[outer[i]] = 0;
    }
}

int Matching::GetFreeBlossomIndex()
{
    int i = free.back();
    free.pop_back();
    return i;
}

void Matching::AddFreeBlossomIndex(int i)
{
    free.push_back(i);
}

void Matching::ClearBlossomIndices()
{
    free.clear();
    for (int i = n; i < 2 * n; i++)
        AddFreeBlossomIndex(i);
}

//Contracts the blossom w, ..., u, v, ..., w, where w is the first vertex that appears in the paths from u and v to their respective roots
int Matching::Blossom(int u, int v)
{
    int t = GetFreeBlossomIndex();

    vector<bool> isInPath(2 * n, false);

    //Find the tip of the blossom
    int u_ = u;
    while (u_ != -1)
    {
        isInPath[outer[u_]] = true;

        u_ = forest[outer[u_]];
    }

    int v_ = outer[v];
    while (not isInPath[v_])
        v_ = outer[forest[v_]];
    tip[t] = v_;

    //Find the odd circuit, update shallow, outer, blossom and deep
    //First we construct the set shallow (the odd circuit)
    list<int> circuit;
    u_ = outer[u];
    circuit.push_front(u_);
    while (u_ != tip[t])
    {
        u_ = outer[forest[u_]];
        circuit.push_front(u_);
    }

    shallow[t].clear();
    deep[t].clear();
    for (list<int>::iterator it = circuit.begin(); it != circuit.end(); it++)
    {
        shallow[t].push_back(*it);
    }

    v_ = outer[v];
    while (v_ != tip[t])
    {
        shallow[t].push_back(v_);
        v_ = outer[forest[v_]];
    }

    //Now we construct deep and update outer
    for (list<int>::iterator it = shallow[t].begin(); it != shallow[t].end(); it++)
    {
        u_ = *it;
        outer[u_] = t;
        for (list<int>::iterator jt = deep[u_].begin(); jt != deep[u_].end(); jt++)
        {
            deep[t].push_back(*jt);
            outer[*jt] = t;
        }
    }

    forest[t] = forest[tip[t]];
    type[t] = EVEN;
    root[t] = root[tip[t]];
    active[t] = true;
    outer[t] = t;
    mate[t] = mate[tip[t]];

    return t;
}

void Matching::UpdateDualCosts()
{
    double e1 = 0, e2 = 0, e3 = 0;
    int inite1 = false, inite2 = false, inite3 = false;
    for (int i = 0; i < m; i++)
    {
        int u = G.GetEdge(i).first,
            v = G.GetEdge(i).second;

        if ((type[outer[u]] == EVEN and type[outer[v]] == UNLABELED) or (type[outer[v]] == EVEN and type[outer[u]] == UNLABELED))
        {
            if (!inite1 or GREATER(e1, slack[i]))
            {
                e1 = slack[i];
                inite1 = true;
            }
        }
        else if ((outer[u] != outer[v]) and type[outer[u]] == EVEN and type[outer[v]] == EVEN)
        {
            if (!inite2 or GREATER(e2, slack[i]))
            {
                e2 = slack[i];
                inite2 = true;
            }
        }
    }
    for (int i = n; i < 2 * n; i++)
    {
        if (active[i] and i == outer[i] and type[outer[i]] == ODD and (!inite3 or GREATER(e3, dual[i])))
        {
            e3 = dual[i];
            inite3 = true;
        }
    }
    double e = 0;
    if (inite1) e = e1;
    else if (inite2) e = e2;
    else if (inite3) e = e3;

    if (GREATER(e, e2 / 2.0) and inite2)
        e = e2 / 2.0;
    if (GREATER(e, e3) and inite3)
        e = e3;

    for (int i = 0; i < 2 * n; i++)
    {
        if (i != outer[i]) continue;

        if (active[i] and type[outer[i]] == EVEN)
        {
            dual[i] += e;
        }
        else if (active[i] and type[outer[i]] == ODD)
        {
            dual[i] -= e;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u = G.GetEdge(i).first,
            v = G.GetEdge(i).second;

        if (outer[u] != outer[v])
        {
            if (type[outer[u]] == EVEN and type[outer[v]] == EVEN)
                slack[i] -= 2.0 * e;
            else if (type[outer[u]] == ODD and type[outer[v]] == ODD)
                slack[i] += 2.0 * e;
            else if ((type[outer[v]] == UNLABELED and type[outer[u]] == EVEN) or (type[outer[u]] == UNLABELED and type[outer[v]] == EVEN))
                slack[i] -= e;
            else if ((type[outer[v]] == UNLABELED and type[outer[u]] == ODD) or (type[outer[u]] == UNLABELED and type[outer[v]] == ODD))
                slack[i] += e;
        }
    }
    for (int i = n; i < 2 * n; i++)
    {
        if (GREATER(dual[i], 0))
        {
            blocked[i] = true;
        }
        else if (active[i] and blocked[i])
        {
            //The blossom is becoming unblocked
            if (mate[i] == -1)
            {
                DestroyBlossom(i);
            }
            else
            {
                blocked[i] = false;
                Expand(i);
            }
        }
    }
}

pair< list<int>, double> Matching::SolveMinimumCostPerfectMatching(const vector<double>& cost)
{
    SolveMaximumMatching();
    if (!perfect)
        throw "Error: The graph does not have a perfect matching";

    Clear();

    //Initialize slacks (reduced costs for the edges)
    slack = cost;

    PositiveCosts();

    //If the matching on the compressed graph is perfect, we are done
    perfect = false;
    while (not perfect)
    {
        //Run an heuristic maximum matching algorithm
        Heuristic();
        //Grow a hungarian forest
        Grow();
        UpdateDualCosts();
        //Set up the algorithm for a new grow step
        Reset();
    }

    list<int> matching = RetrieveMatching();

    double obj = 0;
    for (list<int>::iterator it = matching.begin(); it != matching.end(); it++)
        obj += cost[*it];

    double dualObj = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (i < n) dualObj += dual[i];
        else if (blocked[i]) dualObj += dual[i];
    }

    return pair< list<int>, double >(matching, obj);
}

void Matching::PositiveCosts()
{
    double minEdge = 0;
    for (int i = 0; i < m;i++)
        if (GREATER(minEdge - slack[i], 0))
            minEdge = slack[i];

    for (int i = 0; i < m; i++)
        slack[i] -= minEdge;
}

list<int> Matching::SolveMaximumMatching()
{
    Clear();
    Grow();
    return RetrieveMatching();
}

//Sets up the algorithm for a new run
void Matching::Clear()
{
    ClearBlossomIndices();

    for (int i = 0; i < 2 * n; i++)
    {
        outer[i] = i;
        deep[i].clear();
        if (i < n)
            deep[i].push_back(i);
        shallow[i].clear();
        if (i < n) active[i] = true;
        else active[i] = false;

        type[i] = 0;
        forest[i] = -1;
        root[i] = i;

        blocked[i] = false;
        dual[i] = 0;
        mate[i] = -1;
        tip[i] = i;
    }
    slack.assign(m, 0);
}

list<int> Matching::RetrieveMatching()
{
    list<int> matching;

    for (int i = 0; i < 2 * n; i++)
        if (active[i] and mate[i] != -1 and outer[i] == i)
            Expand(i, true);

    for (int i = 0; i < m; i++)
    {
        int u = G.GetEdge(i).first;
        int v = G.GetEdge(i).second;

        if (mate[u] == v)
            matching.push_back(i);
    }
    return matching;
}


pair< Graph, vector<double> > ReadWeightedGraph(string filename)
{
    //Please see Graph.h for a description of the interface

    ifstream file;
    file.open(filename.c_str());

    string s;
    getline(file, s);
    stringstream ss(s);
    int n;
    ss >> n;
    getline(file, s);
    ss.str(s);
    ss.clear();
    int m;
    ss >> m;

    Graph G(n);
    vector<double> cost(m);
    for (int i = 0; i < m; i++)
    {
        getline(file, s);
        ss.str(s);
        ss.clear();
        int u, v;
        double c;
        ss >> u >> v >> c;

        G.AddEdge(u, v);
        cost[G.GetEdgeIndex(u, v)] = c;
    }

    file.close();
    return make_pair(G, cost);
}

void MinimumCostPerfectMatchingExample(string filename)
{
    Graph G;
    vector<double> cost;

    //Read the graph
    pair< Graph, vector<double> > p = ReadWeightedGraph(filename);
    //pair< Graph, vector<double> > p = CreateRandomGraph();
    G = p.first;
    cost = p.second;

    //Create a Matching instance passing the graph
    Matching M(G);

    //Pass the costs to solve the problem
    pair< list<int>, double > solution = M.SolveMinimumCostPerfectMatching(cost);

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

bool Connected(const Graph& G)
{
    vector<bool> visited(G.GetNumVertices(), false);
    list<int> L;

    int n = 0;
    L.push_back(0);
    while (not L.empty())
    {
        int u = L.back();
        L.pop_back();
        if (visited[u]) continue;

        visited[u] = true;
        n++;

        for (list<int>::const_iterator it = G.AdjList(u).begin(); it != G.AdjList(u).end(); it++)
        {
            int v = *it;
            L.push_back(v);
        }
    }

    return G.GetNumVertices() == n;
}


//Dijkstra's algorithm using binary heap
//Returns a pair (vector<int>, vector<double>)
//vector<double> gives the cost of the optimal path to each vertex
//vector<int> gives the parent of each vertex in the tree of optimal paths
pair< vector<int>, vector<double> > Dijkstra(const Graph& G, int origin, const vector<double>& cost)
{
    BinaryHeap B;

    int n = G.GetNumVertices();

    //Father of each vertex in the optimal path tree
    vector<int> father(n, -1);

    //Used to indicate whether a vertex is permanently labeled
    vector<bool> permanent(n, false);

    vector<double> pathCost(n, numeric_limits<double>::infinity());

    //Put s in the heap
    B.Insert(0, origin);
    pathCost[origin] = 0;

    for (int i = 0; i < n; i++)
    {
        //Select the vertex that can be reached with smallest cost
        int u = B.DeleteMin();

        permanent[u] = true;

        //Update the heap with vertices adjacent to u
        for (list<int>::const_iterator it = G.AdjList(u).begin(); it != G.AdjList(u).end(); it++)
        {
            int v = *it;

            if (permanent[v])
                continue;

            double c = pathCost[u] + cost[G.GetEdgeIndex(u, v)];

            //v has not been discovered yet
            if (father[v] == -1)
            {
                father[v] = u;
                pathCost[v] = c;
                B.Insert(c, v);
            }
            //we found a cheaper connection to v
            else if (LESS(c, pathCost[v]))
            {
                father[v] = u;
                pathCost[v] = c;
                B.ChangeKey(c, v);
            }
        }
    }

    if (B.Size() > 0)
        throw "Error: graph is not connected";

    return make_pair(father, pathCost);
}

/*
Solves the chinese postman problem
returns a pair containing a list and a double
the list is the sequence of vertices in the solution
the double is the solution cost
*/
pair< list<int>, double > ChinesePostman(const Graph& G, const vector<double>& cost)
{
    //Check if the graph if connected
    if (not Connected(G))
        throw "Error: Graph is not connected";

    //Build adjacency lists using edges in the graph
    vector< list<int> > A(G.GetNumVertices(), list<int>());
    for (int u = 0; u < G.GetNumVertices(); u++)
        A[u] = G.AdjList(u);

    //Find vertices with odd degree
    vector<int> odd;
    for (int u = 0; u < G.GetNumVertices(); u++)
        if (A[u].size() % 2)
            odd.push_back(u);

    //If there are odd degree vertices
    if (not odd.empty())
    {
        //Create a graph with the odd degree vertices
        Graph O(odd.size());
        for (int u = 0; u < (int)odd.size(); u++)
            for (int v = u + 1; v < (int)odd.size(); v++)
                O.AddEdge(u, v);

        vector<double> costO(O.GetNumEdges());

        //Find the shortest paths between all odd degree vertices
        vector< vector<int> > shortestPath(O.GetNumVertices());
        for (int u = 0; u < (int)odd.size(); u++)
        {
            pair< vector<int>, vector<double> > sp = Dijkstra(G, odd[u], cost);

            shortestPath[u] = sp.first;

            //The cost of an edge uv in O will be the cost of the corresponding shortest path in G
            for (int v = 0; v < (int)odd.size(); v++)
                if (v != u)
                    costO[O.GetEdgeIndex(u, v)] = sp.second[odd[v]];
        }

        //Find the minimum cost perfect matching of the graph of the odd degree vertices
        Matching M(O);
        pair< list<int>, double > p = M.SolveMinimumCostPerfectMatching(costO);
        list<int> matching = p.first;

        //If an edge uv is in the matching, the edges in the shortest path from u to v should be duplicated in G
        for (list<int>::iterator it = matching.begin(); it != matching.end(); it++)
        {
            pair<int, int> p = O.GetEdge(*it);
            int u = p.first, v = odd[p.second];

            //Go through the path adding the edges
            int w = shortestPath[u][v];
            while (w != -1)
            {
                A[w].push_back(v);
                A[v].push_back(w);
                v = w;
                w = shortestPath[u][v];
            }
        }
    }

    //Find an Eulerian cycle in the graph implied by A
    list<int> cycle;
    //This is to keep track of how many times we can traverse an edge
    vector<int> traversed(G.GetNumEdges(), 0);
    for (int u = 0; u < G.GetNumVertices(); u++)
    {
        for (list<int>::iterator it = A[u].begin(); it != A[u].end(); it++)
        {
            int v = *it;

            //we do this so that the edge is not counted twice
            if (v < u) continue;

            traversed[G.GetEdgeIndex(u, v)]++;
        }
    }

    cycle.push_back(0);
    list<int>::iterator itp = cycle.begin();
    double obj = 0;
    while (itp != cycle.end())
    {
        //Let u be the current vertex in the cycle, starting at the first
        int u = *itp;
        list<int>::iterator jtp = itp;
        jtp++;

        //if there are non-traversed edges incident to u, find a subcycle starting at u
        //replace u in the cycle by the subcycle
        while (not A[u].empty())
        {
            while (not A[u].empty() and traversed[G.GetEdgeIndex(u, A[u].back())] == 0)
                A[u].pop_back();

            if (not A[u].empty())
            {
                int v = A[u].back();
                A[u].pop_back();
                cycle.insert(jtp, v);
                traversed[G.GetEdgeIndex(u, v)]--;
                obj += cost[G.GetEdgeIndex(u, v)];
                u = v;
            }
        }

        //go to the next vertex in the cycle and do the same
        itp++;
    }

    return pair< list<int>, double >(cycle, obj);
}

void solve() {
    int n, m;
    cin >> n >> m;
    Graph G(n);
    vector<double> cost(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        double c;
        cin >> u >> v >> c;

        G.AddEdge(u, v);
        cost[G.GetEdgeIndex(u, v)] = c;
    }
    auto res = ChinesePostman(G, cost);
    auto ans = ceil(res.second);
    cout << (long long)ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
