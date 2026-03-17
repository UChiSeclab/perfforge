#include <iostream>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

#define int long long

typedef long long ll;

const ll MOD = 1e9 + 7;

ll binPow(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    if (sum % n != 0)
    {
        cout << 0;
        return 0;
    }
    sum /= n;
    vector<ll> fact(1e5 + 1);
    fact[0] = 1;
    for (ll i = 1; i <= 1e5; ++i) fact[i] = (fact[i - 1] * i) % MOD;
    int sources = 0, sinks = 0;
    for (int i : a)
    {
        if (i < sum) ++sinks;
        if (i > sum) ++sources;
    }
    ll res = 1;
    if (sinks <= 1 || sources <= 1)
    {
        res = fact[n];
        map<int, int> help;
        for (int i : a) ++help[i];
        for (auto i : help) res = (res * binPow(fact[i.second], MOD - 2)) % MOD;
    }
    else
    {
        res = (((((2 * fact[n]) % MOD) * binPow(fact[sources + sinks], MOD - 2)) % MOD) * binPow(fact[n - sources - sinks], MOD - 2)) % MOD;
        res = (res * fact[sources]) % MOD;
        res = (res * fact[sinks]) % MOD;
        map<int, int> help;
        for (int i : a) if (i != sum) ++help[i];
        for (auto i : help) res = (res * binPow(fact[i.second], MOD - 2)) % MOD;
    }
    cout << res;
    return 0;
}
