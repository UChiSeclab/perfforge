#include <bits/stdc++.h>
using namespace std;

int LIGHT_SIZE;
bool light[101];
int start[101];
int cycle[101];

int ini_Lights(const string& s) {
    LIGHT_SIZE = s.size();
    int on = 0;
    for (int i = 0; i < s.size(); i++) {
        light[i] = s[i] == '1';
        if (light[i]) {
            on++;
        }
    }
    return on;
}

int simRound(int round, int lastOn) {
    int on = lastOn;
    for (int i = 0; i < LIGHT_SIZE; i++) {
        int begin = round - start[i];
        if (begin >= 0 && begin % cycle[i] == 0) {
            light[i] = !light[i];
            if (light[i]) {
                on++;
            } else {
                on--;
            }
        }
    }
    return on;
}

void check_frequent_toggles_invariant(int LIGHT_SIZE, const int* cycle) {
    int frequentToggles = 0;
    for (int i = 0; i < LIGHT_SIZE; ++i) {
        if (cycle[i] == 1) { // Assuming cycle of 1 is frequent
            ++frequentToggles;
        }
    }
    if (frequentToggles > LIGHT_SIZE / 2) { // If more than half have frequent toggles
        cerr << "Warning: Performance bottleneck condition triggered - frequent toggles!" << endl;
        abort();
    }
}

void check_high_simulation_time_invariant(int simulationTime, int LIGHT_SIZE, int max_on) {
    if (simulationTime > 100000 && max_on < LIGHT_SIZE / 2) { // If running too long with less than half on
        cerr << "Warning: Performance bottleneck condition triggered - high simulation time!" << endl;
        abort();
    }
}

void check_dense_light_setup_invariant(int initial_on_count, int LIGHT_SIZE) {
    if (initial_on_count > LIGHT_SIZE / 2) { // If more than half are initially on
        cerr << "Warning: Performance bottleneck condition triggered - dense light setup!" << endl;
        abort();
    }
}

int main() {
    cin >> LIGHT_SIZE;
    string s;
    cin >> s;

    int max_on = ini_Lights(s);
    int last_on = max_on;

    // Check for dense light setup
    check_dense_light_setup_invariant(max_on, LIGHT_SIZE);

    for (int i = 0; i < LIGHT_SIZE; i++) {
        cin >> cycle[i] >> start[i];
    }

    // Check for frequent toggles
    check_frequent_toggles_invariant(LIGHT_SIZE, cycle);

    for (int i = 1; i <= 100000; i++) {
        last_on = simRound(i, last_on);
        max_on = max(max_on, last_on);

        // Check for high simulation time
        check_high_simulation_time_invariant(i, LIGHT_SIZE, max_on);

        if (max_on == LIGHT_SIZE) {
            break;
        }
    }
    cout << max_on << endl;
}