#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  vector<pair<int, int> > a(t);
  for (int i = (0); i < (t); i++) {
    int x;
    cin >> x;
    a[i] = make_pair(x, i);
  }
  sort(a.begin(), a.end());
  queue<int> next;
  int MAXN = 1000005;
  vector<bool> isprime(MAXN, 1);
  int last = 1;
  int ans = 1;
  vector<int> rta(t);
  for (int T = (0); T < (t); T++) {
    if (last >= a[T].first)
      rta[a[T].second] = ans;
    else {
      while (last < a[T].first) {
        last++;
        if (!next.empty() && (next.front() == last)) {
          next.pop();
          ans--;
        }
        if (isprime[last]) {
          ans++;
          next.push(last * last);
          for (int i = 2 * last; i < MAXN; i += last) isprime[i] = 0;
        }
      }
      rta[a[T].second] = ans;
    }
  }
  for (int i = (0); i < (t); i++) cout << rta[i] << '\n';
  return 0;
}
