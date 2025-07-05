#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <iterator>
#include <string.h>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <fstream>
#include <assert.h>

using namespace std;

long long MOD = 1e9 + 7;
long long fac[200500];

long long mult(long long a, long long b)
{
    return (a * b) % MOD;
}

long long add(long long a, long long b)
{
    return (a + b) % MOD;
}

long long sub(long long a, long long b)
{
    return (a - b + MOD) % MOD;
}

long long binpow(long long a, long long n)
{
    // Check for recursive power calculation bottleneck
    check_binpow_invariant(n);

    if (n == 0)
        return  1;
    if (n % 2)
        return mult(a, binpow(a, n - 1));
    long long b = binpow(a, n / 2);
    return mult(b, b);
}

long long inv(long long x)
{
    return binpow(x, MOD - 2);
}

void prec()
{
    fac[0] = 1;
    for (size_t i = 1; i < 200400; i++)
    {
        fac[i] = mult(fac[i - 1], i);
    }
}

long long C(int n, int k)
{
    return mult(fac[n], inv(mult(fac[k], fac[n - k])));
}

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    long long ans = 0;
    long long f = C(n, n / 2);
    if(n&1)
        f = mult(f, 2);
    int g = min(1-l, r - n);
    int lx = 1 - g, rx = n + g;
    int cnt1 = 0, cnt2 = 0;
    ans += mult(f, g);

    // Check for extensive loop iterations
    check_diff_invariant(g, n);

    for (long long diff = g + 1; ; diff++)
    {
        long long ma = n + diff;
        long long mi = 1 - diff;
        long long badl = max(0ll, diff - (1-l));
        long long badr = max(0ll, diff - (r-n));
        int h = n - badl - badr;

        // Check for combinatorial explosion
        check_combinatorial_invariant(h);

        if (n%2==0 && (badr > n / 2 || badl > n / 2))
            break;
        if (n & 1 && (badr > n / 2 || badl > n / 2))
        {
            if (badr == badl)
                break;
            badr = max(badr, badl);
            if (badr - 1 != n / 2)
                break;
        }
        if (h < 0)
            break;
        else
        {
            if (n % 2 == 0)
            {
                int q = n / 2;
                q -= badr;
                ans = add(ans, C(h, q));
            }
            else
            {
                int q = n / 2;
                q -= badr;
                ans = add(ans, C(h, q));
                ans = add(ans, C(h, q+1));
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    prec();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}