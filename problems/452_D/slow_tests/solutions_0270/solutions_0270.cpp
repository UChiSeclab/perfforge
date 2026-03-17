#include <bits/stdc++.h>
using namespace std;
int k, n1, n2, n3, t1, t2, t3;
int A[4][10009];
int getsttime() {
  int a = 0, b = 0, c = 0, d = 0;
  for (int i = 0; i < k; i++) {
    if (A[0][i] < A[0][a]) a = i;
  }
  for (int i = 0; i < n1; i++) {
    if (A[1][i] < A[1][b]) b = i;
  }
  for (int i = 0; i < n2; i++) {
    if (A[2][i] < A[2][c]) c = i;
  }
  for (int i = 0; i < n3; i++) {
    if (A[3][i] < A[3][d]) d = i;
  }
  int st;
  st = max(max(max(0, A[1][b]), A[2][c] - t1), A[3][d] - t1 - t2);
  A[0][a] = st;
  A[1][b] = st + t1;
  A[2][c] = st + t1 + t2;
  A[3][d] = st + t1 + t2 + t3;
  return st;
}
int main() {
  cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
  memset(A, 0, sizeof(A));
  int x;
  for (int i = 0; i < k; i++) {
    x = getsttime();
  }
  cout << x + t1 + t2 + t3 << endl;
  return 0;
}
