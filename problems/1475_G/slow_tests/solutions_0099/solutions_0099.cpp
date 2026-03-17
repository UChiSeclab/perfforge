#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <bitset>
#include <queue>
#include <map>
#include <random>
#include <queue>
#include <assert.h>

using namespace std;

#define ll long long
#define endl '\n'
#define cint(a) int a; cin >> a;

const int N = 2e5 + 1;

int a[N];
int dp[N];
int s[N];

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		cint(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			s[a[i]] = 0;
			dp[a[i]] = 0;
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			s[a[i]]++;
			dp[a[i]]++;
		}
		int m = unique(a, a + n) - a;
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			ans = max(ans, dp[a[i]]);
			for (int j =  2 * a[i]; j < N; j += a[i])
			{
				dp[j] = max(dp[j], dp[a[i]] + s[j]);
			}
		}
		cout << n - ans << endl;
	cont:;
	}
}