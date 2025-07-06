#include <bits/stdc++.h>
using namespace std;

// Checkers for performance-characterizing invariants
void check_uncertainty_invariant(int questionCount, int n) {
    if (questionCount > n * 0.5) {
        cerr << "Warning: Performance bottleneck triggered due to high degree of uncertainty!" << endl;
        abort();
    }
}

void check_recursion_invariant(int recursionCalls, int n) {
    if (recursionCalls > n * n) {
        cerr << "Warning: Performance bottleneck triggered due to excessive recursion calls!" << endl;
        abort();
    }
}

void check_input_size_invariant(int n, int questionCount) {
    if (n == 100 && questionCount > n / 4) {
        cerr << "Warning: Performance bottleneck triggered due to large input size with high complexity!" << endl;
        abort();
    }
}

template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T sgn(T a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
int n;
int m;
const int N = 101;
bool was[N][N][N], ans;
char s[N];
int recursionCalls = 0;  // Track recursion calls

void go(int i, int j, int k) {
  check_recursion_invariant(++recursionCalls, n);  // Check recursion depth and calls

  if (i == n) {
    ans |= k == m;
    return;
  }
  if (was[i][j][k]) return;
  if (s[i] == 'N')
    go(i + 1, j + 1, max(j + 1, k));
  else if (s[i] == 'Y')
    go(i + 1, 0, k);
  else if (s[i] == '?')
    go(i + 1, 0, k), go(i + 1, j + 1, max(j + 1, k));
  was[i][j][k] = true;
  return;
}

int main() {
  scanf("%d%d ", &n, &m);
  gets(s);
  
  int questionCount = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') questionCount++;
  }
  
  check_uncertainty_invariant(questionCount, n);  // Check for high degree of uncertainty
  check_input_size_invariant(n, questionCount);   // Check for large input size with complexity

  go(0, 0, 0);
  if (ans)
    puts("YES");
  else
    puts("NO");

  return 0;
}