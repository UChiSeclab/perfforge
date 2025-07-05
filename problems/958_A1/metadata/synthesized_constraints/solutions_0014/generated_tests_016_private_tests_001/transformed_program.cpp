#include <bits/stdc++.h>
using namespace std;

// Checkers
void check_transform_repetition(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive transformation checks!" << endl;
        abort();
    }
}

void check_transformation_complexity(bool condition) {
    if (condition) {
        cerr << "Warning: Transformation complexity triggered - excessive nested operations!" << endl;
        abort();
    }
}

// Transformation and solution functions remain unchanged
pair<long long, long long> vflip(long long i, long long j, long long n) {
    return {i, n - j - 1};
}

pair<long long, long long> hflip(long long i, long long j, long long n) {
    return {n - i - 1, j};
}

pair<long long, long long> rot90(long long i, long long j, long long n) {
    return {n - j - 1, i};
}

pair<long long, long long> rot180(long long i, long long j, long long n) {
    return {n - i - 1, n - j - 1};
}

pair<long long, long long> rot270(long long i, long long j, long long n) {
    return {j, n - i - 1};
}

pair<long long, long long> transform(long long i, long long j, long long x, long long n) {
    pair<long long, long long> coord = {i, j};
    long long p = 5;
    pair<long long, long long> (*fn[])(long long, long long, long long) = {vflip, hflip, rot90, rot180, rot270};

    int transform_calls = 0; // Track number of calls
    while (p--) {
        if (x & 1) coord = fn[p](coord.first, coord.second, n);
        x >>= 1;
        transform_calls++;
    }

    // Check excessive number of transformations
    check_transform_repetition(transform_calls > 5); // Arbitrary threshold to trigger warning

    return coord;
}

void solve() {
    long long n;
    cin >> n;
    
    string m1[n], m2[n];
    for (auto &second : m1) cin >> second;
    for (auto &second : m2) cin >> second;

    bool yes;
    long long x = 125;

    // Check complexity of transformations on full iteration
    check_transformation_complexity(x > 100); // Check if too many iterations are needed

    while (x--) {
        yes = true;
        for (long long i = 0; i < n; ++i)
            for (long long j = 0; j < n; ++j) {
                pair<long long, long long> pt = transform(i, j, x, n);
                if (m1[i][j] != m2[pt.first][pt.second]) {
                    yes = false;
                    break;
                }
            }
        if (yes) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));
    int T = 1, t = 1;
    while (T--) {
        solve();
        cout << "\n";
    }
    return 0;
}