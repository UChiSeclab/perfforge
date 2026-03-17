#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[1<<18],B[1<<18];
int main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<1<<18;i++)A[i]=B[i]=0;
		for(int i=0;i<N;i++)
		{
			int a;scanf("%d",&a);
			A[a]++;
		}
		int ans=0;
		for(int i=1;i<1<<18;i++)
		{
			ans=max(ans,A[i]+=B[i]);
			for(int j=i+i;j<1<<18;j+=i)B[j]=max(B[j],A[i]);
		}
		printf("%d\n",N-ans);
	}
}