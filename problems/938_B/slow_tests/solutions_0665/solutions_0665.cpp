#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const long long inf = 1e9 + 7;
const long double eps = (long double)1e-12;
const double pi = 3.141592653;
const long long linf = 1e18 + 7;
const int logn = 20;
int n, a[maxn], tim, ans;
map<int, int> cnt;
int fir, sec;
int res;
int main() {
  fir = 1;
  sec = 1e6;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]] = 1;
    res++;
  }
  while (fir <= sec) {
    fir++;
    sec--;
    if (cnt[fir]) cnt[fir] = 0, res--;
    if (cnt[sec]) cnt[sec] = 0, res--;
    tim++;
    if (!res) break;
  }
  cout << tim;
  return 0;
}
