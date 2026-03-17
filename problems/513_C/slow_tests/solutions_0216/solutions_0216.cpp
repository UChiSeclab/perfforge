#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
int n, l[6], r[6];
vector<int> ll, rr;
int aa, bb;
long double x, y;
void calc(int mm) {
  int nn = n - 1;
  for (int i = 0; i < (nn); i++) {
    if (ll[i] > bb) return;
  }
  long double xx = 0, yy = 0;
  for (int i = int(1); i <= int(aa - 1); i++) {
    bool good = true;
    for (int j = 0; j < (nn); j++)
      if (ll[j] > i) good = false;
    if (!good) continue;
    for (int k = int(1); k <= int((1 << nn) - 1); k++) {
      good = true;
      for (int j = 0; j < (nn); j++) {
        if ((k >> j) % 2 == 1 && i > rr[j]) good = false;
        if ((k >> j) % 2 == 0 && i <= ll[j]) good = false;
      }
      if (!good) continue;
      long long yyy = 1;
      for (int j = 0; j < (nn); j++) {
        if ((k >> j) % 2 == 0) {
          yyy *= min(i - 1, rr[j]) - ll[j] + 1;
        }
      }
      xx += i * yyy;
      yy += yyy;
    }
  }
  for (int i = int(aa); i <= int(bb); i++) {
    long long xx_ = 0, yy_ = 0;
    bool good = true;
    for (int j = 0; j < (nn); j++)
      if (ll[j] > i) good = false;
    if (!good) continue;
    for (int k = int(1); k <= int((1 << nn) - 1); k++) {
      good = true;
      for (int j = 0; j < (nn); j++) {
        if ((k >> j) % 2 == 1 && i > rr[j]) good = false;
        if ((k >> j) % 2 == 0 && i <= ll[j]) good = false;
      }
      if (!good) continue;
      long long yyy = 1;
      for (int j = 0; j < (nn); j++) {
        if ((k >> j) % 2 == 0) {
          yyy *= min(i - 1, rr[j]) - ll[j] + 1;
        }
      }
      for (int j = 0; j < (nn); j++) {
        if ((k >> j) % 2 == 1 && j < mm) good = false;
      }
      xx += i * yyy;
      yy += yyy;
      if (!good) {
        xx_ += i * yyy;
        yy_ += yyy;
      }
    }
    x += xx - xx_;
    y += yy - yy_;
  }
}
void process() {
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> l[i] >> r[i];
  x = 0;
  y = 0;
  for (int i = 0; i < (n); i++) {
    ll.clear();
    rr.clear();
    aa = l[i];
    bb = r[i];
    for (int j = 0; j < (n); j++) {
      if (j != i) {
        ll.push_back(l[j]);
        rr.push_back(r[j]);
      }
    }
    calc(i);
  }
  cout.precision(10);
  cout << fixed << x / y << endl;
}
void make() {
  freopen("in.txt", "wt", stdout);
  int N = 200000, M = 150000, Q = 300000;
  cout << N << endl;
  for (int i = 0; i < N; i++) cout << 1000000 - i << " ";
  exit(0);
}
int main() {
  process();
  return 0;
}
