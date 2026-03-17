#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, vector<string> > flag;
  map<string, int> mp;
  int n;
  cin >> n;
  while (n--) {
    string name;
    int score;
    cin >> name >> score;
    mp[name] = mp[name] + score;
    if (mp[name] >= 0) {
      for (int i = 0; i <= mp[name]; i++) {
        flag[i].push_back(name);
      }
    }
  }
  int maax = -1;
  map<string, int>::iterator i;
  for (i = mp.begin(); i != mp.end(); ++i) {
    if (i->second > maax) {
      maax = i->second;
    }
  }
  vector<string> winner;
  for (i = mp.begin(); i != mp.end(); ++i) {
    if (i->second == maax) {
      winner.push_back(i->first);
    }
  }
  for (auto i = flag[maax].begin(); i != flag[maax].end(); i++) {
    if (mp[*i] == maax) {
      cout << *i << endl;
      break;
    }
  }
  return 0;
}
