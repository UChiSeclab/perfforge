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

void check_large_input_invariant(int n) {
    if (n > 500) { // Considering n > 500 as a performance bottleneck threshold
        cerr << "Warning: Performance bottleneck condition triggered due to large number of petrol stations!" << endl;
        abort();
    }
}

void check_frequent_stops_invariant(const int stops[], int n) {
    for (int i = 1; i < n; ++i) {
        if (stops[i] - stops[i-1] < 5) { // If stops are too close, indicating frequent computation
            cerr << "Warning: Performance bottleneck condition triggered due to closely spaced station stops!" << endl;
            abort();
        }
    }
}

void check_sequential_simulation_invariant(double lower, double upper) {
    if (fabs(upper - lower) < EPS) { // If bounds are very close, implying extensive computations
        cerr << "Warning: Performance bottleneck condition triggered due to sequential simulation complexity!" << endl;
        abort();
    }
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
  check_large_input_invariant(N); // Check for large input size
  int a[2000] = {};
  for (int i = 0; i < N; i++) {
    scanf("%d ", &a[i]);
  }
  check_frequent_stops_invariant(a, N); // Check for frequent stops
  double lower = GetBound(a, N, false);
  double upper = GetBound(a, N, true);
  check_sequential_simulation_invariant(lower, upper); // Check for close bounds
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