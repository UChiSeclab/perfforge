#include <bits/stdc++.h>
using namespace std;

void check_long_abbreviation_invariant(int length) {
    if (length > 7) {
        cerr << "Warning: Performance bottleneck condition triggered - abbreviation too long!" << endl;
        abort();
    }
}

void check_recursion_depth_invariant(int depth) {
    if (depth > 10) {  // arbitrary threshold for recursion depth
        cerr << "Warning: Performance bottleneck condition triggered - recursion depth too high!" << endl;
        abort();
    }
}

void check_exponentiation_invariant(int length) {
    if (length > 7) {  // threshold based on experience; longer strings increase computation
        cerr << "Warning: Performance bottleneck condition triggered - exponentiation overhead!" << endl;
        abort();
    }
}

long long ten_pow(int s) {
    long long r = 1;
    for (int i = 0; i < s; ++i) r *= 10;
    return r;
}

long long check_for(char *abbr, int depth = 0) {
    int h = strlen(abbr);
    
    // Invariant checks
    check_recursion_depth_invariant(depth);  // Check recursion depth
    check_exponentiation_invariant(h);       // Check length for potential overhead

    long long base = atoi(abbr);
    if (abbr[0] == '0') {
        base += ten_pow(h);
    }
    long long y = (1989 - base + ten_pow(h) - 1) / ten_pow(h) * ten_pow(h) + base;
    if (h > 1) {
        while (check_for(abbr + 1, depth + 1) >= y) y += ten_pow(h);
    }
    return y;
}

int main() {
    int n;
    cin >> n;
    char s[50];
    while (n--) {
        cin >> s;
        char *num = s + 4;

        // Invariant check for abbreviation length
        check_long_abbreviation_invariant(strlen(num)); 

        cout << check_for(num) << endl;
    }
    return 0;
}