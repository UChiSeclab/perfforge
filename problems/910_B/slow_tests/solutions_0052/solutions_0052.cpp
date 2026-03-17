#include <bits/stdc++.h>
const double pi =
    3.141592653589793238462643383279502884197169399375105820974944;
using namespace std;
long long n, i, j, k, l, sum = 0, flag = 0, ans = 0, a, b, A, B;
vector<long long int> v;
long long f(int a, int b, int k) {
  if (a == 0 && b == 0) return 0;
  long long l = 1000000007;
  if (a != 0) {
    if (k - A > 0) l = min(l, f(a - 1, b, k - A));
    if (k - A == 0) {
      l = min(l, f(a - 1, b, 0));
      l = min(l, 1 + f(a - 1, b, n));
    }
    if (k < A) l = min(l, 1 + f(a, b, n));
  }
  if (b != 0) {
    if (k - B > 0) l = min(l, f(a, b - 1, k - B));
    if (k - B == 0) {
      l = min(l, f(a, b - 1, 0));
      l = min(l, 1 + f(a, b - 1, n));
    }
    if (k < B) l = min(l, 1 + f(a, b, n));
  }
  return l;
}
int main() {
  int t = 1;
  while (t--) {
    cin >> n >> A >> B;
    cout << 1 + f(4, 2, n) << '\n';
  }
  return 0;
}
