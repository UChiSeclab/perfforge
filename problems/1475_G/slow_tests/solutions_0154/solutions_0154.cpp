#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 2 * 1e5 + 5;
int dp[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
				
		fill(dp, dp+maxN, 0);
		
		for(int x=0;x<n;x++){
			dp[data[x]]++;
		}
		
		int ans = 0;
		for(int x=1;x<=200000;x++){
			int best = dp[x];
			for(int y=1;y*y<=x;y++){
				if(x % y == 0){
					if(x/y != x) best = max(best, dp[x] + dp[x/y]);
					if(x/y != y){
						best = max(best, dp[x] + dp[y]);
					}
				}
			}
			dp[x] = best;
			ans = max(ans, dp[x]);
		}
		
		cout << n-ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

