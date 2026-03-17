#include <bits/stdc++.h>
using namespace std;
int a[10];
int n, k;
int ccnt;
bool go(int now) {
  int cnt = 0;
  while (now != 1 && cnt <= k) {
    now = a[now];
    cnt++;
  }
  if (now == 1) return 1;
  return 0;
}
void dfs(int now) {
  if (now == k + 1) {
    bool flag = 1;
    for (int i = 1; i <= k; i++)
      if (!go(i)) flag = 0;
    ccnt += flag;
    return;
  }
  for (int i = 1; i <= k; i++) {
    a[now] = i;
    dfs(now + 1);
    a[now] = 0;
  }
}
int main() {
  cin >> n >> k;
  long long now = 1;
  for (int i = 1; i <= n - k; i++) (now *= (n - k)) %= 1000000007;
  dfs(1);
  cout << (long long)ccnt * now % 1000000007 << endl;
  return 0;
}
