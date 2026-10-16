#include <bits/stdc++.h>

// Note: __int128 est une extension de GCC/Clang et peut ne pas être disponible sur d'autres compilateurs.
// Pour la portabilité, vous pourriez avoir besoin d'implémenter une multiplication pour de grands entiers.
template<typename T>
T power(T base, T exp, T mod) {
    T res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp /= 2;
    }
    return res;
}

template<typename T>
class MillerRabin {
private:
    std::vector<T> bases;

    bool check(T n, T a) {
        if (a >= n) return true;

        T m = n - 1;
        int k = 0;
        while (m % 2 == 0) {
            m /= 2;
            k++;
        }

        T x = power(a, m, n);
        if (x == 1 || x == n - 1) return true;

        for (int i = 0; i < k - 1; ++i) {
            x = (__int128)x * x % n;
            if (x == n - 1) return true;
        }

        return false;
    }

public:
    MillerRabin() {
        // Bases de test fiables pour les entiers 64-bit
        // Ces bases garantissent une précision déterministe pour les nombres < 3.3 * 10^14
        // Pour les nombres plus grands, il est recommandé d'utiliser un jeu de bases plus étendu
        // ou d'inclure des bases aléatoires.
        bases = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
    }

    bool isPrime(T n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (T base : bases) {
            if (!check(n, base)) {
                return false;
            }
        }
        return true;
    }
};