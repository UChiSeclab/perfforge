#include <bits/stdc++.h>
using namespace std;
void println(vector<int> x) {
  for (int i = 0; i < ((int)x.size()); ++i)
    printf("%d%c", x[i], " \n"[i == (int)x.size() - 1]);
}
void scanln(vector<int>& x, int sz) {
  x.resize(sz);
  for (int i = 0; i < (sz); ++i) scanf("%d", &x[i]);
}
template <class T>
void read(T* x, int l, int r) {
  for (int i = (l); i <= (r); ++i) read(x[i]);
}
void println(int* x, int l, int r) {
  for (int i = (l); i <= (r); ++i) printf("%d%c", x[i], " \n"[i == r]);
}
long long myrand(long long mod) {
  return ((long long)rand() << 32 ^ (long long)rand() << 16 ^ rand()) % mod;
}
void println(vector<long long> x) {
  for (int i = 0; i < ((int)x.size()); ++i)
    printf("%lld%c", x[i], " \n"[i == (int)x.size() - 1]);
}
void scanln(vector<long long>& x, int sz) {
  x.resize(sz);
  for (int i = 0; i < (sz); ++i) scanf("%lld", &x[i]);
}
void println(long long* x, int l, int r) {
  for (int i = (l); i <= (r); ++i) printf("%lld%c", x[i], " \n"[i == r]);
}
long long L, R;
void getdp(int n, unordered_map<int, long long>& col_odd,
           unordered_map<int, long long>& col_even) {
  if (col_odd.find(n) != col_odd.end()) return;
  if (n == 1) {
    col_even[n] = R / 2 - (L + 1) / 2 + 1;
    col_odd[n] = R - L + 1 - col_even[n];
    col_even[n] %= 998244353LL;
    col_odd[n] %= 998244353LL;
  } else {
    getdp(n / 2, col_odd, col_even);
    if (n % 2) getdp(n - n / 2, col_odd, col_even);
    col_odd[n] = ((col_odd[n / 2] * col_even[n - n / 2]) % 998244353LL +
                  (col_even[n / 2] * col_odd[n - n / 2]) % 998244353LL) %
                 998244353LL;
    col_even[n] = ((col_odd[n / 2] * col_odd[n - n / 2]) % 998244353LL +
                   (col_even[n / 2] * col_even[n - n / 2]) % 998244353LL) %
                  998244353LL;
  }
}
void getdp2(int m, unordered_map<int, long long>& odd,
            unordered_map<int, long long>& even) {
  if (odd.find(m) != odd.end()) return;
  getdp2(m / 2, odd, even);
  if (m % 2) getdp2(m - m / 2, odd, even);
  odd[m] = ((odd[m / 2] * even[m - m / 2]) % 998244353LL +
            (even[m / 2] * odd[m - m / 2]) % 998244353LL) %
           998244353LL;
  even[m] = ((odd[m / 2] * odd[m - m / 2]) % 998244353LL +
             (even[m / 2] * even[m - m / 2]) % 998244353LL) %
            998244353LL;
}
long long doit(long long n, long long m) {
  unordered_map<int, long long> col_odd, col_even;
  getdp(n, col_odd, col_even);
  unordered_map<int, long long> odd, even;
  odd[1] = col_odd[n];
  even[1] = col_even[n];
  getdp2(m, odd, even);
  return (m % 2 == 1 && n % 2 == 1) ? (even[m] + odd[m]) % 998244353LL
                                    : even[m];
}
int main(int argc, char* argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  ;
  scanf("%lld%lld", &L, &R);
  printf("%lld\n", doit(n, m));
  ;
  return 0;
}
