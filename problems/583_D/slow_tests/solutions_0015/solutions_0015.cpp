#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1100;
int n, p[MAXN], t, cnt[MAXN], hi = -1, maks = -1;
int ans;
void brut() {
  vector<int> v, sol;
  for (int j = (0); j < int(t); j++)
    for (int i = (0); i < int(n); i++) v.push_back(p[i]);
  for (int i = (0); i < int((int)v.size()); i++) {
    vector<int>::iterator it = upper_bound((sol).begin(), (sol).end(), v[i]);
    if (it == sol.end())
      sol.push_back(v[i]);
    else
      *it = v[i];
  }
  printf("%d\n", (int)sol.size());
}
void fix(int x) {
  vector<int> v, sol;
  for (int k = (0); k < int(n); k++)
    for (int i = (0); i < int(n); i++)
      if (p[i] <= x) v.push_back(p[i]);
  for (int i = (0); i < int((int)v.size()); i++) {
    vector<int>::iterator it = upper_bound((sol).begin(), (sol).end(), v[i]);
    if (it == sol.end())
      sol.push_back(v[i]);
    else
      *it = v[i];
  }
  int a = (int)sol.size();
  sol.clear();
  v.clear();
  for (int k = (0); k < int(n); k++)
    for (int i = (0); i < int(n); i++)
      if (p[i] >= x) v.push_back(p[i]);
  for (int i = (0); i < int((int)v.size()); i++) {
    vector<int>::iterator it = upper_bound((sol).begin(), (sol).end(), v[i]);
    if (it == sol.end())
      sol.push_back(v[i]);
    else
      *it = v[i];
  }
  ans = max(ans, a + (t - 2 * n) * cnt[x] + (int)sol.size());
}
int main() {
  scanf("%d %d", &n, &t);
  for (int i = (0); i < int(n); i++) {
    scanf("%d", &p[i]);
    cnt[p[i]]++;
  }
  if (t <= 2 * n) {
    brut();
    return 0;
  }
  for (int i = (0); i < int(n); i++) fix(p[i]);
  printf("%d\n", ans);
  return 0;
}
