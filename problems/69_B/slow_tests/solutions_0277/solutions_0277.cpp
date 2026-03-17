#include <bits/stdc++.h>
using namespace std;
struct A {
  int start, finish;
  int time, coin;
  A() {}
  A(int s, int f, int t, int c) { start = s, finish = f, time = t, coin = c; }
} a[105];
int main() {
  int n, m;
  cin >> n >> m;
  multimap<pair<int, int>, int> s;
  for (int i = 0; i < m; i++) {
    cin >> a[i].start >> a[i].finish >> a[i].time >> a[i].coin;
    s.insert(make_pair(make_pair(a[i].start, 0), i));
    s.insert(make_pair(make_pair(a[i].finish, 1), i));
  }
  a[101].coin = 0;
  set<pair<int, int> > p;
  int last = 0, ans = 0;
  for (multimap<pair<int, int>, int>::iterator i = s.begin(); i != s.end();
       i++) {
    int t = i->first.first, o = i->first.second, id = i->second;
    if (o == 0) {
      int dif = t - last - 1;
      last = t - 1;
      int winner = (p.size() ? p.begin()->second : 101);
      ans += a[winner].coin * dif;
      p.insert(make_pair(a[id].time, id));
    } else {
      int dif = t - last;
      last = t;
      int winner = (p.size() ? p.begin()->second : 101);
      ans += a[winner].coin * dif;
      p.erase(make_pair(a[id].time, id));
    }
  }
  cout << ans << "\n";
  return 0;
}
