#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MAXX = 1e6;
int cnt[MAXX + 10];
int pcnt[MAXX + 10];

void check_uniqueness_invariant(int asz, int n) {
    if (asz > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - too many unique elements!" << endl;
        abort();
    }
}

void check_element_gap_invariant(const vector<int>& a) {
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] - a[i-1] > 10000) {  // arbitrary large gap threshold
            cerr << "Warning: Performance bottleneck condition triggered - large gaps between elements!" << endl;
            abort();
        }
    }
}

void check_binary_search_invariant(int smallest, int largest) {
    if (smallest < largest / 100) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive binary search range!" << endl;
        abort();
    }
}

void check_high_value_distribution(const vector<int>& a) {
    int high_count = 0;
    for (int value : a) {
        if (value > 900000) {
            high_count++;
        }
    }
    if (high_count > a.size() / 4) {  // arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered - too many high values!" << endl;
        abort();
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 1) continue;
        a.push_back(x);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int asz = a.size();

    // Check for high value distribution
    check_high_value_distribution(a);

    // Check for element gap invariant
    check_element_gap_invariant(a);

    for (int i = 0; i < asz; i++) cnt[a[i]]++;
    for (int i = 1; i <= MAXX; i++) {
        pcnt[i] = pcnt[i - 1] + cnt[i];
    }
    
    int ans = 0;
    for (int i = asz - 1; i >= 0; i--) {
        // Check for binary search efficiency
        check_binary_search_invariant(a[0], a[i]);

        for (int j = a[i]; j <= MAXX; j += a[i]) {
            int L = j, R = min(MAXX, j + a[i] - 1);
            while (L <= R) {
                int M = (R + L) / 2;
                int ccnt = pcnt[min(MAXX, j + a[i] - 1)] - pcnt[M - 1];
                if (ccnt > 0)
                    L = M + 1;
                else
                    R = M - 1;
            }
            if (R >= j) {
                ans = max(ans, R - j);
            }
        }
    }

    // Check for array uniqueness
    check_uniqueness_invariant(asz, n);

    printf("%d", ans);
    return 0;
}