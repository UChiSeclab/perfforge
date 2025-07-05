#include <bits/stdc++.h>
using namespace std;

long long n, x, y, c;

long long pintados(long long segundos) {
    long long pos, aArriba = 0, aAbajo = 0, contador = 0;
    bool arriba = true, abajo = true;
    for (pos = x - segundos; pos < 1; ++pos) {
        if (y + aAbajo == n) abajo = false;
        if (y - aArriba == 1) arriba = false;
        if (abajo) ++aAbajo;
        if (arriba) ++aArriba;
    }
    for (pos; pos <= x && pos <= n; ++pos) {
        contador += aAbajo + aArriba + 1;
        if (contador < 0) return INT_MAX;
        if (y + aAbajo == n) abajo = false;
        if (y - aArriba == 1) arriba = false;
        if (abajo) ++aAbajo;
        if (arriba) ++aArriba;
    }
    aArriba = aAbajo = 0;
    arriba = abajo = true;
    for (pos = x + segundos; pos > n; --pos) {
        if (y + aAbajo == n) abajo = false;
        if (y - aArriba == 1) arriba = false;
        if (abajo) ++aAbajo;
        if (arriba) ++aArriba;
    }
    for (pos; pos > x; --pos) {
        contador += aAbajo + aArriba + 1;
        if (contador < 0) return INT_MAX;
        if (y + aAbajo == n) abajo = false;
        if (y - aArriba == 1) arriba = false;
        if (abajo) ++aAbajo;
        if (arriba) ++aArriba;
    }
    return contador;
}

long long buscar() {
    long long izq = 0, der = min((long long)2e5, n * 2), centro;
    while (izq <= der) {
        centro = (der - izq) / 2 + izq;
        long long segundos = pintados(centro), ant = pintados(centro - 1);
        if (segundos >= c && ant < c) return centro;
        if (segundos < c)
            izq = centro + 1;
        else
            der = centro - 1;
    }
}

int main() {
    cin >> n >> x >> y >> c;

    // Insert performance checkers after reading inputs
    check_grid_size_invariant(n, c);  // Check for large grid size and required active cells
    check_boundary_invariant(x, y, n, c);  // Check for initial cell near boundary with large 'c'
    check_active_cells_invariant(n, c);  // Check for high number of active cells required

    cout << buscar() << '\n';
}