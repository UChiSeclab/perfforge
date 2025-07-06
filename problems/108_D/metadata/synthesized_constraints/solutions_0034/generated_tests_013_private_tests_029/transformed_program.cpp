#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const bool debug = true;
const long long INFL = LLONG_MAX;
int A, B, N, M, H, S[1010];
long double memo[100100][102];
bool was[100100][102];

long double dp(int b, int n) {
    int a = A;
    if (a + b < n) return 0;
    if (b < n) return 0;
    if (n == 0) return 1;
    if (a < 0 || b < 0 || n < 0) return 0;
    if (was[b][n]) return memo[b][n];
    long double x = (long double)n / (a + b);
    memo[b][n] = x * dp(b - 1, n - 1) + (1 - x) * dp(b - 1, n);
    was[b][n] = 1;
    return memo[b][n];
}

// Insert checker functions
void check_recursion_depth_invariant(int totalPlayers, int totalStudents, int departments) {
    if (totalPlayers > totalStudents * 0.9 && departments > 50) {
        cerr << "Warning: Performance bottleneck condition triggered due to high recursion depth!" << endl;
        abort();
    }
}

void check_availability_invariant(int totalStudents, int requiredPlayers) {
    if (totalStudents < requiredPlayers + 5) {
        cerr << "Warning: Performance bottleneck condition triggered due to limited student availability!" << endl;
        abort();
    }
}

void check_memoization_efficiency_invariant(int availablePlayers, int requiredPlayers) {
    if (availablePlayers < requiredPlayers * 0.3) {
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient memoization!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.precision(15);
    cout << fixed;
    cin >> N >> M >> H;
    for (int(i) = 1; (i) <= (M); (i)++) cin >> S[i];
    S[H]--;
    for (int(i) = 1; (i) <= (M); (i)++)
        if (i == H)
            A = S[i];
        else
            B += S[i];
    N--;

    // Total number of students
    int totalStudents = A + B + 1; 

    // Insert invariants to check performance bottlenecks
    check_recursion_depth_invariant(N, totalStudents, M);
    check_availability_invariant(totalStudents, N);
    check_memoization_efficiency_invariant(B, N);

    if (A + B < N) {
        cout << -1 << '\n';
    } else {
        cout << (1 - dp(B, N)) << '\n';
    }
}