#include <bits/stdc++.h>
using namespace std;

void check_balance_operations(int imbalanceCount) {
    if (imbalanceCount > 1000) {
        cerr << "Warning: Performance bottleneck - excessive balancing operations detected!" << endl;
        abort();
    }
}

void check_large_vector_search(int vectorSize) {
    if (vectorSize > 50000) {
        cerr << "Warning: Performance bottleneck - large vector search detected!" << endl;
        abort();
    }
}

void check_imbalance_complexity(int imbalance) {
    if (imbalance > 50) {
        cerr << "Warning: Performance bottleneck - high imbalance complexity detected!" << endl;
        abort();
    }
}

void check_accumulated_balances(int balanceValue) {
    if (abs(balanceValue) > 100) {
        cerr << "Warning: Performance bottleneck - accumulated balances detected!" << endl;
        abort();
    }
}

int main() {
    int n;
    vector<int> balance(100005);
    vector<int>::iterator it;
    int sum = 0, total = 0;
    char c, last = '*';
    int ok = 0, zero = 0;
    int ans = 0;
    scanf("%d ", &n);

    // Check large input size which may lead to excessive balancing operations
    check_balance_operations(n);

    for (int i = 0; i < n;) {
        scanf("%c", &c);
        if (c == '(') {
            if (last == ')') {
                if (sum < 0) {
                    total += sum;
                    ok++;
                    sum = 0;
                }
            }
            sum++;
            last = '(';
        } else if (c == ')') {
            sum--;
            last = ')';
        } else {
            if (sum > 0) {
                if (ok == 0)
                    balance[i] = total + sum;
                else
                    balance[i] = 0x3f3f3f3f;
            } else {
                balance[i] = total + sum;
                if (balance[i] == 0) zero++;
            }
            i++;
            total = 0;
            sum = 0;
            last = '*';
            ok = 0;
        }
    }

    // Check for possible imbalance complexity
    check_imbalance_complexity(sum);

    for (int i = 0; i < n; i++) {
        if (balance[i] != 0x3f3f3f3f && balance[i] != 0) {
            // Check accumulated balances
            check_accumulated_balances(balance[i]);

            it = find(balance.begin(), balance.end(), 0 - balance[i]);

            // Check large search overhead in vector
            check_large_vector_search(it - balance.begin());

            if (it != balance.end()) {
                *it = 0x3f3f3f3f;
                balance[i] = 0x3f3f3f3f;
                ans++;
            }
        }
    }

    ans += zero / 2;
    printf("%d\n", ans);
    return 0;
}