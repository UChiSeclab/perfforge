#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10; // max value of N as per problem constraints
string s[MAX_N], x[MAX_N];
int n;

// Check for repeated rotations of a large matrix
void check_repeated_rotations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated rotations of large matrix!" << endl;
        abort();
    }
}

// Check for complex flip requirements and multiple rotations
void check_complex_flip(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - complex flip requirements and multiple rotations!" << endl;
        abort();
    }
}

// Check for large matrix operations
void check_large_matrix(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large matrix operations!" << endl;
        abort();
    }
}

void rotate() {
    string t[MAX_N];
    for (int i = 0; i < n; ++i) {
        t[i] = string(n, '0');
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            t[i][j] = s[j][n - 1 - i];
    for (int i = 0; i < n; ++i) s[i] = t[i];
}

void flip() {
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            swap(s[i][j], s[j][i]);
}

void solve() {
    cin >> n;

    // Check for large matrix operations
    check_large_matrix(n > 8); // Example threshold based on problem constraints

    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> x[i];

    int rotation_count = 0;

    for (int t = 0; t < 4; ++t) {
        bool check = true;
        for (int i = 0; i < n; ++i)
            if (s[i] != x[i]) check = false;
        if (check) {
            puts("Yes");
            return;
        }
        rotate();
        rotation_count++;
    }

    // Check for repeated rotations
    check_repeated_rotations(rotation_count >= 4);

    flip();
    rotation_count = 0;

    for (int t = 0; t < 4; ++t) {
        bool check = true;
        for (int i = 0; i < n; ++i)
            if (s[i] != x[i]) check = false;
        if (check) {
            puts("Yes");
            return;
        }
        rotate();
        rotation_count++;
    }

    // Check for complex flip requirements and multiple rotations
    check_complex_flip(rotation_count >= 4 && flip_count > 0);

    puts("No");
}

int main() {
    int Test = 1;
    for (int i = 0; i < Test; ++i) {
        solve();
    }
}