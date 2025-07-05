#include <bits/stdc++.h>
using namespace std;

// Function implementations for performance checks
void check_rabbit_carrot_invariant(long long n, long long k, long long totalCarrotLength) {
    if (k > n && k > totalCarrotLength * 0.9) {
        cerr << "Warning: Performance bottleneck condition triggered - too many rabbits compared to carrot length!" << endl;
        abort();
    }
}

void check_similar_carrot_length_invariant(const vector<long long>& carrots) {
    map<long long, int> lengthFrequency;
    for (auto length : carrots) {
        lengthFrequency[length]++;
    }
    for (auto [length, freq] : lengthFrequency) {
        if (freq > carrots.size() * 0.5) {
            cerr << "Warning: Performance bottleneck condition triggered - too many carrots with similar length!" << endl;
            abort();
        }
    }
}

void check_large_carrot_splits_invariant(const vector<long long>& carrots) {
    int largeCarrotThreshold = 100000; // Arbitrary threshold for "large"
    int splitRequirement = 0;
    for (auto length : carrots) {
        if (length > largeCarrotThreshold) {
            splitRequirement++;
        }
    }
    if (splitRequirement > carrots.size() * 0.3) {
        cerr << "Warning: Performance bottleneck condition triggered - too many large carrot splits required!" << endl;
        abort();
    }
}

// Original program
mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

long long int lol(long long int what, long long int parts) {
    long long int t1 = what / parts;
    what %= parts;
    long long int t2 = t1 + 1;
    long long int ans = (long long int)pow(t1, 2) * (parts - what);
    ans += (long long int)pow(t2, 2) * what;
    return ans;
}

long long int bachat(pair<long long int, long long int> p) {
    long long int a1 = lol(p.first, p.second);
    long long int a2 = lol(p.first, p.second + 1);
    return a1 - a2;
}

struct cmp {
    bool operator()(const pair<long long int, long long int> &a,
                    const pair<long long int, long long int> &b) const {
        long long int a1 = bachat(a);
        long long int b1 = bachat(b);
        return a1 > b1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int n, k;
    cin >> n >> k;
    vector<long long int> a(n);
    long long int totalCarrotLength = 0;
    
    for (long long int i = 0; i < n; i++) {
        cin >> a[i];
        totalCarrotLength += a[i];
    }

    // Performance checks based on the problem constraints
    check_rabbit_carrot_invariant(n, k, totalCarrotLength);
    check_similar_carrot_length_invariant(a);
    check_large_carrot_splits_invariant(a);

    long long int ans = 0;
    multiset<pair<long long int, long long int>, cmp> st;
    for (long long int i = 0; i < n; i++) {
        if (a[i] > 1) {
            st.insert({a[i], 1});
        } else {
            ans++;
        }
    }

    while (n < k) {
        pair<long long int, long long int> p = *st.begin();
        st.erase(st.begin());
        p.second++;
        if (p.second == p.first) {
            ans += p.second;
        } else {
            st.insert(p);
        }
        n++;
    }

    for (auto itr = st.begin(); itr != st.end(); ++itr) {
        ans += lol(itr->first, itr->second);
    }

    cout << ans << "\n";
}