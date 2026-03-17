#include <bits/stdc++.h>
using namespace std;
long long y, k, n;
int main() {
  scanf("%I64d", &y);
  scanf("%I64d", &k);
  scanf("%I64d", &n);
  long long s;
  vector<int> ans;
  for (long long i = 1; i < 100001ll; i++) {
    s = i * k;
    if (s > n) break;
    if (s <= y)
      continue;
    else {
      ans.push_back((int)(s - y));
    }
  }
  if (ans.size() == 0)
    cout << -1;
  else {
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  }
}
