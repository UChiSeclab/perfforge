#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<set<pii>, set<pii> > line;
map<int, line> lines;
int n, w, h;

// Checker functions defined above
void check_interaction_invariant(int verticalCount, int horizontalCount);
void check_set_size_invariant(size_t setSize);
void check_loop_iteration_invariant(size_t iterationCount);

void insert_dancer(int type, int pos, int t, int i) {
    int line_number = pos - t;
    if (type == 1)
        lines[line_number].first.insert(pii(pos, i));
    else if (type == 2)
        lines[line_number].second.insert(pii(pos, i));
}

int output[100000][2];

int main() {
    cin >> n >> w >> h;
    for (int i = 0; i < n; ++i) {
        int g, p, t;
        cin >> g >> p >> t;
        insert_dancer(g, p, t, i);
    }

    for (auto it = lines.begin(); it != lines.end(); ++it) {
        set<pii> verticals = it->second.first;
        set<pii> horizontals = it->second.second;

        // Check for large set sizes
        check_set_size_invariant(verticals.size());
        check_set_size_invariant(horizontals.size());

        auto outer_iterator = verticals.size() ? verticals.begin() : horizontals.end();
        auto inner_iterator = horizontals.size() ? horizontals.end() : verticals.begin();

        if (!verticals.size()) --outer_iterator;
        if (horizontals.size()) --inner_iterator;

        bool inner_vertical = horizontals.empty();
        bool outer_horizontal = verticals.empty();

        size_t loopCount = 0;

        while (inner_iterator != verticals.end()) {
            // Increment loop counter
            loopCount++;

            // Check for excessive loop iterations
            check_loop_iteration_invariant(loopCount);

            const int index = inner_iterator->second;
            const int final_pos = outer_iterator->first;

            if (!outer_horizontal) {
                output[index][0] = final_pos;
                output[index][1] = h;
                ++outer_iterator;
            } else {
                output[index][0] = w;
                output[index][1] = final_pos;
                if (outer_iterator != horizontals.begin()) --outer_iterator;
            }

            if (outer_iterator == verticals.end()) {
                if (horizontals.empty()) break;
                outer_iterator = horizontals.end();
                --outer_iterator;
                outer_horizontal = true;
            }
            
            if (inner_iterator == horizontals.begin()) {
                inner_iterator = verticals.begin();
                inner_vertical = true;
                continue;
            }

            if (!inner_vertical)
                --inner_iterator;
            else
                ++inner_iterator;
        }

        // Check for high interaction in the line
        check_interaction_invariant(verticals.size(), horizontals.size());
    }

    for (int i = 0; i < n; ++i) {
        cout << output[i][0] << " " << output[i][1] << endl;
    }

    return 0;
}