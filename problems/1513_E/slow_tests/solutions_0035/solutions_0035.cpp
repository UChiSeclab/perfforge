#include <bits/stdc++.h>
using namespace std;

#define fast_io {ios::sync_with_stdio(0); cin.tie(0);}
#define all(v)  v.begin(),v.end()
#define pb push_back
#define pf push_front
#define bs binary_search
#define popb pop_back
#define F first
#define S second
#define ccc cout<<1<<" ";
#define prin(v) {forn(i,v.size()) cout<<v[i]<<" "; cout<<endl;}
#define forn(i,n) for(int i=0;i<(n);i++)
#define len() length()

typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<bool> vbool;
typedef vector<double> vdouble;
typedef pair<double,double> pdd;
typedef pair<bool,bool> pbb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = INT_MAX;
const ll MOD =  1e9+7;
const ll MOD_2 = 998244353;
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

int main()
{
   ll n; cin >> n;
   vll a(n);
   ll s = 0;
   forn(i,n){
     cin >> a[i];
     s += a[i];
   }
   
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
   
   forn(i,n)
   {
     if(a[i] < s / n) mn++;
     if(a[i] > s / n) mx++;
     if(a[i] == s / n) sr++;
     
     mp[a[i]]++;
   }
   
   ll d = 1;
   for(auto u : mp)
   {
     d = (d * fact[u.S]) % MOD;
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
