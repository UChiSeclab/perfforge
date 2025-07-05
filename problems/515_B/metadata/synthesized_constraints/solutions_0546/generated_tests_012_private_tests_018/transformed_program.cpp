#include <bits/stdc++.h>
using namespace std;

bool m[105], h[105];
int n, M, fm, fh, x;
bool dp[105][105];

void check_initial_overlap(int happy_boys, int total_boys, int happy_girls, int total_girls) {
    int min_required_happy = (total_boys + total_girls) / 2;
    if ((happy_boys + happy_girls) < min_required_happy) {
        cerr << "Warning: Insufficient initial overlap of happiness!" << endl;
        abort();
    }
}

void check_iteration_count(int current_iterations, int threshold = 1000) {
    if (current_iterations > threshold) {
        cerr << "Warning: Excessive iterations detected!" << endl;
        abort();
    }
}

void check_sparse_initial_happiness(int happy_boys, int total_boys, int happy_girls, int total_girls) {
    if (happy_boys == 0 || happy_girls == 0) {
        cerr << "Warning: Sparse initial happiness distribution!" << endl;
        abort();
    }
}

void check_large_matrix_operations(int n, int m) {
    if (n * m > 10000) {  // Adjust threshold based on problem constraints
        cerr << "Warning: Potential large matrix operations!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d%d", &n, &M, &fm);
    for (int i = 0; i < fm; ++i) {
        scanf("%d", &x);
        m[x] = 1;
    }
    scanf("%d", &fh);
    for (int i = 0; i < fh; ++i) {
        scanf("%d", &x);
        h[x] = 1;
    }
  
    // Check for performance bottlenecks
    check_initial_overlap(fm, n, fh, M);
    check_sparse_initial_happiness(fm, n, fh, M);
    check_large_matrix_operations(n, M);

    if (fm == n && fh == M) {
        puts("Yes");
        return 0;
    }

    int d, i, j;
    d = i = j = 0;
    while (d <= 1000000) {
        dp[i][j] = 1;
        if (m[i] || h[j]) {
            if (!m[i]) fm++;
            if (!h[j]) fh++;
            m[i] = h[j] = 1;
        }
        if (fm == n && fh == M) {
            puts("Yes");
            return 0;
        }
        d++;
        i = d % n;
        j = d % M;

        // Check iteration count for early detection of excessive iterations
        check_iteration_count(d, 1000);  // You can adjust threshold if needed
    }

    if (fm == n && fh == M)
        puts("Yes");
    else
        puts("No");
    return 0;
}