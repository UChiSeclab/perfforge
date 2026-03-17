#include <bits/stdc++.h>
using namespace std;
vector<int> V;
vector<int> T;
vector<int> N;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    V.push_back(a);
  }
  int tak = 0, nie = 0;
  sort(V.begin(), V.end());
  int p = 0;
  for (int i = 0; i < (int)V.size(); i++) {
    while ((p + 1) * (p + 1) <= V[i]) p++;
    int odl = min(V[i] - p * p, (p + 1) * (p + 1) - V[i]);
    if (odl == 0) {
      tak++;
      if (V[i] == 0)
        T.push_back(2);
      else
        T.push_back(1);
    } else {
      nie++;
      N.push_back(odl);
    }
  }
  sort(T.begin(), T.end());
  sort(N.begin(), N.end());
  long long res = 0;
  if (tak > n / 2) {
    int zamien = tak - n / 2;
    for (int i = 0; i < zamien; i++) {
      res += (long long)T[i];
    }
  } else {
    int zamien = nie - n / 2;
    for (int i = 0; i < zamien; i++) {
      res += (long long)N[i];
    }
  }
  cout << res << endl;
}
