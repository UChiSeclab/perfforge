#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N], k;
long long cost(int len, int parts) {
  int len1 = len / parts;
  int len2 = len1 + 1;
  int cnt2 = len % parts, cnt1 = parts - cnt2;
  return (1LL * cnt1 * len1 * len1 + 1LL * cnt2 * len2 * len2);
}
struct node {
  int len, parts;
  node() { len = parts = 0; }
  node(int _len, int _parts) {
    len = _len;
    parts = _parts;
  }
  long long optimizerAnswer() const {
    return cost(len, parts) - cost(len, parts + 1);
  }
};
bool operator<(node a, node b) {
  return a.optimizerAnswer() < b.optimizerAnswer();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  priority_queue<node> pq;
  for (int(i) = (1); (i) <= (n); ++(i)) {
    cin >> a[i];
    pq.push(node(a[i], 1));
  }
  while (k-- > n) {
    node u = pq.top();
    pq.pop();
    pq.push(node(u.len, u.parts + 1));
  }
  long long ans = 0;
  while (pq.size()) {
    node u = pq.top();
    pq.pop();
    ans += cost(u.len, u.parts);
  }
  cout << ans;
}
