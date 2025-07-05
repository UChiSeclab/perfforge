#include <bits/stdc++.h>
using namespace std;

int cnt[5];

long long Solve() {
    long long ans = 0;
    for (;;) {
        if (cnt[0] && cnt[2] && cnt[3]) {
            ans += 256;
            --cnt[0];
            --cnt[2];
            --cnt[3];
        } else if (cnt[0] && cnt[1]) {
            ans += 32;
            --cnt[0];
            --cnt[1];
        } else
            break;
    }
    return ans;
}

void check_excessive_iterations(int k2, int k5, int k6) {
    if (k2 > 1000000 && k5 > 1000000 && k6 > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive iterations!" << endl;
        abort();
    }
}

void check_imbalance(int k2, int k3, int k5, int k6) {
    if ((k2 > 1000000 || k5 > 1000000 || k6 > 1000000) && k3 < k2 / 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to imbalance in digit counts!" << endl;
        abort();
    }
}

void check_input_constraints(int k2, int k3, int k5, int k6) {
    if (k2 > 4000000 && k3 > 4000000 && k5 > 4000000 && k6 > 4000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to maximum input constraints!" << endl;
        abort();
    }
}

int main() {
    int k2, k3, k5, k6;
    scanf("%d%d%d%d", &k2, &k3, &k5, &k6);
    // Set the counts
    cnt[0] = k2; cnt[1] = k3; cnt[2] = k5; cnt[3] = k6;
    
    // Perform the checks
    check_excessive_iterations(k2, k5, k6);
    check_imbalance(k2, k3, k5, k6);
    check_input_constraints(k2, k3, k5, k6);

    cout << Solve() << endl;
    return 0;
}