#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    int N;  // 棋盘的大小 N x N
    vector<vector<string>> solutions;  // 存储所有解

    // 检查当前位置 (row, col) 是否可以放置皇后
    bool isSafe(const vector<string>& board, int row, int col) {
        // 检查列冲突
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // 检查主对角线冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // 检查副对角线冲突
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    // 回溯法解决 N 皇后问题
    void solveNQueensHelper(vector<string>& board, int row) {
        if (row == N) {
            // 找到一个解，保存结果
            solutions.push_back(board);
            return;
        }

        // 尝试每一列
        for (int col = 0; col < N; col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';  // 放置皇后
                solveNQueensHelper(board, row + 1);  // 递归处理下一行
                board[row][col] = '.';  // 回溯，撤销皇后
            }
        }
    }

public:
    NQueens(int N) : N(N) {}

    // 主函数，调用回溯法来求解
    vector<vector<string>> solve() {
        vector<string> board(N, string(N, '.'));  // 初始化棋盘
        solveNQueensHelper(board, 0);  // 从第 0 行开始解决问题
        return solutions;
    }

    // 输出所有解
    void printSolutions() {
        auto solutions = solve();
        for (const auto& solution : solutions) {
            for (const auto& row : solution) {
                cout << row << endl;
            }
            cout << endl;  // 每个解后换行
        }
    }
};

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    NQueens nQueens(N);
    nQueens.printSolutions();  // 打印所有解

    return 0;
}