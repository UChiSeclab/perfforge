#include <bits/stdc++.h>
using namespace std;

int sum[10], S[1000010], T[1000010], len, n, m;
int c1[1000010], c2[1000010], c3[1000010], ans[1000010];
char ch[1000010];
int judgeCallCount = 0; // Counter for judge function calls
int permutationCount = 0; // Counter for permutations attempted
int sortOperationCount = 0; // Counter for sorting operations

// Checker functions from Phase 3
void check_length_invariant(int judgeCalls, int threshold) {
    if (judgeCalls > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive calls to judge function!" << endl;
        abort();
    }
}

void check_permutation_invariant(int uniquePermutations, int threshold) {
    if (uniquePermutations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive permutations of digit sequences!" << endl;
        abort();
    }
}

void check_digit_sort_invariant(int sortOperations, int threshold) {
    if (sortOperations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive digit sorting operations!" << endl;
        abort();
    }
}

bool judge(int l) {
    int tmp[10], t = 0, ll = l;
    memset(tmp, 0, sizeof(tmp));
    while (l) {
        t++;
        tmp[l % 10]++;
        l /= 10;
    }
    for (int i = 0; i <= 9; i++)
        if (sum[i] < tmp[i]) return false;
    if (n - t != ll) return false;
    for (int i = 0; i <= 9; i++) sum[i] -= tmp[i];
    for (int i = 1; i <= m; i++) sum[T[i]]--;
    judgeCallCount++; // Increment the judge call count
    return true;
}

bool cmp(int a[], int b[]) {
    for (int i = 1; i <= len; i++) {
        if (a[i] == b[i]) continue;
        if (a[i] < b[i])
            return true;
        else
            return false;
    }
    return true;
}

int main() {
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    for (int i = 1; i <= n; i++) S[i] = ch[i] - '0';
    scanf("%s", ch + 1);
    m = strlen(ch + 1);
    for (int i = 1; i <= m; i++) T[i] = ch[i] - '0';
    for (int i = 1; i <= n; i++) sum[S[i]]++;

    // Check length invariant before proceeding
    check_length_invariant(judgeCallCount, 100); // Example threshold

    for (int i = 1; i <= n; i++) {
        if (judge(i)) {
            len = i;
            break;
        }
    }

    if (len == 1 && T[1] == 0) {
        printf("0\n");
        return 0;
    }

    if (T[1] == 0) {
        c1[1] = 0x3f3f3f3f;
    } else {
        for (int i = 1; i <= m; i++) c1[i] = T[i];
        int tot = m;
        for (int i = 0; i <= 9; i++) {
            for (int j = 1; j <= sum[i]; j++) {
                c1[++tot] = i;
            }
        }
    }

    check_permutation_invariant(permutationCount, 1000); // Example threshold

    for (int i = 1; i <= 9; i++) {
        int tot2 = 0, tot3 = 0;
        if (sum[i] != 0) {
            sum[i]--;
            c2[++tot2] = i;
            c3[++tot3] = i;
            for (int j = 0; j <= 9; j++) {
                if (j != T[1]) {
                    for (int k = 1; k <= sum[j]; k++) {
                        c2[++tot2] = j;
                    }
                    for (int k = 1; k <= sum[j]; k++) {
                        c3[++tot3] = j;
                    }
                } else {
                    for (int k = 1; k <= sum[j]; k++) {
                        c2[++tot2] = j;
                    }
                    for (int k = 1; k <= m; k++) {
                        c2[++tot2] = T[k];
                    }
                    for (int k = 1; k <= m; k++) {
                        c3[++tot3] = T[k];
                    }
                    for (int k = 1; k <= sum[j]; k++) {
                        c3[++tot3] = j;
                    }
                }
            }
            permutationCount++; // Increment permutation count
            break;
        }
    }

    if (c2[1] == 0) {
        c2[1] = 0x3f3f3f3f;
        c3[1] = 0x3f3f3f3f;
    }

    ans[1] = 0x3f3f3f3f;
    if (cmp(c1, ans)) memcpy(ans, c1, sizeof(ans));
    if (cmp(c2, ans)) memcpy(ans, c2, sizeof(ans));
    if (cmp(c3, ans)) memcpy(ans, c3, sizeof(ans));

    // Check digit sort invariant before output
    check_digit_sort_invariant(sortOperationCount, 50); // Example threshold

    for (int i = 1; i <= len; i++) printf("%d", ans[i]);
    return 0;
}