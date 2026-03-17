#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  vector<int> ans(n, 1000000000);
  priority_queue<pair<int, int> > pq;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    pq.push(make_pair(h * -1, i));
  }
  pq.push(make_pair(-1, 0));
  pq.push(make_pair(-1, n - 1));
  while (!pq.empty()) {
    int node = pq.top().second;
    int value = pq.top().first * -1;
    pq.pop();
    if (ans[node] <= value) continue;
    ans[node] = value;
    if (node + 1 < n) pq.push(make_pair((value + 1) * -1, node + 1));
    if (node - 1 > -1) pq.push(make_pair((value + 1) * -1, node - 1));
  }
  int as = -1;
  for (int i = 0; i < n; i++) as = max(ans[i], as);
  cout << as << endl;
  return 0;
}
