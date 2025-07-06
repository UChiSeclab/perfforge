#include <bits/stdc++.h>
using namespace std;

// Checker functions based on inferred performance-characterizing invariants
void check_close_to_target(int n, int m) {
    if (n < m && (m - n) <= 5) { // Arbitrary small threshold for checking closeness
        cerr << "Warning: Performance bottleneck condition triggered - n is very close to m" << endl;
        abort();
    }
}

void check_not_power_of_two(int n, int m) {
    if (n < m && (n * 2) > m) {
        cerr << "Warning: Performance bottleneck condition triggered - n is not a suitable power of two for m" << endl;
        abort();
    }
}

void check_redundant_operations(int current, int target) {
    if (current == target - 1) { // If one step away from target
        cerr << "Warning: Performance bottleneck condition triggered - redundant operations when close to target" << endl;
        abort();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // Apply the performance checks
    check_close_to_target(n, m);
    check_not_power_of_two(n, m);
    
    queue<int> q;
    q.push(n);
    map<int, int> mp;
    mp[n] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        
        // Check for redundant operations
        check_redundant_operations(cur, m);
        
        if (cur == m) break;
        if (cur != 1 && mp[cur - 1] == 0)
            q.push(cur - 1), mp[cur - 1] = mp[cur] + 1;
        if (mp[cur * 2] == 0 && cur <= m)
            q.push(cur * 2), mp[cur * 2] = mp[cur] + 1;
    }
    cout << mp[m] - 1;
    return 0;
}