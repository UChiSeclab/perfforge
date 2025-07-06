#include <bits/stdc++.h>
using namespace std;

// Function prototypes for the checkers
void check_iteration_space_invariant(int o_hits, int i_hits);
void check_innermost_loop_invariant(int j_iterations);
void check_boundary_check_invariant(int cnt_evaluations);
void check_grid_density_invariant(int a_hits);

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < 4 * n + 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v.push_back(make_pair(a, b));
  }

  int o_hits = 0;
  int i_hits = 0;
  int total_j_iterations = 0;
  int total_cnt_evaluations = 0;
  int total_a_hits = 0;

  for (int o = 0; o <= 50; o++) {
    o_hits++;
    for (int i = 0; i <= 50; i++) {
      i_hits++;
      for (int a = 2; a <= 50; a++) {
        total_a_hits++;
        int x1 = i, x2 = i + a, y1 = o, y2 = o + a;
        vector<bool> vis(4 * n + 1, 0);
        int cnt = 0;
        for (int j = 0; j < 4 * n + 1; j++) {
          total_j_iterations++;
          if ((v[j].first == x1 || v[j].first == x2) && y1 <= v[j].second &&
              v[j].second <= y2) {
            vis[j] = 1;
            cnt++;
            continue;
          }
          if ((v[j].second == y1 || v[j].second == y2) && x1 <= v[j].first &&
              v[j].first <= x2) {
            vis[j] = 1;
            cnt++;
          }
        }

        total_cnt_evaluations++;
        if (cnt == 4 * n) {
          for (int j = 0; j < 4 * n + 1; j++) {
            if (vis[j] == 0) {
              cout << v[j].first << " " << v[j].second << endl;
              return 0;
            }
          }
        }
      }
    }
  }

  // Place checkers outside heavy loops to avoid additional overhead inside critical sections
  check_iteration_space_invariant(o_hits, i_hits);
  check_innermost_loop_invariant(total_j_iterations);
  check_boundary_check_invariant(total_cnt_evaluations);
  check_grid_density_invariant(total_a_hits);

  return 0;
}