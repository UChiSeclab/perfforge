#include <bits/stdc++.h>
using namespace std;
int digitos(long long x) {
  int c = 0;
  while (x /= 10) c++;
  return c;
}
long long calcx(long long mid) {
  long long x = (mid * mid - mid) / 2 + 1;
  int c = digitos(mid);
  for (int i = 1; i <= c; i++) {
    long long a = mid - pow(10, i) + 1;
    long long r = (a * a - a) / 2;
    x += r;
  }
  return x;
}
long long calcd(long long midi) {
  long long dig = digitos(midi) + 1;
  string s = "";
  for (int i = 0; i < dig - 1; i++) s += "1";
  s += "0";
  return dig * midi - stoi(s);
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    long long k;
    cin >> k;
    long long lo = 1, hi = INT_MAX;
    while (hi - lo > 0) {
      long long mid = lo + (hi - lo) / 2;
      long long x = calcx(mid);
      long long y = calcx(mid + 1) - 1;
      if (k > y)
        lo = mid + 1;
      else if (k < x)
        hi = mid;
      else {
        long long dif = k - x + 1;
        long long loi = 1, hii = mid;
        while (hii - loi >= 0) {
          long long midi = loi + (hii - loi) / 2;
          long long xr = calcd(midi);
          long long yr = calcd(midi + 1) - 1;
          if (dif > yr)
            loi = midi + 1;
          else if (dif < xr)
            hii = midi;
          else {
            string midis = to_string(midi);
            long long difd = dif - xr;
            cout << midis[difd] << endl;
            break;
          }
        }
        break;
      }
    }
  }
  return 0;
}
