#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_frequency_distribution(const vector<int>& as) {
    for (size_t i = 1; i < as.size(); ++i) {
        if (as[i] - as[i-1] < 0) {
            cerr << "Warning: Performance bottleneck condition triggered due to non-smooth frequency distribution!" << endl;
            abort();
        }
    }
}

void check_exception_path(const vector<int>& ss) {
    for (size_t i = 1; i < ss.size(); ++i) {
        if (ss[i] != ss[i-1] && ss[i] != ss[i-1] + 1) {
            cerr << "Warning: Exception path triggered due to inappropriate sequence of numbers!" << endl;
            abort();
        }
    }
}

void check_unique_elements(const vector<int>& as) {
    if (as.size() == 1 && as[0] != 1) {
        cerr << "Warning: Unique element series might cause performance bottleneck!" << endl;
        abort();
    }
}

int main() {
    int n;
    while (scanf("%d", &n) >= 1) {
        vector<int> ss(n);
        for (int i = 0; i < n; i++) scanf("%d", &ss[i]);
        sort(ss.begin(), ss.end());

        try {
            vector<int> as;
            int pval = ss[0];
            as.push_back(0);

            for (int i = 0; i < n; i++) {
                if (pval != ss[i]) {
                    if (pval + 1 != ss[i]) throw pval + 1;
                    pval = ss[i];
                    as.push_back(1);
                } else {
                    as[((int)(as).size()) - 1]++;
                }
            }

            check_frequency_distribution(as); // Check frequency distribution invariant

            int n = ((int)(as).size());
            if (n < 2) throw -1;

            int px = as[0];
            for (int i = 1; i < n; i++) {
                int nx = as[i] - px;
                if (nx < 0) throw 0;
                if (!nx && i + 1 < n) throw 0;
                px = nx;
            }
            if (px) throw 0;
            printf("YES\n");
        } catch (...) {
            printf("NO\n");
        }
        break;
    }
    return 0;
}