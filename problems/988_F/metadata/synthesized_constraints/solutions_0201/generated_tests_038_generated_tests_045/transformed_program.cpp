#include <bits/stdc++.h>
using namespace std;

int a, n, m, inf = (int)1e9;
vector<unordered_map<int, int>> memo;
vector<int> rain;
vector<int> umbrella;

// Performance checkers
void check_memoization_efficiency(int pos, int memoSizeThreshold) {
    if (memo[pos].size() > memoSizeThreshold) {
        cerr << "Warning: Excessive memoization states explored - potential inefficiency!" << endl;
        abort();
    }
}

void check_umbrella_weight_and_distribution(int position, int weightThreshold) {
    if (umbrella[position] > weightThreshold) {
        cerr << "Warning: High umbrella weight impacting fatigue!" << endl;
        abort();
    }
}

void check_path_decision_complexity(int pos, int nonRainSegmentThreshold) {
    static int nonRainCount = 0;
    if (!rain[pos]) {
        nonRainCount++;
        if (nonRainCount > nonRainSegmentThreshold) {
            cerr << "Warning: High complexity due to multiple non-rain segments!" << endl;
            abort();
        }
    } else {
        nonRainCount = 0; // reset when encountering rain
    }
}

void check_umbrella_availability(int availableUmbrellas, int umbrellaThreshold) {
    if (availableUmbrellas < umbrellaThreshold) {
        cerr << "Warning: Insufficient umbrellas for rainy segments!" << endl;
        abort();
    }
}

int fatigue(int pos, int w) {
    if (pos == a) return 0;
    check_memoization_efficiency(pos, 500);  // Check memoization efficiency condition
    if (not memo[pos].empty()) {
        auto s = memo[pos].find(w);
        if (s != end(memo[pos])) return s->second;
    }
    int best = inf;
    if (umbrella[pos]) {
        check_umbrella_weight_and_distribution(pos, 50000);  // Check umbrella weight condition
        best = min(best, umbrella[pos] + fatigue(pos + 1, umbrella[pos]));
    }
    if (not w) {
        if (rain[pos] and not umbrella[pos]) return inf;
    } else {
        best = min(best, w + fatigue(pos + 1, w));
    }
    if (not rain[pos]) {
        check_path_decision_complexity(pos, 100);  // Check path decision complexity condition
        best = min(best, fatigue(pos + 1, 0));
    }
    memo[pos][w] = best;
    return best;
}

void solve() {
    cin >> a >> n >> m;
    memo.resize(a + 1);
    rain.resize(a + 1);
    umbrella.resize(a + 1, inf);

    int l, r;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        for (int j = l; j < r; ++j) {
            rain[j] = 1;
        }
    }

    int x, p;
    int availableUmbrellas = 0;
    for (int i = 0; i < m; ++i) {
        cin >> x >> p;
        umbrella[x] = min(p, umbrella[x]);
        availableUmbrellas++;
    }

    check_umbrella_availability(availableUmbrellas, 1);  // Check umbrella availability condition

    int best = fatigue(0, 0);
    cout << (best < inf ? best : -1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}