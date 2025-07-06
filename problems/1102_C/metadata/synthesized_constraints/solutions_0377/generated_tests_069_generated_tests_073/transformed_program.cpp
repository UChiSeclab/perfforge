#include <bits/stdc++.h>
using namespace std;

// Inserted function to check high iteration invariant
void check_high_iteration_invariant(int n, int x, int y, const vector<int>& a) {
    int count_close_to_x = 0;
    for (int durability : a) {
        if (durability <= x + 1) {
            count_close_to_x++;
        }
    }
    if (x < y && count_close_to_x > n / 2) {
        cerr << "Warning: High iteration invariant triggered - many doors with durability close to x" << endl;
        abort();
    }
}

// Inserted function to check nested loop invariant
void check_nested_loop_invariant(int n, int x, int y, const vector<int>& a) {
    int count_hard_to_break = 0;
    for (int durability : a) {
        if (durability > x && durability < x + y) {
            count_hard_to_break++;
        }
    }
    if (count_hard_to_break > n / 2) {
        cerr << "Warning: Nested loop invariant triggered - many doors toggling between non-zero states" << endl;
        abort();
    }
}

// Inserted function to check threshold invariant
void check_threshold_invariant(int n, int x, const vector<int>& a) {
    int count = 0;
    for (int durability : a) {
        if (durability <= x) {
            count++;
        }
    }
    if (count > n / 2) {
        cerr << "Warning: Threshold invariant triggered - many doors with initial durability <= x" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Inserted invariant checks after input reading
    check_high_iteration_invariant(n, x, y, a);
    check_nested_loop_invariant(n, x, y, a);
    check_threshold_invariant(n, x, a);

    if (x > y) {
        cout << n << "\n";
        return 0;
    } else if (x < y) {
        int doors = n;
        for (int i = 0;; i++) {
            if (i % 2 == 0) {
                int flag = 1;
                for (int j = 0; j < n; j++) {
                    if (a[j] <= x && a[j] != 0) {
                        flag = 0;
                    }
                }
                if (flag) {
                    cout << n - doors << "\n";
                    return 0;
                }
                long long mini = x, pos = -1;
                for (int j = 0; j < n; j++) {
                    if (x - a[j] >= 0) {
                        if (mini > x - a[j]) {
                            pos = j;
                            mini = x - a[j];
                        }
                    }
                }
                a[pos] = 0;
                doors--;
            } else {
                long long mini = x, pos = -1;
                for (int j = 0; j < n; j++) {
                    if (a[j] > 0 && a[j] <= mini) {
                        mini = a[j];
                        pos = j;
                    }
                }
                a[pos] += y;
            }
        }
    } else {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (x >= a[i]) {
                count++;
            }
        }
        if (count % 2) count++;
        cout << count / 2 << "\n";
    }
    return 0;
}