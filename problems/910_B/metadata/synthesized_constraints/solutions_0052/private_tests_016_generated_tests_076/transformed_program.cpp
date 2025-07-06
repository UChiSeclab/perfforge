#include <bits/stdc++.h>
using namespace std;

long long n, i, j, k, l, sum = 0, flag = 0, ans = 0, a, b, A, B;
vector<long long int> v;

// Checker functions
void check_recursion_invariant(int n, int a, int b) {
    if (n <= a + b) {
        cerr << "Warning: Recursion invariant triggered - small bar length relative to needed pieces!" << endl;
        abort();
    }
}

void check_remainder_invariant(int k, int A, int B) {
    if (k <= A || k <= B) {
        cerr << "Warning: Remainder invariant triggered - small remainder leads to excessive recursion!" << endl;
        abort();
    }
}

void check_minimal_bar_invariant(int n, int A, int B) {
    if (n == A || n == B) {
        cerr << "Warning: Minimal bar invariant triggered - bar length barely sufficient for one side!" << endl;
        abort();
    }
}

long long f(int a, int b, int k) {
    if (a == 0 && b == 0) return 0;
    long long l = 1000000007;
    if (a != 0) {
        if (k - A > 0) l = min(l, f(a - 1, b, k - A));
        if (k - A == 0) {
            l = min(l, f(a - 1, b, 0));
            l = min(l, 1 + f(a - 1, b, n));
        }
        if (k < A) l = min(l, 1 + f(a, b, n));
    }
    if (b != 0) {
        if (k - B > 0) l = min(l, f(a, b - 1, k - B));
        if (k - B == 0) {
            l = min(l, f(a, b - 1, 0));
            l = min(l, 1 + f(a, b - 1, n));
        }
        if (k < B) l = min(l, 1 + f(a, b, n));
    }
    return l;
}

int main() {
    int t = 1;
    while (t--) {
        cin >> n >> A >> B;

        // Insert invariants checks after reading inputs
        check_recursion_invariant(n, A, B);
        check_minimal_bar_invariant(n, A, B);

        cout << 1 + f(4, 2, n) << '\n';
    }
    return 0;
}