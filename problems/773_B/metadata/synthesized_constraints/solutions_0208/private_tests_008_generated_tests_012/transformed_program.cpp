#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_binary_search_space(int searchSpace, int threshold) {
    if (searchSpace > threshold) {
        cerr << "Warning: Performance bottleneck - excessive binary search space!" << endl;
        abort();
    }
}

void check_repeated_score_calculation(int scoreCalculationCount, int threshold) {
    if (scoreCalculationCount > threshold) {
        cerr << "Warning: Performance bottleneck - excessive score calculations!" << endl;
        abort();
    }
}

void check_fine_grained_adjustments(int adjustmentCount, int threshold) {
    if (adjustmentCount > threshold) {
        cerr << "Warning: Performance bottleneck - fine-grained adjustments!" << endl;
        abort();
    }
}

int n;
int a[120][5];
int cur_maxpoint[5];
int nb_solved[5];
int optimal_config[5];
int idx_to_maxpoint[6];
int new_nb_solved[5];
int new_maxpoint[5];
int finalRs = 2000000000;

int calculate_score(int idx, int* maxpoints) {
    static int scoreCalculationCount = 0;
    scoreCalculationCount++;
    check_repeated_score_calculation(scoreCalculationCount, 10000); // Arbitrary threshold for excessive calculations

    int rs = 0;
    for (int j = 0; j < 5; j++) {
        if (a[idx][j] > -1) {
            rs += ((maxpoints[j] / 250) * (250 - a[idx][j]));
        }
    }
    return rs;
}

bool compare(int p, int q, int x, int y) {
    int tmp1 = x * q;
    int tmp2 = y * p;
    if (tmp1 > tmp2) return false;
    return true;
}

bool strict_compare(int p, int q, int x, int y) {
    int tmp1 = x * q;
    int tmp2 = y * p;
    if (tmp1 >= tmp2) return false;
    return true;
}

int ratio_to_maxpoint(int ratio_up, int ratio_down) {
    if (compare(1, 1, ratio_up, ratio_down) &&
        strict_compare(ratio_up, ratio_down, 1, 2))
        return 500;
    if (compare(1, 2, ratio_up, ratio_down) &&
        strict_compare(ratio_up, ratio_down, 1, 4))
        return 1000;
    if (compare(1, 4, ratio_up, ratio_down) &&
        strict_compare(ratio_up, ratio_down, 1, 8))
        return 1500;
    if (compare(1, 8, ratio_up, ratio_down) &&
        strict_compare(ratio_up, ratio_down, 1, 16))
        return 2000;
    if (compare(1, 16, ratio_up, ratio_down) &&
        strict_compare(ratio_up, ratio_down, 1, 32))
        return 2500;
    return 3000;
}

bool isPossible(int proposedRs) {
    int new_n = n + proposedRs;
    for (int j = 0; j < 5; j++) {
        if (optimal_config[j] == 1)
            new_nb_solved[j] = nb_solved[j] + proposedRs;
        else
            new_nb_solved[j] = nb_solved[j];
    }
    for (int j = 0; j < 5; j++) {
        int ratio_up = new_nb_solved[j];
        int ratio_down = new_n;
        new_maxpoint[j] = ratio_to_maxpoint(ratio_up, ratio_down);
    }
    bool returnedval =
        (calculate_score(0, new_maxpoint) > calculate_score(1, new_maxpoint));
    return returnedval;
}

void binarysearch(int left, int right) {
    check_binary_search_space(right - left, 5000); // Arbitrary threshold for search space size

    for (int i = left; i <= right; i++) {
        if (isPossible(i)) {
            if (i < finalRs) finalRs = i;
        }
    }
}

int main() {
    idx_to_maxpoint[0] = 500;
    idx_to_maxpoint[1] = 1000;
    idx_to_maxpoint[2] = 1500;
    idx_to_maxpoint[3] = 2000;
    idx_to_maxpoint[4] = 2500;
    idx_to_maxpoint[5] = 3000;
    nb_solved[0] = 0;
    nb_solved[1] = 0;
    nb_solved[2] = 0;
    nb_solved[3] = 0;
    nb_solved[4] = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
            if (a[i][j] >= 0) nb_solved[j]++;
        }
    }
    for (int j = 0; j < 5; j++) {
        int ratio_up = nb_solved[j];
        int ratio_down = n;
        cur_maxpoint[j] = ratio_to_maxpoint(ratio_up, ratio_down);
    }
    if (calculate_score(0, cur_maxpoint) > calculate_score(1, cur_maxpoint))
        cout << "0\n";
    else {
        for (int j = 0; j < 5; j++) {
            if (a[0][j] == -1) {
                optimal_config[j] = 0;
            } else {
                if (a[1][j] == -1)
                    optimal_config[j] = -1;
                else {
                    if (a[0][j] < a[1][j])
                        optimal_config[j] = -1;
                    else if (a[0][j] == a[1][j])
                        optimal_config[j] = 0;
                    else if (a[0][j] > a[1][j])
                        optimal_config[j] = 1;
                }
            }
        }
        finalRs = 2000000000;
        binarysearch(1, 5000);
        if (finalRs == 2000000000) finalRs = -1;
        cout << finalRs << "\n";
    }
}