#include <bits/stdc++.h>
using namespace std;

int dp[109][109][109][5], m, noatk, nodef, atkcard[109], card[109], defcard[109];

void check_defensive_cards_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - too many defensive cards!" << endl;
        abort();
    }
}

void check_offensive_capability_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - Ciel's cards are not strong enough!" << endl;
        abort();
    }
}

void check_cache_efficiency_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent cache misses!" << endl;
        abort();
    }
}

void check_backtracking_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive backtracking with low-strength cards!" << endl;
        abort();
    }
}

int memoize(int ceil, int atk, int def, int cardlef) {
    if (ceil == m && cardlef == 2 && (atk != noatk || def != nodef))
        return -1 * 10000000;
    if (ceil == m) return 0;
    if (dp[ceil][atk][def][cardlef] != -1) return dp[ceil][atk][def][cardlef];
    int ans = -1 * 10000000;

    // Check if the recursion is getting too deep with too many defensive cards
    check_defensive_cards_invariant(nodef > 80 && ceil < m / 2);

    if (cardlef != 0) ans = max(ans, card[ceil] + memoize(ceil + 1, atk, def, 2));
    if (atk < noatk && card[ceil] >= atkcard[atk])
        ans = max(ans, card[ceil] - atkcard[atk] + memoize(ceil + 1, atk + 1, def, cardlef));
    if (def < nodef && card[ceil] > defcard[def])
        ans = max(ans, memoize(ceil + 1, atk, def + 1, cardlef));
    if (def < nodef && cardlef != 2)
        ans = max(ans, memoize(ceil, atk, def + 1, 0));
    if (atk < noatk && cardlef != 2)
        ans = max(ans, memoize(ceil, atk + 1, def, 0));
    ans = max(ans, memoize(ceil + 1, atk, def, cardlef));

    // Check for frequent cache misses in the dynamic programming approach
    check_cache_efficiency_invariant((atk + def > 50) && (dp[ceil][atk][def][cardlef] == -1));

    return dp[ceil][atk][def][cardlef] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = int(0); i <= int(n - 1); i++) {
        string str;
        cin >> str;
        int val;
        scanf("%d", &val);
        if (str == "ATK")
            atkcard[noatk++] = val;
        else
            defcard[nodef++] = val;
    }

    sort(atkcard, atkcard + noatk);
    reverse(atkcard, atkcard + noatk);
    sort(defcard, defcard + nodef);
    reverse(defcard, defcard + nodef);

    for (int i = int(0); i <= int(m - 1); i++) scanf("%d", &card[i]);
    sort(card, card + m);
    reverse(card, card + m);

    // Check for limited offensive capability against strong attack cards
    check_offensive_capability_invariant((noatk > 0) && (card[0] < atkcard[noatk - 1]));

    // Check for excessive backtracking with low-value offensive cards
    check_backtracking_invariant((card[m - 1] < 100) && (m > 80));

    int ans = memoize(0, 0, 0, 1);
    printf("%d\n", ans);
    return 0;
}