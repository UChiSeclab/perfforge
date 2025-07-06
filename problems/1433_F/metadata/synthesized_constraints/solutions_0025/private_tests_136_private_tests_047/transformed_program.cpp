#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const long long INF = 5e18;
const double pi = acos(-1.0);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void check_array_initialization_invariant(int iterations) {
    if (iterations > 200000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive array initialization iterations!" << endl;
        abort();
    }
}

void check_recursion_invariant(int depth, int branches) {
    if (depth > 70 && branches > 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth and branching!" << endl;
        abort();
    }
}

void check_matrix_size_invariant(int n, int m) {
    if (n * m > 4900) {
        cerr << "Warning: Performance bottleneck condition triggered - large matrix size!" << endl;
        abort();
    }
}

void check_modulo_operation_invariant(int k) {
    if (k < 2) {
        cerr << "Warning: Performance bottleneck condition triggered - trivial modulo operation!" << endl;
        abort();
    }
}

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
inline long long mod(long long n, long long m) {
    long long ret = n % m;
    if (ret < 0) ret += m;
    return ret;
}

vector<int> calc(vector<int> &vet, int n) {
    int v[200000];
    for (int i = 0; i < 200000; i++) {
        v[i] = INF;
    }
    v[0] = 0;
    for (int &i : vet) {
        for (int j = 199999; j - i >= 0; j--) {
            if (v[j - i] != INF) {
                v[j] = min(v[j - i] + 1, v[j]);
            }
        }
    }
    
    // Check for excessive iterations in the calc function
    int iterations = 200000 * vet.size();
    check_array_initialization_invariant(iterations);

    vector<int> ans;
    for (int i = 0; i < 200000; i++) {
        if (v[i] <= n) {
            ans.push_back(i);
        }
    }
    return ans;
}

int memo[75][200200];
int n, m, k;
vector<vector<int>> adj;

int dp(int pos, int sum) {
    if (pos == n) {
        if (sum % k == 0)
            return sum;
        else
            return -INF;
    }
    int &x = memo[pos][sum];
    if (x != -1) return x;
    if (sum % k == 0) {
        x = sum;
    } else {
        x = -INF;
    }

    // Check for high recursion depth and branching
    check_recursion_invariant(pos, adj[pos].size());

    for (int &i : adj[pos]) {
        x = max(x, dp(pos + 1, sum + i));
    }
    return x;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    cin >> n >> m >> k;

    // Check for potentially large matrix operations
    check_matrix_size_invariant(n, m);

    vector<int> vet(m);
    vector<int> ans;
    adj.clear();
    for (int i = 0; i < n; i++) {
        for (int &j : vet) {
            cin >> j;
        }
        ans = calc(vet, m / 2);
        vector<int> newans;
        map<int, int> mapa;
        for (int &i : ans) {
            mapa[i % k] = max(i, mapa[i % k]);
        }
        for (auto &i : mapa) {
            newans.push_back(i.second);
        }
        ans = newans;
        adj.push_back(ans);
    }

    // Check for trivial modulo operation
    check_modulo_operation_invariant(k);

    cout << dp(0, 0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while (t--) {
        solve();
    }
}