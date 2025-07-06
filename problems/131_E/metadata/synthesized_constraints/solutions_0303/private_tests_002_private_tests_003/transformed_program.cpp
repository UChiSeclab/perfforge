#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > mas;
map<pair<int, int>, int> MI, MA;

// Checker for map operation bottlenecks
void check_map_operation_invariant(int uniqueKeys) {
    if (uniqueKeys > 10000) { // Arbitrary threshold for map size impact
        cerr << "Warning: Performance bottleneck condition triggered due to extensive map operations!" << endl;
        abort();
    }
}

// Checker for dense board condition
void check_dense_board_invariant(int n, int m) {
    if (m > n / 2) { // Arbitrary threshold for density of queens
        cerr << "Warning: Performance bottleneck condition triggered due to dense queen placement on the board!" << endl;
        abort();
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Check the dense board condition
    check_dense_board_invariant(n, m);

    mas.resize(m);
    for (int i = (0); i < (m); ++i) {
        int cj, ci;
        scanf("%d %d", &cj, &ci);
        --cj;
        --ci;
        mas[i] = make_pair(cj, ci);

        if (!((MI).find(make_pair(cj, -1)) != (MI).end()))
            MI[make_pair(cj, -1)] = ci;
        MI[make_pair(cj, -1)] =
            ((MI[make_pair(cj, -1)] <= ci) ? MI[make_pair(cj, -1)] : ci);
        if (!((MA).find(make_pair(cj, -1)) != (MA).end()))
            MA[make_pair(cj, -1)] = ci;
        MA[make_pair(cj, -1)] =
            ((MA[make_pair(cj, -1)] >= ci) ? MA[make_pair(cj, -1)] : ci);
        if (!((MI).find(make_pair(-1, ci)) != (MI).end()))
            MI[make_pair(-1, ci)] = cj;
        MI[make_pair(-1, ci)] =
            ((MI[make_pair(-1, ci)] <= cj) ? MI[make_pair(-1, ci)] : cj);
        if (!((MA).find(make_pair(-1, ci)) != (MA).end()))
            MA[make_pair(-1, ci)] = cj;
        MA[make_pair(-1, ci)] =
            ((MA[make_pair(-1, ci)] >= cj) ? MA[make_pair(-1, ci)] : cj);

        pair<int, int> v = make_pair(mas[i].first - ((cj <= ci) ? cj : ci),
                                     mas[i].second - ((cj <= ci) ? cj : ci));
        v.first += 1;
        v.second += 1;
        if (!((MI).find(v) != (MI).end())) MI[v] = ci;
        MI[v] = ((MI[v] <= ci) ? MI[v] : ci);
        if (!((MA).find(v) != (MA).end())) MA[v] = ci;
        MA[v] = ((MA[v] >= ci) ? MA[v] : ci);

        v = make_pair(mas[i].first + ((n - cj <= ci) ? n - cj : ci),
                      mas[i].second - ((n - cj <= ci) ? n - cj : ci));
        v.first += 1;
        v.second += 1;
        v.first = -v.first;
        v.second = -v.second;
        if (!((MI).find(v) != (MI).end())) MI[v] = ci;
        MI[v] = ((MI[v] <= ci) ? MI[v] : ci);
        if (!((MA).find(v) != (MA).end())) MA[v] = ci;
        MA[v] = ((MA[v] >= ci) ? MA[v] : ci);
    }

    // Check the map operation bottleneck condition
    check_map_operation_invariant(MI.size() + MA.size());

    int ans[16];
    memset(ans, 0, sizeof(ans));
    for (int i = (0); i < (m); ++i) {
        int r = 0, mi, ma;
        int cj = mas[i].first, ci = mas[i].second;
        if (((MI).find(make_pair(cj, -1)) != (MI).end()) &&
            ((MA).find(make_pair(cj, -1)) != (MA).end())) {
            mi = MI[make_pair(cj, -1)];
            ma = MA[make_pair(cj, -1)];
            if (mi < ci) ++r;
            if (ma > ci) ++r;
        }
        if (((MI).find(make_pair(-1, ci)) != (MI).end()) &&
            ((MA).find(make_pair(-1, ci)) != (MA).end())) {
            mi = MI[make_pair(-1, ci)];
            ma = MA[make_pair(-1, ci)];
            if (mi < cj) ++r;
            if (ma > cj) ++r;
        }

        pair<int, int> v;
        v = make_pair(mas[i].first - ((cj <= ci) ? cj : ci),
                      mas[i].second - ((cj <= ci) ? cj : ci));
        v.first += 1;
        v.second += 1;
        if (((MI).find(v) != (MI).end()) && ((MA).find(v) != (MA).end())) {
            mi = MI[v];
            ma = MA[v];
            if (mi < ci) ++r;
            if (ma > ci) ++r;
        }
        v = make_pair(mas[i].first + ((n - cj <= ci) ? n - cj : ci),
                      mas[i].second - ((n - cj <= ci) ? n - cj : ci));
        v.first += 1;
        v.second += 1;
        v.first = -v.first;
        v.second = -v.second;
        if (((MI).find(v) != (MI).end()) && ((MA).find(v) != (MA).end())) {
            mi = MI[v];
            ma = MA[v];
            if (mi < ci) ++r;
            if (ma > ci) ++r;
        }
        ++ans[r];
    }
    for (int i = (0); i < (9); ++i) {
        printf("%d", ans[i]);
        if (i + 1 == 9)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}