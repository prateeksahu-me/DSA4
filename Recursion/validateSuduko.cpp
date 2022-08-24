#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;
bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}
class ValidSudoku {
  public:
    bool validSudoku(vector<vector<char>>& board) {
      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
          if (board[i][j] == '.') {
            for (char c = '1'; c <= '9'; c++) {
              if (isValid(board, i, j, c)) {
                board[i][j] = c;

                if (validSudoku(board))
                  return true;
                else
                  board[i][j] = '.';
              }
            }

            return false;
          }
        }
      }
      return true;

    }
};

int main() {
    FastIO();
    vector<vector<char>> grid;
    ReadMatrix<char>().SquareMatrix(9, grid);
    bool result = ValidSudoku().validSudoku(grid);
    cout << boolalpha << result;
    return 0;
}