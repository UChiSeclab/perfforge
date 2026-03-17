#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define Max(x,y)((x)>(y)?x:y)
#define For(i,x,y)for(i=x;i<=(y);i++)
int a[N],f[N];
int read()
{
	int A;
	bool K;
	char C;
	C=A=K=0;
	while(C<'0'||C>'9')K|=C=='-',C=getchar();
	while(C>'/'&&C<':')A=(A<<3)+(A<<1)+(C^48),C=getchar();
	return(K?-A:A);
}
int main()
{
	int t,n,i,j;
	t=read();
	while(t--)
	{
		n=read();
		For(i,1,200000)a[i]=0;
		For(i,1,n)a[read()]++;
		For(i,0,200000)f[i]=a[i];
		For(i,1,200000)
		{
			For(j,2,200000/i)f[i*j]=Max(f[i*j],f[i]+a[i*j]);
			f[0]=Max(f[0],f[i]);
		}
		cout<<n-f[0]<<endl;
	}
	return 0;
}