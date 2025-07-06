#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
int Frequencies[5], Answer;

// Checker functions for performance bottlenecks
void check_imbalanced_distribution(int freq1, int freq2) {
    if (freq1 > 0 && freq2 > 0) {
        cerr << "Warning: Performance bottleneck condition triggered - imbalanced distribution of students!" << endl;
        abort();
    }
}

void check_frequent_small_swaps(int freq1, int freq2) {
    if (freq1 > 0 && freq2 > 0) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent small swaps detected!" << endl;
        abort();
    }
}

void check_complex_redistribution(int freq1, int freq2, int freq3, int freq4) {
    if (freq1 > 0 && freq2 > 0 && freq3 > 0 && freq4 > 0) {
        cerr << "Warning: Performance bottleneck condition triggered - complex redistribution cycles!" << endl;
        abort();
    }
}

void Solve() {
    bool bigMove = true;
    while (bigMove) {
        bigMove = false;

        // Check for imbalanced distribution before attempting swaps
        check_imbalanced_distribution(Frequencies[1], Frequencies[2]);

        while (Frequencies[1] > 0 && Frequencies[2] > 0) {
            --Frequencies[1];
            --Frequencies[2];
            ++Frequencies[3];
            ++Answer;
            bigMove = true;

            // Check for frequent small swaps
            check_frequent_small_swaps(Frequencies[1], Frequencies[2]);
        }
        
        while (Frequencies[2] >= 3) {
            Frequencies[2] -= 3;
            Frequencies[3] += 2;
            Answer += 2;
            bigMove = true;
        }

        while (Frequencies[2] >= 2) {
            Frequencies[2] -= 2;
            ++Frequencies[4];
            Answer += 2;
            bigMove = true;
        }

        bool move = true;
        while (move) {
            move = false;

            while (Frequencies[2] > 0 && Frequencies[4] > 0) {
                --Frequencies[2];
                --Frequencies[4];
                Frequencies[3] += 2;
                ++Answer;
                move = true;
                bigMove = true;
            }

            while (Frequencies[2] > 0 && Frequencies[3] >= 2) {
                --Frequencies[2];
                Frequencies[3] -= 2;
                Frequencies[4] += 2;
                Answer += 2;
                move = true;
                bigMove = true;
            }

            // Check for complex redistribution cycles
            check_complex_redistribution(Frequencies[1], Frequencies[2], Frequencies[3], Frequencies[4]);
        }

        while (Frequencies[1] >= 3) {
            Frequencies[1] -= 3;
            ++Frequencies[3];
            Answer += 2;
            bigMove = true;
        }

        move = true;
        while (move) {
            move = false;

            while (Frequencies[1] > 1 && Frequencies[4] > 0) {
                Frequencies[1] -= 2;
                --Frequencies[4];
                Frequencies[3] += 2;
                Answer += 2;
                move = true;
                bigMove = true;
            }

            while (Frequencies[1] > 0 && Frequencies[3] > 0) {
                --Frequencies[1];
                --Frequencies[3];
                ++Frequencies[4];
                ++Answer;
                move = true;
                bigMove = true;
            }

            while (Frequencies[1] > 0 && Frequencies[4] > 1) {
                --Frequencies[1];
                Frequencies[4] -= 2;
                Frequencies[3] += 3;
                Answer += 2;
                move = true;
                bigMove = true;
            }
        }

        while (Frequencies[1] >= 2) {
            Frequencies[1] -= 2;
            ++Frequencies[2];
            ++Answer;
            bigMove = true;
        }
    }

    if (Frequencies[1] > 0 || Frequencies[2] > 0) Answer = -1;
}

void Read() {
    int n;
    cin >> n;
    for (; n > 0; --n) {
        int value;
        cin >> value;
        ++Frequencies[value];
    }
}

void Print() {
    cout << Answer << "\n";
}

int main() {
    Read();
    Solve();
    Print();
    return 0;
}