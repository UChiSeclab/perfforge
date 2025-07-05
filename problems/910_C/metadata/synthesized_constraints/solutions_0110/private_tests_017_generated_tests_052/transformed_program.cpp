#include <bits/stdc++.h>
const int MAXD = 10;
int A[MAXD]{};
char buff[MAXD]{};
bool lead[MAXD]{};
int sum[MAXD]{};
int N, ret = 1E9;

// Function to check permutation size invariant
void check_permutation_size_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: permutation_size_invariant triggered - too many feasible permutations" << endl;
        abort();
    }
}

// Function to check digit impact invariant
void check_digit_impact_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: digit_impact_invariant triggered - high impact from multiple digits" << endl;
        abort();
    }
}

// Function to check leading digit invariant
void check_leading_digit_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: leading_digit_invariant triggered - excessive leading digit constraints" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %s", buff);
        for (int j = strlen(buff) - 1, t = 1; j >= 0; --j, t *= MAXD)
            sum[buff[j] - 'a'] += t;
        lead[buff[0] - 'a'] = true;
    }
    
    // Check for permutation size invariant
    int distinct_letters_count = std::count_if(sum, sum + MAXD, [](int x) { return x > 0; });
    check_permutation_size_invariant(distinct_letters_count > 8);
    
    // Check for digit impact invariant
    int significant_digit_count = std::count_if(sum, sum + MAXD, [](int x) { return x > 100; });
    check_digit_impact_invariant(significant_digit_count > 5);
    
    // Check for leading digit invariant
    int lead_constraints = std::count(lead, lead + MAXD, true);
    check_leading_digit_invariant(lead_constraints > 5);
    
    std::iota(A, A + MAXD, 0);
    do {
        if (lead[A[0]]) continue;
        int res = 0;
        for (int i = 0; i < MAXD; ++i) res += i * sum[A[i]];
        ret = std::min(res, ret);
    } while (std::next_permutation(A, A + MAXD));
    
    printf("%d\n", ret);
    return 0;
}