#include <bits/stdc++.h>
using namespace std;

vector<vector<long long> > mul(vector<vector<long long> > a, vector<vector<long long> > b) {
    // Check for potentially large matrix operations
    check_matrix_operations(a.size(), b.size());

    vector<vector<long long> > c(a.size(), vector<long long>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int x = 0; x < b[0].size(); x++) {
            for (int j = 0; j < b.size(); j++)
                c[i][x] = (c[i][x] + a[i][j] * b[j][x]) % 998244353;
        }
    }
    return c;
}

vector<vector<long long> > pow(vector<vector<long long> > a, long long x) {
    // Check for deep recursion
    check_recursive_depth(x);

    if (x == 1) return a;
    vector<vector<long long> > tmp = pow(a, x / 2);
    tmp = mul(tmp, tmp);
    if (x % 2) tmp = mul(tmp, a);
    return tmp;
}

int main() {
    long long n, m, l, r;
    cin >> n >> m >> l >> r;

    // Check for large grid size implying potential performance bottleneck
    check_large_grid(n, m);

    long long e = r / 2 - (l - 1) / 2, o = (r + 1) / 2 - l / 2;
    vector<vector<long long> > mat({{e, o}, {o, e}});
    mat = pow(mat, n * m);
    cout << (mat[0][0] + (n * m % 2) * mat[0][1]) % 998244353;

    return 0;
}

// Checker functions implementation
void check_large_grid(long long n, long long m) {
    if (n * m > 1000000) { // Threshold chosen for demonstration purposes
        cerr << "Warning: Performance bottleneck condition triggered due to large matrix exponentiation!" << endl;
        abort();
    }
}

void check_matrix_operations(int a_size, int b_size) {
    if (a_size > 100 || b_size > 100) { // Arbitrarily chosen threshold for matrix size
        cerr << "Warning: Performance bottleneck condition triggered due to large matrix operations!" << endl;
        abort();
    }
}

void check_recursive_depth(long long depth) {
    if (depth > 20) { // Example threshold for recursion depth
        cerr << "Warning: Performance bottleneck condition triggered due to deep recursion!" << endl;
        abort();
    }
}