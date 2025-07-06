#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n, c, prec[maxn], x, cnt[maxn];
vector<int> posi[maxn];

void check_max_element_invariant(int mma) {
    if (mma > 400000) {
        cerr << "Warning: Performance bottleneck condition triggered due to high maximum element value!" << endl;
        abort();
    }
}

void check_sparse_elements_invariant(int num_c_elements, int n) {
    if (num_c_elements > n * 0.9) {
        cerr << "Warning: Performance bottleneck due to sparse non-target elements!" << endl;
        abort();
    }
}

void check_excessive_operations_invariant(int meaningful_operations, int mma) {
    if (meaningful_operations < mma * 0.1) {
        cerr << "Warning: Performance bottleneck due to excessive operations with little processing!" << endl;
        abort();
    }
}

int main() {
    int mma = -1;
    scanf("%d%d", &n, &c);
    int num_c_elements = 0; // Count the number of elements equal to `c`
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        mma = max(mma, x);
        prec[i] = prec[i - 1];
        if (x == c) {
            prec[i]++;
            num_c_elements++;
        } else {
            posi[x].push_back(i);
        }
    }

    // Check performance conditions after input processing
    check_max_element_invariant(mma);
    check_sparse_elements_invariant(num_c_elements, n);

    int ans = prec[n];
    int meaningful_operations = 0; // To track how many times the inner loop has meaningful work

    for (int i = 1; i <= mma; i++) {
        if (!posi[i].size()) continue;
        meaningful_operations++;
        int tmp = 0;
        for (int j = 0; j < posi[i].size(); j++) {
            int nowpos = posi[i][j];
            tmp = max(tmp, prec[nowpos - 1] - cnt[i]);
            cnt[i]++;
            ans = max(ans, prec[n] - prec[nowpos] + tmp + cnt[i]);
        }
    }

    // Final check for excessive operations
    check_excessive_operations_invariant(meaningful_operations, mma);

    printf("%d\n", ans);
    return 0;
}