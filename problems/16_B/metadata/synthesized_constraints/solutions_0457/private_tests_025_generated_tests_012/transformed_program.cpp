#include <bits/stdc++.h>
using namespace std;

// Checker functions based on performance-characterizing invariants
void check_high_matchbox_count(const vector<pair<int, int>>& data, int n) {
    int total_matchboxes = 0;
    for (const auto& container : data) {
        total_matchboxes += container.first;
    }
    if (total_matchboxes > 10 * n) { // Example threshold
        cerr << "Warning: High matchbox count per container may lead to excessive iterations!" << endl;
        abort();
    }
}

void check_large_n_compared_to_matchboxes(int total_matchboxes, int n) {
    if (n > total_matchboxes) {
        cerr << "Warning: Rucksack capacity n is significantly larger than total matchboxes!" << endl;
        abort();
    }
}

void check_uneven_distribution(const vector<pair<int, int>>& data) {
    int total_matchboxes = 0;
    for (const auto& container : data) {
        total_matchboxes += container.first;
    }
    for (const auto& container : data) {
        if (container.first > 0.75 * total_matchboxes) { // Example threshold
            cerr << "Warning: Single container dominates matchbox distribution!" << endl;
            abort();
        }
    }
}

int main() {
    int i, j, k;
    int n, m, a = 0, b, c, d;
    int count = 0;
    int x, y, z;
    vector<pair<int, int> > data;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> x >> y;
        data.push_back(make_pair(x, y));
    }

    // Insert checker functions after reading input data
    check_high_matchbox_count(data, n);

    int total_matchboxes = 0;
    for (const auto& container : data) {
        total_matchboxes += container.first;
    }
    
    check_large_n_compared_to_matchboxes(total_matchboxes, n);
    check_uneven_distribution(data);

    sort(data.begin(), data.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (a.second < b.second);
    });
    reverse(data.begin(), data.end());
    for (j = 0; j < m; j++) {
        while (data[j].first--) {
            if (count < n) {
                a += data[j].second;
                count++;
            } else
                break;
        }
    }
    cout << a;
    data.clear();
    return 0;
}