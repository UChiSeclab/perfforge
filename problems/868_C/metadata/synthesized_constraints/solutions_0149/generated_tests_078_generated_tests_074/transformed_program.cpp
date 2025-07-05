#include <bits/stdc++.h>
using namespace std;
set<int> si;
int n, k;

// Checker functions
void check_combinatorial_exploration(size_t subsetCount) {
    if (subsetCount > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive subset exploration!" << endl;
        abort();
    }
}

void check_recursive_depth_and_chosen_size(size_t depth, size_t chosenSize, size_t n) {
    if (chosenSize > n / 2 && depth > 20) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion depth and chosen size!" << endl;
        abort();
    }
}

void check_imbalance_in_team_knowledge(const vector<int>& knowledgeDistribution, size_t n) {
    for (int count : knowledgeDistribution) {
        if (count > n * 0.75) {
            cerr << "Warning: Performance bottleneck condition triggered - imbalance in team knowledge distribution!" << endl;
            abort();
        }
    }
}

bool solve(set<int> &cands, vector<int> &chosen, size_t depth) {
    check_combinatorial_exploration(cands.size());
    check_recursive_depth_and_chosen_size(depth, chosen.size(), n);

    if (cands.empty()) {
        if (chosen.empty()) {
            return false;
        }
        for (int i = 0; i < k; ++i) {
            int cnt = 0;
            for (const int num : chosen) {
                cnt += (((num >> i) & 0x1) ? -1 : 1);
            }
            if (cnt < 0) {
                return false;
            }
        }
        return true;
    }
    int val = *cands.begin();
    bool ok = false;
    cands.erase(val);
    ok |= solve(cands, chosen, depth + 1);
    chosen.push_back(val);
    ok |= solve(cands, chosen, depth + 1);
    chosen.pop_back();
    cands.insert(val);
    return ok;
}

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    vector<int> knowledgeDistribution(1 << k, 0);

    for (int i = 0; i < n; ++i) {
        int val = 0;
        for (int j = 0; j < k; ++j) {
            int t;
            cin >> t;
            val |= (t << j);
        }
        si.insert(val);
        knowledgeDistribution[val]++;
    }

    check_imbalance_in_team_knowledge(knowledgeDistribution, n);

    vector<int> chosen;
    cout << (solve(si, chosen, 0) ? "YES\n" : "NO\n");
}