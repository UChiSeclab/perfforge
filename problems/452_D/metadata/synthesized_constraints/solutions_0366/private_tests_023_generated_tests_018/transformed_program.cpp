#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_machine_utilization(int k, int n1, int n2, int n3) {
    if (k > n1 * n2 * n3) {
        cerr << "Warning: Machine utilization invariant triggered - high demand relative to machine capacity!" << endl;
        abort();
    }
}

void check_processing_times(int t1, int t2, int t3) {
    if (t1 + t2 + t3 > 3 * min(t1, min(t2, t3))) {
        cerr << "Warning: Sequential processing invariant triggered - slow turnover due to processing times!" << endl;
        abort();
    }
}

void check_array_management(int k, int n1, int n2, int n3) {
    if (k > (n1 + n2 + n3)) {
        cerr << "Warning: Array management invariant triggered - excessive checks due to high number of items!" << endl;
        abort();
    }
}

int main() {
    int k, n1, n2, n3, t1, t2, t3, t, num;
    int a[10000], b[10000], c[10000], l, r;
    
    scanf("%d%d%d%d%d%d%d", &k, &n1, &n2, &n3, &t1, &t2, &t3);

    // Insert checks after reading input values
    check_machine_utilization(k, n1, n2, n3);
    check_processing_times(t1, t2, t3);
    check_array_management(k, n1, n2, n3);

    for (t = 0; l < k; t++) {
        while (r < k && check1(t) && check2(t + t1) && check3(t + t1 + t2)) {
            a[r] = t + t1;
            b[r] = t + t1 + t2;
            c[r] = t + t1 + t2 + t3;
            r++;
        }
        while (t == c[l] && l <= r) l++;
    }
    printf("%d\n", t - 1);
}