#include <bits/stdc++.h>
using namespace std;

int LO[10], HI[10];
int SN;

double dp(int id, int M, int s) {
    if (id == SN) return s <= 0 ? 1 : 0;
    double r = 0;
    double den = (HI[id] - LO[id] + 1);
    if (LO[id] <= M && M <= HI[id]) {
        r += 1.0 / den * dp(id + 1, M, s - 1);
    }
    if (LO[id] < M) {
        double num = HI[id] < M ? den : (M - LO[id]);
        r += num / den * dp(id + 1, M, s);
    }
    return r;
}

void check_large_range_invariant(int L[], int H[], int n) {
    for (int i = 0; i < n; ++i) {
        if ((H[i] - L[i] > 8000) && H[i] > 9000) {
            cerr << "Warning: Performance bottleneck condition triggered - large range with high upper bounds!" << endl;
            abort();
        }
    }
}

void check_similar_high_bids(int L[], int H[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(H[i] - H[j]) < 500 && H[i] > 8000 && H[j] > 8000) {
                cerr << "Warning: Performance bottleneck condition triggered - similar high bids across companies!" << endl;
                abort();
            }
        }
    }
}

void check_high_H_value(int H[], int n) {
    for (int i = 0; i < n; ++i) {
        if (H[i] > 9500) {
            cerr << "Warning: Performance bottleneck condition triggered - high value of H[i]!" << endl;
            abort();
        }
    }
}

int main() {
    int L[10], H[10];
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> L[i] >> H[i];
    }

    // Insert performance checks after reading input
    check_large_range_invariant(L, H, N);
    check_similar_high_bids(L, H, N);
    check_high_H_value(H, N);

    double ex = 0;
    for (int i = 0; i < N; ++i) {
        int id = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            LO[id] = L[j];
            HI[id] = H[j];
            id++;
        }
        SN = N - 1;
        for (int j = 1; j < H[i]; ++j) {
            double den = H[i] - L[i] + 1;
            double p = j < L[i] ? 1 : (1.0 * (H[i] - j) / den);
            ex += j * dp(0, j, 1) * p;
        }
    }
    SN = N;
    for (int i = 0; i < N; ++i) {
        LO[i] = L[i];
        HI[i] = H[i];
    }
    for (int i = 1; i <= 10000; ++i) {
        ex += i * dp(0, i, 2);
    }
    printf("%0.10lf\n", ex);
}