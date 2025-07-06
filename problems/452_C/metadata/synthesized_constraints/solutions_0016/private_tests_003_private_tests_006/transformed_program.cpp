#include <bits/stdc++.h>
using namespace std;

void check_vector_size_invariant(size_t v1_size, size_t v2_size) {
    if (v1_size > 10000 || v2_size > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - large vector operations!" << endl;
        abort();
    }
}

void check_sort_invariant(size_t operation_count) {
    if (operation_count > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent sorting operations!" << endl;
        abort();
    }
}

void check_iteration_invariant(size_t iteration_count) {
    if (iteration_count > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration counts!" << endl;
        abort();
    }
}

void check_function_call_invariant(int n) {
    if (n > 900) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive function calls!" << endl;
        abort();
    }
}

int N, M;
double rez;
vector<double> v1, v2;

double prob(int k) {
    v1.clear();
    v2.clear();
    if (k > M) return 0;
    for (int i = M - k + 1; i <= M; ++i) {
        v1.push_back(i);
    }
    for (int i = M * N - N - M + k + 1; i <= M * N - N; ++i) {
        v1.push_back(i);
    }
    for (int i = N - k + 1; i <= N; ++i) {
        v1.push_back(i);
    }
    for (int i = M * N - M + 1; i <= M * N; ++i) {
        v2.push_back(i);
    }
    for (int i = 1; i <= k; ++i) {
        v2.push_back(i);
    }

    check_vector_size_invariant(v1.size(), v2.size()); // Check for large vector operations

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    check_sort_invariant(v1.size()); // Check for frequent sorting operations

    double ret = 1;
    for (int i = 0; i < v1.size(); ++i) {
        ret = ret * v1[i] / v2[i];
    }

    check_iteration_invariant(v1.size()); // Check for high iteration counts

    return ret;
}

int main() {
    scanf("%d%d", &N, &M);

    check_function_call_invariant(N); // Check for excessive function calls

    if (N == 1) {
        printf("%.12lf", 1.0);
        return 0;
    }
    for (int i = 1; i <= N; ++i) {
        double x = prob(i);
        rez += x * i * i / N;
    }
    printf("%.12lf", rez);
    return 0;
}