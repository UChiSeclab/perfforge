#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef vector<LL> 		VL;
#define si(n) cin>>n
#define dout(n) cout<<n<<"\n"
#define DRT() int t; si(t); while(t--)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//# define M_PI           3.14159265358979323846264338327950288
// DSU

void IO(){
	#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	off;
}
const int N = 2e5 + 10;
LL score[N];
int main(){
	IO();
	DRT(){
		memset(score, 0, sizeof(score));
		LL n;cin>>n;
		VL arr(n);
		rep(i,0,n){
			cin>>arr[i];
		}
		sort(ALL(arr), greater<LL> ());
		LL ans = 0;
		rep(i,0,n){
			LL mm = 0;
			LL can = 1;
			if(i-1 >= 0 && arr[i] == arr[i-1])
				can = 0;
			if(can)
			for(LL j=arr[i]; j < N; j+= arr[i]){
				mm = max(mm, score[j]);
			}
			score[arr[i]] = max(score[arr[i]], mm);
			score[arr[i]]++;
			ans = max(ans, score[arr[i]]);
		}
		dout(n - ans);
	}
	return 0;
}