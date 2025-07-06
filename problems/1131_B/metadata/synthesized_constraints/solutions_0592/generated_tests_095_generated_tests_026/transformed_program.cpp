#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// Invariant checks
void check_large_score_difference(int current, int previous) {
    if (current - previous > 1000000) {
        cerr << "Warning: Large score difference detected between consecutive moments!" << endl;
        abort();
    }
}

void check_unequal_score_increase(int aCurrent, int aPrevious, int bCurrent, int bPrevious) {
    if (abs(aCurrent - aPrevious) > 1000 && abs(bCurrent - bPrevious) < 10) {
        cerr << "Warning: Uneven score increase detected!" << endl;
        abort();
    }
    if (abs(bCurrent - bPrevious) > 1000 && abs(aCurrent - aPrevious) < 10) {
        cerr << "Warning: Uneven score increase detected!" << endl;
        abort();
    }
}

void check_large_initial_score(int a, int b) {
    if (a > 1000000 || b > 1000000) {
        cerr << "Warning: Large initial score detected!" << endl;
        abort();
    }
}

int main() {
    int N, A[10001] = {}, B[10001] = {};
    cin >> N;
    
    // Initial score check
    check_large_initial_score(A[0], B[0]);

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];

        // Check for large initial scores
        if (i == 1) {
            check_large_initial_score(A[i], B[i]);
        }

        // Check for large score differences
        check_large_score_difference(A[i], A[i-1]);
        check_large_score_difference(B[i], B[i-1]);

        // Check for uneven score increases
        check_unequal_score_increase(A[i], A[i-1], B[i], B[i-1]);
    }

    int ret = 1;
    for (int i = 1; i <= N; i++) {
        while (A[i - 1] < A[i] || B[i - 1] < B[i]) {
            bool f = A[i - 1] < A[i];
            bool g = B[i - 1] < B[i];
            if (f) {
                if (g) {
                    if (A[i - 1] < B[i - 1])
                        ++A[i - 1];
                    else
                        ++B[i - 1];
                } else {
                    ++A[i - 1];
                }
            } else {
                ++B[i - 1];
            }
            ret += A[i - 1] == B[i - 1];
        }
    }
    cout << ret << endl;
}