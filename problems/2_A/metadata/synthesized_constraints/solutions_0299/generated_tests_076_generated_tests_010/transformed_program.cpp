#include <bits/stdc++.h>
using namespace std;

// Function to check for high accumulated points that could lead to performance bottlenecks
void check_high_accumulated_points(int score) {
    if (score > 500) { // Threshold can be adjusted based on constraints
        cerr << "Warning: Performance bottleneck condition triggered - high accumulated points!" << endl;
        abort();
    }
}

// Function to check frequent high scores affecting the flag data structure
void check_frequent_high_scores(int score, int currentMax) {
    if (score > 300 && currentMax > 500) { // Hypothetical thresholds
        cerr << "Warning: Performance bottleneck condition triggered - frequent high scores!" << endl;
        abort();
    }
}

// Function to check player's score growth significantly over rounds
void check_score_growth(int score, int iterations) {
    if (score > 300 && iterations > 500) { // Hypothetical thresholds
        cerr << "Warning: Performance bottleneck condition triggered - score growth with large range!" << endl;
        abort();
    }
}

int main() {
    map<int, vector<string>> flag;
    map<string, int> mp;
    int n;
    cin >> n;
    while (n--) {
        string name;
        int score;
        cin >> name >> score;
        mp[name] = mp[name] + score;

        // Insert a check for high accumulated points
        check_high_accumulated_points(mp[name]);

        if (mp[name] >= 0) {
            for (int i = 0; i <= mp[name]; i++) {
                flag[i].push_back(name);
            }
        }
    }
    int maax = -1;
    map<string, int>::iterator i;
    for (i = mp.begin(); i != mp.end(); ++i) {
        if (i->second > maax) {
            maax = i->second;
        }
    }
    vector<string> winner;
    for (i = mp.begin(); i != mp.end(); ++i) {
        if (i->second == maax) {
            winner.push_back(i->first);
        }
    }

    // Before determining the winner, check for frequent high scores
    for (auto &entry : flag[maax]) {
        check_frequent_high_scores(mp[entry], maax);
    }

    for (auto i = flag[maax].begin(); i != flag[maax].end(); i++) {
        if (mp[*i] == maax) {
            cout << *i << endl;
            break;
        }
    }
    return 0;
}