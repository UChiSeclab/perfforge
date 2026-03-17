#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-4;
const double Q = (1.0 + sqrt(5.0)) / 2.0;
char a[100000 + 100];
char b[100000 + 100];
int q[100000 + 100];
int p[100000 + 100];
int A[100000 + 100];
int B[100000 + 100];
int sA[100000 + 100];
int sB[100000 + 100];
int mx;
void reverse(int *a, int n) {
  for (int i = 0; i <= n / 2; i++) {
    swap(a[i], a[n - i - 1]);
  }
}
void check() {
  int q = 0, p = 0;
  for (int i = mx - 3; i < mx; i++) {
    q += B[i] - A[i];
  }
}
string solve(string &a, string &b) {
  memset(A, 0, sizeof(A));
  memset(B, 0, sizeof(B));
  int n = a.size();
  for (int i = 0; i < n; i++) {
    A[i] = a[i] - '0';
    B[i] = b[i] - '0';
    if (A[i] == B[i]) {
      A[i] = B[i] = 0;
    }
  }
  for (int i = 0; i < n - 2; i++) {
    if (A[i] >= B[i]) {
      A[i] -= B[i];
      B[i] = 0;
    } else if (B[i] >= A[i]) {
      B[i] -= A[i];
      A[i] = 0;
    }
    if (A[i] < -20 || B[i] > 20) {
      return "<";
    } else if (A[i] > 20 || B[i] < -20) {
      return ">";
    }
    A[i + 1] += A[i];
    A[i + 2] += A[i];
    A[i] = 0;
    B[i + 1] += B[i];
    B[i + 2] += B[i];
    B[i] = 0;
  }
  double aa = A[n - 2] * Q + A[n - 1];
  double bb = B[n - 2] * Q + B[n - 1];
  if (aa < bb - EPS) {
    return "<";
  } else if (aa > bb + EPS) {
    return ">";
  } else {
    return "=";
  }
}
int main() {
  scanf("%s%s", a, b);
  string strA(a);
  string strB(b);
  while (strA.size() < strB.size()) {
    strA = '0' + strA;
  }
  while (strB.size() < strA.size()) {
    strB = '0' + strB;
  }
  printf("%s\n", solve(strA, strB).c_str());
  return 0;
}
