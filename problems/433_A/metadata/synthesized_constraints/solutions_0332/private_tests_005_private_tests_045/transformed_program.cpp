#include <bits/stdc++.h>
using namespace std;

// Function to check exhaustive combination conditions
void check_exhaustive_combination_invariant(int n, const vector<int>& apple) {
    int count100 = count(apple.begin(), apple.end(), 100);
    int count200 = n - count100;
    if (n > 50 && abs(count100 - count200) > 10) {
        cerr << "Warning: Performance bottleneck - exhaustive combinations likely due to imbalanced weights." << endl;
        abort();
    }
}

// Function to check if a quick initial balance is impossible
void check_initial_balance_invariant(int totalWeight) {
    if (totalWeight % 200 != 0) {
        cerr << "Warning: Performance bottleneck - no immediate balance possible due to indivisible total weight." << endl;
        abort();
    }
}

// Function to check complex weight distribution conditions
void check_complex_distribution_invariant(int n, const vector<int>& apple) {
    int count100 = count(apple.begin(), apple.end(), 100);
    int count200 = n - count100;
    if (abs(count100 - count200) > 20) {
        cerr << "Warning: Performance bottleneck - complex weight distribution requiring many combinations." << endl;
        abort();
    }
}

int main() {
    int n, x, y, tmp;
    bool flag = false;
    cin >> n;
    vector<int> apple(n);
    for (int i = 0; i < n; i++) cin >> apple[i];
    
    // Calculate total weight and check for immediate balance impossibility
    int totalWeight = accumulate(apple.begin(), apple.end(), 0);
    check_initial_balance_invariant(totalWeight);

    // Check for complex distribution conditions
    check_complex_distribution_invariant(n, apple);

    x = apple[0];
    for (int i = 1; i < n; i++) {
        y = apple[i];
        for (int j = 1; j < n; j++) {
            if (j == i) continue;
            tmp = apple[j];
            if (x <= y)
                x += tmp;
            else
                y += tmp;
        }
        if (x == y) {
            cout << "YES" << endl;
            flag = true;
            break;
        } else {
            x = apple[0];
            flag = false;
        }
    }
    if (!flag) cout << "NO" << endl;
    return 0;
}