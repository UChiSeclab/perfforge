#include <bits/stdc++.h>
using namespace std;

void check_multiset_operations(int q_size, int k) {
    if (q_size == k) {
        cerr << "Warning: Performance bottleneck triggered by excessive multiset operations!" << endl;
        abort();
    }
}

void check_iteration_complexity(int i, long long S, long long b) {
    if (i > 0 && S > b) {
        cerr << "Warning: Performance bottleneck due to high iterative complexity!" << endl;
        abort();
    }
}

void check_budget_constraints(long long remaining_budget, int iteration_count) {
    if (remaining_budget < 10000 && iteration_count > 50) { // Example thresholds
        cerr << "Warning: Performance bottleneck due to tight budget constraints!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    k--;
    long long b;
    cin >> b;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    n--;
    long long S = 0;
    multiset<long long> p, q;
    
    for (int i = 1; i < n; i++) {
        q.insert(a[i]);
        S += a[i];
    }
    
    while (((int)(q).size()) != k) {
        S -= *q.begin();
        p.insert(*q.begin());
        q.erase(q.begin());
    }
    
    // Insert check for first invariant
    check_multiset_operations((int)q.size(), k);
    
    // Insert check for second invariant
    check_iteration_complexity(0, S + a[0], b);
    
    if (S + a[0] > b) {
        cout << 1 << endl;
        return 0;
    }
    
    for (int i = 1; i < n; i++) {
        if (q.find(a[i]) != q.end()) {
            S -= a[i];
            q.erase(q.find(a[i]));
        } else {
            p.erase(p.find(a[i]));
        }
        
        if (((int)(p).size()) == 0 || a[i - 1] >= *p.rbegin()) {
            S += a[i - 1];
            q.insert(a[i - 1]);
        }
        
        while (((int)(q).size()) > k) {
            S -= *q.begin();
            p.insert(*q.begin());
            q.erase(q.begin());
        }
        
        while (((int)(q).size()) < k) {
            long long tmp = *p.rbegin();
            S += tmp;
            p.erase(p.find(tmp));
            q.insert(tmp);
        }
        
        // Insert check for second invariant within the loop
        check_iteration_complexity(i, S + a[i], b);
        
        if (S + a[i] > b) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    
    // Insert final check for budget constraints before exiting
    check_budget_constraints(b - S, n);
    
    cout << n + 1 << endl;
    return 0;
}