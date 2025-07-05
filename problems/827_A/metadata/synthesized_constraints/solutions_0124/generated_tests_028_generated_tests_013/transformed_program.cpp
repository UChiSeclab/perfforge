#include <bits/stdc++.h>
using namespace std;
char ans[2000006];

void check_overlap_invariant(int ki, int totalKi) {
    if (ki > 50 || totalKi > 100000) { 
        cerr << "Warning: Overlap invariant triggered - too many insertions at close positions!" << endl;
        abort();
    }
}

void check_length_invariant(int len) {
    if (len > 100000) { 
        cerr << "Warning: Length invariant triggered - constructed string too long!" << endl;
        abort();
    }
}

void check_total_insertion_length_invariant(int totalInsertionLength) {
    if (totalInsertionLength > 1000000) { 
        cerr << "Warning: Total insertion length invariant triggered - too many insertions!" << endl;
        abort();
    }
}

int main() {
    int n, a, b, i, l, len = 0, tot;
    scanf("%d", &n);
    int totalKi = 0; // Track total occurrences
    int totalInsertionLength = 0; // Track total insertion length

    while (n--) {
        string str;
        cin >> str;
        scanf("%d", &b);
        l = str.length();
        tot = 0;
        totalKi += b;
        totalInsertionLength += l * b;

        check_overlap_invariant(b, totalKi);
        check_total_insertion_length_invariant(totalInsertionLength);

        while (b--) {
            scanf("%d", &a);
            a--;
            len = max(len, a + l);
            for (i = max(a, tot); i < a + l; i++) ans[i] = str[i - a];
            tot = a + l;
        }
    }

    check_length_invariant(len); // Check final length of constructed string

    for (i = 0; i < len; i++) {
        if (ans[i] == '\0')
            printf("a");
        else
            printf("%c", ans[i]);
    }
    return 0;
}