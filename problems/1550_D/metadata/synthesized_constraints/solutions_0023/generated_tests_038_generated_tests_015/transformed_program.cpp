#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=vector<ll>;
#define rep(i,N) for(i=0;i<(ll)N;++i)
constexpr ll mod=1000000007;

void check_set_invariant(const set<ll>& se, ll N) {
    if (se.size() > 1.5 * N) { // Arbitrary threshold; se shouldn't grow too large
        cerr << "Warning: set_invariant triggered - large number of elements in set" << endl;
        abort();
    }
}

void check_loop_invariant(const set<ll>& se, ll N) {
    if (se.size() > 1.5 * N) { // Again, a threshold that triggers when set operations may slow down
        cerr << "Warning: loop_invariant triggered - excessive element processing in loop" << endl;
        abort();
    }
}

void check_combination_invariant(ll callCount, ll threshold) {
    if (callCount > threshold) { // Threshold on combination function calls
        cerr << "Warning: combination_invariant triggered - excessive combination calculations" << endl;
        abort();
    }
}

void check_range_invariant(ll l, ll r, ll N) {
    if ((r - l) > 2 * N) { // Threshold on allowable range size
        cerr << "Warning: range_invariant triggered - excessive range size" << endl;
        abort();
    }
}

ll modinv(ll a,const ll m=mod) noexcept{
  ll b=m,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+m)%m;
}

ll modncr(const ll n,const ll r) noexcept{
  if(n<r||r<0)return 0;
  static vec modncrlistp={1},modncrlistm={1};
  ll i,size=modncrlistp.size();
  if(size<=n){
    modncrlistp.resize(n+1);
    modncrlistm.resize(n+1);
    if(!size){
      modncrlistp[0]=modncrlistm[0]=1;
      size++;
    }
    for(i=size;i<=n;i++) modncrlistp[i]=modncrlistp[i-1]*i%mod;
    modncrlistm[n]=modinv(modncrlistp[n]);
    for(i=n;i>size;--i) modncrlistm[i-1]=modncrlistm[i]*i%mod;
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int codeforces;
  cin>>codeforces;
  while(codeforces--){
    ll i, N, A, B;
    cin>>N>>A>>B;
    
    // Check range invariant
    check_range_invariant(A, B, N);

    ll ans=min(B-N-1,-A)*modncr(N,N/2);
    if(ans<0)ans=0;
    if(N&1)ans+=ans;
    ans%=mod;

    set<ll> se;
    rep(i,N) se.emplace(-(A-i-1));
    rep(i,N) se.emplace(B-i-1);

    // Check set invariant
    check_set_invariant(se, N);

    if(*se.begin()==0) se.erase(se.begin());

    // Check loop invariant
    check_loop_invariant(se, N);

    ll combinationCallCount = 0; // For tracking combination calls
    for(auto i:se){
      ll a=min(-i-A+N+1,N),b=min(B-i,N);
      if(a<=0||b<=0||a+b<N) continue;
      ll c=min(b,N-a),d=min(a,N-b);
      ll m=N-c-d;
      if(m<0) continue;

      // Increase combination call count
      combinationCallCount++;

      ans+=modncr(m,N/2-c);
      if(N&1) ans+=modncr(m,N/2+1-c);
    }

    // Check combination invariant
    check_combination_invariant(combinationCallCount, 10 * N); // Example threshold

    cout << ans % mod << endl;
  }
  return 0;
}