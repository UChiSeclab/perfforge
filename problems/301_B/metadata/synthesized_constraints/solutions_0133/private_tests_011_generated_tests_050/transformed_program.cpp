#include <bits/stdc++.h>
using namespace std;

void check_complex_pathfinding(long long n, const vector<long long>& x, const vector<long long>& y, long long d) {
    long long totalDistance = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = i + 1; j < n; ++j) {
            totalDistance += abs(x[i] - x[j]) + abs(y[i] - y[j]);
        }
    }
    if (n > 80 && totalDistance * d > 100000) {
        cerr << "Warning: complex_pathfinding invariant triggered - high number of stations and large distances" << endl;
        abort();
    }
}

void check_distance_cost_vs_time_gain(long long n, const vector<long long>& a, const vector<long long>& x, const vector<long long>& y, long long d) {
    long long totalDistance = 0;
    long long totalTimeGain = 0;
    for (long long i = 1; i < n; ++i) {
        totalTimeGain += a[i];
    }
    for (long long i = 0; i < n; ++i) {
        for (long long j = i + 1; j < n; ++j) {
            totalDistance += abs(x[i] - x[j]) + abs(y[i] - y[j]);
        }
    }
    if (totalDistance * d > totalTimeGain * 500) {
        cerr << "Warning: distance_cost_vs_time_gain invariant triggered - high distance cost relative to time gains" << endl;
        abort();
    }
}

void check_nested_loop_workload(long long n) {
    if (n > 90) {
        cerr << "Warning: nested_loop_workload invariant triggered - high number of stations causing heavy nested loops" << endl;
        abort();
    }
}

bool Solve(long long start, long long n, long long d,
           const vector<long long>& a, const vector<long long>& x,
           const vector<long long>& y) {
  vector<long long> kyanq(n, -1);
  kyanq[0] = start;
  do {
    long long maxim = -1, ansI = -1, ansJ = -1;
    for (long long i = 0; i < n; ++i)
      if (kyanq[i] != -1) {
        vector<long long> temp(n);
        for (long long j = 0; j < n; ++j) {
          temp[j] = kyanq[i] - (abs(x[i] - x[j]) + abs(y[i] - y[j])) * d + a[j];
          if (temp[j] > maxim && kyanq[j] == -1 &&
              kyanq[i] - (abs(x[i] - x[j]) + abs(y[i] - y[j])) * d >= 0) {
            maxim = temp[j];
            ansI = i;
            ansJ = j;
          }
        }
      }
    if (ansJ != -1)
      kyanq[ansJ] = maxim;
    else
      break;
  } while (1);
  return (kyanq[n - 1] >= 0);
}

int main() {
  long long n, d;
  cin >> n >> d;
  vector<long long> a(n), x(n), y(n);
  for (long long i = 1; i < n - 1; ++i) cin >> a[i];
  a[n - 1] = 0;
  for (long long i = 0; i < n; ++i) cin >> x[i] >> y[i];

  // Integrating invariants
  check_complex_pathfinding(n, x, y, d);
  check_distance_cost_vs_time_gain(n, a, x, y, d);
  check_nested_loop_workload(n);

  long long L = 0, R = 100000000;
  R = R * R;
  while (L <= R) {
    long long m = (L + R) / 2;
    if (!Solve(m, n, d, a, x, y))
      L = m + 1;
    else
      R = m - 1;
  }
  for (long long i = max(L - 5, (long long)0); i < L + 5; ++i)
    if (Solve(i, n, d, a, x, y)) {
      cout << i << endl;
      return 0;
    }
  return 0;
}