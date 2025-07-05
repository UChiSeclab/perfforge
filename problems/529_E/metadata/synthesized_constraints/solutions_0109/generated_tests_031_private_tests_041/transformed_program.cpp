#include <bits/stdc++.h>
const long long OO = 1000000007;
const long long MAXN = 100005;
using namespace std;

// Checker function for large amounts with small denominations
void check_large_amount_with_small_denominations(int min_denomination, int requested_amount) {
    if (requested_amount > 10000000 && min_denomination == 1) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - large amount with small denomination!" << endl;
        abort();
    }
}

// Checker function for limits on bill counts and queries
void check_limits_on_bill_counts(int k, int q) {
    if (q > 15 && k > 15) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - high number of bills and queries!" << endl;
        abort();
    }
}

int n, k, q;
int a[5005];
vector<int> res;
map<int, bool> in;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        in[a[i]] = true;
    }
    
    // Insert the invariant check after reading denominations
    check_limits_on_bill_counts(k, q);
    
    cin >> q;
    
    for (long long z = 0; z < q; ++z) {
        int x;
        int mn = k + 1;
        cin >> x;
        
        // Insert the invariant check for each requested amount
        check_large_amount_with_small_denominations(a[0], x);
        
        for (int i = k; i > 0; --i) {
            for (int j = i; j > 0; --j) {
                for (int t = 0; t < n; ++t) {
                    if (((x - a[t] * j == 0) && i == j) ||
                        (i != j && (x - a[t] * j > 0) &&
                        ((x - a[t] * j) % (i - j) == 0) &&
                        in[(x - a[t] * j) / (i - j)])) {
                        mn = i;
                        break;
                    }
                }
            }
        }
        
        if (mn == k + 1)
            res.push_back(-1);
        else
            res.push_back(mn);
    }
    
    for (int i = 0; i < q; ++i) 
        cout << res[i] << endl;
    
    return 0;
}