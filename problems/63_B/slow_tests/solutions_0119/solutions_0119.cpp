#include <bits/stdc++.h>
using namespace std;
map<int, int> cant;
int main() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cant[a]++;
  }
  bool finished = false;
  int coins = -1;
  cant[0] = -1;
  while (!finished) {
    coins++;
    finished = true;
    for (int i = 1; i < k; i++) {
      if ((cant[i] == 1 && cant[i - 1] == -1) || cant[i] > 1) {
        finished = false;
        cant[i]--;
        if (cant[i + 1] == -1)
          cant[i + 1] = 1;
        else
          cant[i + 1]++;
      } else if (cant[i] == 0) {
        cant[i] = -1;
      }
    }
  }
  cout << coins << endl;
}
