#include <bits/stdc++.h>
using namespace std;

void check_nivel_invariant(int nivel, int n) {
    if (nivel > n / 2) {
        cerr << "Warning: nivel_invariant triggered - excessive loop iterations due to large nivel" << endl;
        abort();
    }
}

void check_distance_invariant(int distIzq, int distDer, int distArr, int distAb, int n) {
    if (distIzq > n / 2 || distDer > n / 2 || distArr > n / 2 || distAb > n / 2) {
        cerr << "Warning: distance_invariant triggered - excessive loop iterations due to large distances" << endl;
        abort();
    }
}

void check_binary_search_invariant(int izq, int der, int n) {
    if (der - izq > n) {
        cerr << "Warning: binary_search_invariant triggered - excessive binary search iterations" << endl;
        abort();
    }
}

long long cuadros(int n, int x, int y, int nivel) {
    int aux = x;
    x = y;
    y = aux;
    y = (n + 1) - y;
    long long sumaArr = 0;
    long long sumaAb = 0;
    int distIzq = x - 1;
    int distDer = n - x;
    int distArr = n - y;
    int distAb = y - 1;
    int cuadrosIzq = nivel;
    int cuadrosDer = nivel;
    if (distIzq < cuadrosIzq) cuadrosIzq = distIzq;
    if (distDer < cuadrosDer) cuadrosDer = distDer;

    // Check distance invariants before the loops
    check_distance_invariant(distIzq, distDer, distArr, distAb, n);

    for (int i = 0; i < cuadrosDer + 1; i++) {
        int c = nivel - i;
        if (distArr < c)
            sumaArr += 1 + distArr;
        else
            sumaArr += 1 + c;
        if (distAb < c)
            sumaAb += distAb;
        else {
            sumaAb += c;
        }
    }
    for (int i = 1; i < cuadrosIzq + 1; i++) {
        int c = nivel - i;
        if (distArr < c)
            sumaArr += 1 + distArr;
        else
            sumaArr += 1 + c;
        if (distAb < c)
            sumaAb += distAb;
        else {
            sumaAb += c;
        }
    }
    return sumaArr + sumaAb;
}

int main() {
    int n, x, y, limite;
    cin >> n >> x >> y >> limite;
    int izq = 0, der = 10000000, mid;

    // Check binary search invariant
    check_binary_search_invariant(izq, der, n);

    while (izq < der) {
        mid = (izq + der) / 2;
        // Check nivel invariant before calling cuadros
        check_nivel_invariant(mid, n);

        if (limite <= cuadros(n, x, y, mid))
            der = mid;
        else
            izq = mid + 1;
    }
    cout << der << endl;
    return 0;
}