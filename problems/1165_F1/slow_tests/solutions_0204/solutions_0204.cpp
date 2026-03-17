#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long int> k;
vector<pair<long long int, long long int> > deal;
bool pred(long long day) {
  vector<long long int> last(n + 1, -1);
  for (long long int i = 1; i < m + 1; i++) {
    if (deal[i].first <= day) {
      last[deal[i].second] = max(last[deal[i].second], deal[i].first);
    }
  }
  vector<vector<long long int> > off(200005);
  for (long long int i = 1; i < n + 1; i++) {
    if (last[i] != -1) {
      off[last[i]].push_back(i);
    }
  }
  vector<long long int> reqd = k;
  long long cur = 0L;
  for (long long int i = 1; i < day + 1; i++) {
    cur++;
    for (auto j : off[i]) {
      if (cur >= reqd[j]) {
        cur -= reqd[j];
        reqd[j] = 0;
      } else {
        reqd[j] -= cur;
        cur = 0;
        break;
      }
    }
  }
  long long sum = 0L;
  for (auto i : reqd) {
    sum += i;
  }
  return (sum * 2 <= cur);
}
int main() {
  cin >> n >> m;
  k.resize(n + 1);
  long long sum = 0L;
  for (long long int i = 1; i < n + 1; i++) {
    cin >> k[i];
    sum += k[i];
  }
  deal.resize(m + 1);
  for (long long int i = 1; i < m + 1; i++) {
    cin >> deal[i].first >> deal[i].second;
  }
  long long x = 0L;
  for (long long step = 2 * sum; step >= 1; step /= 2) {
    while (!pred(x + step)) x += step;
  }
  cout << x + 1;
  return 0;
}
