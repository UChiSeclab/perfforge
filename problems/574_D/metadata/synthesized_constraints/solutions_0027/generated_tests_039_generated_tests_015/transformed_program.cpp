#include <bits/stdc++.h>
using namespace std;

long long h[100000 + 2], cost[100000 + 2];
bool vst[100000 + 2];

void check_high_tower_count(int n) {
    if (n > 99900) { // Close to the upper constraint limit of 100000
        cerr << "Warning: Performance bottleneck - high number of towers close to constraint limit!" << endl;
        abort();
    }
}

void check_frequent_boundary_blocks(const vector<int>& heights) {
    int low_height_count = 0;
    for (int h : heights) {
        if (h <= 2) {
            ++low_height_count;
        }
    }
    if (low_height_count > (0.8 * heights.size())) {
        cerr << "Warning: Performance bottleneck - frequent boundary block destruction!" << endl;
        abort();
    }
}

void check_dense_queue_usage(const vector<int>& heights) {
    int boundary_count = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
        if ((i == 0 || heights[i - 1] == 0 || heights[i] == 1) ||
            (i == heights.size() - 1 || heights[i + 1] == 0 || heights[i] == 1)) {
            ++boundary_count;
        }
    }
    if (boundary_count > (0.7 * heights.size())) {
        cerr << "Warning: Performance bottleneck - dense priority queue operations!" << endl;
        abort();
    }
}

int main() {
    int n;
    while (cin >> n) {

        // Performance check for high number of towers
        check_high_tower_count(n);

        vector<int> heights(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            q;

        h[0] = cost[0] = h[n + 1] = cost[n + 1] = 0;
        vst[0] = vst[n + 1] = true;
        
        for (int i = 1; i <= n; ++i) {
            cin >> h[i];
            heights[i - 1] = h[i];  // Store in vector for further checks
            cost[i] = h[i];
            vst[i] = false;
        }

        // Performance check for frequent boundary block destruction
        check_frequent_boundary_blocks(heights);

        for (int i = 1; i <= n; ++i) {
            if (h[i - 1] == 0 || h[i + 1] == 0 || h[i] == 1) {
                cost[i] = 1;
            }
            q.push(pair<long long, int>(cost[i], i));
        }

        long long len = 0;
        while (!q.empty()) {
            pair<long long, int> node = q.top();
            q.pop();
            int xi = node.second;
            if (vst[xi]) continue;
            vst[xi] = true;
            if (cost[xi - 1] > cost[xi] + 1) {
                cost[xi - 1] = cost[xi] + 1;
                q.push(pair<long long, int>(cost[xi - 1], xi - 1));
            }
            if (cost[xi + 1] > cost[xi] + 1) {
                cost[xi + 1] = cost[xi] + 1;
                q.push(pair<long long, int>(cost[xi + 1], xi + 1));
            }
            len = max(cost[xi], len);
        }

        // Performance check for dense queue usage
        check_dense_queue_usage(heights);

        for (int _ = 1; _ <= n; ++_) cerr << cost[_] << ' ';
        cerr << endl;
        cout << len << endl;
    }
    return 0;
}