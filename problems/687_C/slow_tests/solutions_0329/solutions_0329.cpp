#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<vector<vector<bool> > > dp(
      n + 1, vector<vector<bool> >(k + 1, vector<bool>(k + 1, 0)));
  vector<int> inp;
  int temp;
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    inp.push_back(temp);
  }
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int l = 0; l <= k; l++) {
        dp[i][j][l] =
            dp[i - 1][j][l] ||
            (j >= inp[i - 1]
                 ? dp[i - 1][j - inp[i - 1]][l] ||
                       (l >= inp[i - 1]
                            ? dp[i - 1][j - inp[i - 1]][l - inp[i - 1]]
                            : 0)
                 : 0);
      }
    }
  }
  map<int, int> a;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (dp[i][k][j] == 1) {
        a[j] = 1;
      }
    }
  }
  cout << a.size() << endl;
  for (map<int, int>::iterator it = a.begin(); it != a.end(); it++)
    cout << it->first << "	";
  cout << endl;
}
