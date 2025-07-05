#include <bits/stdc++.h>
using namespace std;

// Checker functions defined
void check_excessive_fights(long long count) {
    if (count > 1000) {  // Arbitrary threshold for excessive fights
        cerr << "Warning: Performance bottleneck condition triggered - excessive fights!" << endl;
        abort();
    }
}

set<pair<queue<long long>, queue<long long>>> previous_states;

bool check_repeating_state(queue<long long> A, queue<long long> B) {
    pair<queue<long long>, queue<long long>> current_state = {A, B};
    if (previous_states.find(current_state) != previous_states.end()) {
        cerr << "Warning: Performance bottleneck condition triggered - repeating state detected!" << endl;
        abort();
    }
    previous_states.insert(current_state);
    return false;
}

void check_fight_threshold(long long count) {
    if (count == 10'000'000) {  // The loop's hardcoded maximum iterations
        cerr << "Warning: Performance bottleneck condition triggered - fight threshold reached!" << endl;
        abort();
    }
}

int main() {
    long long int n, i, a, b, val;
    cin >> n;
    cin >> a;
    queue<long long int> A, B;
    for (i = 0; i < a; i++) cin >> val, A.push(val);
    cin >> b;
    for (i = 0; i < b; i++) cin >> val, B.push(val);
    long long int count = 0, val1, val2;
    
    // Check the initial state for potential repeating state
    check_repeating_state(A, B);

    for (count = 0; !A.empty() && !B.empty() && count < 10'000'000; count++) {
        val1 = A.front(), val2 = B.front();
        A.pop(), B.pop();
        if (val1 > val2)
            A.push(val2), A.push(val1);
        else
            B.push(val1), B.push(val2);
        
        // Check for repeating state
        check_repeating_state(A, B);
        
        // Check for excessive fights
        if (count % 100 == 0) { // Only check every 100 iterations to reduce overhead
            check_excessive_fights(count);
        }
    }
    
    // Check if the maximum fight threshold is reached
    check_fight_threshold(count);

    if (count == 10'000'000)
        cout << "-1\n";
    else {
        if (A.empty())
            cout << count << " "
                 << "2\n";
        else
            cout << count << " "
                 << "1\n";
    }
    return 0;
}