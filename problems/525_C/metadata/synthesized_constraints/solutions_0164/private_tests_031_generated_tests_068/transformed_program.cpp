#include <bits/stdc++.h>
using namespace std;

long long n, i, temp, b[1000001], mx, ans, lel;
long long r[1000001];
pair<long long, long long> a[100001];

// Function to check performance bottlenecks due to high stick lengths
void check_max_length_invariant(long long mx) {
    if (mx >= 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to high stick length!" << endl;
        abort();
    }
}

// Function to check performance bottlenecks due to frequent adjustments on large arrays
void check_large_array_operations(long long n, long long max_length) {
    if (n > 10000 && max_length > 500000) {
        cerr << "Warning: Performance bottleneck condition triggered due to frequent adjustments on large arrays!" << endl;
        abort();
    }
}

// Function to check performance bottlenecks due to large vector operations
void check_large_vector_operations(const vector<long long>& kek) {
    if (kek.size() > 200000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large vector operations!" << endl;
        abort();
    }
}

// Function to check performance bottlenecks due to nested loop complexity
void check_nested_loop_complexity(long long n, long long max_length) {
    if (n > 10000 && max_length > 500000) {
        cerr << "Warning: Performance bottleneck condition triggered due to nested loop complexity!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> temp;
        b[temp]++;
        mx = max(temp, mx);
    }

    // Check for performance bottlenecks after reading inputs
    check_max_length_invariant(mx);
    check_large_array_operations(n, mx);

    for (i = mx; i >= 1; i--) {
        if ((b[i] + r[i]) % 2 == 1 && b[i]) {
            b[i]--, r[i - 1]++;
        }
    }

    vector<long long> kek;
    for (i = mx; i >= 1; i--) {
        b[i] = b[i] + r[i];
        for (int j = 0; j < b[i] - b[i] % 2; j++) kek.push_back(i);
    }

    // Check for performance bottlenecks before processing the kek vector
    check_large_vector_operations(kek);

    for (int i = 0; i < kek.size(); i += 4) {
        if (i + 3 < kek.size()) {
            ans += kek[i] * kek[i + 2];
        }
    }

    cout << ans << "\n";
    return 0;
}