#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, k, m;
long long vis[400001];
int vis2[200001];
int main() {
  int n;
  cin >> n;
  long long sum1 = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    vis[a]++;
    vis2[a] = 1;
    sum1 += a;
  }
  long long mx = 0;
  if (vis[1]) {
    cout << sum1 << endl;
  } else {
    for (int i = 1; i <= 400000; i++) {
      vis[i] += vis[i - 1];
    }
    for (int i = 2; i <= 200000; i++) {
      if (vis2[i] == 0) continue;
      long long sum = (vis[2 * i - 1] - vis[i - 1]) * i;
      for (int j = i * 2; j <= 400000 - i; j += i) {
        sum += (vis[i + j - 1] - vis[j - 1]) * j;
      }
      mx = max(mx, sum);
    }
    cout << mx << endl;
  }
  return 0;
}
