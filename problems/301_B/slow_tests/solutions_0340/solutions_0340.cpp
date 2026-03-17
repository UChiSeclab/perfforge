#include <bits/stdc++.h>
using namespace std;
void _ad(int &p) {
  static int i = 0;
  p = i++;
}
int n, m, d;
int s1[2];
vector<pair<int, int> > st;
vector<long long> mark(st.size());
vector<long long> w;
bool dfs(int v, long long a) {
  if (v == n - 1) return true;
  mark[v] = a;
  bool ans = false;
  for (int i = 0; i < st.size(); i++) {
    long long dist = abs(st[v].first - st[i].first);
    dist += abs(st[v].second - st[i].second);
    dist *= d;
    if (a >= dist) {
      if (i != v && (mark[i] == 0 || mark[i] < a + w[i] - dist)) {
        if (dfs(i, a + w[i] - dist)) ans = true;
      }
    }
  }
  return ans;
}
bool can(int a) {
  mark.assign(st.size(), 0);
  return dfs(0, a);
}
int main() {
  int i;
  cin >> n >> d;
  w.push_back(0);
  int a;
  for (i = (0); i < (((n - 2))); ++i) {
    cin >> a;
    w.push_back(a);
  }
  w.push_back(0);
  int b;
  for (i = (0); i < (((n))); ++i) {
    cin >> a >> b;
    st.push_back(make_pair(a, b));
  }
  int ans = 0;
  long long l = 0;
  long long r = 1e12;
  while (l <= r) {
    int m = (l + r) / 2;
    if (can(m)) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  cout << ans;
  return 0;
}
