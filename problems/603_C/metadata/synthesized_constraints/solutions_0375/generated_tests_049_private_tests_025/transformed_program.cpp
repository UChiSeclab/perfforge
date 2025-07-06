#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
int T = 1, used[100100];
int dp[100100];
int k;

// Checker functions for performance-characterizing invariants
void check_deep_recursion_invariant(int x, int k) {
    if (x > 100000 && k % 2 == 1 && x % 2 == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - deep recursion with large even numbers!" << endl;
        abort();
    }
}

void check_grundy_number_invariant(int x) {
    if (x > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - high Grundy number calculation!" << endl;
        abort();
    }
}

void check_recursive_division_invariant(int x) {
    int divisions = 0;
    while (x % 2 == 0) {
        x /= 2;
        divisions++;
    }
    if (divisions > 10) {
        cerr << "Warning: Performance bottleneck condition triggered - recursive division and recombination!" << endl;
        abort();
    }
}

int mex(vector<int> &v) {
    T++;
    for (int i = 0; i < (int)v.size(); i++) used[v[i]] = T;
    for (int i = 0;; i++) {
        if (used[i] != T) return i;
    }
}

int calc(int n) {
    if (n == 0) return 0;
    int &res = dp[n];
    if (res != -1) return res;
    vector<int> v;
    v.push_back(calc(n - 1));
    if (n % 2 == 0) {
        if (k % 2) {
            v.push_back(calc(n / 2));
        } else {
            v.push_back(0);
        }
    }
    return res = mex(v);
}

int main() {
    memset(dp, -1, sizeof dp);
    int ans = 0;
    int n, x;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        // Insert checker functions at appropriate points
        check_deep_recursion_invariant(x, k);
        check_grundy_number_invariant(x);
        check_recursive_division_invariant(x);

        if (x < 100100)
            ans ^= calc(x);
        else {
            if (k % 2 == 1) {
                if (x % 2 == 0) {
                    int t = 0;
                    while (x % 2 == 0) {
                        x /= 2;
                        t++;
                    }
                    if (t % 2 == 0)
                        ans ^= 2;
                    else
                        ans ^= 1;
                }
            } else {
                ans ^= (x % 2 == 0);
            }
        }
    }
    if (ans)
        cout << "Kevin" << endl;
    else
        cout << "Nicky" << endl;
    return 0;
}