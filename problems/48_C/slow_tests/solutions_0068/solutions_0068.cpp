#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int segms[1001];
  int h0 = 0;
  for (int i = 0; i < n; i++) {
    int h1;
    cin >> h1;
    segms[i] = h1 - h0;
    h0 = h1;
  }
  double x = 1;
  double y = 0;
  double maxa = 100000000;
  double mina = 10;
  for (int i = 0; i < n; i++) {
    double nmaxa = (10 * (segms[i] + 1) - y) / x;
    double nmina = (10 * segms[i] - y) / x;
    if (nmaxa < maxa) maxa = nmaxa;
    if (nmina > mina) mina = nmina;
    x = x + 1;
    y = y - segms[i] * 10;
  }
  int vozm = -1;
  int mx = 1000001;
  for (int i = 1; i < mx; i++) {
    double nmaxa = (10 * (i + 1) - y) / x;
    double nmina = (10 * (i)-y) / x;
    if (nmaxa > mina && maxa > nmina)
      if (vozm == -1) {
        vozm = h0 + i;
        continue;
      } else {
        cout << "not unique";
        return 0;
      }
  }
  cout << "unique" << endl << vozm;
}
