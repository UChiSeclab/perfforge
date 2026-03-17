#include<bits/stdc++.h>

using namespace std;
using ll = long long;

class Combination2 {
    using T = unsigned long long;
    T MOD;
    vector<T> fact;
public :
    Combination2(int n, T MOD = 0)
    : MOD(MOD), fact(n+1) {
        fact[0] = 1;
        for(auto i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * i % MOD;
    }

    T pow_mod(long long x, long long y, long long mod) {
        auto ret=1ll;
        while (y) {
                if (y % 2)
                    ret = ret * x % mod;
                x =  x * x % mod;
                y /= 2;
            }
        return ret;
    }

    T nCr(int n, int r) {
        if(n < 0 || r > n || r < 0) return 0; // modified
        return fact[n] * pow_mod(fact[n-r], MOD - 2, MOD) % MOD * pow_mod(fact[r], MOD - 2, MOD) % MOD;
    }
};

constexpr int MOD = 1e9 + 7;
void solve(int TestCase) {
    ll n, l, r;
    cin >> n >> l >> r;

    Combination2 C(n, MOD);

    auto k = min(abs(l - 1), abs(r - n));
    ll ret = k * C.nCr(n, n / 2) % MOD;
    if(n % 2)
        ret = ret * 2 % MOD;

    while(true) {
        ++k;
        auto plus = max(1ll, l + k); //i - k < l [1, plus)
        auto minus = min(n, r - k); // i + k > r (minus, n]
        
        ll add = C.nCr(minus - plus + 1, n / 2 - (plus - 1));
        if(n % 2)
            add += C.nCr(minus - plus + 1, (n + 1) / 2 - (plus - 1));

        if(minus - plus + 1 < 0) break;

        ret = (ret + add) % MOD;
    }

    cout << ret << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}