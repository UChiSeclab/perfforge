#include <bits/stdc++.h>
using namespace std;

void zanj0() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

// Checkers as defined in Phase 3
void check_high_iteration_invariant(int n, int loopCount, int threshold) {
    if (n >= threshold && loopCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count with potential expensive calls!" << endl;
        abort();
    }
}

void check_frequent_sorting_invariant(int n, int sortCount, int threshold) {
    if (n >= threshold && sortCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent sorting of large arrays!" << endl;
        abort();
    }
}

void check_binary_search_invariant(int n, int searchCount, int threshold) {
    if (n >= threshold && searchCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - intensive binary search operations!" << endl;
        abort();
    }
}

int getVal(vector<int>& v, int curr, int till, int dontTake) {
  int low = curr;
  int high = v.size() - 1;
  int start = -1, endd = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (v[mid] >= till) {
      start = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  low = curr;
  high = v.size() - 1;
  endd = high + 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (v[mid] >= dontTake) {
      endd = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (start == -1 || endd < start) return 0;
  return endd - start;
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n), v2(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  int ret = 0;
  int threshold = 100; // Example threshold based on problem constraints

  // Check potential issues before starting the main loop
  check_frequent_sorting_invariant(n, 25, threshold);

  for (int i = 0; i <= 24; i++) {
    int div = (1l << (i + 1));
    for (int j = 0; j < n; j++) {
      v2[j] = v[j] % div;
    }
    sort(v2.begin(), v2.end());
   
    int cnt = 0;
    int loopCount = 0;
    for (int j = 0; j + 1 < n; j++) {
      int firstTill = pow(2, i) - v2[j];
      int firstDontTake = pow(2, i + 1) - v2[j];
      cnt += getVal(v2, j + 1, firstTill, firstDontTake);

      int secondTill = pow(2, i) + pow(2, i + 1) - v2[j];
      int secondDontTake = (pow(2, i + 2) - 2) + 1 - v2[j];
      cnt += getVal(v2, j + 1, secondTill, secondDontTake);
      
      loopCount++;
    }

    // Check for high iteration count coupled with expensive operations
    check_high_iteration_invariant(n, loopCount, threshold);

    if (cnt & 1) ret += pow(2, i);
  }
  cout << ret << "\n";
}

int32_t main() {
  zanj0();
  solve();
  cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC << "ms\n";
  return 0;
}