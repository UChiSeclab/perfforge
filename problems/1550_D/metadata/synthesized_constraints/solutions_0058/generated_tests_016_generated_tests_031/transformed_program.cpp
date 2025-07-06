#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxn = 2e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
const ll mod = 1e9 + 7;
ll fac[maxn];

ll mul(ll x , ll y){
    return x * y % mod;
}

ll add(ll x , ll y){
    x += y;
    if(x >= mod)x -= mod;
    return x;
}

ll sub(ll x , ll y){
    x -= y;
    if(x < 0)x += mod;
    return x;
}

ll qpow(ll x , ll n){
    ll ans = 1;
    while(n){
        if(n & 1)ans = mul(ans , x);
        x = mul(x , x);
        n /= 2;
    }
    return ans;
}

ll inverse(ll x){
    return qpow(x , mod - 2);
}

ll C(int n , int m){
    if(n < 0 || m < 0 || n < m)return 0;
    return mul(fac[n] , mul(inverse(fac[n - m]) , inverse(fac[m])));
}

void init(){
    fac[0] = 1;
    for(int i = 1; i < maxn; ++i)fac[i] = mul(fac[i - 1] , (ll)i);
}

// Checker functions for performance bottlenecks
void check_limit_invariant(int limit, int N) {
    if (limit > N / 10) { // Arbitrary threshold based on the analysis
        cerr << "Warning: Performance bottleneck condition triggered due to excessive loop iterations!" << endl;
        abort();
    }
}

void check_combinatorial_invariant(int len, int N, int pos_only) {
    if (len > N / 10) { // Arbitrary threshold for len
        cerr << "Warning: Performance bottleneck condition triggered due to large combinatorial calculations!" << endl;
        abort();
    }
}

void check_input_characteristics(int N, int L, int R) {
    if (N > 10000 && (R - L) > N * 10) { // Arbitrary threshold for extensive input range
        cerr << "Warning: Performance bottleneck condition triggered due to extensive input range!" << endl;
        abort();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int t;
    cin >> t;
    while(t--){
        int N , L , R;
        cin >> N >> L >> R;
        
        // Check for input characteristics before processing
        check_input_characteristics(N, L, R);
        
        ll ans = 0;
        int limit = min(R - N , 1 - L);

        // Check for limit invariant after computing limit
        check_limit_invariant(limit, N);

        if(limit >= 1){
            ans = add(ans , limit);
            if(N & 1){
                ans = mul(ans , add(C(N , N / 2) , C(N , N / 2 + 1)));
            }
            else{
                ans = mul(ans , C(N , N / 2));
            }
        }
        for(int i = 1;; ++i){
            int x = limit + i;
            int pos_only = max(1 , L + x);
            int neg_only = min(N , R - x);
            int len = neg_only - pos_only + 1;
            
            // Check for combinatorial invariant inside the loop
            check_combinatorial_invariant(len, N, pos_only);

            if(len < 0)break;
            if(N & 1){
                ans = add(ans , C(len , N / 2 - (pos_only - 1)));
                ans = add(ans , C(len , N / 2 - (pos_only - 1) + 1));
            }   
            else{
                ans = add(ans , C(len , N / 2 - (pos_only - 1)));
            }
        }
        cout << ans << endl;
    }
}