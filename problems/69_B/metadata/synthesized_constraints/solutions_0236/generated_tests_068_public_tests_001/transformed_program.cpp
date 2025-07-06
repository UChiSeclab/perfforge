#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_sort_invariant(int numCompetitors) {
    if (numCompetitors > 70) {
        cerr << "Warning: Performance bottleneck due to excessive sorting!" << endl;
        abort();
    }
}

void check_overlap_invariant(int overlapCount) {
    if (overlapCount > 50) {
        cerr << "Warning: Performance bottleneck due to high overlap in sections!" << endl;
        abort();
    }
}

void check_section_overlap_invariant(int sectionsWithHighOverlap) {
    if (sectionsWithHighOverlap > 10) {
        cerr << "Warning: Performance bottleneck due to many high-overlap sections!" << endl;
        abort();
    }
}

bool cmp(const pair<int, pair<int, int> >& a,
         const pair<int, pair<int, int> >& b) {
    if (a.first < b.first) return true;
    if (a.first == b.first)
        if (a.second.first < b.second.first) return true;
    return false;
}

int main() {
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, pair<int, int> > > > v(n + 1);

    // Track overlaps for each section
    vector<int> sectionCompetitors(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int l, r, t, c;
        cin >> l >> r >> t >> c;
        for (int j = l; j <= r; j++) {
            v[j].push_back(make_pair(t, make_pair(i + 1, c)));
            sectionCompetitors[j]++;
        }
    }

    // Check for high overlap before sorting
    for (int i = 1; i <= n; i++) {
        check_overlap_invariant(sectionCompetitors[i]);
    }

    int sectionsWithHighOverlap = 0;
    for (int i = 1; i <= n; i++) {
        if (sectionCompetitors[i] > 50) {
            sectionsWithHighOverlap++;
        }
    }
    check_section_overlap_invariant(sectionsWithHighOverlap);

    // Sorting competitors in each section
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end(), cmp);
        check_sort_invariant(v[i].size());
    }

    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i].size()) res += v[i][0].second.second;
    }
    cout << res;
    return 0;
}