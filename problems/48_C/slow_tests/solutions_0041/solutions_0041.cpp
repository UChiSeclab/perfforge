#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-6;
int ROUND(double x) { return (int)(x + 0.5); }
bool ISINT(double x) { return fabs(ROUND(x) - x) <= EPS; }
bool ISEQUAL(double x, double y) {
  return fabs(x - y) <= EPS * max(1.0, max(fabs(x), fabs(y)));
}
double SQSUM(double x, double y) { return x * x + y * y; }
template <class T>
bool INRANGE(T x, T a, T b) {
  return a <= x && x <= b;
}
int GetFinalStation(const int a[], int N, double alpha) {
  double hp = alpha;
  int st = 0;
  int i = 0;
  while (1) {
    int susumu = (int)(hp / 10.0);
    st += susumu;
    hp -= susumu * 10.0;
    if (hp < 10.0) {
      hp += alpha;
      if (i == N) {
        return st;
      }
      i++;
    }
  }
}
double GetBound(const int a[], int N, bool upper) {
  {
    double lo = 10.0;
    double hi = 20000000.0;
    for (int z = 0; z < 500; z++) {
      double mid = lo + (hi - lo) / 2.0;
      double hp = mid;
      int st = 0;
      int i = 0;
      bool sageru = true;
      if (upper) {
        sageru = false;
      }
      while (1) {
        int susumu = (int)(hp / 10.0);
        st += susumu;
        hp -= susumu * 10.0;
        if (hp < 10.0) {
          hp += mid;
          if (upper == true && st > a[i]) {
            sageru = true;
            break;
          } else if (upper == false && st < a[i]) {
            sageru = false;
            break;
          } else {
            i++;
            if (i >= N) {
              break;
            }
          }
        }
      }
      if (sageru) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    return lo;
  }
}
int main() {
  int N;
  scanf("%d ", &N);
  int a[2000] = {};
  for (int i = 0; i < N; i++) {
    scanf("%d ", &a[i]);
  }
  double lower = GetBound(a, N, false);
  double upper = GetBound(a, N, true);
  int lower_station = GetFinalStation(a, N, lower + EPS);
  int upper_station = GetFinalStation(a, N, upper - EPS);
  if (lower_station == upper_station) {
    printf("unique\n");
    printf("%d\n", lower_station);
  } else {
    printf("not unique\n");
  }
  return 0;
}
