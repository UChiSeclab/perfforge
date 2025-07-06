#include <bits/stdc++.h>
using namespace std;

std::string getCurrentState(std::queue<int> v1, std::queue<int> v2) {
    std::string state = "V1:";
    while (!v1.empty()) {
        state += std::to_string(v1.front()) + ",";
        v1.pop();
    }
    state += "V2:";
    while (!v2.empty()) {
        state += std::to_string(v2.front()) + ",";
        v2.pop();
    }
    return state;
}

void check_cycle_invariant(std::unordered_set<std::string> &stateHistory, const std::string &currentState) {
    if (stateHistory.find(currentState) != stateHistory.end()) {
        cerr << "Warning: Performance bottleneck condition - cyclic game state detected!" << endl;
        abort();
    }
    stateHistory.insert(currentState);
}

int main() {
    int j, n, a, b, k, c;
    long int i;
    queue<int> v1;
    queue<int> v2;
    cin >> n;
    cin >> a;
    while (a--) {
        cin >> k;
        v1.push(k);
    }
    cin >> b;
    while (b--) {
        cin >> k;
        v2.push(k);
    }

    unordered_set<string> stateHistory;  // To store previous states

    for (i = 0;; i++) {
        // Generate the current state and check for cycles
        string currentState = getCurrentState(v1, v2);
        check_cycle_invariant(stateHistory, currentState);

        if (v1.empty()) {
            printf("%ld 2\n", i);
            return 0;
        }
        if (v2.empty()) {
            printf("%ld 1\n", i);
            return 0;
        }
        if (i > 40000000) {
            printf("-1\n");
            return 0;
        }
        a = v1.front();
        v1.pop();
        b = v2.front();
        v2.pop();
        if (a > b) {
            v1.push(b);
            v1.push(a);
        } else {
            v2.push(a);
            v2.push(b);
        }
    }
    return 0;
}