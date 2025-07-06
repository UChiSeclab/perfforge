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

void check_exponentiation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to high exponentiation load!" << endl;
        abort();
    }
}

void check_factorial_calculation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive factorial calculation!" << endl;
        abort();
    }
}

void check_balance_complexity_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to complex balance characteristics!" << endl;
        abort();
    }
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
    
    // Check for potential factorial calculation bottleneck
    check_factorial_calculation_invariant(n > 50000); // Adjust threshold accordingly

    vector<ll> fact(1e5 + 1);
    fact[0] = 1;
    for (ll i = 1; i <= 1e5; ++i) fact[i] = (fact[i - 1] * i) % MOD;
    int sources = 0, sinks = 0;
    for (int i : a)
    {
        if (i < sum) ++sinks;
        if (i > sum) ++sources;
    }
    
    // Check for potential balance complexity bottleneck
    check_balance_complexity_invariant(sources > n / 2 && sinks > n / 2); // Adjust conditions to detect complex balances

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
    
    // Check for potential exponentiation bottleneck
    check_exponentiation_invariant(res > MOD); // A simple condition to illustrate checking during result calculation

    cout << res;
    return 0;
}