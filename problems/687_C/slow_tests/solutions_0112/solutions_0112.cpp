#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<bool> > > dpArr;
int main(int argc, char const *argv[]) {
  int N, K;
  cin >> N >> K;
  std::vector<int> coin(N + 1);
  dpArr = vector<vector<vector<bool> > >(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> coin[i];
  }
  for (int i = 0; i < N + 1; ++i) {
    dpArr[i] = vector<vector<bool> >(K + 1, vector<bool>(K + 1, false));
    dpArr[i][0][0] = true;
  }
  for (int i = 1; i < N + 1; ++i) {
    for (int k = 0; k < K + 1; ++k) {
      for (int x = 0; x <= k; ++x) {
        dpArr[i][k][x] = dpArr[i - 1][k][x];
        if (k >= coin[i]) {
          dpArr[i][k][x] = dpArr[i][k][x] || dpArr[i - 1][k - coin[i]][x];
          if (x >= coin[i]) {
            dpArr[i][k][x] =
                dpArr[i][k][x] || dpArr[i - 1][k - coin[i]][x - coin[i]];
          }
        }
      }
    }
  }
  set<int> A;
  for (int x = 0; x < K + 1; ++x) {
    if (dpArr[N][K][x]) A.insert(x);
  }
  cout << A.size() << endl;
  for (std::set<int>::iterator i = A.begin(); i != A.end(); ++i) {
    cout << *i << ' ';
  }
  cout << endl;
  return 0;
}
