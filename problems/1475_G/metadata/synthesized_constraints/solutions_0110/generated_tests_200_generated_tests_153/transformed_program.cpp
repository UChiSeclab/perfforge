#include<cstdio>
#include<algorithm>
using namespace std;

int T, N;
int A[1<<18], B[1<<18];

// Checker functions
void check_divisibility_invariant(int n, int max_val) {
    if (n > 100 && max_val <= 100) {
        cerr << "Warning: Performance bottleneck condition triggered due to high divisibility checks!" << endl;
        abort();
    }
}

void check_multiplicity_invariant(const int A[], int length, int threshold) {
    int count_small_numbers = 0;
    for (int i = 0; i < length; ++i) {
        if (A[i] < threshold) {
            count_small_numbers++;
        }
    }
    if (count_small_numbers > length / 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to high multiplicity of small numbers!" << endl;
        abort();
    }
}

void check_initialization_invariant(int t, int n) {
    if (t * n > 500000) {
        cerr << "Warning: Performance bottleneck condition triggered due to heavy initialization overhead!" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &T);

    // Check for initialization overhead
    check_initialization_invariant(T, 200000); // Reasonable upper bound per constraints

    for(; T--; ) {
        scanf("%d", &N);

        for(int i = 0; i < 1<<18; i++) A[i] = B[i] = 0;

        int max_val = 0;
        for(int i = 0; i < N; i++) {
            int a;
            scanf("%d", &a);
            A[a]++;
            if (a > max_val) max_val = a;
        }

        // Check for high divisibility and multiplicity
        check_divisibility_invariant(N, max_val);
        check_multiplicity_invariant(A, N, 100);

        int ans = 0;
        for(int i = 1; i < 1<<18; i++) {
            ans = max(ans, A[i] += B[i]);
            for(int j = i + i; j < 1<<18; j += i) B[j] = max(B[j], A[i]);
        }

        printf("%d\n", N - ans);
    }
}