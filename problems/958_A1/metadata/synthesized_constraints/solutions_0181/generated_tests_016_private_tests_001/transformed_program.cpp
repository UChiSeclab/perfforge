#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> matrix1, matrix2;

// Checkers
void check_iteration_invariant(int numTransformations) {
    if (numTransformations > 30) {
        cerr << "Warning: Performance bottleneck condition triggered - too many transformation checks!" << endl;
        abort();
    }
}

void check_element_access_invariant(int N) {
    if (N * N > 100) {  // N is ≤ 10, this is more of a guard
        cerr << "Warning: Performance bottleneck condition triggered - excessive element accesses!" << endl;
        abort();
    }
}

void check_simultaneous_transformation_invariant(int numSimultaneousChecks) {
    if (numSimultaneousChecks > 36) {
        cerr << "Warning: Performance bottleneck condition triggered - too many simultaneous transformations!" << endl;
        abort();
    }
}

// Helper functions
vector<vector<bool>> copy(vector<vector<bool>> matrix) {
    int N = matrix.size();
    vector<vector<bool>> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i].resize(N);
        for (int j = 0; j < N; j++) ans[i][j] = matrix[i][j];
    }
    return ans;
}

vector<vector<bool>> flip_vertical(vector<vector<bool>> matrix) {
    int N = matrix.size();
    vector<vector<bool>> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i].resize(N);
        for (int j = 0; j < N; j++) ans[i][j] = matrix[i][N - 1 - j];
    }
    return ans;
}

vector<vector<bool>> flip_horizontal(vector<vector<bool>> matrix) {
    int N = matrix.size();
    vector<vector<bool>> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i].resize(N);
        for (int j = 0; j < N; j++) ans[i][j] = matrix[N - 1 - i][j];
    }
    return ans;
}

vector<vector<bool>> rotate_90(vector<vector<bool>> matrix) {
    int N = matrix.size();
    vector<vector<bool>> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i].resize(N);
        for (int j = 0; j < N; j++) ans[i][j] = matrix[N - 1 - j][i];
    }
    return ans;
}

vector<vector<bool>> rotate_180(vector<vector<bool>> matrix) {
    int N = matrix.size();
    vector<vector<bool>> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i].resize(N);
        for (int j = 0; j < N; j++) ans[i][j] = matrix[j][i];
    }
    return ans;
}

vector<vector<bool>> rotate_270(vector<vector<bool>> matrix) {
    int N = matrix.size();
    vector<vector<bool>> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i].resize(N);
        for (int j = 0; j < N; j++) ans[i][j] = matrix[j][N - 1 - i];
    }
    return ans;
}

bool isEqual(vector<vector<bool>> matrix1, vector<vector<bool>> matrix2) {
    for (int i = 0; i < matrix1.size(); i++)
        for (int j = 0; j < matrix1[i].size(); j++)
            if (matrix1[i][j] != matrix2[i][j]) return false;
    return true;
}

bool checkEquality() {
    vector<vector<bool>> tmp1, tmp2;
    int numTransformations = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            switch (i) {
            case 0:
                tmp1 = copy(matrix1);
                break;
            case 1:
                tmp1 = flip_vertical(matrix1);
                break;
            case 2:
                tmp1 = flip_horizontal(matrix1);
                break;
            case 3:
                tmp1 = rotate_90(matrix1);
                break;
            case 4:
                tmp1 = rotate_180(matrix1);
                break;
            case 5:
                tmp1 = rotate_270(matrix1);
                break;
            }

            switch (j) {
            case 0:
                tmp2 = copy(matrix2);
                break;
            case 1:
                tmp2 = flip_vertical(matrix2);
                break;
            case 2:
                tmp2 = flip_horizontal(matrix2);
                break;
            case 3:
                tmp2 = rotate_90(matrix2);
                break;
            case 4:
                tmp2 = rotate_180(matrix2);
                break;
            case 5:
                tmp2 = rotate_270(matrix2);
                break;
            }

            numTransformations++;
            check_iteration_invariant(numTransformations);

            if (isEqual(tmp1, tmp2)) return true;
        }
    }

    check_simultaneous_transformation_invariant(numTransformations);

    return false;
}

int main() {
    int N;
    cin >> N;

    check_element_access_invariant(N);

    matrix1.resize(N);
    matrix2.resize(N);
    string str;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        cin >> str;
        matrix1[i].assign(N, false);
        for (int j = 0; j < N; j++)
            if (str[j] == 'X') matrix1[i][j] = true;
    }
    for (int i = 0; i < N; i++) {
        cin >> str;
        matrix2[i].assign(N, false);
        for (int j = 0; j < N; j++)
            if (str[j] == 'X') matrix2[i][j] = true;
    }
    if (checkEquality())
        cout << "Yes";
    else
        cout << "No";
    cout << "\n";
    return 0;
}