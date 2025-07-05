#include <bits/stdc++.h>

void check_excessive_iterations(const std::string &str) {
    int questionCount = std::count(str.begin(), str.end(), '?');
    if (questionCount > 30) { // Arbitrarily chosen threshold for demonstration
        std::cerr << "Warning: Performance bottleneck due to excessive '?' characters in sequence." << std::endl;
        abort();
    }
}

void check_redundant_processing(const std::string &str) {
    if (str.size() > 80 && std::count(str.begin(), str.end(), '?') > 20) { // Arbitrary thresholds
        std::cerr << "Warning: Performance bottleneck due to redundant processing of '?' in long sequences." << std::endl;
        abort();
    }
}

void check_long_unwatched_streaks(const std::string &str) {
    int maxConsecutiveN = 0, currentN = 0;
    for (char c : str) {
        if (c == 'N') {
            currentN++;
            if (currentN > maxConsecutiveN) maxConsecutiveN = currentN;
        } else {
            currentN = 0;
        }
    }
    if (maxConsecutiveN > 20) { // Arbitrary threshold
        std::cerr << "Warning: Performance bottleneck due to long streaks of 'N'." << std::endl;
        abort();
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    char str[101];
    scanf("%s", str);
    
    std::string series(str);

    // Apply the performance checks after input
    check_excessive_iterations(series);
    check_redundant_processing(series);
    check_long_unwatched_streaks(series);

    char cur[101];
    for (int i = 0; i + k - 1 < n; ++i) {
        int j = i + k - 1;
        for (int l = 0; l < n; ++l) {
            cur[l] = str[l];
        }
        for (int l = 0; l < n; ++l) {
            if (i <= l && l <= j) {
                if (str[l] == '?') {
                    cur[l] = 'N';
                }
            } else {
                if (str[l] == '?') {
                    cur[l] = 'Y';
                }
            }
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            while (i < n && cur[i] == 'N') {
                ++cnt;
                ++i;
            }
            if (cnt > 0) {
                --i;
                if (cnt > mx) {
                    mx = cnt;
                }
            }
        }
        if (mx == k) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}