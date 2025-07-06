#include <bits/stdc++.h>
using namespace std;
const int MAXN = 12;
int n;
char mtrx[MAXN][MAXN];
char temp[MAXN][MAXN];
char comp[MAXN][MAXN];

// Checker functions
void check_transformation_repetition(int n, int i, int j, int k, int f) {
    if (n == 10 && i * j * k * f > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive transformations!" << endl;
        abort();
    }
}

void check_rotation_flip_complexity(int n, int totalTransformations) {
    if (n == 10 && totalTransformations > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - high rotation complexity!" << endl;
        abort();
    }
}

void check_verification_checks(int n, int checkCount) {
    if (n == 10 && checkCount > 5000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive verification checks!" << endl;
        abort();
    }
}

void translate_matrix(int dx, int dy) {
    char temp2[MAXN][MAXN];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            temp2[i][j] = temp[((i - dy) % n + n) % n][((j - dx) % n + n) % n];
    memcpy(temp, temp2, sizeof(temp));
}

void rotate_matrix(int r) {
    char temp2[MAXN][MAXN];
    while (r--) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                temp2[i][j] = temp[n - j - 1][i];
    }
    memcpy(temp, temp2, sizeof(temp));
}

void flip_matrix(int f) {
    char temp2[MAXN][MAXN];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            temp2[i][j] = temp[f & 1 ? n - i - 1 : i][f & 2 ? n - j - 1 : j];
    memcpy(temp, temp2, sizeof(temp));
}

bool check() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (temp[i][j] != comp[i][j]) return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mtrx[i][j], temp[i][j] = mtrx[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> comp[i][j];
    
    bool ok = false;
    int totalTransformations = 0;
    int checkCount = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 4; ++k)
                for (int f = 0; f < 4; ++f) {
                    totalTransformations++;
                    memcpy(temp, mtrx, sizeof(temp));
                    translate_matrix(i, j);
                    rotate_matrix(k);
                    flip_matrix(f);
                    if (check()) {
                        checkCount++;
                        i = j = n, k = 4;
                        ok = true;
                    }
                    // Checkers for bottleneck conditions
                    check_transformation_repetition(n, i, j, k, f);
                    check_verification_checks(n, checkCount);
                }

    check_rotation_flip_complexity(n, totalTransformations);

    cout << (ok ? "Yes\n" : "No\n");
}