#include <bits/stdc++.h>
using namespace std;

map<string, int> ma;
int n;
string s;
char ss[100000];

// Checkers based on the invariants
void check_recursion_depth_invariant(int currentDepth, int maxAllowedDepth) {
    if (currentDepth > maxAllowedDepth) {
        cerr << "Warning: Performance bottleneck condition triggered due to high recursion depth!" << endl;
        abort();
    }
}

void check_complex_macro_invariant(bool complexMacroCondition) {
    if (complexMacroCondition) {
        cerr << "Warning: Performance bottleneck condition triggered due to complex macro expressions!" << endl;
        abort();
    }
}

void check_macro_expansion_invariant(int macroCount, int threshold) {
    if (macroCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive macro expansions!" << endl;
        abort();
    }
}

int work(int l, int r, int currentDepth) {
    check_recursion_depth_invariant(currentDepth, 50); // Example: max depth allowed is 50

    int i, zz = 0;
    for (i = r; i > l; i--) {
        if (s[i] == '(')
            zz++;
        else if (s[i] == ')')
            zz--;
        else if ((s[i] == '+' || s[i] == '-') && zz == 0) {
            int ll = work(l, i - 1, currentDepth + 1);
            int rr = work(i + 1, r, currentDepth + 1);
            if (ll == 4 || rr == 4 || (s[i] == '-' && rr == 3))
                return 4;
            else
                return 3;
        }
    }

    zz = 0;
    for (i = r; i > l; i--) {
        if (s[i] == '(')
            zz++;
        else if (s[i] == ')')
            zz--;
        else if ((s[i] == '*' || s[i] == '/') && zz == 0) {
            int ll = work(l, i - 1, currentDepth + 1);
            int rr = work(i + 1, r, currentDepth + 1);
            if (ll == 4 || rr == 4 || ll == 3 || rr == 3 || (s[i] == '/' && rr == 2))
                return 4;
            else
                return 2;
        }
    }
    if (s[l] == '(') return ((work(l + 1, r - 1, currentDepth + 1) == 4) ? 4 : 1);
    
    string sa;
    sa = "";
    for (i = l; i <= r; i++) sa = sa + s[i];

    // Check complex macro condition (e.g., unbracketed operations)
    check_complex_macro_invariant(sa.find('*') != string::npos || sa.find('/') != string::npos);

    if (ma[sa] == 0) {
        ma[sa] = 1;
        return (1);
    } else
        return ma[sa];
}

int main() {
    cin >> n;
    int i, j;
    gets(ss);

    // Check macro expansion invariant before processing
    check_macro_expansion_invariant(n, 100); // Example: threshold is 100 macros

    for (i = 1; i <= n; i++) {
        string sa = s = "";
        cin >> sa;
        if (sa.length() != 7) cin >> sa;
        cin >> sa;
        gets(ss);
        for (j = 0; ss[j]; j++)
            if (ss[j] != ' ') s = s + ss[j];
        ma[sa] = work(0, s.length() - 1, 0); // Start with zero recursion depth
    }

    s = "";
    gets(ss);
    for (i = 0; ss[i]; i++)
        if (ss[i] != ' ') s = s + ss[i];

    if (work(0, s.length() - 1, 0) != 4)
        printf("OK\n");
    else
        printf("Suspicious\n");
}