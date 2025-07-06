#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdlib>
#define N 200010
#define M 1000000007
#define sup 0x3f3f3f3f
#define inf -0x3f3f3f3f
#define ll long long
using namespace std;

ll n,m,cntm,cnta,tot_mi,tot_ma,f[N],ans,ax,sum,mi[N],ma[N],num_mi[N],num_ma[N],maxid_mi,minid_ma,num_l;
struct Point{
    ll id,a;
    bool operator <(const Point &rhs)const{
        return a<rhs.a;
    }
}s[N];

inline int read(){
    int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}

void init(){
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=(f[i-1]*i)%M;
    }
    return;
}

ll pow(ll x,ll y){
    ll c=1;
    while(y){
        if(y&1)c=(c*x)%M;
        x=(x*x)%M;
        y>>=1;
    }
    return c;
}

bool check(){
    if(sum%n)return 0;
    sort(s+1,s+1+n);

    // Check sorting dependency
    check_sort_invariant(n > 10000); // Example threshold for large array sorting

    ax=sum/n;
    for(int i=0;i<N;i++){
        mi[i]=inf;
        ma[i]=inf;
    }

    // Check large data initialization
    check_initialization_invariant(n > 50000); // Example threshold for large data initialization

    for(int i=1;i<=n;i++){
        if(s[i].a<ax){
            maxid_mi=max(maxid_mi,s[i].id);
            if(s[i].a==mi[cntm]){
                num_mi[cntm]++;
            }    
            else{
                mi[++cntm]=s[i].a;
                num_mi[cntm]=1;
            }
        }
        else if(s[i].a>ax){
            minid_ma=min(minid_ma,s[i].id);
            if(s[i].a==ma[cnta]){
                num_ma[cnta]++;
            }
            else {
                ma[++cnta]=s[i].a;
                num_ma[cnta]=1;
            }
        }
        else{
            num_l++;
        }
    }

    // Check computation through large loops
    check_large_loop_invariant(cnta > 1000 || cntm > 1000); // Example threshold for loop complexity

    for(int i=1;i<=cnta;i++){
        tot_ma+=num_ma[i];
    }
    for(int i=1;i<=cntm;i++){
        tot_mi+=num_mi[i];
    }
    if(tot_mi<=1 || tot_ma<=1)return true;
    return true;
}

int main(){
    n=read();
    init();
    for(int i=1;i<=n;i++){
        s[i].a=read();
        s[i].id=i;
        sum+=s[i].a;
    }

    // Check conditional path execution
    check_conditional_path_invariant(sum > 1000000000); // Example threshold for complex input condition

    if( !check() ){
        printf("0\n");
        return 0;
    }
    else{
        if(tot_mi<=1 || tot_ma<=1){
            ans=1;
            for(int i=1;i<=cnta;i++){
                ans=ans*pow(f[num_ma[i]],M-2)%M;
            }
            for(int i=1;i<=cntm;i++){
                ans=ans*pow(f[num_mi[i]],M-2)%M;
            }
            ans=(ans*f[n])%M*pow(f[num_l],M-2)%M;
        }
        else{
            ans=2;
            ans=(ans*f[tot_mi]%M*f[tot_ma])%M;
            for(int i=1;i<=cnta;i++){
                ans=ans*pow(f[num_ma[i]],M-2)%M;
            }
            for(int i=1;i<=cntm;i++){
                ans=ans*pow(f[num_mi[i]],M-2)%M;
            }
            ans=ans*f[n]%M*pow(f[tot_ma+tot_mi],M-2)%M*pow(f[n-tot_ma-tot_mi],M-2)%M;
        }
        printf("%lld\n",ans);
    }
    return 0;
}