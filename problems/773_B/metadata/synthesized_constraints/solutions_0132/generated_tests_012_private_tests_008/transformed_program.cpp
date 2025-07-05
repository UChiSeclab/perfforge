#include <bits/stdc++.h>
using namespace std;
const int K = 5;
const int INF = 1e9;
int t[2][K];
int num[K];
int n;
int Pow2[K + 2] = {1, 2, 4, 8, 16, 32, INF};

void check_iterative_search_space(int iterations) {
    if (iterations > 7000) {  // Threshold based on n and configurations
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations in iterative search space!" << endl;
        abort();
    }
}

void check_frequent_solve_calls(int solveCalls) {
    if (solveCalls > 5000) {  // Arbitrary threshold considering problem constraints
        cerr << "Warning: Performance bottleneck condition triggered - excessive calls to solve() function!" << endl;
        abort();
    }
}

int solve(int v) {
    int arr[K];
    for (int i = 0; i < K; i++) {
        arr[i] = v % 6;
        v /= 6;
    }
    pair<int, int> bots[K];
    int iterationCount = 0;
    for (int s = n; s < 8000; s++) {
        iterationCount++;
        fill(bots, bots + K, pair<int, int>(0, INF));
        bool ind = true;
        for (int i = 0; i < K; i++) {
            if (t[0][i] == -1) {
                if (!(num[i] * Pow2[arr[i]] <= s &&
                      (arr[i] == 5 || s < num[i] * Pow2[arr[i] + 1]))) {
                    ind = false;
                    break;
                }
                bots[i] = {0, 0};
            } else {
                bots[i].first =
                    max(bots[i].first,
                        (arr[i] == 5 ? -num[i] : (s / Pow2[arr[i] + 1] + 1 - num[i])));
                bots[i].second = min(bots[i].second, s / Pow2[arr[i]] - num[i]);
            }
        }
        if (!ind) continue;
        int max_sum = 0;
        for (int i = 0; i < K; i++) {
            if (bots[i].first > bots[i].second) {
                ind = false;
                break;
            }
            max_sum = max(max_sum, bots[i].first);
        }
        if (!ind || max_sum + n > s) {
            continue;
        }
        check_iterative_search_space(iterationCount);  // Insert checker for iterations
        return s - n;
    }
    return -1;
}

bool check(int v) {
    int arr[K];
    for (int i = 0; i < K; i++) {
        arr[i] = v % 6;
        v /= 6;
    }
    int score[K];
    for (int i = 0; i < K; i++) score[i] = 500 * (arr[i] + 1);
    int s[2] = {0, 0};
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 2; j++) {
            if (t[j][i] == -1) continue;
            s[j] += score[i] * (250 - t[j][i]) / 250;
        }
    }
    return s[0] > s[1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < K; j++) {
            int tmp;
            cin >> tmp;
            if (i < 2) {
                t[i][j] = tmp;
            }
            if (tmp != -1) num[j]++;
        }
    }
    int res = INF;
    int solveCallCount = 0;
    for (int i = 0; i < 7776; i++) {
        if (check(i)) {
            int tmp = solve(i);
            solveCallCount++;
            if (tmp >= 0) res = min(res, tmp);
        }
    }
    check_frequent_solve_calls(solveCallCount);  // Insert checker for solve() calls
    if (res < INF) {
        cout << res << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}