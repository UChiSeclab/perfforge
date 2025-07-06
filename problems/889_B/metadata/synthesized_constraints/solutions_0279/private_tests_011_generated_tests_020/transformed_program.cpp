#include <bits/stdc++.h>
using namespace std;

string A[26], s;
bool vis[26];
int n, h[26], q[26];

bool cmp(int x, int y) { return A[x] < A[y]; }

void check_string_comparison_invariant(int loopIterations, int repeatedComparisons) {
    if (loopIterations > 1000 && repeatedComparisons > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive string comparisons!" << endl;
        abort();
    }
}

void check_character_frequency_invariant(int frequencyChecks, int uniqueChars) {
    if (frequencyChecks > 5000 && uniqueChars < 5) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent character checks on similar strings!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int nestedLoops, int stringSize) {
    if (nestedLoops > 500 && stringSize > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - nested loops on large data structures!" << endl;
        abort();
    }
}

void check_string_construction_invariant(int concatenationOps, int maxStringLength) {
    if (concatenationOps > 200 && maxStringLength > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive string concatenations!" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &n);
    int loopIterations = 0, repeatedComparisons = 0, frequencyChecks = 0, uniqueChars = 0;
    int nestedLoops = 0, concatenationOps = 0, maxStringLength = 0;

    for (int i = 0; i <= 25; ++i) h[i] = 0;
    for (int cas = 1; cas <= n; ++cas) {
        cin >> s;
        int len = s.length();
        for (int i = 0; i <= len - 1; ++i) {
            h[s[i] - 'a']++;
            if (h[s[i] - 'a'] > 1) {
                printf("NO\n");
                return 0;
            }
        }
        for (int i = 0; i <= 25; ++i) h[i] = 0;
        for (int i = 0; i <= len - 1; ++i) {
            int c = s[i] - 'a';
            if (A[c].length() == 0) A[c] = A[c] + (char)('a' + c);
            int pos = 0, lenA = A[c].length();
            for (int j = 0; j <= lenA - 1; ++j) {
                if (A[c][j] == 'a' + c) pos = j;
                repeatedComparisons++;
            }
            int l = i - 1, r = pos - 1;
            for (; l >= 0 && r >= 0; l--, r--) {
                if (s[l] != A[c][r]) {
                    printf("NO\n");
                    return 0;
                }
                loopIterations++;
            }
            int L = l;
            l = i + 1, r = pos + 1;
            for (; l < len && r < lenA; l++, r++) {
                if (s[l] != A[c][r]) {
                    printf("NO\n");
                    return 0;
                }
                loopIterations++;
            }
            int R = l;
            for (int j = L; j >= 0; --j) {
                A[c] = s[j] + A[c];
                concatenationOps++;
            }
            for (int j = R; j <= len - 1; ++j) {
                A[c] = A[c] + s[j];
                concatenationOps++;
            }
        }
    }

    for (int i = 0; i <= 25; ++i) vis[i] = true;
    for (int i = 25; i >= 0; --i) {
        for (int j = i + 1; j <= 25; ++j) {
            for (int k = 0; k <= 25; ++k) h[k] = 0;
            int leni = A[i].length(), lenj = A[j].length();
            for (int k = 0; k <= leni - 1; ++k) ++h[A[i][k] - 'a'];
            for (int k = 0; k <= lenj - 1; ++k) ++h[A[j][k] - 'a'];
            int let = -1, posi = 0, posj = 0;
            for (int k = 0; k <= 25; ++k) {
                frequencyChecks++;
                if (h[k] > 1) {
                    let = k;
                    break;
                }
            }
            if (let < 0) continue;
            for (int k = 0; k <= leni - 1; ++k)
                if (A[i][k] == 'a' + let) posi = k;
            for (int k = 0; k <= lenj - 1; ++k)
                if (A[j][k] == 'a' + let) posj = k;
            int l = posi - 1, r = posj - 1;
            for (; l >= 0 && r >= 0; l--, r--) {
                if (A[i][l] != A[j][r]) {
                    printf("NO\n");
                    return 0;
                }
                nestedLoops++;
            }
            int L = r;
            l = posi + 1, r = posj + 1;
            for (; l < leni && r < lenj; ++l, ++r) {
                if (A[i][l] != A[j][r]) {
                    printf("NO\n");
                    return 0;
                }
                nestedLoops++;
            }
            int R = r;
            for (int k = L; k >= 0; --k) A[i] = A[j][k] + A[i];
            for (int k = R; k <= lenj - 1; ++k) A[i] = A[i] + A[j][k];
        }
        for (int j = 0; j <= 25; ++j) h[j] = 0;
        for (int j = 0; j <= (int)A[i].length() - 1; ++j) ++h[A[i][j] - 'a'];
        for (int j = 0; j <= 25; ++j)
            if (h[j] > 1) {
                printf("NO\n");
                return 0;
            }
    }

    for (int i = 1; i <= 25; ++i)
        for (int j = 0; j <= i - 1; ++j)
            if (vis[j]) {
                for (int k = 0; k <= 25; ++k) h[k] = 0;
                int leni = A[i].length(), lenj = A[j].length();
                for (int k = 0; k <= leni - 1; ++k) ++h[A[i][k] - 'a'];
                for (int k = 0; k <= lenj - 1; ++k) ++h[A[j][k] - 'a'];
                int let = -1, posi = 0, posj = 0;
                for (int k = 0; k <= 25; ++k)
                    if (h[k] > 1) {
                        let = k;
                        break;
                    }
                if (let < 0) continue;
                vis[i] = false;
                break;
            }
    for (int i = 0; i <= 25; ++i) q[i] = i;
    sort(q, q + 26, cmp);
    for (int i = 0; i <= 25; ++i)
        if (vis[q[i]]) cout << A[q[i]];
    cout << endl;

    // Check invariants at the end
    check_string_comparison_invariant(loopIterations, repeatedComparisons);
    check_character_frequency_invariant(frequencyChecks, uniqueChars);
    check_nested_loop_invariant(nestedLoops, s.length());
    check_string_construction_invariant(concatenationOps, maxStringLength);

    return 0;
}