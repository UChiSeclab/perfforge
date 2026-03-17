#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int dp[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>v[i];
            mp[v[i]]++;
        }
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;){
            dp[v[i]]=mp[v[i]];
            for(int j=2*v[i];j<N;j+=v[i]){
                 dp[v[i]]=max(dp[j]+mp[v[i]],dp[v[i]]);
            }
            i=i-mp[v[i]];
        }
        int mx=0;
        for(int i=0;i<N;i++){
              mx=max(mx,dp[i]);
        }
        cout<<n-mx<<endl;
        for(int i=0;i<=v[n-1];i++){
            dp[i]=0;
        }
    }
    return 0;
}