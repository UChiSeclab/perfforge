#include <bits/stdc++.h>
using namespace std;
int Ha[30];
int N, K;

// Checkers based on performance-characterizing invariants
void check_exponential_growth_invariant(int K) {
    if ((1 << (1 << K)) > 1000000) { // Threshold chosen to imply large combination space
        cerr << "Warning: Exponential growth invariant triggered - too many combinations!" << endl;
        abort();
    }
}

void check_input_space_invariant(int n, int K) {
    if (n > 100 && K == 4) { // Threshold for high complexity due to input size and maximum teams
        cerr << "Warning: Input space invariant triggered - large search space!" << endl;
        abort();
    }
}

void check_problem_set_invariant(int cnt, int K) {
    if (cnt > (1 << K) / 2) { // Threshold for inefficient evaluation of problem sets
        cerr << "Warning: Problem set invariant triggered - inefficient evaluation!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d", &N, &K);

    // Check input space complexity before proceeding
    check_input_space_invariant(N, K);

    for (int i = 1; i <= N; i++) {
        int s = 0;
        for (int j = 1; j <= K; j++) {
            int x;
            scanf("%d", &x);
            s = (s << 1) + x;
        }
        Ha[s]++;
    }

    // Check exponential growth in combinations
    check_exponential_growth_invariant(K);

    for (int s = 1; s < (1 << (1 << K)); s++) {
        int sum[4] = {0}, cnt = 0;
        bool can = true;
        for (int i = 0; i < (1 << K); i++) {
            if ((s >> i) & 1) {
                cnt++;
                if (!Ha[i]) can = false;
                for (int t = 0; t < 4; t++) sum[t] += (i >> t) & 1;
            }
        }
        if (!can) continue;

        // Check problem set evaluation inefficiency
        check_problem_set_invariant(cnt, K);

        bool ok = true;
        for (int i = 0; i < 4; i++) {
            if (sum[i] <= cnt / 2)
                ;
            else
                ok = false;
        }
        if (ok) return puts("YES"), 0;
    }
    puts("NO");
    return 0;
}