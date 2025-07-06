#include <bits/stdc++.h>
using namespace std;

// Checker for large n and excessive division operations
void check_large_n_divisions(long long n, long long curr) {
    if (n >= 1e9 && curr > n / 1000) {
        cerr << "Warning: Performance bottleneck due to large n causing too many division operations!" << endl;
        abort();
    }
}

// Checker for frequent set insertions
void check_frequent_set_insertions(long long n, long long curr, const set<long long>& used) {
    if (used.size() > 100000 && curr > n / 1000) {
        cerr << "Warning: Performance bottleneck due to frequent set insertions!" << endl;
        abort();
    }
}

// Checker for excessive loop iterations
void check_loop_execution_count(long long n, long long curr) {
    if (curr > n / 1000) {
        cerr << "Warning: Performance bottleneck due to excessive loop iterations!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        set<long long> ans;
        set<long long> used;
        ans.insert(0);
        ans.insert(1);
        ans.insert(n);
        long long curr = 2;

        // Place checks before the loop to catch initial conditions
        check_large_n_divisions(n, curr);
        check_frequent_set_insertions(n, curr, used);
        
        while (used.find(curr) == used.end() && curr <= n / 2) {
            long long aux = n / curr;
            long long aux2 = n / aux;
            ans.insert(aux);
            ans.insert(aux2);
            used.insert(curr);
            used.insert(aux);
            
            // Check within the loop to catch dynamic conditions
            check_loop_execution_count(n, curr);
            
            curr++;
        }
        
        cout << ans.size() << "\n";
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}