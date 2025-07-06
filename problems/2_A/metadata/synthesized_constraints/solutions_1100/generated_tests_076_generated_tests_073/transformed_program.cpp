#include <bits/stdc++.h>
using namespace std;

// Function to check high score iteration
void check_high_score_iteration(int score) {
    if (score > 500) { // Assume a score threshold indicating potential slowdown
        cerr << "Warning: High score iteration invariant triggered - excessive iterations!" << endl;
        abort();
    }
}

// Function to check frequent score updates
void check_frequent_score_updates(const map<int, vector<string>>& flag, int maxScore) {
    if (flag.size() > 100 && maxScore > 500) { // Threshold based on simultaneous high scores and large flag map
        cerr << "Warning: Frequent score updates invariant triggered - large data growth!" << endl;
        abort();
    }
}

// Function to check multiple high score players
void check_multiple_high_score_players(const vector<string>& winnerList) {
    if (winnerList.size() > 5) { // Arbitrary threshold for multiple high-scoring players
        cerr << "Warning: Multiple high score players invariant triggered!" << endl;
        abort();
    }
}

int main() {
    map<int, vector<string>> flag;
    map<string, int> mp;
    int n;
    cin >> n;
    int maxScore = 0; // Track the maximum score encountered

    while (n--) {
        string name;
        int score;
        cin >> name >> score;
        mp[name] = mp[name] + score;

        // Check for high score iteration before the loop
        check_high_score_iteration(mp[name]);

        if (mp[name] >= 0) {
            for (int i = 0; i <= mp[name]; i++) {
                flag[i].push_back(name);
            }
        }

        // Track the maximum score encountered
        if (mp[name] > maxScore) {
            maxScore = mp[name];
        }
    }

    // Check for data growth post-processing
    check_frequent_score_updates(flag, maxScore);

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

    // Check for multiple players with high scores
    check_multiple_high_score_players(winner);

    for (auto i = flag[maax].begin(); i != flag[maax].end(); i++) {
        if (mp[*i] == maax) {
            cout << *i << endl;
            break;
        }
    }
    return 0;
}