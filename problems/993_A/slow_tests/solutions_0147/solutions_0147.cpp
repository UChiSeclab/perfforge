#include <bits/stdc++.h>
using namespace std;
const int MN = 100005, inf = 1000000005, MOD = 1000000007;
const long long INF = 1000000000000000005LL;
pair<int, int> A[10], B[10];
int det(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
  int a = B.first - A.first, b = B.second - A.second, c = C.first - A.first,
      d = C.second - A.second;
  return (a * d - b * c);
}
bool inside(pair<int, int> a) {
  int mia = inf, mib = inf;
  int maa = -inf, mab = -inf;
  for (int i = 0; i < 4; ++i) {
    int cura = det(A[i], A[(i + 1) % 4], a),
        curb = det(B[i], B[(i + 1) % 4], a);
    mia = min(mia, cura);
    mib = min(mib, curb);
    maa = max(maa, cura);
    mab = max(mab, curb);
  }
  int ok = 0;
  if (mia >= 0 || maa <= 0) ++ok;
  if (mib >= 0 || mab <= 0) ++ok;
  return (ok == 2);
}
int main() {
  for (int i = 0; i < 4; ++i) scanf("%d%d", &A[i].first, &A[i].second);
  for (int i = 0; i < 4; ++i) scanf("%d%d", &B[i].first, &B[i].second);
  for (int x = -100; x <= 100; ++x)
    for (int y = -100; y <= 100; ++y) {
      pair<int, int> cur = {x, y};
      if (inside(cur)) {
        printf("YES");
        return 0;
      }
    }
  printf("NO");
  return 0;
}
