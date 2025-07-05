#include <bits/stdc++.h>
using namespace std;

bool pos[5001];
vector<int> susedi[5001];
vector<int> novi[5001];
queue<int> ent;
vector<pair<int, int>> iztr;

void check_disconnected_nodes(int unreachableCount, int totalNodes) {
    if (unreachableCount > totalNodes / 2) { // Arbitrary threshold: more than half the nodes are unreachable
        cerr << "Warning: Potential performance bottleneck due to many unreachable nodes!" << endl;
        abort();
    }
}

void check_repeated_initialization(int callCount) {
    if (callCount > 1000) { // Arbitrarily chosen threshold based on performance insight
        cerr << "Warning: Performance bottleneck due to repeated large array initialization!" << endl;
        abort();
    }
}

void check_excessive_queue_operations(int totalQueueOps) {
    if (totalQueueOps > 10000) { // Arbitrarily chosen threshold for excessive operations
        cerr << "Warning: Excessive queue operations detected, potential slowdown!" << endl;
        abort();
    }
}

int howmany(int s) {
    while (ent.empty() == false) {
        ent.pop();
    }
    int br = 1, a = 0, b = 0, otg = 0;
    bool moipos[5001];
    for (int i = 0; i < 5001; i++) {
        moipos[i] = false;
    }
    ent.push(s);
    moipos[s] = true;
    int queueOperations = 0;
    while (br > 0) {
        a = ent.front();
        ent.pop();
        br--;
        for (int i = 0; i < susedi[a].size(); i++) {
            b = susedi[a][i];
            if (moipos[b] == false) {
                moipos[b] = true;
                if (pos[b] == false) {
                    otg++;
                    novi[s].push_back(b);
                }
                ent.push(b);
                br++;
                queueOperations++;
            }
        }
    }
    check_excessive_queue_operations(queueOperations);
    return otg;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s, a = 0, b = 0, br = 1, otg = 0;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        susedi[a].push_back(b);
    }

    ent.push(s);
    pos[s] = true;

    while (br > 0) {
        a = ent.front();
        ent.pop();
        br--;
        for (int i = 0; i < susedi[a].size(); i++) {
            b = susedi[a][i];
            if (pos[b] == false) {
                pos[b] = true;
                ent.push(b);
                br++;
            }
        }
    }

    int unreachableCount = 0;
    int howmanyCalls = 0;

    for (int i = 1; i <= n; i++) {
        if (pos[i] == false) {
            unreachableCount++;
            while (ent.empty() == false) {
                ent.pop();
            }
            a = howmany(i);
            iztr.push_back({a, i});
            howmanyCalls++;
            check_repeated_initialization(howmanyCalls);
        }
    }

    check_disconnected_nodes(unreachableCount, n);

    sort(iztr.begin(), iztr.end());

    for (int i = iztr.size() - 1; i >= 0; i--) {
        a = iztr[i].second;
        if (pos[a] == false) {
            pos[a] = true;
            otg++;
            for (int j = 0; j < novi[a].size(); j++) {
                b = novi[a][j];
                if (pos[b] == false) {
                    pos[b] = true;
                }
            }
        }
    }

    cout << otg << "\n";

    return 0;
}