#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_cyclical_exchange(bool condition, int iteration) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - cyclical card exchanges detected at iteration " << iteration << "!" << endl;
        abort();
    }
}

void check_balanced_distribution(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - balanced initial card distribution!" << endl;
        abort();
    }
}

void check_large_iterations(bool condition, int iteration) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations in game loop at iteration " << iteration << "!" << endl;
        abort();
    }
}

int main() {
    int n, k1, k2, x, y, i;
    cin >> n;
    queue<int> q1;
    queue<int> q2;
    cin >> k1;
    for (i = 0; i < k1; i++) {
        cin >> x;
        q1.push(x);
    }
    cin >> k2;
    for (i = 0; i < k2; i++) {
        cin >> x;
        q2.push(x);
    }

    // Check for balanced initial distribution
    // This is a simplistic check assuming if both players have half of the cards, it might be balanced.
    check_balanced_distribution(k1 == k2);

    set<pair<vector<int>, vector<int>>> previous_states; // Track previous states to detect cycles
    for (i = 1; i <= 40000000; i++) {
        x = q1.front();
        q1.pop();
        y = q2.front();
        q2.pop();
        if (x > y) {
            q1.push(y);
            q1.push(x);
        } else if (y > x) {
            q2.push(x);
            q2.push(y);
        }
        if (q1.empty()) break;
        if (q2.empty()) break;

        // Detect cyclical exchanges
        vector<int> state_q1, state_q2;
        queue<int> temp1 = q1, temp2 = q2;
        while (!temp1.empty()) { state_q1.push_back(temp1.front()); temp1.pop(); }
        while (!temp2.empty()) { state_q2.push_back(temp2.front()); temp2.pop(); }
        check_cyclical_exchange(previous_states.count({state_q1, state_q2}) > 0, i);
        previous_states.insert({state_q1, state_q2});

        // Check for excessive iterations
        check_large_iterations(i >= 1000000, i);  // Example threshold
    }

    if (q1.empty())
        cout << i << " "
             << "2" << endl;
    else if (q2.empty())
        cout << i << " "
             << "1" << endl;
    else
        cout << "-1" << endl;

    return 0;
}