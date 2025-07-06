#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_laundry_machine_ratio(int k, int n1, int n2, int n3) {
    if (k > 10 * std::min({n1, n2, n3})) {  // Arbitrary threshold
        cerr << "Warning: Performance bottleneck - High laundry to machine ratio!" << endl;
        abort();
    }
}

void check_workload_imbalance(int t1, int t2, int t3) {
    if ((t1 > 10 * t2) || (t1 > 10 * t3) || (t2 > 10 * t1) || (t2 > 10 * t3) || (t3 > 10 * t1) || (t3 > 10 * t2)) {
        cerr << "Warning: Performance bottleneck - Workload imbalance between stages!" << endl;
        abort();
    }
}

void check_frequent_vector_access(const vector<int>& f) {
    if (f.size() > 1000) {  // Threshold for detecting large size
        cerr << "Warning: Performance bottleneck - Frequent access to large vector!" << endl;
        abort();
    }
}

int k, n1, n2, n3, t1, t2, t3;
int t = 0;
vector<int> f;

bool can(int x) {
    int c1 = f.end() - upper_bound(f.begin(), f.end(), t + x - t1);
    int c2 = f.end() - upper_bound(f.begin(), f.end(), t + x - t2);
    int c3 = f.end() - upper_bound(f.begin(), f.end(), t + x - t3);
    if (c1 >= n1) return false;
    if (c2 >= n2) return false;
    if (c3 >= n3) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    
    // Insert checkers after reading inputs
    check_high_laundry_machine_ratio(k, n1, n2, n3);
    check_workload_imbalance(t1, t2, t3);

    for (int p = 1; p <= k; p++) {
        int l = 0;
        int r = 1000 * 1000;
        while (l < r) {
            int m = (l + r) / 2;
            if (can(m))
                r = m;
            else
                l = m + 1;
        }
        t += l;
        f.push_back(t);

        // Check vector after each addition
        check_frequent_vector_access(f);
    }

    cout << t + t1 + t2 + t3;
    return 0;
}