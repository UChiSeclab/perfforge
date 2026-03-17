#include <bits/stdc++.h>
using namespace std;
bool visited[50][51][2000];
struct State {
  int pos;
  int last_box;
  int candies_eaten;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N = 0, S = 0, K = 0;
  cin >> N >> S >> K;
  --S;
  vector<int> R(N);
  for (int &i : R) cin >> i;
  string C;
  cin >> C;
  State initial = {S, -1, 0};
  vector<State> queue = {initial};
  visited[S][0][0] = true;
  int steps = 0;
  while (!queue.empty()) {
    vector<State> next_queue;
    for (State s : queue) {
      for (int eat = 0; eat < 2; ++eat) {
        if (eat) {
          if (s.last_box >= 0 &&
              (R[s.pos] <= R[s.last_box] || C[s.pos] == C[s.last_box])) {
            break;
          }
          s.candies_eaten += R[s.pos];
          s.last_box = s.pos;
          if (s.candies_eaten >= K) {
            cout << steps << endl;
            return 0;
          }
        }
        for (int step = -1; step <= +1; ++step) {
          if (step == 0) continue;
          State t = s;
          t.pos += step;
          if (t.pos >= 0 && t.pos < N &&
              !visited[t.pos][t.last_box + 1][t.candies_eaten]++) {
            next_queue.push_back(t);
          }
        }
      }
    }
    queue = next_queue;
    ++steps;
  }
  cout << -1 << endl;
}
