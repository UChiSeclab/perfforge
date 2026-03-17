#include <bits/stdc++.h>
using namespace std;
int memo[(int)1e6 + 1000], a[(int)1e6 + 1000];
int main() {
  int n, to = 0;
  cin >> n;
  memset(a, -1, sizeof a);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    tmp++;
    cin >> a[tmp];
    to = max(to, tmp);
  }
  for (int i = 1; i < to + 1; i++)
    if (a[i] == -1)
      memo[i] = memo[i - 1];
    else
      memo[i] = memo[(i - a[i] - 1 >= 0 ? i - a[i] - 1 : 0)] + 1;
  int mx = memo[to];
  for (int i = 1; i < to + 1; i++) {
    mx = max(mx, memo[i - 1] + 1);
  }
  cout << (mx == memo[to] ? n - mx : n + 1 - mx) << endl;
}
