#include <bits/stdc++.h>
using namespace std;
struct trio {
  int first;
  int second;
  int third;
};
struct long_trio {
  long long first;
  long long second;
  long long third;
};
const long long INF = 1e18 + 2;
const int LIT = 505;
const int BIG = 200001;
string months[12] = {"January",   "February", "March",    "April",
                     "May",       "June",     "July",     "August",
                     "September", "October",  "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long fact[13] = {1,    1,     2,      6,       24,       120,      720,
                      5040, 40320, 362280, 3622800, 39916800, 479001600};
int cx[6] = {1, -1, 0, 0, 0, 0};
int cy[6] = {0, 0, 1, -1, 0, 0};
int cz[6] = {0, 0, 0, 0, 1, -1};
long long st_10[10] = {1,       10,       100,       1000,      10000,
                       1000000, 10000000, 100000000, 1000000000};
long long n, m, k, l, r, x, y, t, ans = 1, w, s;
int main() {
  cin >> n >> m >> k;
  if (k == -1) {
    if ((n + m) % 2 == 1) {
      cout << 0;
      return 0;
    }
  }
  n--;
  m--;
  n = n % (1000000007 - 1);
  m = m % (1000000007 - 1);
  n = (n * m) % (1000000007 - 1);
  long long i2_in_10_6 = 1;
  for (int i = 0; i < 1000000; i++) {
    i2_in_10_6 = (i2_in_10_6 * 2) % 1000000007;
  }
  while (n > 0) {
    if (n > 1000000) {
      ans = (ans * i2_in_10_6) % 1000000007;
      n -= 1000000;
    } else {
      ans = (ans * 2) % 1000000007;
      n--;
    }
  }
  cout << ans;
}
