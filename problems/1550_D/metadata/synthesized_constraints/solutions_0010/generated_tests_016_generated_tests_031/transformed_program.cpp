#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int mod=1e9+7;
ll fac[maxn];

// Function to check combinatorial explosion
void check_combinatorial_explosion(int mx, int mi, int n) {
    if (mx - mi > n / 2) {
        cerr << "Warning: Combinatorial explosion detected - mx-mi exceeds half of n" << endl;
        abort();
    }
}

// Function to check large range handling
void check_large_range_handling(int mi, int n) {
    if (mi > n) {
        cerr << "Warning: Large range handling detected - mi exceeds n" << endl;
        abort();
    }
}

void exgcd(ll a,ll b,ll &x,ll &y)
{
    if (!b)x=1,y=0;
    else
    {
        exgcd(b,a%b,x,y);
        ll t=x;
        x=y;
        y=t-a/b*y;
    }
}

ll inv(ll a)
{
    ll x,y;
    exgcd(a,mod,x,y);
    return (x%mod+mod)%mod;
}

void init()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=fac[i-1]*i,fac[i]%=mod;
}

ll C(int n,int m)
{
    return ((fac[n]*inv(fac[n-m]))%mod*inv(fac[m]))%mod;
}

int main()
{
    int t,n,l,r;
    init();
    cin>>t;
    while(t--)
    {
        cin>>n>>l>>r;
        int mi=min(1-l,r-n);
        int mx=max(1-l,r-n);

        // Check for large range handling
        check_large_range_handling(mi, n);

        // Check for combinatorial explosion
        check_combinatorial_explosion(mx, mi, n);
        
        ll ans=C(n,n/2)*mi;
        ans%=mod;
        if(n&1) ans=(ans*2)%mod;
        for(int i=1;i<=min(mx-mi,n/2);i++)
        {
            ans+=C(n-i,n/2),ans%=mod;
            if(n&1) ans+=C(n-i,n/2+1),ans%=mod;
        }
        for(int i=mx-mi+1;i<=n/2;i++)
        {
            ans+=C(n-i*2+mx-mi,n/2-i+mx-mi),ans%=mod;
            if(n&1) ans+=C(n-i*2+mx-mi,n/2+1-i+mx-mi),ans%=mod;
        }
        if(n&1)
        {
            int top=n/2+mi;
            int v=min(r-top-n/2,n/2+1-top-l);
            ans=(ans+max(0,v))%mod;
            v=min(r-top-n/2-1,n/2+2-top-l);
            ans=(ans+max(v,0))%mod;
        }
        else
        {
            int top=n/2+mi;
            int v=min(r-top-n/2,n/2+1-top-l);
            ans=(ans+max(0,v))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;   
}