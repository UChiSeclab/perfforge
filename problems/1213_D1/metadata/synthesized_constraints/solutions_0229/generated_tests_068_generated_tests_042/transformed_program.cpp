#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_nested_loop_overhead(const vector<long long>& v) {
    long long max_operations = 0;
    for (auto num : v) {
        long long operations = 0;
        while (num > 0) {
            num /= 2;
            operations++;
        }
        max_operations = std::max(max_operations, operations);
    }
    if (max_operations > 20) {
        cerr << "Warning: Performance bottleneck - excessive divisions in nested loops!" << endl;
        abort();
    }
}

void check_large_number_of_iterations(long long n, long long k) {
    if (n > 40 && k > 3) {
        cerr << "Warning: Performance bottleneck - large n and high k result in many iterations!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, k;
    cin >> n >> k;

    // Check for potential large iteration overhead before processing
    check_large_number_of_iterations(n, k);

    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Check for nested loop overhead after reading input
    check_nested_loop_overhead(v);

    long long ans = 1e18;
    for (long long i = 0; i < n; i++) {
        long long cnt = 0, tmpp = v[i];
        bool bl = true;
        while (tmpp >= 0) {
            if (!bl) {
                break;
            }
            if (tmpp == 0) {
                bl = false;
            }
            vector<long long> tmp;
            for (long long j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                if (tmpp == v[j]) {
                    tmp.push_back(0);
                } else if (v[i] > v[j]) {
                    continue;
                } else {
                    long long nm = v[j], cl = 0;
                    while (nm != tmpp) {
                        nm /= 2;
                        cl++;
                        if (nm <= tmpp) {
                            break;
                        }
                    }
                    if (nm == tmpp) {
                        tmp.push_back(cl);
                    } else {
                        continue;
                    }
                }
            }
            if (tmp.size() < k - 1) {
                tmpp /= 2;
                cnt++;
                continue;
            }
            sort(tmp.begin(), tmp.end());
            long long qq = 0;
            for (long long y = 0; y < k - 1; y++) {
                qq += tmp[y];
            }
            qq += cnt;
            if (qq < ans) {
                ans = qq;
            }
            tmpp /= 2;
            cnt++;
        }
    }
    cout << ans;
}