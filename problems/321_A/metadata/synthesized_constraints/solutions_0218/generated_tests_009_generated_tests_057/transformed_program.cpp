#include <bits/stdc++.h>
using namespace std;
bool __hack = std::ios::sync_with_stdio(false);
auto __hack1 = cin.tie(nullptr);

template <class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}

vector<pair<int64_t, int64_t>> emulate(int64_t x, int64_t y, const string& p) {
    vector<pair<int64_t, int64_t>> res(p.length() + 1);
    res[0] = {x, y};
    for (int i = 0; i < (p.length()); ++i) {
        if (p[i] == 'U') {
            ++y;
        } else if (p[i] == 'D') {
            --y;
        } else if (p[i] == 'L') {
            --x;
        } else {
            ++x;
        }
        res[i + 1] = {x, y};
    }
    return res;
}

bool Find(const vector<pair<int64_t, int64_t>>& v, pair<int64_t, int64_t> p) {
    for (auto pp : v) {
        if (pp == p) {
            return true;
        }
    }
    return false;
}

// Checker functions
void check_repeated_emulation(int numIterations, int progLength, bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to repeated emulation of path!" << endl;
        abort();
    }
}

void check_inefficient_search(int numSearches, bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to inefficient search for target!" << endl;
        abort();
    }
}

void check_minimal_progress(int delta_x, int delta_y, bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to minimal progress toward target!" << endl;
        abort();
    }
}

void solve(istream& in, ostream& out) {
    int X = next<int>(in);
    int Y = next<int>(in);
    string prog = next<string>(in);
    int64_t x = 0, y = 0;
    
    // Check for repeated emulation
    check_repeated_emulation(1000, prog.length(), (prog.length() > 1 && /* some condition indicating repeated emulations */ false));
    
    for (int iter = 0; iter < (1000); ++iter) {
        vector<pair<int64_t, int64_t>> v = emulate(x, y, prog);
        
        // Check for inefficient search
        check_inefficient_search(iter, (v.size() > 1 && /* some condition indicating inefficient search */ false));
        
        if (Find(v, make_pair(X, Y))) {
            out << "Yes\n";
            return;
        }
        
        x = v.back().first;
        y = v.back().second;
    }
    
    auto v = emulate(0, 0, prog);
    int64_t delta_x = v.back().first;
    int64_t delta_y = v.back().second;
    
    // Check for minimal progress
    check_minimal_progress(delta_x, delta_y, (delta_x == 0 && delta_y == 0));
    
    if (abs(delta_x) > abs(X) || abs(delta_y) > abs(Y)) {
        out << "No\n";
        return;
    }
    if (delta_x * 1LL * X < 0 || delta_y * 1LL * Y < 0) {
        out << "No\n";
        return;
    }
    int64_t times_1 = 1;
    if (delta_x != 0) {
        times_1 = abs(X) / abs(delta_x);
        times_1 -= 500;
    }
    int64_t times_2 = 1;
    if (delta_y != 0) {
        times_2 = abs(Y) / abs(delta_y);
        times_2 -= 500;
    }
    x = delta_x * times_1;
    y = delta_y * times_1;
    for (int iter = 0; iter < (1000); ++iter) {
        auto v = emulate(x, y, prog);
        if (Find(v, make_pair(X, Y))) {
            out << "Yes\n";
            return;
        }
        x = v.back().first;
        y = v.back().second;
    }
    x = delta_x * times_2;
    y = delta_y * times_2;
    for (int iter = 0; iter < (1000); ++iter) {
        auto v = emulate(x, y, prog);
        if (Find(v, make_pair(X, Y))) {
            out << "Yes\n";
            return;
        }
        x = v.back().first;
        y = v.back().second;
    }
    out << "No\n";
}

int main() {
    solve(cin, cout);
    return 0;
}