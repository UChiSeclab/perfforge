#include <bits/stdc++.h>
using namespace std;
using Matrix = vector<vector<char>>;

// Checker functions
void check_rotation_invariant(int rotationCount) {
    if (rotationCount > 10) { // Excessive rotations
        cerr << "Warning: Performance bottleneck condition triggered - excessive rotations!" << endl;
        abort();
    }
}

void check_transformation_invariant(int transformationCount) {
    if (transformationCount > 50) { // Excessive transformations
        cerr << "Warning: Performance bottleneck condition triggered - excessive transformations!" << endl;
        abort();
    }
}

void check_equivalence_invariant(int checkCount) {
    if (checkCount > 100) { // Excessive equivalence checks
        cerr << "Warning: Performance bottleneck condition triggered - excessive equivalence checks!" << endl;
        abort();
    }
}

Matrix Rotate90(const Matrix& m) {
    const int n = (int)m.size();
    Matrix res(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = m[n - 1 - j][i];
        }
    }
    return res;
}

Matrix Rotate180(const Matrix& m) { return Rotate90(Rotate90(m)); }
Matrix Rotate270(const Matrix& m) { return Rotate90(Rotate180(m)); }

Matrix FlipVertical(const Matrix& m) {
    const int n = (int)m.size();
    Matrix res(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = m[n - i - 1][j];
        }
    }
    return res;
}

Matrix FlipHorizontal(const Matrix& m) {
    return Rotate180(FlipVertical(Rotate180(m)));
}

int main() {
    int n;
    cin >> n;
    Matrix a(n, vector<char>(n)), b(n, vector<char>(n));
    for (auto& x : {&a, &b}) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> (*x)[i][j];
            }
        }
    }
    
    vector<Matrix (*)(const Matrix&)> funcs = {Rotate90, Rotate180, Rotate270};
    int rotationCount = 0;
    int transformationCount = 0;
    int checkCount = 0;
    
    for (int i = 0; i <= 3; ++i) {
        Matrix x = (i == 3) ? b : funcs[i](b);
        rotationCount++;
        check_rotation_invariant(rotationCount);
        
        for (int mask = 0; mask <= 3; ++mask) {
            transformationCount++;
            check_transformation_invariant(transformationCount);
            
            if (mask & 1) {
                x = FlipVertical(x);
            }
            if (mask >> 1 & 1) {
                x = FlipHorizontal(x);
            }
            
            for (int j = 0; j <= 3; ++j) {
                Matrix y = (j == 3) ? x : funcs[j](x);
                checkCount++;
                check_equivalence_invariant(checkCount);
                
                if (y == a) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
}