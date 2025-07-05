#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;
int N = 1e5 + 10;

ll binpow(ll a, ll y)
{
   ll res = 1;
   while(y > 0)
   {
     if(y & 1) res = (res * a) % MOD;
     a = (a * a) % MOD;
     y /= 2;
   }
   return res;
}

// Function to check if the distribution of elements is too uneven
void check_distribution_invariant(const vector<ll>& a, ll s, ll n) {
    ll mean = s / n;
    ll min_count = 0, max_count = 0;
    for (ll i : a) {
        if (i < mean) min_count++;
        if (i > mean) max_count++;
    }
    if (min_count > n / 2 || max_count > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - uneven distribution of elements!" << endl;
        abort();
    }
}

// Function to check for expensive modular operations
void check_modular_operations_invariant(ll n, ll mn, ll mx) {
    if (mn > n / 2 || mx > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - expensive modular operations!" << endl;
        abort();
    }
}

// Function to check precomputation overhead
void check_precomputation_invariant(ll s, ll n) {
    if (s % n != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - unnecessary precomputation!" << endl;
        abort();
    }
}

int main()
{
   ll n; cin >> n;
   vll a(n);
   ll s = 0;
   for(int i = 0; i < n; i++){
     cin >> a[i];
     s += a[i];
   }
   
   check_precomputation_invariant(s, n); // Placed before factorial computation

   if(s % n > 0){
     cout << 0;
     return 0;
   }
   
   vll fact(N);
   fact[0] = 1;
   for(ll i = 1; i < N; i++)
   {
     fact[i] = (fact[i-1] * i) % MOD;
   }
   
   map < ll, ll > mp;
   ll mn = 0, sr = 0, mx = 0;
   
   for(int i = 0; i < n; i++)
   {
     if(a[i] < s / n) mn++;
     if(a[i] > s / n) mx++;
     if(a[i] == s / n) sr++;
     
     mp[a[i]]++;
   }
   
   check_distribution_invariant(a, s, n); // Placed after determining distribution
   check_modular_operations_invariant(n, mn, mx); // Placed after calculating mn and mx

   ll d = 1;
   for(auto u : mp)
   {
     d = (d * fact[u.second]) % MOD;
   }
   
   ll ans = (fact[mn] * fact[mx]) % MOD;
   
   if(mn <= 1 || mx <= 1)
   {
     ans = fact[n];
     ans = (ans * binpow(d, MOD - 2)) % MOD;
     cout << ans;
     return 0;
   }

   ll z = (fact[sr] * fact[n - sr]) % MOD;
   ll C = (fact[n] * binpow(z, MOD - 2)) % MOD;
   
   ans = (ans * C) % MOD;
   ans = (ans * fact[sr]) % MOD;
   ans = (ans * binpow(d, MOD - 2)) % MOD;
   ans = (ans * 2) % MOD;
   
   cout << ans;
}