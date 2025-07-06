#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_combination_invariant(int n) {
    if (n >= 50) {
        cerr << "Warning: Performance bottleneck condition triggered due to high combination complexity!" << endl;
        abort();
    }
}

void check_sorting_invariant(int sortCount) {
    if (sortCount > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered due to redundant sorting!" << endl;
        abort();
    }
}

void check_instability_calc_invariant(int calcIterations) {
    if (calcIterations > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive instability calculations!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    
    // Check invariant for combination complexity
    check_combination_invariant(n);
    
    vector<int> cnt;
    for (int i = 0; i < n * 2; i++) {
        int x;
        cin >> x;
        cnt.push_back(x);
    }
    
    int ans = INT_MAX;
    int sortCount = 0;  // Track number of sorts
    int calcIterations = 0;  // Track number of calculations
    
    for (int i = 0; i < cnt.size(); i++) {
        for (int e = 0; e < cnt.size(); e++) {
            if (i != e) {
                vector<int> tmp;
                for (int j = 0; j < cnt.size(); j++) {
                    if (j != e && j != i) {
                        tmp.push_back(cnt[j]);
                    }
                }
                sort(tmp.begin(), tmp.end());
                sortCount++;
                
                // Check invariant for redundant sorting
                check_sorting_invariant(sortCount);
                
                int t = 0;
                for (int j = 1; j < tmp.size(); j += 2) {
                    t += (tmp[j] - tmp[j - 1]);
                    calcIterations++;
                }
                
                // Check invariant for excessive instability calculations
                check_instability_calc_invariant(calcIterations);
                
                ans = min(ans, t);
            }
        }
    }
    cout << ans;
    return 0;
}