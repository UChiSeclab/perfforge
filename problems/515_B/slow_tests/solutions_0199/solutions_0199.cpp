#include <bits/stdc++.h>
using namespace std;
set<int> happyB;
set<int> happyG;
bool boys[111];
bool girls[111];
int main() {
  int x;
  int B, G;
  int g, b;
  cin >> B >> G;
  cin >> b;
  while (b--) {
    cin >> x;
    boys[x] = true;
  }
  cin >> g;
  while (g--) {
    cin >> x;
    girls[x] = true;
  }
  for (int i = 0; i < (1000 * 1000 + 1); i++) {
    int Gindex = i % G;
    int Bindex = i % B;
    if (boys[Bindex] || girls[Gindex]) {
      boys[Bindex] = true;
      girls[Gindex] = true;
      happyB.insert(Bindex);
      happyG.insert(Gindex);
    }
    if (happyG.size() == G && happyB.size() == B) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
}
