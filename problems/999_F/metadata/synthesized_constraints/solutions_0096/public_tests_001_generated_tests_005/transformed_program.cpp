#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXK = 12;
const int MAXV = 1e5 + 5;
int N, K;
int card[MAXV];
int fav[MAXV];
int joy[MAXK];
int dp[MAXV];

// Checkers for performance invariants
void check_high_frequency_invariant(int freq) {
    if (freq > 20) { // Arbitrary threshold for high frequency
        cerr << "Warning: High frequency of cards with favorite numbers can cause performance slowdown!" << endl;
        abort();
    }
}

void check_shared_favorite_invariant(int players_sharing_favorite) {
    if (players_sharing_favorite > 5) { // Arbitrary threshold for number of players sharing favorite numbers
        cerr << "Warning: Multiple players with shared favorite numbers can cause performance slowdown!" << endl;
        abort();
    }
}

void check_distinct_card_invariant(int distinct_cards) {
    if (distinct_cards > 100) { // Arbitrary threshold for distinct card numbers
        cerr << "Warning: Many distinct card numbers matching favorite numbers can cause performance slowdown!" << endl;
        abort();
    }
}

int solve(int player, int freq) {
    check_high_frequency_invariant(freq); // Check for high frequency of cards

    memset(dp, 0xaf, sizeof dp);
    dp[0] = 0;
    for (int a = 0; a < player; a++) {
        for (int b = freq; b >= 0; b--) {
            for (int c = 0; c <= K && c <= b; c++) {
                dp[b] = max(dp[b], dp[b - c] + joy[c]);
            }
        }
    }
    return *max_element(dp, dp + MAXV);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> K;
    int distinct_card_count = 0;
    for (int a = 1; a <= N * K; a++) {
        int x;
        cin >> x;
        if (card[x] == 0) distinct_card_count++; // Counting distinct cards
        card[x]++;
    }

    check_distinct_card_invariant(distinct_card_count); // Check for distinct card count

    int shared_favorite_players = 0;
    for (int a = 1; a <= N; a++) {
        int x;
        cin >> x;
        if (fav[x] == 0) shared_favorite_players++;
        fav[x]++;
    }

    check_shared_favorite_invariant(shared_favorite_players); // Check for shared favorite numbers

    for (int a = 1; a <= K; a++) {
        cin >> joy[a];
    }

    int ans = 0;
    for (int a = 0; a < MAXV; a++) {
        if (card[a] != 0 && fav[a] != 0) {
            ans += solve(fav[a], card[a]);
        }
    }
    cout << ans;
}