#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ctx, oty;
  cin >> ctx >> oty;
  long long original = 1, copies = 0;
  while (original < oty) {
    copies++;
    original++;
  }
  if (original == oty && copies == ctx) {
    cout << "Yes" << endl;
    return 0;
  }
  while (copies < ctx && copies != 0) {
    copies += 2;
    if (original == oty && copies == ctx) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
