#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
int a, b, mo, ans, _2;

// Checker for large 'b' value
void check_large_b_invariant(int b) {
    if (b > 1000000) {  // Threshold chosen to catch potential slowdowns
        cerr << "Warning: Performance bottleneck condition triggered due to large value of b!" << endl;
        abort();
    }
}

// Checker for excessive calls to calc
void check_calc_calls_invariant(int numCalls) {
    if (numCalls > 1000000) {  // Threshold for detecting excessive calls
        cerr << "Warning: Performance bottleneck condition triggered due to excessive calls to calc!" << endl;
        abort();
    }
}

int Pow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % P)
    if (b & 1) res = 1ll * res * a % P;
  return res;
}

int calc(int a0, int d, int n) {
  int an = a0 + 1ll * d * (n - 1) % P;
  an %= P;
  int res = (a0 + an) % P * 1ll * n % P * 1ll * _2 % P;
  return res;
}

int main() {
  scanf("%d%d", &a, &b);

  // Check for large 'b' before executing the loop
  check_large_b_invariant(b);

  _2 = Pow(2, P - 2);
  int calcCalls = 0;  // Counter to track the number of calls to calc

  for (mo = 1; mo < b; mo++) {
    ans += calc((mo + 1ll * b * mo) % P, (1ll * b * mo) % P, a);
    calcCalls++;  // Increment the call count

    if (ans >= P) ans -= P;
  }

  // Check for excessive calls to calc after the loop
  check_calc_calls_invariant(calcCalls);

  printf("%d\n", ans);
}