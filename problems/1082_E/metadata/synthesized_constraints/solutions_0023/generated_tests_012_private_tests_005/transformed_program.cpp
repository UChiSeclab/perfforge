#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_large_list_invariant(int listSize) {
    if (listSize > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - large list size for sorting!" << endl;
        abort();
    }
}

void check_outer_loop_invariant(int loopIterations, int n) {
    if (loopIterations > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive outer loop iterations!" << endl;
        abort();
    }
}

void check_frequent_operations_invariant(int operationCount, int threshold) {
    if (operationCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent operations on data structures!" << endl;
        abort();
    }
}

template <typename T>
void __exit(T message);

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &V);

template <class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P);

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, c, ans = 0;
    cin >> n >> c;
    vector<int> A(n + 1), S(500003, 0), C(n + 1, 0);
    vector<vector<int> > P(500003);

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        S[A[i]]++;
        P[A[i]].push_back(i);
        C[i] = C[i - 1] + (A[i] == c);
    }
    ans = C[n];

    int outerLoopIterations = 0;
    for (int i = 0; i < 500003 && ans < n; i++) {
        outerLoopIterations++;
        if (S[i] > 0) {
            ans = max(ans, max(C[n] + 1, S[i]));
            sort(P[i].begin(), P[i].end());

            // Check for large list size before sorting
            check_large_list_invariant(P[i].size());

            int cur = 0, mini = 0;
            for (int j = 0; j < P[i].size(); j++) {
                if (P[i][j] != 0) mini = min(mini, j - C[P[i][j] - 1]);
                cur = max(cur, j + 1 - C[P[i][j]] - mini);
            }
            ans = max(ans, C[n] + cur);
        }
    }

    // Check for excessive outer loop iterations
    check_outer_loop_invariant(outerLoopIterations, n);

    // Hypothetical frequent operations check (if applicable)
    // check_frequent_operations_invariant(someCount, someThreshold);

    cout << ans << endl;
    return 0;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &V) {
    if (!V.empty()) {
        out << "{";
        for (auto v : V) out << v << ", ";
        out << "\b\b}";
    } else {
        out << "{}";
    }
    return out;
}

template <typename T>
void __exit(T message) {
    cout << message << endl;
    exit(0);
}

template <class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P) {
    out << "(" << P.first << ", " << P.second << ")";
    return out;
}