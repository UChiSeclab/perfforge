#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_input_sizes(long long int n, long long int m) {
    if (n > 80000 || m > 80000) {
        cerr << "Warning: large_input_sizes invariant triggered - n or m is too large!" << endl;
        abort();
    }
}

void check_map_update_frequency(const map<long long int, long long int>& fre) {
    if (fre.size() > 50000) {
        cerr << "Warning: map_update_frequency invariant triggered - too many unique sensor positions!" << endl;
        abort();
    }
}

void check_iteration_count(long long int n, long long int m) {
    if (n * m > 500000000) {
        cerr << "Warning: iteration_count invariant triggered - potential excessive iterations!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int n, y1;
    cin >> n >> y1;
    map<long long int, long long int> fre;
    vector<long long int> arr1(n);
    for (long long int i = 0; i < n; i++) {
        cin >> arr1[i];
        fre[arr1[i]]++;
    }

    long long int m, y2;
    cin >> m >> y2;
    vector<long long int> arr2(m);
    for (long long int i = 0; i < m; i++) {
        cin >> arr2[i];
        fre[arr2[i]]++;
    }

    // Insert checks after reading inputs
    check_large_input_sizes(n, m);  // Check for large input sizes
    check_map_update_frequency(fre);  // Check for high frequency of map updates
    check_iteration_count(n, m);  // Check for excessive iterations

    long long int ans = 0;
    for (auto x : fre) {
        ans = max(ans, x.second);
    }

    for (long long int i = 0; i < 32; i++) {
        long long int val = ((long long int)1 << i);
        val *= 2;
        map<long long int, long long int> m1;
        for (long long int i = 0; i < n; i++) {
            m1[arr1[i] % val]++;
        }
        for (long long int i = 0; i < m; i++) {
            m1[(arr2[i] + val / 2) % val]++;
        }
        for (auto x : m1) {
            ans = max(ans, x.second);
        }
        m1.clear();

        for (long long int i = 0; i < m; i++) {
            m1[arr2[i] % val]++;
        }
        for (long long int i = 0; i < n; i++) {
            m1[(arr1[i] + val / 2) % val]++;
        }
        for (auto x : m1) {
            ans = max(ans, x.second);
        }
    }

    cout << ans << "\n";
}