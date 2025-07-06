#include <bits/stdc++.h>
using namespace std;

// Checker for large n
void check_large_n_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large n leading to heavy loop iteration!" << endl;
        abort();
    }
}

// Checker for heavy increment operations in the loop
void check_heavy_increment_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated increments in loop!" << endl;
        abort();
    }
}

// Checker for potential large sorting overhead
void check_sort_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - sorting a large array!" << endl;
        abort();
    }
}

int main() {
    long long int n, i, j, k, x, y, m, t;
    cin >> n >> m;
    vector<long long int> vec;
    long long int sm = 0;
    
    check_large_n_invariant(n > 50000); // Check if n is large enough to potentially cause slowdowns
    
    for (i = 0; i < n; i++) {
        cin >> j;
        vec.push_back(j);
        sm += j;
    }
    
    check_sort_invariant(n > 50000); // Check if sorting a large array could be a bottleneck
    sort(vec.begin(), vec.end());
    
    if (vec.size() == 1) {
        printf("0\n");
        return 0;
    }
    
    long long int ans = 0;
    long long int curr = 0;
    
    for (i = 0; i < n; i++) {
        ans += 1;
        check_heavy_increment_invariant(vec[i] > curr); // Check if repeated increments occur
        if (vec[i] > curr) curr++;
    }
    
    ans += max((long long int)0, vec[n - 1] - curr);
    cout << sm - ans << endl;
}