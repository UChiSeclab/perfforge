#include<bits/stdc++.h>
#define ull unsigned long long
#define ll int64_t 
#define f(i,s,e) for(i=s;i<e;++i)
#define endl << "\n"
#define sp << " "
#define INF INFINITY
#define mset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI acos(-1) 
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define eb(a) emplace_back(a)
#define print(x) for(auto it:x) cout<<it<<' '; cout<<"\n";

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

int dfs(vector <vector<int>>&adj,vector<bool>&visited,vector<int>&count,int node)
{
	int i = 0;
	visited[node] = true;
	// cout << node  sp;
	for(auto v : adj[node])
	{
		if(visited[v])
			i = max(i,count[v]);
		else
			i = max(i,dfs(adj,visited,count,v));
	}
	count[node] += i ;
	return count[node];
}

int main()
{
	FAST_IO ;
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,k,n,m;
		cin >> n;
		vector<int>arr(n);
		set <int> s;
		m = 0;
		for(i=0;i<n;i++)
		{
			cin >> arr[i];
			s.insert(arr[i]);
			m = max(m,arr[i]);
		}
		if(n==1)
		{
			cout << "0\n";
			continue ;
		}
		vector<int>count(m+1,0);
		f(i,0,n)
			count[arr[i]]++;
		vector<vector <int>>adj(m+1);
		for(auto it = s.begin() ; it!=s.end() ;it++)
		{
			j = (*it);
			for(i=1;i*i<=j;i++)
			{
				if(j%i!=0)
					continue ;
				if(count[i] && (j!=i))
					adj[j].pb(i);
				k = j/i ;
				if(k!=i && i!=1 && count[k])
					adj[j].pb(k);
			}
		}
		vector<bool>visited(m+1,false);
		f(i,1,m+1)
		{
			if(visited[i])
				continue;
			dfs(adj,visited,count,i);
			// cout endl;
		}
		j = 0;
		f(i,1,m+1)
			j = max(j,count[i]);
		// print(count);
		cout << n - j endl;
	}
	return 0;
}

/*
If u haven't come up with an approach yet ,skip this one
  Try this when feeling stuck -
  1. Int overflow, array bounds
  2. Special cases (n=1?)
  3. Prove your approach to yourself(mathematical induction,counter-intuitive or stronger test cases)
  4. Calm down and don't look at standings and stop thinking about rating and think about the question
  5. Just do it! 
*/ 

//Benq's advice - 
/* 
	And following advices are must for me -
	* do something instead of nothing and stay organized
	* WRITE STUFF DOWN 
*/

//#define _GLIBCXX_DEBUG 
// It will convert WA verdict to runtime error if that error is caused due to out of bound excess , declare it at the top
//#pragma GCC optimize "trapv" 
// It will convert WA to runtime error if WA was caused due to int overflow error,declare it anywhere
