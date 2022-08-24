#include<bits/stdc++.h>
using namespace std;

const int dx[] = { 1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
bool isSafe(vector < vector < int >> & grid, int x, int y) {
  int r = grid.size();
  int c = grid[0].size();
  return (x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == 1);
}

int rottingOranges(vector<vector<int>>& grid) {
 int r = grid.size();
  int c = grid[0].size();
  queue < pair < int, int >> q;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 2) {
        q.push({ i,  j });
      }
    }
  }
  int days = -2;
  while (!q.empty()) {
    int qs = q.size();
    while (qs--) {
      pair < int, int > p = q.front();
      int x = p.first;
      int y = p.second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        if (isSafe(grid, x + dx[i], y + dy[i])) {
          q.push({
            x + dx[i],
            y + dy[i]
          });
          grid[x + dx[i]][y + dy[i]] = 2;
        }
      }
    }
    days += 1;
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 1) {
        return -1;
      }
    }
  }
  return days == -2 ? 0 : days + 1;
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