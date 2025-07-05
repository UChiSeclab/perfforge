#include <bits/stdc++.h>
using namespace std;

bool visited[50][51][2000];
struct State {
  int pos;
  int last_box;
  int candies_eaten;
};

// Checker functions to implement the invariants
void check_high_state_transition(int steps, int maxStepsThreshold) {
    if (steps > maxStepsThreshold) {
        cerr << "Warning: High state transition detected!" << endl;
        abort();
    }
}

void check_complex_path_navigation(int exploredStates, int maxStatesThreshold) {
    if (exploredStates > maxStatesThreshold) {
        cerr << "Warning: Complex path navigation detected!" << endl;
        abort();
    }
}

void check_inefficient_movement(int repeatedMoves, int maxRepeatedMovesThreshold) {
    if (repeatedMoves > maxRepeatedMovesThreshold) {
        cerr << "Warning: Inefficient movement detected!" << endl;
        abort();
    }
}

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
  int totalStateTransitions = 0;  // Track total state transitions
  int totalExploredStates = 0;    // Track total explored states
  
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
            totalStateTransitions++;  // Increment for each state considered valid
          }
        }
      }
      totalExploredStates++;
    }
    
    queue = next_queue;
    ++steps;

    // Insert checker calls after each main loop iteration
    check_high_state_transition(steps, 500);  // Arbitrary threshold for steps
    check_complex_path_navigation(totalExploredStates, 10000);  // Arbitrary threshold for explored states
    check_inefficient_movement(totalStateTransitions, 20000);  // Arbitrary threshold for state transitions
  }

  cout << -1 << endl;
}