#include <bits/stdc++.h>
using namespace std;

char nr1[100010], nr2[100010];
int recursiveDepth = 0; // To track recursion depth
size_t zeroAdditions = 0; // To track adding leading zeros
size_t stringModifications = 0; // To track string modifications

void check_recursive_calls(size_t depth) {
    if (depth > 50) {
        cerr << "Warning: Performance bottleneck condition triggered! - Excessive recursive calls in replace()" << endl;
        abort();
    }
}

void check_leading_zeros(size_t zeroCount) {
    if (zeroCount > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered! - Excessive leading zeros being added" << endl;
        abort();
    }
}

void check_string_modifications(size_t modifications) {
    if (modifications > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered! - Too many string modifications" << endl;
        abort();
    }
}

void replace(string &st) {
    recursiveDepth++;
    check_recursive_calls(recursiveDepth);
    
    st.pop_back();
    if (st.size() > 1) st.pop_back();
    if (st.size() > 0 && st[st.size() - 1] == '1')
        replace(st);
    else
        st += '1';
    st += '0';
    st += '0';
    
    recursiveDepth--;
}

void addZero(string &n1, string &n2) {
    if (n1.size() > n2.size()) {
        int it = (int)(n1.size() - n2.size());
        zeroAdditions += it;
        check_leading_zeros(zeroAdditions);
        
        for (int i = 0; i < it; i++) n2 = "0" + n2;
    }
    if (n1.size() < n2.size()) {
        int it = (int)(n2.size() - n1.size());
        zeroAdditions += it;
        check_leading_zeros(zeroAdditions);
        
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
            replace(n1);
        } else
            n1 += nr1[i];
        
        stringModifications++;
        check_string_modifications(stringModifications);
    }
    len = strlen(nr2) - 1;
    for (int i = 1; i < len; i++) {
        if (n2[n2.size() - 1] == nr2[i] && nr2[i] == '1') {
            replace(n2);
        } else
            n2 += nr2[i];
        
        stringModifications++;
        check_string_modifications(stringModifications);
    }
    addZero(n1, n2);
    if (n1.size() == n2.size()) {
        int rez = n1.compare(n2);
        if (rez == 0)
            printf("=\n");
        else if (rez < 0)
            printf("<\n");
        else
            printf(">\n");
    } else
        printf("not equal\n");
}

int main() {
    fgets(nr1, 100010, stdin);
    fgets(nr2, 100010, stdin);
    compare();
    return 0;
}