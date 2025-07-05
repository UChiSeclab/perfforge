#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_permutation_invariant(int nonZeroCount) {
    if (nonZeroCount > 7) { // Arbitrary threshold for illustration
        cerr << "Warning: Performance bottleneck condition triggered - excessive permutations due to diverse leading characters!" << endl;
        abort();
    }
}

void check_leading_character_invariant(int uniqueLeadingChars) {
    if (uniqueLeadingChars > 8) { // Arbitrary threshold for illustration
        cerr << "Warning: Performance bottleneck condition triggered - high diversity in leading characters!" << endl;
        abort();
    }
}

void check_digit_contribution_invariant(int contributionOverlap) {
    if (contributionOverlap > 5) { // Arbitrary threshold for illustration
        cerr << "Warning: Performance bottleneck condition triggered - complex digit contribution calculations!" << endl;
        abort();
    }
}

int n, p[10];
long long num[10];
char s[10];
bool canZero[10];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 10; i++) canZero[i] = 1;

    set<char> leadingChars; // To track unique leading characters
    vector<int> nonZeroDigits(10, 0); // To track which letters cannot be zero

    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int len = (int)strlen(s);
        canZero[s[0] - 'a'] = 0;
        leadingChars.insert(s[0]); // Track leading characters
        for (int j = len - 1, k = 1; j >= 0; j--, k *= 10) {
            num[s[j] - 'a'] += k;
            nonZeroDigits[s[j] - 'a']++;
        }
    }

    // Check for performance invariants before the permutation intensive process
    int nonZeroCount = count(canZero, canZero + 10, 0); // Find count of non-zero constraints
    check_permutation_invariant(nonZeroCount);

    int uniqueLeadingChars = leadingChars.size();
    check_leading_character_invariant(uniqueLeadingChars);

    int maxContributionOverlap = *max_element(nonZeroDigits.begin(), nonZeroDigits.end());
    check_digit_contribution_invariant(maxContributionOverlap);

    for (int i = 0; i < 10; i++) p[i] = i;
    long long res = 9e18;
    do {
        if (!canZero[p[0]]) continue;
        long long loc = 0;
        for (int i = 0; i < 10; i++) {
            loc += num[p[i]] * i;
        }
        res = min(res, loc);
    } while (next_permutation(p, p + 10));

    printf("%lld", res);
    return 0;
}