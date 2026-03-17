#include <bits/stdc++.h>
using namespace std;
int N, M;
double rez;
vector<double> v1, v2;
double prob(int k) {
  v1.clear();
  v2.clear();
  if (k > M) return 0;
  for (int i = M - k + 1; i <= M; ++i) {
    v1.push_back(i);
  }
  for (int i = M * N - N - M + k + 1; i <= M * N - N; ++i) {
    v1.push_back(i);
  }
  for (int i = N - k + 1; i <= N; ++i) {
    v1.push_back(i);
  }
  for (int i = M * N - M + 1; i <= M * N; ++i) {
    v2.push_back(i);
  }
  for (int i = 1; i <= k; ++i) {
    v2.push_back(i);
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  double ret = 1;
  for (int i = 0; i < v1.size(); ++i) {
    ret = ret * v1[i] / v2[i];
  }
  return ret;
}
int main() {
  scanf("%d%d", &N, &M);
  if (N == 1) {
    printf("%.12lf", 1.0);
    return 0;
  }
  for (int i = 1; i <= N; ++i) {
    double x = prob(i);
    rez += x * i * i / N;
  }
  printf("%.12lf", rez);
  return 0;
}
