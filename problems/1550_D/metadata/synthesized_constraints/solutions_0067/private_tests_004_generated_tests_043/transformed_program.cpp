#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mlp make_pair
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vector<int> >
#define vvc vector<vector<char> >
#define ss second
#define ff first
#define ll long long
#define int ll
#define popcount(x) __builtin_popcountll(x)
#define pii pair<int , int>
#define vpi vector<pii>
#define arr array
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define EACH(x, a) for (auto& x: a)

template<class T> void selfmax(T& a, const T& b) {
    a = max(a , b);
}
template<class T> void selfmin(T& a, const T& b) {
    a = min(a , b);
}

// #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
)

template <typename T>inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)fprintf(stderr, __VA_ARGS__), fflush(stderr)
#endif

// Performance checkers based on inferred invariants
void check_modular_operations_invariant(long long a, long long b) {
    if (b > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive modular arithmetic operations!" << endl;
        abort();
    }
}

void check_loop_invariant(long long loop_range) {
    if (loop_range > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive loop iterations!" << endl;
        abort();
    }
}

void check_input_invariant(long long n, long long l, long long r) {
    if (r - l > n * 500) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive input range!" << endl;
        abort();
    }
}

template<class A> void read(vector<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A> void read(vector<pair<A , A > >& x) {
	EACH(a, x)
		read(a.ff , a.ss);
}

template<typename... T>
void read(vi &a ){
	int n = a.size();
	for (int i = 0 ; i < n ; i++)cin >> a[i];
}

template<class A>void print(vector<A>& a){
    EACH(x , a)cout << x << " ";
    cout << endl;
}

long long prod(long long a, long long b, long long m)
{
    check_modular_operations_invariant(a, b); // Check for excessive modular arithmetic operations
    long long res = 1;

    while(b)
    {
        if(b & 1)
            res = (res * a) % m;
        a = (a % m * a % m ) % m;

        b >>= 1;
    }

    return res;
}

long long power(long long a, long long b, long long m)
{
    long long res = 1;

    while(b)
    {
        if(b & 1)
            res = prod(res, a, m);
        a = prod(a, a, m);

        b >>= 1;
    }

    return res;
}

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1}; //4 Direction
// char dc[] = {'D' , 'R' , 'U' , 'L'};

// int dx[]={1,1,0,-1,-1,-1,0,1};
// int dy[]={0,1,1,1,0,-1,-1,-1};  // 8D

const int MOD = 1e9 + 7;
const int INF = 1000000000;
const int BIGINF = 1e12;

// Returns first i in [l, r] s.t. predicate(i) is true. Never evaluates r.
template <typename I, typename P> I binarysearch(const P &predicate, I l, I r) {
    l--;
    while (r - l > 1) {
        auto mid = l + (r - l) / 2;
        // debug(l , r , mid , predicate(mid) );
        if (predicate(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

ll fact[200009];

void pro()
{
    ll i;
    fact[0]=1;
    for(i=1;i<200009;i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
    }
}

ll ncr(ll n,ll r)
{
    if(n<r||n<0||r<0){return 0;}
    return (fact[n]*(prod(fact[r],MOD-2,MOD)%MOD*prod(fact[n-r],MOD-2,MOD)%MOD)%MOD)%MOD;
}

void solve(){
   ll n,l,r,x,r1,r2,ans=0,i;
   cin>>n>>l>>r;

   check_input_invariant(n, l, r); // Check for excessive input range

   ans=(ncr(n,n/2)*min(1-l,r-n))%MOD;
   if(n%2)
   {
       ans=(ans+ncr(n,(n+1)/2)*min(1-l,r-n))%MOD;
   }
   
   // Determine the loop range for the invariant check
   long long loop_range = min(1-l, r-n) + n + 5 - (min(1-l, r-n) + 1);
   check_loop_invariant(loop_range); // Check for excessive loop iterations

   for(i=min(1-l,r-n)+1;i<=min(1-l,r-n)+n+5;i++)
   {
       r1=max(0LL,l+i-1);
       r2=max(0LL,n+i-r);
       x=0;
       if(r1+r2>n||r1>(n+1)/2||r2>(n+1)/2){break;}
       if(n/2>=r1){x=ncr(n-r1-r2,n/2-r1);}
       if((n+1)/2>=r1){x=(x+ncr(n-r1-r2,(n+1)/2-r1))%MOD;}
       if(n%2==0){x=ncr(n-r1-r2,n/2-r1);}
       //cout<<r1<<" "<<r2<<" "<<i<<" "<<x<<"\n";
       ans=(ans%MOD+x%MOD)%MOD;
   }
   cout<<ans<<"\n";
}

int32_t main(){
    pro();
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;

    for (int tt = 0 ; tt < t ; tt++){
        solve();
    }
}