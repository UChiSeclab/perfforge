#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> q1, q2;

// Check for infinite cycling of cards without termination
void check_cycle_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - infinite cycling of cards detected!" << endl;
        abort();
    }
}

// Check for inefficient queue operations
void check_queue_operation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient queue operations detected!" << endl;
        abort();
    }
}

// Check for persistent player advantage without game termination
void check_player_balance_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - persistent player advantage detected!" << endl;
        abort();
    }
}

int main(int argc, char const *argv[]) {
    time_t t1 = time(NULL);
    cin >> n;
    int cnt1, cnt2;
    cin >> cnt1;
    for (int i = 0; i < cnt1; ++i) {
        int x;
        cin >> x;
        q1.push_back(x);
    }
    cin >> cnt2;
    for (int i = 0; i < cnt2; ++i) {
        int x;
        cin >> x;
        q2.push_back(x);
    }
    int cnt = 0;
    set<pair<vector<int>, vector<int>>> seenStates; // Track seen states to detect cycles

    while (!q1.empty() && !q2.empty()) {
        ++cnt;
        int x1 = q1.front();
        int x2 = q2.front();
        q1.erase(q1.begin());
        q2.erase(q2.begin());

        // Check for inefficient queue operations
        check_queue_operation_invariant(q1.size() > 100 || q2.size() > 100);

        if (x1 > x2) {
            q1.push_back(x2);
            q1.push_back(x1);
        } else {
            q2.push_back(x1);
            q2.push_back(x2);
        }

        // Check for infinite cycles by monitoring repeated states
        pair<vector<int>, vector<int>> currentState = {q1, q2};
        check_cycle_invariant(seenStates.find(currentState) != seenStates.end());
        seenStates.insert(currentState);

        time_t t2 = time(NULL);
        if (t2 - t1 >= 2) break;
        
        // Check for persistent player advantage without termination
        check_player_balance_invariant(cnt > 1000); // Arbitrary threshold to trigger warnings
    }
    
    if (q1.empty())
        cout << cnt << " 2" << endl;
    else if (q2.empty())
        cout << cnt << " 1" << endl;
    else
        cout << "-1" << endl;

    return 0;
}