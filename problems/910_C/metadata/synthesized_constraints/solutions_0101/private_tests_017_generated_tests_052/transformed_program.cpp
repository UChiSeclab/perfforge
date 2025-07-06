#include <bits/stdc++.h>
using namespace std;

int cnt[7][10];

void check_permutation_invariant(int permutationsEvaluated, int factorialLimit) {
    if (permutationsEvaluated > factorialLimit) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive permutations evaluated!" << endl;
        abort();
    }
}

void check_calculation_invariant(int operationCount, int operationLimit) {
    if (operationCount > operationLimit) {
        cerr << "Warning: Performance bottleneck condition triggered - too many costly calculations!" << endl;
        abort();
    }
}

void check_restriction_invariant(bool isRestrictedComputation) {
    if (isRestrictedComputation) {
        cerr << "Warning: Performance bottleneck condition triggered - ineffective pruning of permutations!" << endl;
        abort();
    }
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    int pw10[8];
    pw10[0] = 1;
    for (int i = 1; i < 8; i++) pw10[i] = 10 * pw10[i - 1];
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<string> s(n);
    vector<bool> restricted(10, false);
    
    int operationCount = 0; // For counting operations in permutations

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        restricted[s[i][0] - 'a'] = true;
        for (int j = s[i].size() - 1, k = 0; j >= 0; j--, k++)
            cnt[k][s[i][j] - 'a']++;
    }
    vector<int> p;
    for (int i = 0; i < 10; i++) p.push_back(i);
    int mn = 2000000010;
    int permutationsEvaluated = 0; // For counting permutations

    do {
        permutationsEvaluated++;
        int val = 0;
        int wh0;
        for (int i = 0; i < 10; i++)
            if (p[i] == 0) wh0 = i;
        if (restricted[wh0]) continue;
        
        // Check for ineffective restriction pruning
        check_restriction_invariant(restricted[wh0]);

        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 10; j++) {
                val += cnt[i][j] * pw10[i] * p[j];
                operationCount++;
            }
        }

        mn = min(mn, val);
    } while (next_permutation(p.begin(), p.end()));

    // Check for permutation and calculation invariants
    check_permutation_invariant(permutationsEvaluated, 3628800);
    check_calculation_invariant(operationCount, 167650560);

    cout << mn << endl;
    return 0;
}