#include <bits/stdc++.h>
using namespace std;

// Checker for excessive iterations indicating potential cycle
void check_cycle_invariant(int iterationCount, const deque<long long>& a, const deque<long long>& b) {
    if (iterationCount > 1000000) { // Example threshold to indicate non-termination
        cerr << "Warning: cycle_invariant triggered - excessive iterations indicating potential cycle" << endl;
        abort();
    }
}

// Checker for balanced decks potentially causing prolonged gameplay
void check_balanced_invariant(const deque<long long>& a, const deque<long long>& b) {
    if (a.size() == b.size() && a.size() > 1) { // Example condition: both players have similar deck sizes
        cerr << "Warning: balanced_invariant triggered - balanced decks may cause prolonged gameplay" << endl;
        abort();
    }
}

// Checker for upper limit on iterations
void check_iteration_invariant(int iterationCount) {
    if (iterationCount >= 10000000) { // Upper limit on iterations
        cerr << "Warning: iteration_invariant triggered - exceeded maximum iteration limit" << endl;
        abort();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n;
    cin >> n;
    deque<long long> a;
    deque<long long> b;
    long long c;
    cin >> c;
    for (long long i = 0; i < c; i++) {
        long long d;
        cin >> d;
        a.push_back(d);
    }
    long long d;
    cin >> d;
    for (long long i = 0; i < d; i++) {
        long long e;
        cin >> e;
        b.push_back(e);
    }
    
    long long tot = 0;
    
    // Check for balanced decks
    check_balanced_invariant(a, b);
    
    while (!a.empty() && !b.empty()) {
        long long e = a.front();
        long long f = b.front();
        a.pop_front();
        b.pop_front();
        
        if (e > f) {
            a.push_back(f);
            a.push_back(e);
        } else {
            b.push_back(e);
            b.push_back(f);
        }
        
        tot++;
        
        // Check for excessive iterations or potential cycle
        check_cycle_invariant(tot, a, b);
        
        // Check for iteration limit
        check_iteration_invariant(tot);
    }
    
    if (tot >= 10000000) {
        cout << -1 << endl;
        return 0;
    } else {
        cout << tot << ' ';
    }
    
    if (a.empty()) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
}