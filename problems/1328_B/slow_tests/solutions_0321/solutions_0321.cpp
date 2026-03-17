#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = unsigned long long int;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    string s(n, 'a');
    for (ll i = n - 2; i >= 0; i--) {
      if (k <= n - i - 1) {
        s[i] = 'b';
        s[n - k] = 'b';
        cout << s << '\n';
        break;
      }
      k -= n - i - 1;
    }
  }
  return 0;
}
