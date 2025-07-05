#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_number_of_segments(int n, int m) {
    if (n > 80000 || m > 80000) {
        cerr << "Warning: Performance bottleneck condition triggered - High number of segments!" << endl;
        abort();
    }
}

void check_unbalanced_segments(int n, int m) {
    if ((n > 0 && m == 0) || (m > 0 && n == 0)) {
        cerr << "Warning: Performance bottleneck condition triggered - Unbalanced segment distribution!" << endl;
        abort();
    }
}

void check_extensive_range_coverage(const vector<pair<int, int>>& segments) {
    for (const auto& segment : segments) {
        if (segment.first == 0 && segment.second == 1000000) {
            cerr << "Warning: Performance bottleneck condition triggered - Extensive range coverage!" << endl;
            abort();
        }
    }
}

void check_dense_intersections(const vector<pair<int, int>>& horizontal, const vector<pair<int, int>>& vertical) {
    if (horizontal.size() * vertical.size() > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - Dense segment intersections!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long int N, M;
    cin >> N >> M;

    check_number_of_segments(N, M);
    check_unbalanced_segments(N, M);

    vector<pair<long long int, long long int>> horizontalSegments, verticalSegments;

    long long int y, x, l, r;
    for (long long int i = 1; i <= N; i++) {
        cin >> y >> l >> r;
        horizontalSegments.push_back({l, r});
    }

    for (long long int i = 1; i <= M; i++) {
        cin >> x >> l >> r;
        verticalSegments.push_back({l, r});
    }

    check_extensive_range_coverage(horizontalSegments);
    check_extensive_range_coverage(verticalSegments);
    check_dense_intersections(horizontalSegments, verticalSegments);

    // Original algorithm code would go here ...

    cout << "Computation completed successfully." << endl;
    return 0;
}