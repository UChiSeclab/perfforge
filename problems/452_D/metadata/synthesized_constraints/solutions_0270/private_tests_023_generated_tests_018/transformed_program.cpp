#include <bits/stdc++.h>
using namespace std;

int k, n1, n2, n3, t1, t2, t3;
int A[4][10009];

void check_machine_contention(int k, int n1, int n2, int n3) {
    if (k > 10 * n1 || k > 10 * n2 || k > 10 * n3) {
        cerr << "Warning: Performance bottleneck - high machine contention due to large k relative to machine counts." << endl;
        abort();
    }
}

void check_process_time(int n1, int n2, int n3, int t1, int t2, int t3) {
    if ((t1 > 100 && n1 < 10) || (t2 > 100 && n2 < 10) || (t3 > 100 && n3 < 10)) {
        cerr << "Warning: Performance bottleneck - long processing times with limited machine availability." << endl;
        abort();
    }
}

void check_specific_machine_bottleneck(int n1, int n2, int n3) {
    if (n1 < n2 / 2 || n1 < n3 / 2 || n2 < n1 / 2 || n2 < n3 / 2 || n3 < n1 / 2 || n3 < n2 / 2) {
        cerr << "Warning: Performance bottleneck - imbalance in machine types causing bottleneck." << endl;
        abort();
    }
}

int getsttime() {
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < k; i++) {
        if (A[0][i] < A[0][a]) a = i;
    }
    for (int i = 0; i < n1; i++) {
        if (A[1][i] < A[1][b]) b = i;
    }
    for (int i = 0; i < n2; i++) {
        if (A[2][i] < A[2][c]) c = i;
    }
    for (int i = 0; i < n3; i++) {
        if (A[3][i] < A[3][d]) d = i;
    }
    int st;
    st = max(max(max(0, A[1][b]), A[2][c] - t1), A[3][d] - t1 - t2);
    A[0][a] = st;
    A[1][b] = st + t1;
    A[2][c] = st + t1 + t2;
    A[3][d] = st + t1 + t2 + t3;
    return st;
}

int main() {
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    memset(A, 0, sizeof(A));

    // Check for performance bottlenecks
    check_machine_contention(k, n1, n2, n3); // Check for high machine contention
    check_process_time(n1, n2, n3, t1, t2, t3); // Check for long processing times
    check_specific_machine_bottleneck(n1, n2, n3); // Check for imbalance in machine types

    int x;
    for (int i = 0; i < k; i++) {
        x = getsttime();
    }
    cout << x + t1 + t2 + t3 << endl;
    return 0;
}