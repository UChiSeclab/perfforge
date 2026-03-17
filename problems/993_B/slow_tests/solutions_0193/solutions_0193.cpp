#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return {i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
using ll = long long;
constexpr int mod = 1000 * 1000 * 1000 + 7;
void DodajDo(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int Dodaj(int a, int b) {
  DodajDo(a, b);
  return a;
}
int Mnoz(int a, int b) { return (ll)a * b % mod; }
void MnozDo(int& a, int b) { a = Mnoz(a, b); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  set<pair<int, int>> z[2];
  int roz[2];
  for (int i = 0; i < 2; i++) cin >> roz[i];
  for (int i = 0; i < 2; i++) {
    while (roz[i]--) {
      int a, b;
      cin >> a >> b;
      z[i].insert(make_pair(a, b));
      z[i].insert(make_pair(b, a));
    }
  }
  set<int> dobre;
  bool zle = false;
  for (int h = 0; h < 2; h++) {
    for (auto& it : z[h]) {
      vector<int> jed = {it.first, it.second};
      set<int> jdob;
      for (auto& it2 : z[h ^ 1]) {
        vector<int> dwa = {it2.first, it2.second};
        set<int> to_samo;
        for (int j : jed)
          for (int d : dwa)
            if (j == d) to_samo.insert(d);
        if ((int)to_samo.size() == 1) {
          const int x = *to_samo.begin();
          dobre.insert(x);
          jdob.insert(x);
        }
      }
      if ((int)jdob.size() > 1) {
        zle = true;
      }
    }
  }
  if ((int)dobre.size() == 1)
    cout << *dobre.begin() << endl;
  else if (zle)
    cout << -1 << endl;
  else
    cout << 0 << endl;
  return 0;
}
