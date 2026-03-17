#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  if (n == 0) {
    cout << 3 * m << endl;
    return 0;
  }
  if (m == 0) {
    cout << 2 * n << endl;
    return 0;
  }
  long long u = 2, v = 3;
  priority_queue<long long> pq1, pq2;
  while (1) {
    if (u % 6 == 0) {
      u += 2;
      continue;
    } else {
      pq1.push(u);
      u += 2;
      n--;
    }
    if (n <= 0) break;
  }
  while (1) {
    if (v % 6 == 0) {
      v += 3;
      continue;
    } else {
      pq2.push(v);
      v += 3;
      m--;
    }
    if (m <= 0) break;
  }
  long long w = 6;
  while (1) {
    u = pq1.top();
    v = pq2.top();
    if (w > u && w > v) break;
    if (u > v) {
      pq1.pop();
      pq1.push(w);
      w += 6;
    } else {
      pq2.pop();
      pq2.push(w);
      w += 6;
    }
  }
  cout << max(pq1.top(), pq2.top()) << endl;
  return 0;
}
