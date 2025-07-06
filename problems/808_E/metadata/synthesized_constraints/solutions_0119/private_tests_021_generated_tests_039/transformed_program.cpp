#include <bits/stdc++.h>
using namespace std;

long long n, m, ai, bi;
vector<long long> one, two, three;

// Checkers for performance invariants
void check_capacity_invariant(long long m) {
    if (m > 250000) {  // Assuming a threshold for high capacity
        cerr << "Warning: Performance bottleneck due to high weight capacity!" << endl;
        abort();
    }
}

void check_repeated_elements_invariant(const vector<long long>& weights) {
    map<long long, long long> frequency;
    for (const auto& weight : weights) {
        frequency[weight]++;
        if (frequency[weight] > 50) {  // Assuming 50 as a threshold for repetition
            cerr << "Warning: Performance bottleneck due to repeated element weights!" << endl;
            abort();
        }
    }
}

void check_memory_usage_invariant(long long m, const vector<long long>& weights) {
    long long total_weight = 0;
    for (const auto& weight : weights) {
        total_weight += weight;
    }
    if (m > 250000 && total_weight > 1000000) {  // Arbitrary thresholds
        cerr << "Warning: Performance bottleneck due to large potential memory usage!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    check_capacity_invariant(m); // Check large capacity

    vector<long long> all_weights; // To check invariants related to weights
    for (long long i = 0; i < n; i++) {
        cin >> ai >> bi;
        all_weights.push_back(ai);
        if (ai == 3)
            three.push_back(bi);
        else if (ai == 2)
            two.push_back(bi);
        else
            one.push_back(bi);
    }

    check_repeated_elements_invariant(all_weights); // Check for repeated elements
    check_memory_usage_invariant(m, all_weights); // Check potential memory usage

    sort(one.begin(), one.end(), greater<long long>());
    sort(two.begin(), two.end(), greater<long long>());
    sort(three.begin(), three.end(), greater<long long>());

    vector<vector<long long> > answer;
    for (long long i = 0; i <= m; i++) {
        vector<long long> help;
        help.push_back(-100000000000000000);
        help.push_back(-1);
        help.push_back(-1);
        answer.push_back(help);
    }
    answer[0][0] = 0;
    answer[0][1] = 0;
    answer[0][2] = 0;
    for (long long i = 0; i <= m; i++) {
        if (answer[i][1] == -1) continue;
        if (answer[i][1] < one.size()) {
            long long v = answer[i][0] + one[answer[i][1]];
            if (i + 1 <= m && answer[i + 1][0] < v) {
                answer[i + 1][0] = v;
                answer[i + 1][1] = answer[i][1] + 1;
                answer[i + 1][2] = answer[i][2];
            }
        }
        if (answer[i][2] < two.size()) {
            long long v = answer[i][0] + two[answer[i][2]];
            if (i + 2 <= m && answer[i + 2][0] < v) {
                answer[i + 2][0] = v;
                answer[i + 2][1] = answer[i][1];
                answer[i + 2][2] = answer[i][2] + 1;
            }
        }
    }

    long long ans = 0;
    long long summ = 0;
    long long maximum = 0;
    for (long long i = 0; i <= m; i++) {
        maximum = max(maximum, answer[i][0]);
        answer[i][0] = maximum;
    }
    for (long long i = 0; i <= three.size(); i++) {
        if (3 * i > m) break;
        if (i > 0) summ += three[i - 1];
        if (summ + answer[m - 3 * i][0] > ans) {
            ans = summ + answer[m - 3 * i][0];
        }
    }
    cout << ans << endl;
    return 0;
}