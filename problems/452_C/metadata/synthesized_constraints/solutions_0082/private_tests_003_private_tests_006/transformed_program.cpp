#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:500000000")
using namespace std;

void check_vector_size_invariant(int n, int m, int A_size, int B_size) {
    if ((n > 500 && m > 500) && (A_size > 10000 || B_size > 10000)) {
        cerr << "Warning: Performance bottleneck due to large vector sizes leading to expensive sorting!" << endl;
        abort();
    }
}

void check_loop_iteration_invariant(int n) {
    if (n > 500) {
        cerr << "Warning: Performance bottleneck due to large number of loop iterations over k!" << endl;
        abort();
    }
}

void check_multiplicative_accumulation_invariant(int n, int m, int A_size, int B_size) {
    if ((n > 500 && m > 500) && (A_size * B_size > 1000000)) {
        cerr << "Warning: Performance bottleneck due to excessive multiplicative operations!" << endl;
        abort();
    }
}

double C[1009][1009];
vector<int> A, B;

void add(int n, int k, vector<int> &A, vector<int> &B) {
    for (int i = 0; i < k; i++) B.push_back(k - i), A.push_back(n - i);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Insert check for loop iteration invariant
    check_loop_iteration_invariant(n);

    double res = 0;
    for (int k = 0; k <= n; k++) {
        A.clear(), B.clear();
        add(m, k, A, B);
        add(n * m - m, n - k, A, B);
        add(n * m, n, B, A);

        // Insert check for vector size and sorting invariant
        check_vector_size_invariant(n, m, A.size(), B.size());

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        double ml = 1.0 * k * k / n / n;

        // Insert check for multiplicative accumulation invariant
        check_multiplicative_accumulation_invariant(n, m, A.size(), B.size());

        for (int i = 0; i < A.size(); i++) ml *= 1.0 * A[i] / B[i];
        res += ml;
    }
    
    printf("%.13f\n", n * res);
}