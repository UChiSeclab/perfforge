#include <bits/stdc++.h>
using namespace std;
const int max_n = 100 * 1000;
int a[max_n + 1];
const int mod[] = {1000 * 1000 * 1000 + 7, 1000 * 10000 * 1000 + 9};
const int inf = 1e9;
int str2int(string s) {
  stringstream ss(s);
  int x;
  ss >> x;
  return x;
}
int main() {
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  for (int i = 0; i < (n + 1); i++) {
    string s;
    cin >> s;
    if (s[0] == '?') {
      cnt++;
      a[i] = inf;
    } else
      a[i] = str2int(s);
  }
  if (cnt) {
    if (k == 0)
      cout << ((a[0] == 0 || (a[0] == inf && (n + 1 - cnt) % 2)) ? "YES" : "NO")
           << endl;
    else
      cout << (n % 2 ? "YES" : "NO") << endl;
    return 0;
  }
  for (int m = 0; m < (2); m++) {
    long long sum = 0;
    for (int i = (n); i >= 0; i--) sum = (sum * k + a[i]) % mod[m];
    if (sum != 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
