#include <bits/stdc++.h>
using namespace std;

// Checker for repetitive state invariant
void check_repetitive_state_invariant(long long ans) {
    if (ans > 1000) {  // Arbitrary threshold for demonstration
        cerr << "Warning: repetitive_state_invariant triggered - game may enter a repetitive state with no progress!" << endl;
        abort();
    }
}

// Checker for cyclic sequence invariant
void check_cyclic_sequence_invariant(set<pair<queue<long long int>, queue<long long int>>> &previousStates, queue<long long int> &q1, queue<long long int> &q2) {
    if (previousStates.find({q1, q2}) != previousStates.end()) {
        cerr << "Warning: cyclic_sequence_invariant triggered - potential cyclic sequence detected!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    long long int k1, k2;
    cin >> k1;
    queue<long long int> q1;
    for (__typeof(k1) i = 0; i != k1; ++i) {
        long long int a;
        cin >> a;
        q1.push(a);
    }
    cin >> k2;
    queue<long long int> q2;
    for (__typeof(k2) i = 0; i != k2; ++i) {
        long long int a;
        cin >> a;
        q2.push(a);
    }

    long long int ans = 0;
    set<pair<queue<long long int>, queue<long long int>>> previousStates;

    while (!q1.empty() && !q2.empty()) {
        check_repetitive_state_invariant(ans); // Checking for excessive iterations

        // Record the current state and check for cycles
        check_cyclic_sequence_invariant(previousStates, q1, q2);
        previousStates.insert({q1, q2});

        long long int a = q1.front();
        long long int b = q2.front();
        if (ans > 4e7) {
            cout << -1;
            return 0;
        }
        if (a < b) {
            q2.push(a);
            q2.push(b);
        } else {
            q1.push(b);
            q1.push(a);
        }
        q1.pop();
        q2.pop();
        ans++;
    }

    cout << ans << " ";
    if (q1.empty())
        cout << 2;
    else
        cout << 1;
    return 0;
}