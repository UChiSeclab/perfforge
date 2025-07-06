#include <bits/stdc++.h>
using namespace std;

void check_broad_coverage_invariant(int M, int total_initial_coverage) {
    if (total_initial_coverage < M / 2) {
        cerr << "Warning: Performance bottleneck triggered - large M relative to initial coverage!" << endl;
        abort();
    }
}

void check_sparse_antenna_invariant(int N, int M, const vector<pair<int, int>>& ants) {
    if (N < M / 1000) {
        cerr << "Warning: Performance bottleneck triggered - sparse initial antenna placement!" << endl;
        abort();
    }
}

void check_high_antenna_count_invariant(int N, int M, const vector<pair<int, int>>& ants) {
    int minimal_coverage_count = 0;
    for (const auto& ant : ants) {
        if (ant.second < M / 1000) {
            minimal_coverage_count++;
        }
    }
    if (minimal_coverage_count > N / 2) {
        cerr << "Warning: Performance bottleneck triggered - many antennas with minimal initial coverage!" << endl;
        abort();
    }
}

void check_frequent_updates_invariant(int N, int M) {
    long long maximum_operations = (long long)N * M;
    if (maximum_operations > 1e8) {
        cerr << "Warning: Performance bottleneck triggered - frequent updates to dp/suffix_min arrays!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> ants(N);
    int total_initial_coverage = 0;

    for (int i = 0; i < N; ++i) {
        cin >> ants[i].first >> ants[i].second;
        total_initial_coverage += 2 * ants[i].second;
        M = max(M, ants[i].first + ants[i].second);
    }

    check_broad_coverage_invariant(M, total_initial_coverage);
    check_sparse_antenna_invariant(N, M, ants);
    check_high_antenna_count_invariant(N, M, ants);
    check_frequent_updates_invariant(N, M);

    sort(ants.begin(), ants.end());
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 3 * M));
    vector<vector<int>> suffix_min(N + 1, vector<int>(M + 1, 3 * M));

    for (int i = 0; i < N; ++i) {
        int l = ants[i].first - ants[i].second;
        int r = ants[i].first + ants[i].second;

        for (int j = 1; j <= M; ++j) {
            dp[i][j] = 3 * M;
            if (i > 0) dp[i][j] = dp[i - 1][j];
            if (j < r) continue;
            int ldelta = max(0, l - 1);
            int rdelta = max(0, j - r);
            dp[i][j] = min(dp[i][j], max(ldelta, rdelta));
            int delta = j - r;
            int new_l = max(1, l - delta);
            if (i != 0 || new_l == 1) {
                dp[i][j] = min(dp[i][j], delta + (new_l == 1 || i == 0 ? 0 : suffix_min[i - 1][new_l - 1]));
            }
        }

        for (int j = M; j >= 1; --j) {
            suffix_min[i][j] = dp[i][j];
            if (j < M) {
                suffix_min[i][j] = min(suffix_min[i][j], suffix_min[i][j + 1]);
            }
        }
    }
    int answer = 3 * M;
    for (int i = 0; i < N; ++i) {
        answer = min(answer, dp[i][M]);
    }
    cout << answer << endl;
    return 0;
}