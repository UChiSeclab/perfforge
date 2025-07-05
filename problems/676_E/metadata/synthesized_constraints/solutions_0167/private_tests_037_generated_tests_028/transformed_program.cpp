#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;
int a[100000 + 10], known[100000 + 10];

// Checkers for performance invariants

// Invariant to check for trailing zeros
void check_trailing_zeros_invariant(const int* a, int n) {
    int zero_count = 0;
    for (int i = n; i >= 1; --i) {
        if (a[i] == 0)
            zero_count++;
        else
            break;
    }
    if (zero_count > 5) { // threshold chosen for illustration
        cerr << "Warning: trailing_zeros_invariant triggered - long sequence of trailing zeros" << endl;
        abort();
    }
}

// Invariant to check for excessive loop execution
void check_division_loop_invariant(int all_zero, int n) {
    if (n - all_zero > 5) { // threshold chosen for illustration
        cerr << "Warning: division_loop_invariant triggered - loop could run many times" << endl;
        abort();
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n + 1; i++) {
        char buf[20];
        scanf("%s", buf);
        if (*buf == '?') {
            known[i] = false;
            cnt++;
        } else {
            known[i] = true;
            sscanf(buf, "%d", &a[i]);
        }
    }
    int ok = 0;
    if (k == 0) {
        if (known[1] == 1 && a[1] == 0) ok = 1;
        if (known[1] == 0 && (n + 1 - cnt) % 2 == 1) ok = 1;
    } else {
        if (cnt != 0) ok = (((n + 1 - cnt) % 2 + cnt % 2) % 2) == 0;
        int all_zero = n + 1;
        while (a[all_zero] == 0) all_zero--;
        long long tmp = 0;
        if (cnt == 0) {
            // Check invariant before potentially slow loop
            check_division_loop_invariant(all_zero, n);
            for (int i = 1; i <= n + 1; i++) {
                tmp -= a[i];
                if (tmp % k != 0) break;
                if (i > all_zero && tmp != 0) break;
                tmp /= k;
                if (i == n + 1 && tmp == 0) ok = 1;
            }
        }
    }
    
    // Check invariant on trailing zeros after input processing
    check_trailing_zeros_invariant(a, n);

    printf("%s\n", ok ? "Yes" : "No");
}