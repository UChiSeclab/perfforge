#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_server_availability_invariant(int n, int d) {
    if (n * d > 10000) { // Threshold can be adjusted based on expected load
        cerr << "Warning: Server availability check invariant triggered - high check frequency!" << endl;
        abort();
    }
}

void check_server_marking_invariant(int n, int d) {
    if (n * d > 10000) { // Threshold can be adjusted based on expected load
        cerr << "Warning: Server marking invariant triggered - frequent state updates!" << endl;
        abort();
    }
}

void check_task_overlap_invariant(int n, int d, int k) {
    if ((n - k) * d < 0) { // If k servers are needed, but n-k is small, causing overlap
        cerr << "Warning: Task overlap invariant triggered - insufficient free servers!" << endl;
        abort();
    }
}

bool s[105][1001005];
int n, q;
int t, k, d;

int main() {
    scanf("%d%d", &n, &q);
    memset(s, true, sizeof s);

    for (int i = 0; i < q; i++) {
        scanf("%d%d%d", &t, &k, &d);

        // Check performance invariants
        check_server_availability_invariant(n, d);
        check_server_marking_invariant(n, d);
        check_task_overlap_invariant(n, d, k);

        vector<int> v;
        for (int j = 0; j < n; j++) {
            bool bisa = true;
            for (int l = t; l < t + d; l++) {
                bisa = (bisa && s[j][l]);
            }
            if (bisa) v.push_back(j);
        }
        if (v.size() >= k) {
            int sum = 0;
            for (int j = 0; j < k; j++) {
                sum += v[j] + 1;
                for (int l = t; l < t + d; l++) {
                    s[v[j]][l] = false;
                }
            }
            printf("%d\n", sum);
        } else {
            printf("-1\n");
        }
    }
}