#include <bits/stdc++.h>
using namespace std;
long long h[100000 + 2], cost[100000 + 2];
bool vst[100000 + 2];
int main() {
  int n;
  while (cin >> n) {
    priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                   greater<pair<long long, int> > >
        q;
    h[0] = cost[0] = h[n + 1] = cost[n + 1] = 0;
    vst[0] = vst[n + 1] = true;
    for (int i = 1; i <= n; ++i) {
      cin >> h[i];
      cost[i] = h[i];
      vst[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      if (h[i - 1] == 0 || h[i + 1] == 0 || h[i] == 1) {
        cost[i] = 1;
      }
      q.push(pair<long long, int>(cost[i], i));
    }
    long long len = 0;
    while (!q.empty()) {
      pair<long long, int> node = q.top();
      q.pop();
      int xi = node.second;
      if (vst[xi]) continue;
      vst[xi] = true;
      if (cost[xi - 1] > cost[xi] + 1) {
        cost[xi - 1] = cost[xi] + 1;
        q.push(pair<long long, int>(cost[xi - 1], xi - 1));
      }
      if (cost[xi + 1] > cost[xi] + 1) {
        cost[xi + 1] = cost[xi] + 1;
        q.push(pair<long long, int>(cost[xi + 1], xi + 1));
      }
      len = max(cost[xi], len);
    }
    for (int _ = 1; _ <= n; ++_) cerr << cost[_] << ' ';
    cerr << endl;
    cout << len << endl;
  }
  return 0;
}
