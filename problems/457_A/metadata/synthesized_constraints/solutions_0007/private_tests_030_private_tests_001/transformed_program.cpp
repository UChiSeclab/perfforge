#include <bits/stdc++.h>
using namespace std;

char nr1[100010], nr2[100010];

void check_recursion_invariant(int depth) {
    if (depth > 50) { // Arbitrarily chosen depth threshold
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion depth!" << endl;
        abort();
    }
}

void replace(string &st, int depth) {
    // Check recursion depth
    check_recursion_invariant(depth);

    st.pop_back();
    if (st.size() > 1) st.pop_back();
    if (st.size() > 0 && st[st.size() - 1] == '1')
        replace(st, depth + 1);
    else
        st += '1';
    st += '0';
    st += '0';
}

void check_string_extension_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive string extension!" << endl;
        abort();
    }
}

void addZero(string &n1, string &n2) {
    int lengthDifference = abs((int)(n1.size() - n2.size()));
    
    // Check for excessive padding
    check_padding_invariant(lengthDifference);

    if (n1.size() > n2.size()) {
        int it = (int)(n1.size() - n2.size());
        for (int i = 0; i < it; i++) n2 = "0" + n2;
    }
    if (n1.size() < n2.size()) {
        int it = (int)(n2.size() - n1.size());
        for (int i = 0; i < it; i++) n1 = "0" + n1;
    }
}

void compare() {
    int len = strlen(nr1) - 1;
    string n1, n2;
    n1 = nr1[0];
    n2 = nr2[0];
    
    for (int i = 1; i < len; i++) {
        if (n1[n1.size() - 1] == nr1[i] && nr1[i] == '1') {
            replace(n1, 1);
        } else
            n1 += nr1[i];
    }
    
    len = strlen(nr2) - 1;
    for (int i = 1; i < len; i++) {
        if (n2[n2.size() - 1] == nr2[i] && nr2[i] == '1') {
            replace(n2, 1);
        } else
            n2 += nr2[i];
    }

    addZero(n1, n2);
    int rez = n1.compare(n2);
    if (rez == 0)
        printf("=\n");
    else if (rez < 0)
        printf("<\n");
    else
        printf(">\n");
}

int main() {
    fgets(nr1, 100010, stdin);
    fgets(nr2, 100010, stdin);
    compare();
    return 0;
}