#include <bits/stdc++.h>
using namespace std;

struct par {
    int time;
    int id;
    int profit;
};

bool comp(const par &p1, const par &p2) {
    if (p1.time < p2.time) return true;
    if (p1.time == p2.time) {
        return p1.id < p2.id;
    }
    return false;
}

void check_sorting_overhead(int sectionsCount, int participants) {
    if (sectionsCount * participants > 1000) {
        cerr << "Warning: Performance bottleneck - high sorting overhead due to large number of elements across sections!" << endl;
        abort();
    }
}

void check_overlapping_sections(const vector<int>& sectionSizes) {
    int threshold = 15;
    for (int size : sectionSizes) {
        if (size > threshold) {
            cerr << "Warning: Performance bottleneck - excessive overlap in sections leading to high comparison operations!" << endl;
            abort();
        }
    }
}

void check_high_range_utilization(const vector<par> competitors, int n) {
    int highRangeThreshold = 0.75 * n;
    for (const auto& competitor : competitors) {
        if ((competitor.id == 1 || competitor.id == n) && (competitor.time > highRangeThreshold)) {
            cerr << "Warning: Performance bottleneck - high range utilization by a large number of competitors!" << endl;
            abort();
        }
    }
}

int main() {
    vector<par> v[120];
    par p;
    int n, m;
    int l, r, t, c;
    cin >> n >> m;
    
    vector<int> sectionSizes(n+1, 0);
    vector<par> competitors;
    
    for (int i = 1; i <= m; ++i) {
        cin >> l >> r >> t >> c;
        p.id = i;
        p.time = t;
        p.profit = c;
        competitors.push_back(p);
        for (int j = l; j <= r; ++j) {
            v[j].push_back(p);
            sectionSizes[j]++;
        }
    }

    check_sorting_overhead(n, m);
    check_overlapping_sections(sectionSizes);
    check_high_range_utilization(competitors, n);

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        sort((v[i]).begin(), (v[i]).end(), comp);
        if (v[i].size() > 0) {
            res += v[i][0].profit;
        }
    }
    cout << res << endl;
    return 0;
}