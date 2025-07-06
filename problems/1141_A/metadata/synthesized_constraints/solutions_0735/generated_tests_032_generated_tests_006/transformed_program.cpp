#include <iostream>
using namespace std;

int m, n;

int co(int num, int in) {
  if (num == m) return in;
  if (num > m) return -1;
  in++;
  int in1 = co(num * 2, in);
  int in2 = co(num * 3, in);
  if (in1 == -1 && in2 == -1)
    return -1;
  else
    return in1 == -1 ? in2 : in1;
}

void check_large_target_invariant(int n, int m) {
    if (m > n && m > 1e8) { // Assuming a heuristic threshold for a large m
        cerr << "Warning: Performance bottleneck condition triggered - large target m relative to n!" << endl;
        abort();
    }
}

void check_recursive_depth_invariant(int n, int m) {
    int potentialDepth = 0;
    int temp = m;
    while (temp > n && (temp % 2 == 0 || temp % 3 == 0)) {
        if (temp % 2 == 0) temp /= 2;
        else if (temp % 3 == 0) temp /= 3;
        potentialDepth++;
    }
    if (potentialDepth > 50) { // Arbitrary yet reasonable threshold
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion depth!" << endl;
        abort();
    }
}

void check_unreachable_target_invariant(int n, int m) {
    int temp = m;
    while (temp % 2 == 0) temp /= 2;
    while (temp % 3 == 0) temp /= 3;
    if (temp != n && temp != 1) {
        cerr << "Warning: Performance bottleneck condition triggered - target m seems unreachable!" << endl;
        abort();
    }
}

int main() {
  cin >> n >> m;

  // Perform invariant checks before starting recursion
  check_large_target_invariant(n, m);
  check_recursive_depth_invariant(n, m);
  check_unreachable_target_invariant(n, m);

  cout << co(n, 0);
  return 0;
}