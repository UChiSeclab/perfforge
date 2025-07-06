#include <bits/stdc++.h>
using namespace std;
long long X[110], Y[110];
long long mat[210][210];

void check_vector_multiple_invariant(long long a, long long b, long long vx, long long vy) {
    if (vx == 0 && vy == 0 && (a != 0 || b != 0)) {
        cerr << "Warning: Performance bottleneck condition triggered - target not reachable when net vector is zero!" << endl;
        abort();
    }
}

void check_minimal_adjustment_invariant(long long vx, long long vy) {
    if (vx == 0 && vy == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - minimal net movement per cycle!" << endl;
        abort();
    }
}

void check_matrix_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - matrix checking inefficiency!" << endl;
        abort();
    }
}

int main(int argc, char** argv) {
    long long a, b;
    cin >> a >> b;
    string PAT;
    cin >> PAT;
    long long x = 0, y = 0;
    X[0] = x, Y[0] = y;
    mat[x + 105][y + 105] = 1;
    int N = PAT.size();
    
    for (int i = 0; i < PAT.size(); ++i) {
        if (PAT[i] == 'U')
            y++;
        else if (PAT[i] == 'D')
            y--;
        else if (PAT[i] == 'L')
            x--;
        else
            x++;
        mat[x + 105][y + 105] = 1;
        X[i + 1] = x, Y[i + 1] = y;
    }
    
    long long vx = X[N], vy = Y[N];
    check_minimal_adjustment_invariant(vx, vy); // Check for minimal net movement

    check_vector_multiple_invariant(a, b, vx, vy); // Check for target reachability

    long long mi = 0;
    if (vx && vy)
        mi = min(abs(a / vx), abs(b / vy));
    else if (vx)
        mi = abs(a / vx);
    else if (vy)
        mi = abs(b / vy);
    mi = max(mi - 1000, 0LL);
    a -= vx * mi;
    b -= vy * mi;

    bool ok = 0;
    for (int i = 0; i < 1000000 && !ok; ++i) {
        if (a > -100 && a < 100 && b > -100 && b < 100) {
            check_matrix_invariant(!mat[a + 105][b + 105]); // Check matrix inefficiency
            if (mat[a + 105][b + 105]) ok = 1;
        }
        a -= vx;
        b -= vy;
    }

    cout << (ok ? "Yes" : "No") << endl;
}