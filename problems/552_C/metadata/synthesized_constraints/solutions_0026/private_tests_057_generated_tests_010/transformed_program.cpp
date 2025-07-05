#include <bits/stdc++.h>
using namespace std;

long long w, m, val[105];
map<long long, int> sb;
int ed, st = 1, limit;

void check_exponential_growth_invariant(long long w, long long m) {
    long long power = 1;
    int count = 0;
    while (power <= m && count <= 100) {
        power *= w;
        count++;
    }
    if (power <= m) {
        cerr << "Warning: Exponential growth invariant triggered - m is much larger than powers of w" << endl;
        abort();
    }
}

void check_dfs_invariant(int depth, int branchFactor) {
    if (depth > 50 || branchFactor > 10) {
        cerr << "Warning: dfs_invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

void check_memory_usage_invariant(const map<long long, int>& sb) {
    if (sb.size() > 10000) {
        cerr << "Warning: memory usage invariant triggered - too many entries in map" << endl;
        abort();
    }
}

bool dfs(int cur, long long tmp, int depth) {
    check_dfs_invariant(depth, 3);  // 3 branches per recursive call
    
    if (cur == ed) {
        if (st)
            sb[tmp]++;
        else {
            if (sb.count(m - tmp))
                return true;
            else
                return false;
        }
    } else {
        if (dfs(cur + 1, tmp, depth + 1) || 
            dfs(cur + 1, tmp + val[cur], depth + 1) || 
            dfs(cur + 1, tmp - val[cur], depth + 1))
            return true;
        return false;
    }
    return false;
}

int main(int argc, char *argv[]) {
    cin >> w >> m;
    
    check_exponential_growth_invariant(w, m);  // Check before calculations begin
    
    val[0] = 1;
    for (int i = 1; i <= 101; ++i) {
        val[i] = val[i - 1] * w;
        if (val[i] > m) {
            limit = i;
            break;
        }
    }
    limit++;
    int mid = limit / 2;
    ed = mid;
    dfs(0, 0, 0);
    ed = limit;
    st = 0;
    if (dfs(mid, 0, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    check_memory_usage_invariant(sb);  // Check the map size after dfs

    return 0;
}