#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;

string s[1001];
struct gg {
    int id, w, ww;
    bool flag;
} node[11];

bool vis[11];
int fst[11], ans = INT_MAX, n, cnt = 0, wei[11];

// Checker functions
void check_large_mapping_invariant(int activeMappings, int maxMappings) {
    if (activeMappings == maxMappings) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of active mappings!" << endl;
        abort();
    }
}

void check_repeated_leading_letter_invariant(const std::vector<int>& leadingCounts, int threshold) {
    for (int count : leadingCounts) {
        if (count > threshold) {
            cerr << "Warning: Performance bottleneck condition triggered - high frequency of leading letters!" << endl;
            abort();
        }
    }
}

void check_dfs_search_space_invariant(int currentDepth, int maxDepth, int branchFactor, int maxBranchFactor) {
    if (currentDepth > maxDepth || branchFactor > maxBranchFactor) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive DFS search space!" << endl;
        abort();
    }
}

inline void get_ans() {
    int ret = 0;
    for (int i = 1; i <= cnt; i++) {
        ret += node[i].w * node[i].ww;
        if (ret > ans) return;
    }
    ans = min(ans, ret);
}

void dfs(int pos) {
    check_dfs_search_space_invariant(pos, 11, cnt, 10); // Check DFS search space
    if (pos == cnt + 1) {
        get_ans();
        return;
    } else {
        for (int i = 0; i <= cnt; i++) {
            if (!vis[i]) {
                if (i == 0 && node[pos].flag == 0) continue;
                vis[i] = 1;
                node[pos].w = i;
                dfs(pos + 1);
                vis[i] = 0;
            }
        }
    }
}

int main() {
    int tmp;
    memset(fst, 1, sizeof fst);
    scanf("%d", &n);
    
    vector<int> leadingCounts(10, 0); 
    
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        tmp = 1;
        for (int j = s[i].length() - 1; j >= 0; j--)
            vis[s[i][j] - 'a'] = 1, wei[s[i][j] - 'a'] += tmp, tmp *= 10;
        fst[s[i][0] - 'a'] = 0;
        leadingCounts[s[i][0] - 'a']++;
    }
    
    check_repeated_leading_letter_invariant(leadingCounts, n / 2); // Check for repeated leading letter
    
    for (int i = 0; i < 10; i++)
        if (vis[i])
            node[++cnt].id = i, node[cnt].flag = fst[i], node[cnt].ww = wei[i];
    
    check_large_mapping_invariant(cnt, 10); // Check large mapping invariant
    
    memset(vis, 0, sizeof vis);
    dfs(1);
    printf("%d", ans);
    return 0;
}