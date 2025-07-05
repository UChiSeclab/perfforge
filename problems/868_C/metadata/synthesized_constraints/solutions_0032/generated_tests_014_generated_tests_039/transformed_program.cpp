#include <bits/stdc++.h>
using namespace std;

int n, k;
bool problem[16];

void check_problem_combinations_invariant(int invalidCombinations, int threshold) {
    if (invalidCombinations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - too many invalid combinations!" << endl;
        abort();
    }
}

void check_subset_iteration_invariant(int attempts) {
    if (attempts > 10000) { // Arbitrary large threshold
        cerr << "Warning: Performance bottleneck condition triggered - excessive subset iterations!" << endl;
        abort();
    }
}

void check_known_problem_density_invariant(const vector<int>& knownProblems) {
    int denseCount = 0;
    for (int count : knownProblems) {
        if (count > 2) { // Assumes a team knowing more than half the problems is dense
            denseCount++;
        }
    }
    if (denseCount > 3) { // Arbitrary threshold for density
        cerr << "Warning: Performance bottleneck condition triggered - high known problem density!" << endl;
        abort();
    }
}

bool test(int msk) {
    vector<int> know(k, 0);
    int q = 0;
    for (int i = 0; i < 16; i++) {
        if (msk & (1 << i)) {
            for (int j = 0; j < 4; j++)
                if (i & (1 << j)) know[j]++;
            if (problem[i])
                ++q;
            else
                return false;
        }
    }
    if (*max_element(know.begin(), know.end()) > (q / 2)) return false;
    return true;
}

int main() {
    cin >> n >> k;
    vector<int> knownProblems(1 << k, 0); // Track how many teams know each problem subset

    for (int i = 0; i < n; i++) {
        int msk = 0;
        for (int b, j = k - 1; j >= 0; j--) {
            cin >> b;
            if (b) msk |= (1 << j);
        }
        problem[msk] = true;
        knownProblems[msk]++;
    }

    check_known_problem_density_invariant(knownProblems);

    int invalidCombinationCount = 0;
    int attemptCount = 0;

    for (int i = 1; i < (1 << 16); i++) {
        attemptCount++;
        if (test(i)) {
            cout << "YES\n";
            return 0;
        } else {
            invalidCombinationCount++;
        }

        check_problem_combinations_invariant(invalidCombinationCount, 10000); // Arbitrary threshold
        check_subset_iteration_invariant(attemptCount);
    }

    cout << "NO\n";
    return 0;
}