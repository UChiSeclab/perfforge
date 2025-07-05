#include <bits/stdc++.h>
using namespace std;

void check_collision_group_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Collision group size exceeds threshold!" << endl;
        abort();
    }
}

void check_sorting_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Sorting operation on large group!" << endl;
        abort();
    }
}

int main() {
    pair<long double, long double> dest[100005];
    long long int my[100005];
    long long int gi[100005];
    long long int pi[100005];
    long long int ti[100005];
    long long int n, w, h;
    cin >> n >> w >> h;
    map<long long int, vector<long long int> > verhorz;
    map<long long int, long long int> jh;
    
    for (long long int i = 1; i <= n; i++) {
        long long int g, p, t;
        cin >> g >> p >> t;
        gi[i] = g;
        pi[i] = p;
        ti[i] = t;
        verhorz[p - t].push_back(i);
        jh[p - t]++;
    }
    
    // Check for collision group size
    for (auto& y : verhorz) {
        check_collision_group_invariant(y.second.size() > n / 10); // Threshold: 10% of total dancers
    }
    
    for (auto y : jh) {
        vector<pair<pair<long double, long double>, long long int> > ends;
        vector<pair<pair<long double, long double>, long long int> > starts;
        
        for (auto z : verhorz[y.first]) {
            if (gi[z] == 1) {
                starts.push_back(make_pair(make_pair(pi[z], 0), z));
                ends.push_back(make_pair(make_pair(pi[z], -1 * h), z));
            } else {
                starts.push_back(make_pair(make_pair(0, -1 * pi[z]), z));
                ends.push_back(make_pair(make_pair(w, -1 * pi[z]), z));
            }
        }
        
        // Check for sorting on large groups
        check_sorting_invariant(starts.size() > n / 10); // Threshold: 10% of total dancers
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        for (long long int i = 0; i < starts.size(); i++) {
            dest[starts[i].second].first = ends[i].first.first;
            dest[starts[i].second].second = -1 * ends[i].first.second;
        }
    }
    
    for (long long int i = 1; i <= n; i++) {
        cout << dest[i].first << " " << dest[i].second << endl;
    }
}