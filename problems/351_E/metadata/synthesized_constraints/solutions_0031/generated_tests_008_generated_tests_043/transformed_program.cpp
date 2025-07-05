#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int MAX = 1e6 + 5;
int n, x[MAX], ans, nw, a, b;

// Checker functions

void check_large_sequence_invariant(int n) {
    if (n > 1500) { // Threshold chosen to be closer to the upper bound, but not exact limit
        cerr << "Warning: Performance bottleneck due to large sequence size!" << endl;
        abort();
    }
}

void check_frequent_sign_changes(const vector<int>& x) {
    int sign_change_count = 0;
    for (size_t i = 1; i < x.size(); ++i) {
        if (x[i] * x[i - 1] < 0) {
            ++sign_change_count;
        }
    }
    if (sign_change_count > (x.size() / 2)) { // Arbitrary threshold to indicate frequent changes
        cerr << "Warning: Performance bottleneck due to frequent sign changes!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int n) {
    if (n * n > 2500000) { // Quadratic complexity threshold
        cerr << "Warning: Performance bottleneck due to excessive nested loop operations!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    // Place the invariant checks after the input is read
    check_large_sequence_invariant(n);
    
    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i) cin >> x[i], x[i] = abs(x[i]);
    
    check_frequent_sign_changes(x);
    check_nested_loop_invariant(n);
    
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (x[i] < x[j]) ++ans;
    
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (x[i] > x[j]) ++nw;
    
    ans = min(ans, nw);
    
    for (int i = 1; i <= n; ++i) {
        a = b = 0;
        
        for (int j = i - 1; j >= 1; --j)
            if (x[i] < x[j]) ++a;
        
        for (int j = i + 1; j <= n; ++j)
            if (x[i] > x[j]) ++a;
        
        for (int j = i - 1; j >= 1; --j)
            if (-x[i] < x[j]) ++b;
        
        for (int j = i + 1; j <= n; ++j)
            if (-x[i] > x[j]) ++b;
        
        if (a > b) x[i] = -x[i], nw += -a + b;
        
        ans = min(ans, nw);
    }
    
    nw = 0;
    for (int i = 1; i <= n; ++i) x[i] = abs(x[i]);
    
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (x[i] > x[j]) ++nw;
    
    for (int i = 1; i <= n; ++i) {
        a = b = 0;
        
        for (int j = i - 1; j >= 1; --j)
            if (x[i] < x[j] && abs(x[j]) != x[i]) ++a;
        
        for (int j = i + 1; j <= n; ++j)
            if (x[i] > x[j] && abs(x[j]) != x[i]) ++a;
        
        for (int j = i - 1; j >= 1; --j)
            if (-x[i] < x[j] && abs(x[j]) != x[i]) ++b;
        
        for (int j = i + 1; j <= n; ++j)
            if (-x[i] > x[j] && abs(x[j]) != x[i]) ++b;
        
        if (a > b) {
            a = b = 0;
            for (int j = i - 1; j >= 1; --j)
                if (x[i] < x[j]) ++a;
            
            for (int j = i + 1; j <= n; ++j)
                if (x[i] > x[j]) ++a;
            
            for (int j = i - 1; j >= 1; --j)
                if (-x[i] < x[j]) ++b;
            
            for (int j = i + 1; j <= n; ++j)
                if (-x[i] > x[j]) ++b;
            
            x[i] = -x[i], nw += -a + b;
        }
        ans = min(ans, nw);
    }
    
    nw = 0;
    for (int i = 1; i <= n; ++i) x[i] = abs(x[i]);
    
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (x[i] > x[j]) ++nw;
    
    for (int i = 1; i <= n; ++i) {
        a = b = 0;
        
        for (int j = i - 1; j >= 1; --j)
            if (x[i] < x[j]) ++a;
        
        for (int j = i + 1; j <= n; ++j)
            if (x[i] > x[j]) ++a;
        
        for (int j = i - 1; j >= 1; --j)
            if (-x[i] < x[j]) ++b;
        
        for (int j = i + 1; j <= n; ++j)
            if (-x[i] > x[j]) ++b;
        
        x[i] = -x[i], nw += -a + b;
        ans = min(ans, nw);
    }
    
    cout << ans << '\n';
    return 0;
}