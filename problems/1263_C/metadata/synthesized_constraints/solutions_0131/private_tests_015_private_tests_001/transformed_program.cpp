#include <bits/stdc++.h>
using namespace std;

// Performance-checker functions
void check_sqrt_dependency(int n) {
    int i = sqrt(n);
    if (i > 1000) {  // Threshold check
        cerr << "Warning: Performance bottleneck due to large sqrt(n) value!" << endl;
        abort();
    }
}

void check_set_operations(const set<int>& s) {
    if (s.size() > 1000) {  // Threshold check
        cerr << "Warning: Performance bottleneck due to large set size!" << endl;
        abort();
    }
}

void check_loop_iterations(int iterationCount) {
    if (iterationCount > 5000) {  // Threshold check
        cerr << "Warning: Performance bottleneck due to excessive loop iterations!" << endl;
        abort();
    }
}

void check_output_volume(const set<int>& s) {
    if (s.size() > 1000) {  // Threshold check
        cerr << "Warning: Performance bottleneck due to large output volume!" << endl;
        abort();
    }
}

void search(int n) {
    check_sqrt_dependency(n);  // Check sqrt dependency before loop
    
    int i = sqrt(n);
    set<int> s = {0};
    int mid;
    int iterationCount = 0;  // Track loop iterations

    while (i >= 1) {
        iterationCount++;
        if (s.count(n / i) == 0) {
            s.insert(n / i);
            check_set_operations(s);  // Check set size after insertion
        }
        if (s.count(i) == 0) {
            s.insert(i);
            check_set_operations(s);  // Check set size after insertion
        }
        mid = i / 2;
        if (mid == 0) break;
        if (n / mid == n / i + 1) {
            i = mid - 1;
            if (s.count(n / mid) == 0) {
                s.insert(n / mid);
                check_set_operations(s);  // Check set size after insertion
            }
        } else
            i--;
    }
    
    check_loop_iterations(iterationCount);  // Check total iterations

    cout << s.size() << "\n";
    for (auto it = s.begin(); it != s.end(); ++it) cout << *it << " ";
    cout << "\n";
    
    check_output_volume(s);  // Check output volume
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        search(n);
    }
    return 0;
}