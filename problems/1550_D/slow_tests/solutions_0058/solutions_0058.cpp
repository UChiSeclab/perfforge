#pragma GCC optimize(3)
#pragma GCC optimize(2)
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
        ll ans = 0;
        int limit = min(R - N , 1 - L);
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
            // cout << "show case when x = " << x << endl;
            // for(int j = 1; j <= N; ++j){
            //     printf("for j = %d: " , j);
            //     if(x + j >= L && x + j <= R){
            //         printf("+x works ");
            //     }
            //     if(j - x >= L && j - x <= R){
            //         printf("-x works");
            //     }
            //     puts("");
            // }
            int pos_only = max(1 , L + x);
            int neg_only = min(N , R - x);
            int len = neg_only - pos_only + 1;
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
// F(a) = #(i < j , ai + aj = i + j)
// ai - i = -(aj - j)
// bi = -bj
// |b1| = |b2| = ... = |bN|
// #(bi = -|b|) to be close to #(bi = |b|)
// for even N , #(-) = #(+) = N / 2
// for even N , #(-) = N / 2 , #(+) = N - N / 2 , 
// or #(-) = N / 2 , #(+) = N - N / 2
// |bi| = x , say x + i in [L , R] and 
// ai - i = x , ai - i = -x
// 1 <= x <= min(R - i , i - L) = min(R - N , 1 - L)
// for all x in [1 , min(R - N , 1 - L)] , each element can be either +x or -x
// for x > min(R - N , 1 - L) , some are forced to be +x and some are forced to be -x
// we can see that (also from brute force) , i in [1 , L + x) are forced to be +x
// i in (R - x , N] are forced to be -x
// the things in the middle can be +x or -x
// we can iterate on these x until we get invalid intervals