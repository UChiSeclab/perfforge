#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 5000 + 5;
const int MOD = 1e9 + 7;
char s[maxn], t[maxn], ss[maxn];
int next_[10010];
int ans;

// Implementation of invariant checks
void check_nested_loop_invariant(int len1) {
    if (len1 > 150) {
        cerr << "Warning: Performance bottleneck due to nested loops with large input size!" << endl;
        abort();
    }
}

void check_string_reconstruction_invariant(int len1, int len2) {
    if (len1 > 150 && len2 < 10) {
        cerr << "Warning: Performance bottleneck due to frequent string reconstruction!" << endl;
        abort();
    }
}

void check_subsequence_verification_invariant(int len1, int len2) {
    if (len1 * len2 > 10000) {
        cerr << "Warning: Performance bottleneck due to exhaustive subsequence verification!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    int len1 = strlen(s), len2 = strlen(t);

    // Insert invariant checks
    check_nested_loop_invariant(len1);
    check_string_reconstruction_invariant(len1, len2);
    check_subsequence_verification_invariant(len1, len2);

    for (int i = 0; i <= len1 - 1; i++) {
        for (int j = i; j <= len1 - 1; j++) {
            int cur = 0;
            for (int k = 0; k <= len1 - 1; k++) {
                if (k < i || k > j) ss[cur++] = s[k];
            }
            int l = 0, r = 0;
            while (l < cur && r < len2) {
                if (t[r] == ss[l]) r++;
                l++;
            }
            if (r == len2) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans;
    return 0;
}