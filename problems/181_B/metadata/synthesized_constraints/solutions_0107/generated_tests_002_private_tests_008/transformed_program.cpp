#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_iteration_invariant(int n) {
    if (n > 2500) { // Threshold close to the upper limit of n (3000)
        cerr << "Warning: High iteration invariant triggered - n is large, causing too many computations!" << endl;
        abort();
    }
}

void check_frequent_lookup_invariant(int cnt) {
    if (cnt > 10000) { // Arbitrary threshold for excessive midpoint checks
        cerr << "Warning: Frequent set lookup invariant triggered - excessive midpoint existence checks!" << endl;
        abort();
    }
}

void check_point_distribution_invariant(int numMidpoints, int n) {
    if (numMidpoints > n / 2) { // If more than half of potential midpoints exist
        cerr << "Warning: Point distribution invariant triggered - many midpoints exist among the original points!" << endl;
        abort();
    }
}

int main() {
    pair<double, double> p;
    set<pair<double, double>> s;
    set<pair<double, double>>::iterator it;
    int n, cnt = 0;
    
    cin >> n;
    
    // Check for high iteration potentially causing performance issues
    check_high_iteration_invariant(n);
    
    for (int i = 0; i < n; i++) {
        cin >> p.first >> p.second;
        s.insert(p);
    }
    
    int potentialMidpointsCount = 0;
    
    for (set<pair<double, double>>::iterator it1 = s.begin(); it1 != s.end(); it1++) {
        for (set<pair<double, double>>::iterator it2 = next(it1, 1); it2 != s.end(); it2++) {
            p.first = ((*it1).first + (*it2).first) / 2;
            p.second = ((*it1).second + (*it2).second) / 2;
            it = s.find(p);
            if (it != s.end() && it != it1 && it != it2) {
                cnt++;
                potentialMidpointsCount++;
            }
        }
    }
    
    // Check for frequent lookups
    check_frequent_lookup_invariant(cnt);
    
    // Check for point distribution issues
    check_point_distribution_invariant(potentialMidpointsCount, n);
    
    cout << cnt;
    return 0;
}