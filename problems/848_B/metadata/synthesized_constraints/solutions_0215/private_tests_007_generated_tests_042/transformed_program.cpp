#include <bits/stdc++.h>
using namespace std;

int n, w, h;
unordered_map<int, vector<pair<int, int>>> starts;
unordered_map<int, vector<pair<int, pair<int, int>>>> endss;
pair<int, int> results[100001];

void check_high_dancers(int n) {
    if (n > 10000) {
        cerr << "Warning: Performance bottleneck due to high number of dancers!" << endl;
        abort();
    }
}

void check_large_sort_size(const unordered_map<int, vector<pair<int, int>>>& map) {
    for (const auto& entry : map) {
        if (entry.second.size() > 10000) {
            cerr << "Warning: Performance bottleneck due to large sorting groups!" << endl;
            abort();
        }
    }
}

void check_complex_combinations(int n, int mapSize) {
    if (n > 10000 && mapSize > 10000) {
        cerr << "Warning: Performance bottleneck due to complex group combinations!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> w >> h;

    // Check for high number of dancers
    check_high_dancers(n);

    for (int i = 0; i < n; i++) {
        int g, p, t;
        cin >> g >> p >> t;
        if (g == 1) {
            starts[p - t].push_back(make_pair(p + t, i));
            endss[p - t].push_back(make_pair(p - h, make_pair(p, h)));
        } else {
            starts[p - t].push_back(make_pair(-t - p, i));
            endss[p - t].push_back(make_pair(w - p, make_pair(w, p)));
        }
    }

    // Check for large sort size before sorting
    check_large_sort_size(starts);
    check_large_sort_size(endss);

    // Check for complex combinations
    check_complex_combinations(n, starts.size());

    for (auto &a : starts) {
        sort(a.second.begin(), a.second.end());
    }
    for (auto &a : endss) {
        sort(a.second.begin(), a.second.end());
    }
    for (auto a : starts) {
        auto b = endss[a.first];
        for (int i = 0; i < a.second.size(); i++) {
            results[a.second[i].second] = b[i].second;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", results[i].first, results[i].second);
    }
    return 0;
}