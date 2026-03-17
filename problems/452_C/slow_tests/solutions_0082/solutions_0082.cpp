#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:500000000")
using namespace std;
double C[1009][1009];
vector<int> A, B;
void add(int n, int k, vector<int> &A, vector<int> &B) {
  for (int i = 0; i < k; i++) B.push_back(k - i), A.push_back(n - i);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  double res = 0;
  for (int k = 0; k <= n; k++) {
    A.clear(), B.clear();
    add(m, k, A, B);
    add(n * m - m, n - k, A, B);
    add(n * m, n, B, A);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    double ml = 1.0 * k * k / n / n;
    for (int i = 0; i < A.size(); i++) ml *= 1.0 * A[i] / B[i];
    res += ml;
  }
  printf("%.13f\n", n * res);
}
