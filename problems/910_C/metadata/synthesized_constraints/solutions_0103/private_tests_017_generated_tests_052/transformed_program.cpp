#include <bits/stdc++.h>
using namespace std;

int per[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, ans = 1E9, cnt[6][10], n, cur, pw;
char s[10];
bool chk[10];

void check_permutation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: permutation_invariant triggered - processing all permutations of 10 elements!" << endl;
        abort();
    }
}

void check_leading_chars_invariant(int leading_chars_count) {
    if (leading_chars_count > 5) {  // Arbitrary threshold for demonstration
        cerr << "Warning: leading_chars_invariant triggered - many distinct leading characters!" << endl;
        abort();
    }
}

void check_nested_loop_complexity(bool condition) {
    if (condition) {
        cerr << "Warning: nested_loop_complexity triggered - evaluation of permutations is costly!" << endl;
        abort();
    }
}

int main() {
    scanf("%d\n", &n);
    int leading_chars_count = 0;
    while (n--) {
        scanf("%s\n", s + 1);
        if (!chk[s[1] - 'a']) {
            chk[s[1] - 'a'] = true;
            leading_chars_count++;
        }
        for (int i = strlen(s + 1), pw = 0; i >= 1; pw++, i--)
            cnt[pw][s[i] - 'a']++;
    }
    
    // Check leading characters invariant before permutation processing
    check_leading_chars_invariant(leading_chars_count);
    
    int permutation_count = 0;
    do {
        permutation_count++;
        if (!chk[per[0]]) {
            pw = 1;
            cur = 0;
            for (int i = 0; i < 6; pw *= 10, i++)
                for (int j = 0; j < 10; j++) cur += pw * j * cnt[i][per[j]];
            ans = min(ans, cur);
        }
    } while (next_permutation(per, per + 10));
    
    // Check permutation invariant after the loop
    check_permutation_invariant(permutation_count == 3628800); // 10! permutations
    
    // Check nested loop complexity after permutations are generated
    check_nested_loop_complexity(permutation_count > 1000000); // Arbitrary threshold

    printf("%d", ans);
}