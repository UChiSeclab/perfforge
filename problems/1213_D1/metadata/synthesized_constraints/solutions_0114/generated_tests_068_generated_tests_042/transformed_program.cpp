#include <bits/stdc++.h>
using namespace std;

// Checker functions based on performance-characterizing invariants
void check_large_values(const vector<int>& arr) {
    int threshold = 100000; // Arbitrary threshold for large values
    for (int val : arr) {
        if (val > threshold) {
            cerr << "Warning: Performance bottleneck - large initial values detected!" << endl;
            abort();
        }
    }
}

void check_division_outcomes(int posLen) {
    int threshold = 1000; // Arbitrary threshold for pos length
    if (posLen > threshold) {
        cerr << "Warning: Performance bottleneck - high diversity in division outcomes!" << endl;
        abort();
    }
}

void check_nested_iterations(int posLen, int n) {
    if (posLen * n > 5000) { // Arbitrary threshold for nested loop iterations
        cerr << "Warning: Performance bottleneck - excessive nested iterations!" << endl;
        abort();
    }
}

void check_repeated_sorting(int sortOperations) {
    int threshold = 100; // Arbitrary threshold for sorting operations
    if (sortOperations > threshold) {
        cerr << "Warning: Performance bottleneck - excessive repeated sorting!" << endl;
        abort();
    }
}

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    
    for (int i = 0; i < n; i++) {
        int tnum;
        cin >> tnum;
        num[i] = tnum;
    }

    // Check for large initial values
    check_large_values(num);

    vector<int> pos;
    int posLen = 0;
    int ans = 1e9;

    for (int i = 0; i < n; i++) {
        int x = num[i];
        while (x > 0) {
            pos.push_back(x);
            posLen++;
            x /= 2;
        }
    }

    // Check division outcomes and nested iterations
    check_division_outcomes(posLen);
    check_nested_iterations(posLen, n);

    int sortOperations = 0;

    for (int id = 0; id < posLen; id++) {
        vector<int> cnt;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            int x = num[i];
            while (x > pos[id]) {
                x /= 2;
                cur++;
            }
            if (x == pos[id]) {
                cnt.push_back(cur);
            }
        }
        if (int(cnt.size()) < k)
            continue;
        else {
            sort(cnt.begin(), cnt.end());
            sortOperations++;
            ans = min(ans, accumulate(cnt.begin(), cnt.begin() + k, 0));
        }
    }

    // Check for repeated sorting
    check_repeated_sorting(sortOperations);

    cout << ans << endl;
    return 0;
}