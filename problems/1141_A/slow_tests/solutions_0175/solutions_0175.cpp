#include <bits/stdc++.h>
int m;
int _moves = -1;
void solve(int n, int moves) {
  if (n == m) {
    _moves = moves;
    return;
  } else if (n > m)
    return;
  else if (_moves == -1) {
    solve(n * 2, moves + 1);
    if (_moves == -1) solve(n * 3, moves + 1);
  }
  return;
}
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n >> m;
  solve(n, 0);
  std::cout << _moves << std::endl;
  return 0;
}
