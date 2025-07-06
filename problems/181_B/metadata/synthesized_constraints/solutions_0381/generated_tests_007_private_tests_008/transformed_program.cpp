#include <bits/stdc++.h>
using namespace std;

void check_density_invariant(const map<int, set<int>>& mapa) {
    for (const auto& entry : mapa) {
        if (entry.second.size() > 100) { // Arbitrary threshold for dense y-values
            cerr << "Warning: High density of y-values for x-coordinate " << entry.first << "!" << endl;
            abort();
        }
    }
}

void check_map_size_invariant(const map<int, set<int>>& mapa) {
    if (mapa.size() > 100) { // Arbitrary threshold for number of unique x-coordinates
        cerr << "Warning: Large number of unique x-coordinates!" << endl;
        abort();
    }
}

void check_combination_invariant(int n) {
    if (n > 1000) { // Arbitrary threshold for combinations
        cerr << "Warning: Too many point combinations being evaluated!" << endl;
        abort();
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, i, j, x, y, cont, x2, y2, x3, y3;
  cin >> n;

  check_combination_invariant(n); // Check for excessive combinations

  map<int, set<int>> mapa;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    mapa[x].insert(y);
  }

  check_map_size_invariant(mapa); // Check for too many unique x-coordinates
  check_density_invariant(mapa); // Check for dense y-values for any x-coordinate

  cont = 0;
  for (auto it = mapa.begin(); it != mapa.end(); ++it) {
    for (auto sit = it->second.begin(); sit != it->second.end(); ++sit) {
      auto ita = it;
      while (ita != mapa.end()) {
        auto sita = (ita == it) ? next(sit) : ita->second.begin();
        for (; sita != ita->second.end(); ++sita) {
          x = it->first;
          y = *sit;
          x2 = ita->first;
          y2 = *sita;
          if ((x != x2 || y != y2) && (x + x2) % 2 == 0 && (y + y2) % 2 == 0) {
            x3 = (x + x2) / 2;
            y3 = (y + y2) / 2;
            if (mapa[x3].find(y3) != mapa[x3].end()) {
              cont++;
            }
          }
        }
        ita++;
      }
    }
  }

  cout << cont << endl;
  return 0;
}