#include <iostream>
#include <vector>
using namespace std;
vector<vector<string>> result;

class Solution {
    private:
    void backtracking(int n, int row, vector<string>& chessboard) {
    if (row == n) {
        result.push_back(chessboard);
        return;
    }
    //一行只有一个
    for (int col = 0; col < n; col++) {
        if (isValid(row, col, chessboard, n)) {
            chessboard[row][col] = 'Q';
            backtracking(n, row + 1, chessboard);
            chessboard[row][col] = '.';
        }
    }
}

bool isValid(int row, int col, vector<string>& chessboard, int n) {
    //检查列上没有Q
    for (int i = 0; i < row; i++) {
        if (chessboard[i][col] == 'Q') {
            return false;
        }
    }
    //检查左上角
    for (int i = row - 1, j = col - 1; i>= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    //检查右上角
    for (int i = row - 1, j = col + 1; i >= 0 && j >= 0; i--, j++) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}
public:
    vector<vector<string>> nQueen(int n) {
        result.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> result = sol.nQueen(5);
    for (auto& solve : result) {
        for (string row : solve) {
            cout << "[ ";
            cout << row << " ";
            cout << "]";
        }
    }
    cout << endl;
    return 0;
}
    
 
