#include <bits/stdc++.h>
using namespace std;
const int kInf = 1e9;

// Checkers
void check_large_x_small_denoms(int x, const vector<int>& a, int k) {
    if (x > 1e8 && a.back() <= 10 && k == 20) {
        cerr << "Warning: Large x with small denominations triggered!" << endl;
        abort();
    }
}

void check_high_k_bills(int k) {
    if (k == 20) {
        cerr << "Warning: High maximum k bills triggered!" << endl;
        abort();
    }
}

void check_dominant_small_denoms(const vector<int>& a, int x) {
    if (a.size() == 1 && a[0] <= 10 && x > 1e8) {
        cerr << "Warning: Dominance of small denominations triggered!" << endl;
        abort();
    }
}

void check_wide_range_x(const vector<int>& x_values) {
    int min_x = *min_element(x_values.begin(), x_values.end());
    int max_x = *max_element(x_values.begin(), x_values.end());
    if (max_x - min_x > 1e8) {
        cerr << "Warning: Wide range of x values triggered!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& ai : a) cin >> ai;
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    vector<int> x_values(q);
    for (int qi = 0; qi < q; ++qi) {
        cin >> x_values[qi];
    }
    
    // Insert checkers
    check_high_k_bills(k); // Check for high k values
    check_wide_range_x(x_values); // Check for wide range of x values
    
    for (int qi = 0; qi < q; ++qi) {
        int x = x_values[qi];
        
        // Insert checkers for conditions dependent on each x
        check_large_x_small_denoms(x, a, k); // Check for large x with small denominations
        check_dominant_small_denoms(a, x); // Check for dominance of small denominations
        
        int answer = kInf;
        for (int cnt = 1; cnt <= k; ++cnt) {
            for (int cnt1 = 1; cnt1 <= cnt; cnt1++) {
                int cnt2 = cnt - cnt1;
                vector<int> b = a;
                for (int& bi : b) bi *= cnt2;
                int it = b.size() - 1;
                for (const int& ai : a) {
                    int rem = x - ai * cnt1;
                    if (rem == 0) answer = min(answer, cnt1);
                    if (rem < 0) break;
                    while (it >= 0 && b[it] > rem) it--;
                    if (it >= 0 && b[it] == rem) answer = min(answer, cnt);
                }
            }
        }
        if (answer == kInf) answer = -1;
        cout << answer << endl;
    }
    return 0;
}