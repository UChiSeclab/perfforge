#include <bits/stdc++.h>
using namespace std;

// Function to check high iteration count
void check_high_iteration_count(int a) {
    if (a > 80) { // Threshold set at 80, as discussed
        cerr << "Warning: High iteration count - potential slowdown!" << endl;
        abort();
    }
}

// Function to check cumulative operations
void check_cumulative_operations(int a) {
    if (a > 80) { // This check is same as above since the bottlenecks are linked
        cerr << "Warning: Cumulative operations - potential slowdown!" << endl;
        abort();
    }
}

int a, b, c, d, e, cnt = 0, snt = 0, f;
string s, n, s1;
vector<int> v;
char u;

int main() {
  cin >> a;

  // Check for high iteration count and potential slowdown
  check_high_iteration_count(a);

  // Check for cumulative operations
  check_cumulative_operations(a);

  for (int i = 1; i <= a; i++) {
    cin >> b;
    cnt += (i * b);
  }
  cout << cnt;
}