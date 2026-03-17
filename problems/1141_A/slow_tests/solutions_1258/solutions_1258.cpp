#include <bits/stdc++.h>
using namespace std;
bool sc[10000007];
vector<long long int> pr;
void sieve() {
  for (long long int i = 2; i * i < 10000007; i++) {
    if (!sc[i]) {
      for (long long int j = i * i; j < 10000007; j += i) sc[j] = 1;
    }
  }
  pr.push_back(2);
  for (long long int i = 3; i < 10000007; i += 2)
    if (!sc[i]) pr.push_back(i);
}
pair<long long int, long long int> pf[10000007];
void pri_fact(long long int n) {
  long long int i, u = 0;
  for (i = 0; i < pr.size() && n != 1; i++) {
    long long int c = 0;
    while (!(n % pr[i])) {
      n /= pr[i];
      c++;
    }
    if (c) {
      pf[u].first = pr[i];
      pf[u].second = c;
      u++;
    }
  }
  if (n > 1) {
    pf[u].first = n;
    pf[u].second = 1;
  }
}
int main() {
  long long int x, y;
  cin >> x >> y;
  if (y % x != 0) {
    cout << -1;
    return 0;
  }
  if (x == y) {
    cout << 0;
    return 0;
  }
  sieve();
  long long int z = y / x;
  pri_fact(z);
  long long int s = pf[0].second + pf[1].second;
  if ((long long int)(pow(pf[0].first, pf[0].second) *
                      pow(pf[1].first, pf[1].second)) == z) {
    long long int ct = 0, tc = 0, i;
    for (i = 0; pf[i].first != 0; i++) {
      ct++;
      if (pf[i].first == 2) {
        tc = 0;
      } else if (pf[i].first == 3) {
        tc = 0;
      } else {
        tc = 1;
      }
    }
    if (ct > 2) {
      cout << -1;
      return 0;
    } else if (tc == 1) {
      cout << -1;
      return 0;
    }
    cout << s;
    return 0;
  } else
    cout << -1;
  return 0;
}
