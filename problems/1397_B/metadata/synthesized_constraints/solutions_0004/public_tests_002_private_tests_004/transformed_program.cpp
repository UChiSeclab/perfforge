#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_exponential_growth_invariant(long long c, long long iterations) {
    if (iterations > 1000000) {  // Threshold for excessive iterations
        cerr << "Warning: Exponential growth invariant triggered - excessive iterations due to power growth" << endl;
        abort();
    }
}

void check_large_elements_invariant(vector<long long>& a, long long threshold) {
    long long maxElement = *max_element(a.begin(), a.end());
    if (maxElement > threshold) {
        cerr << "Warning: Large elements invariant triggered - elements significantly larger than expected powers" << endl;
        abort();
    }
}

void check_repeated_adjustments_invariant(long long totalAdjustments) {
    if (totalAdjustments > 1000000) {  // Threshold for excessive adjustments
        cerr << "Warning: Repeated adjustments invariant triggered - excessive adjustments" << endl;
        abort();
    }
}

void solve(vector<long long> a, long long n) {
    long long big = (long long)1e15;
    long long ans = big, c = 1;
    
    // Check for large elements that may cause excessive computations
    check_large_elements_invariant(a, 1000000000);  // Threshold based on input constraints
    
    long long iterations = 0;
    while (1) {
        long long val = 0, pw = 1;
        for (long long i = 0; i < n; i++, pw *= c) {
            if (pw >= big) {
                val = -1;
                break;
            }
            val += abs(pw - a[i]);
        }
        
        // Check for excessive iterations due to exponential power growth
        check_exponential_growth_invariant(c, iterations);
        
        if (val == -1) break;
        ans = min(ans, val);
        c++;
        iterations++;
    }
    
    // Check for high cost due to repeated adjustments
    check_repeated_adjustments_invariant(iterations);
    
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    solve(arr, n);
    return 0;
}