#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
string arr[6336], base = "abcdefghijklmnopqrstuvwxyz", a, now = "a";

// Checker function for too many substrings
void check_substring_count_invariant(int substringCount) {
    if (substringCount > 5000) {  // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - too many substrings generated!" << endl;
        abort();
    }
}

// Checker function for excessive comparisons
void check_comparison_invariant(int comparisonCount) {
    if (comparisonCount > 4000) {  // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - excessive substring comparisons!" << endl;
        abort();
    }
}

// Checker function for frequent permutation generation
void check_permutation_invariant(int permutationCount) {
    if (permutationCount > 100) {  // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - frequent permutation generation!" << endl;
        abort();
    }
}

// Comparator function with invariant check
bool q(string x, string y) {
    static int comparisonCount = 0;
    comparisonCount++;
    check_comparison_invariant(comparisonCount);
    
    if (x.length() != y.length()) return x.length() < y.length();
    return x < y;
}

// Function to generate next permutation
string nextperm(string x) {
    static int permutationCount = 0;
    permutationCount++;
    check_permutation_invariant(permutationCount);

    int l = x.length();
    if (x[l - 1] != 'z') {
        int tmp = (int)x[l - 1];
        tmp++;
        x[l - 1] = (char)tmp;
    } else {
        x[l - 1] = 'a';
        if (l == 1) {
            x = 'a' + x;
            l++;
        } else {
            char buff[22];
            size_t length = x.copy(buff, l - 1, 0);
            buff[length] = '\0';
            string y = buff;
            y = nextperm(y);
            x.replace(0, l - 1, y);
        }
    }
    return x;
}

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        getline(cin, a);
        for (int j = 0; j < a.length(); j++) {
            for (int k = 1; k <= a.length() - j; k++) {
                char b[22];
                size_t length = a.copy(b, k, j);
                b[length] = '\0';
                arr[cnt++] = b;
            }
        }
    }
    
    // Check substring count invariant after all substrings are generated
    check_substring_count_invariant(cnt);

    sort(arr, arr + cnt, q);
    for (int i = 0; i < cnt; i++) {
        if (now == arr[i]) {
            now = nextperm(now);
        }
    }
    printf("%s\n", now.c_str());
    return 0;
}