#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<pair<int, int>> p;
set<pair<double, double>> s;

// Function to check high number of valid midpoints
void check_large_number_of_valid_midpoints(int midpointCountEstimate, int threshold) {
    if (midpointCountEstimate > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - too many valid midpoint pairs!" << endl;
        abort();
    }
}

// Function to check dense point clustering
void check_dense_point_clustering(double averageDistance, double clusteringThreshold) {
    if (averageDistance < clusteringThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered - dense point clustering!" << endl;
        abort();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
        s.insert({x, y});
    }
    
    // Calculate a simple estimate for midpoint count and clustering
    int midpointCountEstimate = 0;
    double totalDistance = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = sqrt(pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2));
            totalDistance += dist;
            double x2 = (double)(p[i].first + p[j].first) / 2;
            double y2 = (double)(p[i].second + p[j].second) / 2;
            if (s.count({x2, y2})) {
                midpointCountEstimate++;
            }
        }
    }

    double averageDistance = totalDistance / (n * (n - 1) / 2);

    // Insert checks before heavy loop processing to prevent overhead
    check_large_number_of_valid_midpoints(midpointCountEstimate, 1000); // Example threshold
    check_dense_point_clustering(averageDistance, 1.0); // Example clustering threshold

    c = 0;
    for (int i = 0; i < n; i++) {
        int x = p[i].first, y = p[i].second;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            int x1 = p[j].first, y1 = p[j].second;
            double x2, y2;
            x2 = (double)(x + x1) / 2, y2 = (double)(y + y1) / 2;
            if (s.count({x2, y2})) c++;
        }
    }
    cout << c / 2;
}