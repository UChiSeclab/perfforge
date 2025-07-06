#include <bits/stdc++.h>
using namespace std;

// Runtime checks based on performance-characterizing invariants
void check_prolonged_loop_invariant(int n, int k, const vector<int>& ranks) {
    if (ranks[0] < k && k > 90) {
        cerr << "Warning: Prolonged loop invariant triggered - low initial ranks with high k" << endl;
        abort();
    }
}

void check_map_update_invariant(int k, const map<long long, long long>& mp) {
    int sum_ranks = 0;
    for (const auto& entry : mp) {
        sum_ranks += entry.first * entry.second;
    }
    if (sum_ranks < k * mp.size() && k > 90) {
        cerr << "Warning: Map update invariant triggered - frequent updates due to low ranks" << endl;
        abort();
    }
}

void check_initial_rank_invariant(int k, const vector<int>& ranks) {
    if (ranks[0] == 1 && k > 90) {
        cerr << "Warning: Initial rank invariant triggered - many ranks to increase" << endl;
        abort();
    }
}

const long long N = 1e6 + 3;
long long n, a, cnt, ans, sum, k;
map<long long, long long> mp, pm;

void DNM() {
    cin >> n >> k;
    vector<int> ranks(n);
    
    for (long long i = 0; i < n; i++) {
        cin >> ranks[i];
        if (ranks[i] < k) mp[ranks[i]]++;
    }
    
    // Insert checks before entering the main loop
    check_prolonged_loop_invariant(n, k, ranks);
    check_initial_rank_invariant(k, ranks);

    while (1) {
        cnt = 0;
        pm.clear();
        for (long long i = 1; i < k; i++) {
            if (mp[i] > 0) mp[i]--, pm[i + 1]++, cnt = 1;
        }
        
        for (long long i = 1; i < k; i++) mp[i] += pm[i];
        
        if (cnt == 0) {
            cout << sum << endl;
            return;
        }
        sum++;
        
        // Check inside loop to capture invariant as map updates
        check_map_update_invariant(k, mp);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int Qu_l_uQ = 1;
    while (Qu_l_uQ--) DNM();
}