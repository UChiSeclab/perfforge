#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e5 + 5;
int n, m;
int dad[MAX];
int dna(int a) {
  if (dad[a] == a) return a;
  return dad[a] = dna(dad[a]);
}
void merge(int a, int b) {
  int pa = dna(a);
  int push_back = dna(b);
  dad[push_back] = pa;
}
set<pair<int, int> > s;
bool is0(int a, int b) {
  if (a > b) swap(a, b);
  return s.find({a, b}) == s.end();
}
const int bor = 5000;
bool p[bor + 5][bor + 5];
set<int> QWER;
int cnt[MAX];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (0), _for = (m); i < _for; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    cnt[a]++;
    cnt[b]++;
    if (a > b) swap(a, b);
    if (n <= bor) {
      p[a][b] = 1;
    } else {
      s.insert({a, b});
    }
  }
  for (int i = (0), _for = (n); i < _for; ++i) dad[i] = i;
  if (n <= bor) {
    for (int i = (0), _for = (n); i < _for; ++i)
      for (int j = (i + 1), _for = (n); j < _for; ++j) {
        if (!p[i][j]) merge(i, j);
      }
    for (int i = (0), _for = (n); i < _for; ++i) QWER.insert(dna(i));
    printf("%d\n", (int)QWER.size() - 1);
    return 0;
  }
  set<int> q;
  int g = -1;
  for (int i = (0), _for = (n); i < _for; ++i) {
    if (cnt[i] < n - 25) {
      if (g < 0) g = i;
      continue;
    }
    q.insert(i);
  }
  srand(time(0));
  for (int i = (0), _for = (50); i < _for; ++i) {
    int r = rand() * rand() + rand();
    q.insert(r % n);
  }
  if (g >= 0) q.insert(g);
  for (auto first : q) {
    for (int i = (0), _for = (n); i < _for; ++i) {
      if (is0(first, i)) merge(first, i);
    }
  }
  for (int i = (0), _for = (n); i < _for; ++i) QWER.insert(dna(i));
  printf("%d\n", (int)QWER.size() - 1);
  return 0;
}
