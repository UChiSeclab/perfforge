#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
char s[maxn];
int a[maxn];

// Checker functions
void check_unmatched_parens_initial(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered - sequence has excessive unmatched opening parentheses!" << endl;
        abort();
    }
}

void check_unmatched_parens_end(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered - sequence has excessive unmatched closing parentheses from the end!" << endl;
        abort();
    }
}

void check_invalid_sequence_count(int invalidCount, int n) {
    if (invalidCount > n / 2) {
        cerr << "Warning: Performance bottleneck triggered - too many invalid sequences!" << endl;
        abort();
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int invalidCount = 0;  // Track how many sequences are marked as invalid

    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        a[i] = 0;
        bool flag = false;
        for (int j = 0; s[j]; j++) {
            if (s[j] == '(')
                a[i]++;
            else
                a[i]--;
            if (a[i] < 0) flag = true;
        }

        // Check for excessive unmatched opening parentheses
        check_unmatched_parens_initial(a[i] >= 0 && flag);

        if (a[i] >= 0 && flag) a[i] = maxn;
        if (a[i] < 0) {
            int tmp = 0;
            for (int j = strlen(s) - 1; j >= 0; j--) {
                if (s[j] == ')')
                    tmp++;
                else
                    tmp--;

                if (tmp < 0) {
                    a[i] = maxn;
                    break;
                }
            }
            // Check for excessive unmatched closing parentheses
            check_unmatched_parens_end(tmp < 0);
        }

        if (a[i] == maxn) invalidCount++;
    }

    // Check if too many sequences are invalid
    check_invalid_sequence_count(invalidCount, n);

    sort(a + 1, a + n + 1);
    int ans = 0;
    int i = 1, j = n;
    while (i < j) {
        if (a[i] + a[j] == 0)
            i++, j--, ans++;
        else {
            while (a[j] > -a[i]) j--;
            while (a[i] < -a[j]) i++;
        }
    }
    printf("%d\n", ans);
    return 0;
}