#include <bits/stdc++.h>
using namespace std;

void check_small_a_values(const vector<pair<int, int>>& p) {
    int small_a_count = 0;
    for (const auto& pair : p) {
        if (pair.first <= 2) {  // Assume 'small' a_i values are <= 2
            small_a_count++;
        }
    }
    if (small_a_count > 50) {  // Arbitrary threshold, adjust as needed
        cerr << "Warning: Performance bottleneck condition triggered - many lights have small 'a' values!" << endl;
        abort();
    }
}

void check_synchronized_b_values(const vector<pair<int, int>>& p) {
    map<int, int> b_count;
    for (const auto& pair : p) {
        b_count[pair.second]++;
    }
    for (const auto& [b_value, count] : b_count) {
        if (count > 30) {  // Arbitrary threshold for synchronization
            cerr << "Warning: Performance bottleneck condition triggered - synchronized 'b' values!" << endl;
            abort();
        }
    }
}

void check_large_number_of_lights(int n) {
    if (n > 90) {  // Close to the upper constraint
        cerr << "Warning: Performance bottleneck condition triggered - high number of lights!" << endl;
        abort();
    }
}

void solve(int test_case) {
    int n;
    cin >> n;

    // Apply check for large number of lights
    check_large_number_of_lights(n);

    string s;
    cin >> s;
    int N = 1e3;
    vector<vector<int>> v(n, vector<int>(N, 0));
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;

    // Apply checks on input data
    check_small_a_values(p);
    check_synchronized_b_values(p);

    for (int i = 0; i < n; i++) {
        if (s[i] - '0') v[i][0] = 1;
        for (int j = 1; j < p[i].second; j++) v[i][j] = v[i][j - 1];
        int temp = v[i][0] ^ 1;
        for (int j = p[i].second; j < N; j += p[i].first) {
            for (int k = 0; j + k < N; k++) v[i][j + k] = temp;
            temp ^= 1;
        }
    }
    int ans = 0;
    for (int j = 0; j < N; j++) {
        int temp = 0;
        for (int i = 0; i < n; i++) temp += v[i][j];
        ans = max(ans, temp);
    }
    cout << ans;
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    for (int i = 0; i < t; i++) solve(i);
    return 0;
}