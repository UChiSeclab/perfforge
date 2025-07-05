#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
constexpr auto MOD = 1000000007LL;
constexpr auto LINF = (1LL << 60);
constexpr auto INF = 2147483647LL;
constexpr auto PI = 3.1415926535897932384626433;
constexpr auto EPS = 1E-9;

void check_excessive_transformation_invariant(int transformations) {
    if (transformations > 64) { // Exhaustive check limit
        cerr << "Warning: Performance bottleneck condition triggered - excessive transformations!" << endl;
        abort();
    }
}

void check_pattern_complexity_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - complex pattern!" << endl;
        abort();
    }
}

void check_matrix_size_invariant(int n) {
    if (n > 10) { // Given constraint
        cerr << "Warning: Performance bottleneck condition triggered - large matrix size!" << endl;
        abort();
    }
}

template <typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1, T2> p) {
    out << p.first << ' ' << p.second;
    return out;
}

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
    in >> p.first >> p.second;
    return in;
}

auto printVector = []<typename T>(ostream& out, vector<T> v) {
    copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
};

int n, vis[4][2][2];
vvi to, v;

vvi rotate(vvi v) {
    vvi ret(n, vi(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) ret[n - 1 - j][i] = v[i][j];
    return ret;
}

vvi vflip(vvi v) {
    vvi ret(n, vi(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) ret[i][n - 1 - j] = v[i][j];
    return ret;
}

vvi hflip(vvi v) {
    vvi ret(n, vi(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) ret[n - 1 - i][j] = v[i][j];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    
    // Insert matrix size invariant check
    check_matrix_size_invariant(n);
    
    to = v = vvi(n, vi(n, 0));
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) v[i][j] = str[j] == 'O';
    }
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) to[i][j] = str[j] == 'O';
    }

    int transformation_attempts = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int r1 = 0; r1 < 4; r1++) {
                    for (int r2 = 0; r2 < 4; r2++) {
                        auto now = v;
                        for (int ii = 0; ii < i; ii++) v = rotate(v);
                        if (j) v = vflip(v);
                        for (int ii = 0; ii < r1; ii++) v = rotate(v);
                        if (k) v = hflip(v);
                        for (int ii = 0; ii < r2; ii++) v = rotate(v);
                        
                        // Count each transformation attempt
                        transformation_attempts++;

                        if (v == to) {
                            cout << "YES" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    // Check excessive transformation attempts
    check_excessive_transformation_invariant(transformation_attempts);
    
    cout << "NO" << endl;
    return 0;
}