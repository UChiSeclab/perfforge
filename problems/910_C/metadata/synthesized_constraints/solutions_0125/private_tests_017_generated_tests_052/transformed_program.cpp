#include <bits/stdc++.h>
using namespace std;

long long sum[10] = {0};
bool starts[10] = {0};
int p[10];

// Function to check permutation invariant
void check_permutation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Permutation invariant triggered - excessive permutations" << endl;
        abort();
    }
}

// Function to check leading zero invariant
void check_leading_zero_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Leading zero invariant triggered - excessive filtering" << endl;
        abort();
    }
}

// Function to check accumulation invariant
void check_accumulation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Accumulation invariant triggered - accumulation workload excessive" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    // Check if n is at its upper bound which might lead to excessive permutations
    check_permutation_invariant(n >= 10);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int val = 1;
        for (int j = (int)s.size() - 1; j >= 0; --j) {
            sum[s[j] - 'a'] += val;
            val *= 10;
        }
        starts[s[0] - 'a'] = true;
    }

    for (int i = 0; i < 10; ++i) {
        p[i] = i;
    }

    long long best = 1LL << 60;
    
    // Check if the permutations reach a critical level
    check_accumulation_invariant(10! > 362880); // Arbitrary threshold for demonstration

    do {
        // Check for leading zero condition
        check_leading_zero_invariant(starts[p[0]]);
        
        if (starts[p[0]]) {
            continue;
        }

        long long curr = 0;
        for (int i = 0; i < 10; ++i) {
            curr += i * sum[p[i]];
        }
        best = min(best, curr);
    } while (next_permutation(p, p + 10));

    cout << best << endl;
    return 0;
}