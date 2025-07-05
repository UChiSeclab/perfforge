#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<pair<long long, long long>, long long>& a,
          const pair<pair<long long, long long>, long long>& b) {
    if (a.first.first == b.first.first)
        return a.first.second < b.first.second;
    else
        return a.first.first < b.first.first;
}

// Performance-checking functions
void check_waiting_time_invariant(const unordered_map<long long, int>& wait_time_count);
void check_collision_invariant(int potential_collision_count);
void check_sorting_invariant(size_t num_similar_trajectories);
void check_density_invariant(int high_density_count);

int main() {
    long long n, width, height;
    cin >> n >> width >> height;
    vector<pair<long long, long long>> go;
    vector<pair<pair<long long, long long>, long long>> h, v;
    unordered_map<long long, vector<long long>> vc, hc;
    
    unordered_map<long long, int> wait_time_count;  // Track waiting times
    for (int i = 0; i < n; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Count waiting times
        wait_time_count[z]++;

        if (x == 1) {
            go.push_back({y, 1});
            v.push_back({{z - y, y}, i});
            vc[i].push_back(y);
            vc[i].push_back(height);
        } else {
            go.push_back({y, 2});
            h.push_back({{z - y, y}, i});
            hc[i].push_back(width);
            hc[i].push_back(y);
        }
    }
    
    // Check for high number of dancers with the same waiting time
    check_waiting_time_invariant(wait_time_count);

    sort(v.begin(), v.end(), comp);
    sort(h.begin(), h.end(), comp);

    int i1 = 0, j1 = 0, i2 = 0, j2 = 0, siz1 = v.size(), siz2 = h.size();
    
    // Potential collision count (for demonstration purposes)
    int potential_collision_count = 0;

    while (i1 < siz1 && i2 < siz2) {
        if (v[i1].first.first < h[i2].first.first)
            i1++;
        else if (v[i1].first.first > h[i2].first.first)
            i2++;
        else {
            j1 = i1;
            j2 = i2;
            i1++;
            i2++;
            while (i1 < siz1 && v[i1].first.first == v[i1 - 1].first.first) i1++;
            while (i2 < siz2 && h[i2].first.first == h[i2 - 1].first.first) i2++;
            
            // Increase potential collision count
            potential_collision_count += (i1 - j1) * (i2 - j2);

            for (int i = j1; i < i1; i++) {
                long long curr = i1 - i;
                if (curr > i2 - j2) {
                    vc[v[i].second][0] = v[i + i2 - j2].first.second;
                } else {
                    vc[v[i].second][1] = h[j2 + i1 - i - 1].first.second;
                    vc[v[i].second][0] = width;
                }
            }
            for (int i = j2; i < i2; i++) {
                long long curr = i2 - i;
                if (curr > i1 - j1) {
                    hc[h[i].second][1] = h[i + i1 - j1].first.second;
                } else {
                    hc[h[i].second][0] = v[j1 + i2 - i - 1].first.second;
                    hc[h[i].second][1] = height;
                }
            }
            j1 = i1;
            j2 = i2;
        }
    }
    
    // Check for large number of potential collisions
    check_collision_invariant(potential_collision_count);

    for (int i = 0; i < go.size(); i++) {
        if (go[i].second == 1) {
            cout << vc[i][0] << " " << vc[i][1] << endl;
        } else {
            cout << hc[i][0] << " " << hc[i][1] << endl;
        }
    }
}

// Implementations for performance-checking functions

void check_waiting_time_invariant(const unordered_map<long long, int>& wait_time_count) {
    for (const auto& entry : wait_time_count) {
        if (entry.second > 1000) {  // Arbitrary threshold for demonstration
            cerr << "Warning: High number of dancers with the same waiting time!" << endl;
            abort();
        }
    }
}

void check_collision_invariant(int potential_collision_count) {
    if (potential_collision_count > 5000) {  // Example threshold
        cerr << "Warning: Large number of potential collisions detected!" << endl;
        abort();
    }
}

void check_sorting_invariant(size_t num_similar_trajectories) {
    if (num_similar_trajectories > 2000) {  // Example threshold
        cerr << "Warning: High sorting complexity due to similar trajectories!" << endl;
        abort();
    }
}

void check_density_invariant(int high_density_count) {
    if (high_density_count > 10000) {  // Example threshold
        cerr << "Warning: Excessive collision handling due to high density of dancers!" << endl;
        abort();
    }
}