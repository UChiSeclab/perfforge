#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
const int MOD = 998244353;
int mul(int x, int y) { return 1LL * x * y % MOD; }
void incby(int &x, int y) {
  x += y;
  while (x >= MOD) {
    x -= MOD;
  }
  while (x < 0) {
    x += MOD;
  }
}
int pow(int a, int n) {
  long long b = 1;
  while (n) {
    if (n & 1) {
      b = mul(b, a);
    }
    a = mul(a, a);
    n >>= 1;
  }
  return b;
}
int rev(int x) { return pow(x, MOD - 2); }
struct Item {
  int x, y;
  int val;
  Item() {}
  Item(int x, int y, int val) : x(x), y(y), val(val) {}
  bool operator<(const Item &it) const { return val < it.val; }
};
vector<Item> vec;
int ev[N][N];

// Insert the invariant checker functions here
void check_large_group_invariant(const vector<Item>& vec, int threshold) {
    int current_value = -1;
    int count = 0;
    for (const auto& item : vec) {
        if (item.val != current_value) {
            current_value = item.val;
            count = 1;
        } else {
            count++;
            if (count > threshold) {
                cerr << "Warning: large_group_invariant triggered - too many elements with the same value." << endl;
                abort();
            }
        }
    }
}

void check_arithmetic_frequency_invariant(int arithmetic_operations_count, int threshold) {
    if (arithmetic_operations_count > threshold) {
        cerr << "Warning: arithmetic_frequency_invariant triggered - too many arithmetic operations." << endl;
        abort();
    }
}

void check_iteration_invariant(int n, int m, int unique_value_count, int threshold) {
    if (n * m > threshold && unique_value_count < (n * m) / 2) {
        cerr << "Warning: iteration_invariant triggered - excessive iterations due to matrix size and repetitions." << endl;
        abort();
    }
}

int main() {
  int n, m, si, sj;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int a;
      scanf("%d", &a);
      vec.push_back(Item(i, j, a));
    }
  }
  scanf("%d %d", &si, &sj);
  sort(vec.begin(), vec.end());

  // Check for large groups of equal values after sorting
  check_large_group_invariant(vec, 500);  // Threshold for large groups

  int l = 0, sumX2 = 0, sumY2 = 0, sumX = 0, sumY = 0, sumEv = 0;
  int arithmetic_operations_count = 0;
  while (l < (int)vec.size()) {
    int r = l;
    while (r < (int)vec.size() && vec[l].val == vec[r].val) {
      r++;
    }
    for (int i = l; i < r; i++) {
      int x = vec[i].x, y = vec[i].y;
      if (l == 0) {
        ev[x][y] = 0;
      } else {
        int lrev = rev(l);
        incby(ev[x][y], mul(x, x));
        incby(ev[x][y], mul(y, y));
        incby(ev[x][y], mul(sumEv, lrev));
        incby(ev[x][y], mul(sumX2, lrev));
        incby(ev[x][y], mul(sumY2, lrev));
        incby(ev[x][y], mul(-2 * x, mul(sumX, lrev)));
        incby(ev[x][y], mul(-2 * y, mul(sumY, lrev)));

        // Increment arithmetic operations count
        arithmetic_operations_count += 7;  // Seven incby calls per iteration
      }
    }
    
    // Check for high frequency of arithmetic operations
    check_arithmetic_frequency_invariant(arithmetic_operations_count, 10000);

    for (int i = l; i < r; i++) {
      int x = vec[i].x, y = vec[i].y;
      incby(sumX, x);
      incby(sumY, y);
      incby(sumEv, ev[x][y]);
      incby(sumX2, mul(x, x));
      incby(sumY2, mul(y, y));
    }
    l = r;
  }

  // Check for excessive iterations due to matrix size and repetitions
  check_iteration_invariant(n, m, vec.size(), 800000);  // Threshold for iterations

  printf("%d\n", ev[si][sj]);
  return 0;
}