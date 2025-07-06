#include <bits/stdc++.h>
struct node {
    int t = INT_MAX, idx = 0, c = 0;
};
using namespace std;

// Checker functions
void check_large_range_invariant(int l, int r, int threshold) {
    if ((r - l + 1) > threshold) {
        cerr << "Warning: Performance bottleneck due to large range of sections covered by a participant!" << endl;
        abort();
    }
}

void check_high_density_invariant(int participantsInSection, int threshold) {
    if (participantsInSection > threshold) {
        cerr << "Warning: Performance bottleneck due to high participant density in a section!" << endl;
        abort();
    }
}

void check_max_section_processing_invariant(int n, int m, int n_threshold, int m_threshold) {
    if (n >= n_threshold && m >= m_threshold) {
        cerr << "Warning: Performance bottleneck due to maximum section processing!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    map<int, deque<node>> mappy;
    int n, m;
    cin >> n >> m;

    // Check for maximum section processing invariant
    check_max_section_processing_invariant(n, m, 100, 100);

    for (int i = 0; i < m; i++) {
        int l, r, t, c;
        cin >> l >> r >> t >> c;
        
        // Check for large range invariant
        check_large_range_invariant(l, r, 50);

        node obj;
        obj.t = t;
        obj.idx = i;
        obj.c = c;
        for (int j = l; j <= r; j++) mappy[j].push_back(obj);
    }

    long long int ans = 0;
    for (int i = 1; i <= n; i++) {
        node curr;
        int participantsInSection = mappy[i].size();

        // Check for high density invariant
        check_high_density_invariant(participantsInSection, 10);

        while (!mappy[i].empty()) {
            node obj = mappy[i].front();
            if (obj.t < curr.t)
                curr = obj;
            else if (obj.t == curr.t && obj.idx < curr.idx)
                curr = obj;
            mappy[i].pop_front();
        }
        ans += curr.c;
    }
    cout << ans;
    return 0;
}