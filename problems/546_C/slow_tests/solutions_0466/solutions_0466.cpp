#include <bits/stdc++.h>
using namespace std;
long long int tc, n, m, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n;
  long long int k1, k2;
  cin >> k1;
  queue<long long int> q1;
  for (__typeof(k1) i = (0) - ((0) > (k1)); i != (k1) - ((0) > (k1));
       i += 1 - 2 * ((0) > (k1))) {
    long long int a;
    cin >> a;
    q1.push(a);
  }
  cin >> k2;
  queue<long long int> q2;
  for (__typeof(k2) i = (0) - ((0) > (k2)); i != (k2) - ((0) > (k2));
       i += 1 - 2 * ((0) > (k2))) {
    long long int a;
    cin >> a;
    q2.push(a);
  }
  long long int af = q1.front();
  long long int bf = q2.front();
  long long int sa = ((int)(q1).size());
  long long int sb = ((int)(q2).size());
  long long int ans = 0;
  while (((int)(q1).size()) && ((int)(q2).size())) {
    long long int a = q1.front();
    long long int b = q2.front();
    if ((ans > 4e7)) {
      cout << -1;
      return 0;
    }
    if (a < b) {
      q2.push(a);
      q2.push(b);
    } else {
      q1.push(b);
      q1.push(a);
    }
    q1.pop();
    q2.pop();
    ans++;
  }
  cout << ans << " ";
  if (((int)(q1).size()) == 0)
    cout << 2;
  else
    cout << 1;
  return 0;
  return 0;
}
