#include <bits/stdc++.h>
using namespace std;
set<int> happyB;
set<int> happyG;
bool boys[111];
bool girls[111];

// Check for inefficient propagation of happiness
void check_inefficient_propagation(int totalBoys, int totalGirls, int happyBoysCount, int happyGirlsCount) {
    int totalFriends = totalBoys + totalGirls;
    int happyFriends = happyBoysCount + happyGirlsCount;

    if (happyFriends < (totalFriends / 2)) {
        cerr << "Warning: Performance bottleneck condition triggered - insufficient initial happy individuals for efficient propagation!" << endl;
        abort();
    }
}

// Check for slow spread due to distribution gaps
void check_distribution_gaps(int totalBoys, int totalGirls, const set<int>& happyBoys, const set<int>& happyGirls) {
    if (happyBoys.size() < (totalBoys / 2) || happyGirls.size() < (totalGirls / 2)) {
        cerr << "Warning: Performance bottleneck condition triggered - gaps in happy individual distribution!" << endl;
        abort();
    }
}

int main() {
    int x;
    int B, G;
    int g, b;
    cin >> B >> G;
    cin >> b;
    while (b--) {
        cin >> x;
        boys[x] = true;
    }
    cin >> g;
    while (g--) {
        cin >> x;
        girls[x] = true;
    }
    
    // Place the checkers after reading input
    check_inefficient_propagation(B, G, count(boys, boys + B, true), count(girls, girls + G, true));
    check_distribution_gaps(B, G, happyB, happyG);

    for (int i = 0; i < (1000 * 1000 + 1); i++) {
        int Gindex = i % G;
        int Bindex = i % B;
        if (boys[Bindex] || girls[Gindex]) {
            boys[Bindex] = true;
            girls[Gindex] = true;
            happyB.insert(Bindex);
            happyG.insert(Gindex);
        }
        if (happyG.size() == G && happyB.size() == B) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}