#include <bits/stdc++.h>

#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> a3;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N=2*1e5+5;



void solve()
{
	int n;cin>>n;

    vi f(N, 0);
    int m=0;
    for (int i=0;i<n;i++)
    {
        int x;cin>>x;
        f[x]++;
        m=max(m, x);
    }

    int maxlen=0;
    for (int i=m;i;i--)
    {
        int x=f[i];
        for (int j=2;i*j<=m;j++) f[i]=max(f[i], f[i*j]+x);
        maxlen=max(maxlen, f[i]);
    }
    cout<<n-maxlen<<"\n";
}

int main()
{
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;cin>>t;
    while (t--) solve();

	return 0;
}
