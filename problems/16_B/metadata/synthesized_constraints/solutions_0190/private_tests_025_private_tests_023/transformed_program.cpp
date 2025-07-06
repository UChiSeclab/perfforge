#include <bits/stdc++.h>
using namespace std;

// Checker function for large n and container capacity
void check_large_n_and_container_capacity(int n, const vector<vector<int>>& x) {
    int total_boxes = 0;
    for (const auto& container : x) {
        total_boxes += container[1];
    }
    if (n > 1e8 && total_boxes > 1e8) { // Thresholds based on problem constraints
        cerr << "Warning: Performance bottleneck condition triggered!" << endl;
        abort();
    }
}

// Checker function for sorting efficiency
void check_sort_efficiency(const vector<vector<int>>& x) {
    if (!is_sorted(x.begin(), x.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0];
    })) {
        cerr << "Warning: Performance bottleneck due to inefficient container order!" << endl;
        abort();
    }
}

// Checker function for rucksack capacity constraint
void check_rucksack_capacity(int n, int m) {
    if (n > 1e8 && m > 10) { // Arbitrary threshold based on problem constraints
        cerr << "Warning: Performance bottleneck due to large rucksack capacity and container count!" << endl;
        abort();
    }
}

int main() {
    int n, m, k = 0, l = 0;
    vector<vector<int>> x;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int w, y;
        vector<int> tmp;
        cin >> w >> y;
        tmp.push_back(y);
        tmp.push_back(w);
        x.push_back(tmp);
    }
    
    // Check the performance-characterizing invariants after input
    check_large_n_and_container_capacity(n, x);
    check_rucksack_capacity(n, m);

    sort(x.begin(), x.end());
    
    // Check the sorting efficiency after sorting
    check_sort_efficiency(x);

    for (int i = m - 1; i >= 0; i--) {
        while (k < n && x[i][1] > 0) {
            k += 1;
            x[i][1] -= 1;
            l += x[i][0];
        }
    }
    cout << l;
}