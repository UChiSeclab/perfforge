#include <bits/stdc++.h>
using namespace std;

// Performance checkers
void check_large_divisor_count(long long n) {
    if (n > 1000000) { // Threshold chosen to prevent excessive operations in large n cases
        cerr << "Warning: Performance bottleneck condition triggered - large divisor count due to high n!" << endl;
        abort();
    }
}

void check_large_vector_size(size_t vectorSize) {
    if (vectorSize > 10000) { // Threshold chosen based on potential vector size impact
        cerr << "Warning: Performance bottleneck condition triggered - large vector size!" << endl;
        abort();
    }
}

int main() {
    int test, tc = 0;
    long long m, n, ans, i, j, r, b, k, g;
    cin >> test;
    while (test--) {
        map<int, int> mp;
        vector<int> vt;
        vt.push_back(0);
        ans = 0;
        cin >> n;

        // Check for potential large divisor count
        check_large_divisor_count(n);

        for (i = sqrt(n + 1); i >= 1; i--) {
            j = n / i;
            if (mp[j] == 0) vt.push_back(j);
            mp[j] = 1;
            j = n / j;
            if (mp[j] == 0) vt.push_back(j);
            mp[j] = 1;
        }
        
        // Check for large vector size before sorting
        check_large_vector_size(vt.size());

        sort(vt.begin(), vt.end());
        n = vt.size();
        cout << n << endl << vt[0];
        for (i = 1; i < n; i++) {
            cout << " " << vt[i];
        }
        cout << endl;
    }
    return 0;
}