#include <bits/stdc++.h>
using namespace std;

int n, t[1001], k;
map<int, int> mx2, mx1, mn1, mn2, nx1, nx2, nn1, nn2;
pair<int, int> pr[1000001];

void check_density_invariant(int n, int m) {
    if (m > n * n / 2) {
        cerr << "Warning: density_invariant triggered - high density of queens on the board!" << endl;
        abort();
    }
}

void check_map_operation_invariant(int mapSize) {
    if (mapSize > 10000) {
        cerr << "Warning: map_operation_invariant triggered - complex map operations!" << endl;
        abort();
    }
}

void check_threats_invariant(int threatsPerQueen) {
    if (threatsPerQueen > 6) {
        cerr << "Warning: threats_invariant triggered - many queens threatening others!" << endl;
        abort();
    }
}

int main() {
    cin >> k >> n;
    
    // Check for high density of queens
    check_density_invariant(n, k);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &pr[i].first, &pr[i].second);
        if (mn2[pr[i].first - pr[i].second] == 0)
            mn2[pr[i].first - pr[i].second] = 1e9;
        mx2[pr[i].first - pr[i].second] =
            max(mx2[pr[i].first - pr[i].second], pr[i].first);
        mn2[pr[i].first - pr[i].second] =
            min(mn2[pr[i].first - pr[i].second], pr[i].first);
        if (mn1[pr[i].first + pr[i].second] == 0)
            mn1[pr[i].first + pr[i].second] = 1e9;
        mx1[pr[i].first + pr[i].second] =
            max(mx1[pr[i].first + pr[i].second], pr[i].first);
        mn1[pr[i].first + pr[i].second] =
            min(mn1[pr[i].first + pr[i].second], pr[i].first);
        if (nn1[pr[i].first] == 0) nn1[pr[i].first] = 1e9;
        nx1[pr[i].first] = max(nx1[pr[i].first], pr[i].second);
        nn1[pr[i].first] = min(nn1[pr[i].first], pr[i].second);
        if (nn2[pr[i].second] == 0) {
            nn2[pr[i].second] = 1e9;
        }
        nx2[pr[i].second] = max(nx2[pr[i].second], pr[i].first);
        nn2[pr[i].second] = min(nn2[pr[i].second], pr[i].first);
    }

    // Check map operations complexity
    check_map_operation_invariant(mx2.size());
    check_map_operation_invariant(mx1.size());
    check_map_operation_invariant(mn1.size());
    check_map_operation_invariant(mn2.size());
    check_map_operation_invariant(nx1.size());
    check_map_operation_invariant(nx2.size());
    check_map_operation_invariant(nn1.size());
    check_map_operation_invariant(nn2.size());

    for (int i = 0; i < n; i++) {
        int y = 0;
        if (mn2[pr[i].first - pr[i].second] < pr[i].first) y++;
        if (mx2[pr[i].first - pr[i].second] > pr[i].first) y++;
        if (mn1[pr[i].first + pr[i].second] < pr[i].first) y++;
        if (mx1[pr[i].first + pr[i].second] > pr[i].first) y++;
        if (nn1[pr[i].first] < pr[i].second) y++;
        if (nx1[pr[i].first] > pr[i].second) y++;
        if (nn2[pr[i].second] < pr[i].first) y++;
        if (nx2[pr[i].second] > pr[i].first) y++;

        // Check threats per queen
        check_threats_invariant(y);
        
        t[y]++;
    }
    for (int i = 0; i <= 8; i++) cout << t[i] << " ";
    return 0;
}