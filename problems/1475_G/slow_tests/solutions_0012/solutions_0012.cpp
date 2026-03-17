#include<bits/stdc++.h>
using namespace std;
#define joker ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define z 1000000007
#define sh 200000
#define pb push_back

#define fi first
#define se second
#define pr(x) printf("%d ", x)
#define sc(x) scanf("%d",&x)
#define mxf INT_MAX
#define mnf INT_MIN
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpi;
typedef map<int,pi> mpii;
void why_so_serious(){
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif 
}



bool cmp(ll a,ll b)
{
	return a>b;
}

// ll f[sh+1];
// ll me(ll x,ll n)
// {
//     ll res=1;
//     while(n>0)
//     {
//         if(n&1)
//             res=(res*x)%z;
//         x=(x*x)%z;
//         n/=2;
//     }
//     return res;
// }
 

// ll mi(ll x)
// {
//     return me(x,z-2);
// }
// void fact(){
//     f[0]=1;
//     for(ll i=1;i<=sh;i++)
//         f[i]=(f[i-1]*i)%z;
// }
// ll ncr(ll n,ll r)
// {
// 	if(n<r)
// 		return 0LL;
//     ll res=f[n];
//     ll tmp=(f[n-r]*f[r])%z;
//     tmp=mi(tmp);
//     res=(res*tmp)%z;
//     return res;
// }
int main()
{
	why_so_serious();
	joker
	// fact();
	int t;
	cin>>t;
	while(t--){
		int n,i;
		cin>>n;
		int ar[n];
		int dp[sh+2];
		memset(dp,0,sizeof(dp));
		map<int,int> mp;
		for(i=0;i<n;i++){
			cin>>ar[i];
			dp[ar[i]]++;
			mp[ar[i]]++;
		}

		sort(ar,ar+n);
		// for(auto it: mp)
		// 	cout<<it.first<<' '<<it.second<<endl;
		
		int ans=0;
		for(auto it=mp.rbegin();it!=mp.rend();it++){
			int val=it->first;
			// cout<<val<<endl;
			int num=val;
			while(num<=sh){
				num+=val;
				if(num<=sh)
				dp[val]=max(dp[val],dp[num]+mp[val]);

			}
			
		}
		for(i=1;i<=sh;i++)
			ans=max(ans,dp[i]);
		cout<<n-ans<<endl;
	}
}

