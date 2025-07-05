#include <bits/stdc++.h>
using namespace std;

int n, a[400005], sum[400005], c[400005];

void check_divisibility_invariant(const unordered_map<int, int>& cardPowers) {
    int commonDivisorCount = 0;
    for (const auto& power : cardPowers) {
        if (power.second > 5) {
            commonDivisorCount++;
        }
    }
    if (commonDivisorCount > 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to many shared divisors!" << endl;
        abort();
    }
}

void check_frequency_invariant(const unordered_map<int, int>& cardPowers) {
    for (const auto& power : cardPowers) {
        if (power.first <= 10 && power.second > 10) {
            cerr << "Warning: Performance bottleneck due to frequent small power values!" << endl;
            abort();
        }
    }
}

void check_absence_of_small_lead_card(bool hasPowerOne) {
    if (!hasPowerOne) {
        cerr << "Warning: Performance bottleneck due to absence of small leading card!" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &n);
    unordered_map<int, int> cardPowers;
    bool hasPowerOne = false;
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        c[a[i]]++;
        sum[a[i] + 1]++;
        cardPowers[a[i]]++;
        if (a[i] == 1) {
            hasPowerOne = true;
        }
    }
    
    // Perform checks after input processing
    check_divisibility_invariant(cardPowers);
    check_frequency_invariant(cardPowers);
    check_absence_of_small_lead_card(hasPowerOne);

    for (int i = 1; i <= 400003; i++) sum[i] += sum[i - 1];
    if (c[1]) {
        long long ans = 0;
        for (int i = 1; i <= n; i++) ans += a[i];
        cout << ans;
        return 0;
    }
    long long ans = 0;
    for (int i = 2; i <= 200000; i++)
        if (c[i]) {
            long long tot = 0;
            for (int j = i; j <= 200000; j += i) {
                tot += (long long)(sum[j + i] - sum[j]) * j;
            }
            ans = max(ans, tot);
        }
    cout << ans;
    return 0;
}