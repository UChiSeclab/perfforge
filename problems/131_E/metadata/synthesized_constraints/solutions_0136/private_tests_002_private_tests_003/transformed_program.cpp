#include <bits/stdc++.h>
using namespace std;
const int inf = 1e5 + 9;
pair<pair<int, int>, int> a[inf];
map<int, int> row, col, d1, d2;
int atta[inf], ans[inf];

// Define the checkers
void check_sort_invariant(int m) {
    if (m > 50000) { // Example threshold for large m
        cerr << "Warning: sort_invariant triggered - sorting a large number of queens" << endl;
        abort();
    }
}

void check_map_operations_invariant(int m) {
    if (m > 50000) { // Example threshold indicating heavy map operations
        cerr << "Warning: map_operations_invariant triggered - excessive map operations for a large number of queens" << endl;
        abort();
    }
}

void check_queen_density_invariant(int n, int m) {
    if (m > 0.8 * n * n) { // Example threshold for high density of queens
        cerr << "Warning: queen_density_invariant triggered - high density of queens on the board" << endl;
        abort();
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Integrate the checkers at appropriate points
    check_sort_invariant(m);
    check_map_operations_invariant(m);
    check_queen_density_invariant(n, m);

    for (int i = 1; i <= m; i++)
        cin >> a[i].first.first >> a[i].first.second, a[i].second = i;
    
    sort(a + 1, a + 1 + m, cmp1);
    for (int i = 1; i <= m; i++) {
        int x = a[i].first.first, y = a[i].first.second, id = a[i].second;
        if (row.find(x) != row.end()) atta[id]++;
        if (col.find(y) != col.end()) atta[id]++;
        if (d1.find(x + y) != d1.end()) atta[id]++;
        if (d2.find(x - y) != d2.end()) atta[id]++;
        d2[x - y] = 1;
        d1[x + y] = 1;
        col[y] = 1;
        row[x] = 1;
    }
    row.clear();
    col.clear();
    d2.clear();
    d1.clear();
    sort(a + 1, a + 1 + m, cmp2);
    for (int i = 1; i <= m; i++) {
        int x = a[i].first.first, y = a[i].first.second, id = a[i].second;
        if (row.find(x) != row.end()) atta[id]++;
        if (col.find(y) != col.end()) atta[id]++;
        if (d1.find(x + y) != d1.end()) atta[id]++;
        if (d2.find(x - y) != d2.end()) atta[id]++;
        d2[x - y] = 1;
        d1[x + y] = 1;
        col[y] = 1;
        row[x] = 1;
    }
    for (int i = 1; i <= m; i++) ans[atta[i]]++;
    for (int i = 0; i <= 8; i++) cout << ans[i] << " ";
}