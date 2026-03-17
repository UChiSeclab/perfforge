#include <bits/stdc++.h>
using namespace std;
int A[200010];
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A + N);
  N = unique(A, A + N) - A;
  int ma = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = A[i]; j <= 1000000; j += A[i]) {
      int f = j, s = j + A[i];
      int p = lower_bound(A + i + 1, A + N, s) - A;
      if (p == 0) continue;
      p--;
      ma = max(ma, A[p] - f);
    }
  }
  cout << ma << endl;
}
