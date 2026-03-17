#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
using pii = pair<int, int>;
unordered_set<int> divisors(int x, int p) {
  unordered_set<int> second;
  if (x <= p) {
    second.insert(x);
    second.insert(1);
    return second;
  } else {
    for (int i = p; i * i <= x; i++) {
      if (x % i == 0) {
        auto last_s = divisors(x / i, i);
        for (auto next : last_s) {
          second.insert(next);
          second.insert(i * next);
        }
      }
    }
    second.insert(1);
    second.insert(x);
    return second;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vc<int> last(1e5 + 1, -1);
  for (int i = 0; i < n; i++) {
    int x, ind;
    cin >> x >> ind;
    ind = i - ind;
    unordered_set<int> div = divisors(x, 2);
    int anz = 0;
    for (auto d : div) {
      if (last[d] < ind) anz++;
      last[d] = i;
    }
    cout << anz << " ";
  }
  cout << "\n";
}
