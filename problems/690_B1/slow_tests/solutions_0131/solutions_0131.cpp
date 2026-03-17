#include <bits/stdc++.h>
using namespace std;
int n;
char buf[55][55];
bool visited4[55][55];
int _4ui = -1, _4li = 55, _4uj = -1, _4lj = 55;
void dfs4(int i, int j) {
  visited4[i][j] = 1;
  _4li = min(_4li, i);
  _4lj = min(_4lj, j);
  _4ui = max(_4ui, i);
  _4uj = max(_4uj, j);
  if (i)
    if (buf[i - 1][j] == '4' && !visited4[i - 1][j]) dfs4(i - 1, j);
  if (j)
    if (buf[i][j - 1] == '4' && !visited4[i][j - 1]) dfs4(i, j - 1);
  if (i < n - 1)
    if (buf[i + 1][j] == '4' && !visited4[i + 1][j]) dfs4(i + 1, j);
  if (j < n - 1)
    if (buf[i][j + 1] == '4' && !visited4[i][j + 1]) dfs4(i, j + 1);
}
bool found_four;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%s", buf[i]);
  try {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (buf[i][j] == '4') {
          if (!visited4[i][j] && found_four) throw 0;
          found_four = 1;
          dfs4(i, j);
        }
    if (!found_four) throw 0;
    for (int i = _4li; i <= _4ui; ++i)
      for (int j = _4lj; j <= _4uj; ++j)
        if (buf[i][j] != '4') throw 0;
    auto ass = [](int i, int j, char a) {
      if (i < 0 || j < 0 || i >= n || j >= n) return;
      if (buf[i][j] != a) throw 0;
    };
    ass(_4ui + 1, _4uj + 1, '1');
    ass(_4ui + 1, _4lj - 1, '1');
    ass(_4li - 1, _4uj + 1, '1');
    ass(_4li - 1, _4lj - 1, '1');
    for (int i = _4li; i <= _4ui; ++i) ass(i, _4uj + 1, '2');
    for (int i = _4li; i <= _4ui; ++i) ass(i, _4lj - 1, '2');
    for (int j = _4lj; j <= _4uj; ++j) ass(_4ui + 1, j, '2');
    for (int j = _4lj; j <= _4uj; ++j) ass(_4li - 1, j, '2');
    if (_4li) --_4li;
    if (_4lj) --_4lj;
    if (_4ui < n - 1) ++_4ui;
    if (_4uj < n - 1) ++_4uj;
    for (int i = _4li; i <= _4ui; ++i)
      for (int j = _4lj; j <= _4uj; ++j) buf[i][j] = '0';
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (buf[i][j] != '0') throw 0;
  } catch (...) {
    puts("No");
    return 0;
  }
  puts("Yes");
}
