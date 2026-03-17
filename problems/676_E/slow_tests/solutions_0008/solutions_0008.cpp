#include <bits/stdc++.h>
using namespace std;
mt19937 mt(time(0));
long long n, k;
long long a[123456];
const long long inf = (int)(1e9);
int cnt = 0;
long long mas[123456];
long long solve() {
  long long md;
  for (int i = mt() % 123456 + (int)(1e9);; i++) {
    bool ok = false;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      md = i;
      break;
    }
  }
  long long tmp = 1;
  for (int i = 0; i <= n; i++) {
    mas[i] = tmp;
    tmp *= k;
    tmp %= md;
  }
  long long sum = 0;
  for (int i = 0; i <= n; i++) {
    long long t = (a[i] * mas[i]) % md;
    sum += t;
    sum %= md;
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i <= n; i++) {
    string s;
    cin >> s;
    if (s == "?")
      a[i] = inf;
    else {
      istringstream iss(s);
      iss >> a[i];
      cnt++;
    }
  }
  if (cnt < n + 1) {
    if (k == 0 && a[0] != 0 && a[0] != inf) {
      cout << "No" << endl;
      exit(0);
    }
    if (n % 2 == 1) {
      if (k == 0 && a[0] == inf && cnt % 2 == 0)
        cout << "No" << endl;
      else
        cout << "Yes" << endl;
    } else {
      if ((k == 0 && a[0] == 0) || (k == 0 && a[0] == inf && cnt % 2 == 1))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
    exit(0);
  }
  long long attempt1 = solve();
  long long attempt2 = solve();
  long long attempt3 = solve();
  if (attempt1 == 0 && attempt2 == 0 && attempt3 == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
