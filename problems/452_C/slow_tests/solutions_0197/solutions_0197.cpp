#include <bits/stdc++.h>
using namespace std;
int n, m;
long double p(int k) {
  vector<long double> A, B;
  for (int i = m - k + 1; i < m + 1; i++)
    if (i > 0)
      A.push_back(i);
    else if (i < 0)
      return 0;
  for (int i = n - k + 1; i < n + 1; i++)
    if (i > 0)
      A.push_back(i);
    else if (i < 0)
      return 0;
  for (int i = m * n - m - n + k + 1; i < m * n - m + 1; i++)
    if (i > 0)
      A.push_back(i);
    else if (i < 0)
      return 0;
  for (int i = 0; i < k + 1; i++)
    if (i > 0)
      B.push_back(i);
    else if (i < 0)
      return 0;
  for (int i = m * n - n + 1; i < m * n + 1; i++)
    if (i > 0)
      B.push_back(i);
    else if (i < 0)
      return 0;
  sort((A).rbegin(), (A).rend());
  sort((B).rbegin(), (B).rend());
  long double res = 1;
  while (B.size() < A.size()) B.push_back(1);
  while (A.size() < B.size()) A.push_back(1);
  for (int i = 0; i < A.size(); i++) res *= A[i] / B[i];
  return res;
}
int main() {
  cin >> n >> m;
  long double res = 0;
  for (int k = 1; k < min(n, m) + 1; k++) {
    res += p(k) * k * k / n;
  }
  printf("%.09f\n", (double)res);
}
