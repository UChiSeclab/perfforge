#include <bits/stdc++.h>
using namespace std;

// Checkers based on derived invariants
void check_unique_density_invariant(long long n, const std::set<long long>& s) {
    long long uniqueCount = s.size();
    long long threshold = std::sqrt(n); // Example threshold based on a heuristic
    if (uniqueCount < threshold) {
        cerr << "Warning: Performance bottleneck condition triggered by low unique value density!" << endl;
        abort();
    }
}

void check_set_growth_invariant(long long n, const std::set<long long>& s) {
    long long setSize = s.size();
    if (setSize > std::log2(n) * 10) { // Example threshold using logarithmic growth
        cerr << "Warning: Performance bottleneck condition triggered by rapid set growth!" << endl;
        abort();
    }
}

void check_redundant_calculation_invariant(long long n, long long divisorRange) {
    if (divisorRange > std::log2(n) * 100) { // Example threshold using divisor range
        cerr << "Warning: Performance bottleneck condition triggered by redundant calculations!" << endl;
        abort();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--) {
        long long n, n1, a;
        cin >> n;
        set<long long> s;
        n1 = n;
        if (n > 1000000) {
            n1 = 1000000;
            a = n / pow(10, 6);
            for (long long i = 1; i < a + 1; i++) s.insert(i);
        }
        
        for (long long i = 1; i < n1 + 1; i++) {
            s.insert(n / i);
        }
        
        // Place checks after generating the set to analyze set characteristics
        check_unique_density_invariant(n, s); // Check unique density
        check_set_growth_invariant(n, s); // Check set growth
        check_redundant_calculation_invariant(n, n1); // Check for redundant calculations
        
        s.insert(0);
        cout << s.size() << endl;
        for (auto i = s.begin(); i != s.end(); i++) cout << *i << " ";
        cout << endl;
    }
}