#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
int n, k1, k2, cnt = 0;
deque<int> p1, p2;

// Checker for potential repeating cycle
void check_cycle_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: cycle_invariant triggered - potential repeating cycle detected!" << endl;
        abort();
    }
}

// Checker for balanced initial distribution
void check_balanced_distribution(bool condition) {
    if (condition) {
        cerr << "Warning: balanced_distribution triggered - potentially balanced stacks detected!" << endl;
        abort();
    }
}

// Checker for equal power stacks
void check_equal_power_stacks(bool condition) {
    if (condition) {
        cerr << "Warning: equal_power_stacks triggered - closely matched card values detected!" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d", &k1);
    for (int i = 1; i <= k1; ++i) {
        int u;
        scanf("%d", &u);
        p1.push_back(u);
    }
    scanf("%d", &k2);
    for (int i = 1; i <= k2; ++i) {
        int u;
        scanf("%d", &u);
        p2.push_back(u);
    }

    // Check for balanced initial distribution
    check_balanced_distribution(abs((int)p1.size() - (int)p2.size()) <= 1);

    // Check for equal power stacks at the start
    vector<int> sorted_p1(p1.begin(), p1.end());
    vector<int> sorted_p2(p2.begin(), p2.end());
    sort(sorted_p1.begin(), sorted_p1.end());
    sort(sorted_p2.begin(), sorted_p2.end());
    bool equal_power_detected = (sorted_p1 == sorted_p2);
    check_equal_power_stacks(equal_power_detected);

    // Simulate the game and detect cycles
    set<pair<deque<int>, deque<int>>> seen_states;
    while (p1.size() != 0 && p2.size() != 0) {
        // Check for a repeating cycle
        check_cycle_invariant(seen_states.count({p1, p2}) > 0);
        seen_states.insert({p1, p2});

        int c1 = p1.front(); p1.pop_front();
        int c2 = p2.front(); p2.pop_front();
        
        if (c1 <= c2) {
            p2.push_back(c1);
            p2.push_back(c2);
        } else {
            p1.push_back(c2);
            p1.push_back(c1);
        }
        cnt++;
        if (cnt == 10000000) break;
        if (p1.size() == 0 || p2.size() == 0) break;
    }
    
    if (p1.size() == 0)
        cout << cnt << " " << "2";
    else if (p2.size() == 0)
        cout << cnt << " " << "1";
    else if (cnt == 10000000)
        cout << "-1";
}