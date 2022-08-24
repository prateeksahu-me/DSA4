#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector < vector < int >> & grid, int i, int j) {
  int n = grid.size();
  int m = grid[0].size();
  return (i >= 0 && j >= 0 && i < n && j < m);
}


int rottingOranges(vector<vector<int>>& grid) {
 int days = 2;
  bool flag = false;
  int n = grid.size();
  int m = grid[0].size();
  while (1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == days) {
          if (isSafe(grid, i + 1, j) && grid[i + 1][j] == 1) {
            grid[i + 1][j] = grid[i][j] + 1;
            flag = true;
          }
          if (isSafe(grid, i, j + 1) && grid[i][j + 1] == 1) {
            grid[i][j + 1] = grid[i][j] + 1;
            flag = true;
          }
          if (isSafe(grid, i - 1, j) && grid[i - 1][j] == 1) {
            grid[i - 1][j] = grid[i][j] + 1;
            flag = true;
          }
          if (isSafe(grid, i, j - 1) && grid[i][j - 1] == 1) {
            grid[i][j - 1] = grid[i][j] + 1;
            flag = true;
          }
        }
      }
    }
    if (flag == false) {
      break;
    }
    flag = false;
    days++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        days = -1;
      }
    }
  }
  return days == -1 ? days : days - 2;
}

int main() {
    int n, m, t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for ( int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        cout << rottingOranges(grid) << endl;
    }
}