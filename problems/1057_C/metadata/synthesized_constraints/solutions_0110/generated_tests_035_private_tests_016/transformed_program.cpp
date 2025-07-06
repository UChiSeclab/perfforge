#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, k, d[N];
char c[N];
struct dt {
  int x, pre;
  inline __attribute__((always_inline)) dt(int x = 0, int pre = 0)
      : x(x), pre(pre) {}
};
queue<dt> q1, q2;
struct memt {
  int d[N][N];
  inline __attribute__((always_inline)) int& operator[](const dt u) {
    return d[u.x][u.pre];
  }
  inline __attribute__((always_inline)) void clear() {
    memset(d, 255, sizeof(d));
  }
} r[2];
inline __attribute__((always_inline)) void upd(dt u, int v, int a) {
  if (r[a][u] == -1) q2.push(u);
  if (v > r[a][u]) r[a][u] = v;
}
bool ex[N];

// Checker function for large state space
void check_state_space_invariant(int exploredStates) {
    if (exploredStates > 10000) {  // threshold based on empirical observation
        cerr << "Warning: state_space_invariant triggered - large state space exploration!" << endl;
        abort();
    }
}

// Checker function for frequent state checks
void check_frequent_state_checks_invariant(int stateChecks) {
    if (stateChecks > 20000) {  // threshold based on empirical observation
        cerr << "Warning: frequent_state_checks_invariant triggered - excessive state checks!" << endl;
        abort();
    }
}

// Checker function for complex input patterns
void check_complex_input_patterns_invariant(int currentPosition, int initialPosition, int steps) {
    if (abs(currentPosition - initialPosition) > 20 && steps > 100) {  // arbitrary parameters for complexity
        cerr << "Warning: complex_input_patterns_invariant triggered - complex input pattern detected!" << endl;
        abort();
    }
}

int main() {
  int s;
  scanf("%d%d%d", &n, &s, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &d[i]), ex[d[i]] = 1;
  if (d[s] >= k) return puts("0"), 0;
  scanf("%s", c + 1);
  for (int i = 1; i <= n; ++i) {
    if (c[i] == 'R')
      c[i] = 1;
    else if (c[i] == 'G')
      c[i] = 2;
    else if (c[i] == 'B')
      c[i] = 3;
    else
      exit(1);
  }
  c[0] = 0;
  int ans = 0;
  r[0].clear(), r[1].clear();
  upd(dt(s, 0), 0, 0), upd(dt(s, s), d[s], 0);
  q1.swap(q2);

  // Variables to track state space exploration and checks
  int exploredStates = 0;
  int stateChecks = 0;

  for (; ans <= n * n; ++ans) {
    int a = ans & 1;
    while (!q1.empty()) {
      dt u = q1.front();
      q1.pop();
      int v = r[a][u];

      // Increment state checks
      stateChecks++;

      if (v >= k) goto ed;
      if (u.x + 1 <= n) {
        dt nu = u;
        ++nu.x;
        upd(nu, v, a ^ 1);

        // Increment explored states
        exploredStates++;

        if (d[u.pre] < d[nu.x] && c[u.pre] != c[nu.x]) {
          nu.pre = nu.x;
          upd(nu, v + d[nu.x], a ^ 1);
        }
      }
      if (1 <= u.x - 1) {
        dt nu = u;
        --nu.x;
        upd(nu, v, a ^ 1);

        // Increment explored states
        exploredStates++;

        if (d[u.pre] < d[nu.x] && c[u.pre] != c[nu.x]) {
          nu.pre = nu.x;
          upd(nu, v + d[nu.x], a ^ 1);
        }
      }
    }
    q1.swap(q2);
    r[a].clear();

    // Perform checks at the end of each iteration
    check_state_space_invariant(exploredStates);
    check_frequent_state_checks_invariant(stateChecks);
    check_complex_input_patterns_invariant(q1.front().x, s, ans);
  }
ed:
  printf("%d\n", ans > n * n ? -1 : ans);
  return 0;
}