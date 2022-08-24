#include <bits/stdc++.h>
using namespace std;


// structure for storing a cell's data
struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
};
 
// Utility method returns true if (x, y) lies
// inside Board
bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

int knightWalk(int N, pair<int,int> &knightPos, pair<int,int> &targetPos){
     // x and y direction, where a knight can move
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
 
    // queue for storing states of knight in board
    queue<cell> q;
 
    // push starting position of knight with 0 distance
    q.push(cell(knightPos.first, knightPos.second, 0));
 
    cell t;
    int x, y;
    bool visit[N + 1][N + 1];
 
    // make all cell unvisited
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;
 
    // visit starting state
    visit[knightPos.first][knightPos.second] = true;
 
    // loop until we have one element in queue
    while (!q.empty()) {
        t = q.front();
        q.pop();
 
        // if current cell is equal to target cell,
        // return its distance
        if (t.x == targetPos.first && t.y == targetPos.second)
            return t.dis;
 
        // loop for all reachable states
        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];
 
            // If reachable state is not yet visited and
            // inside board, push that state into queue
            if (isInside(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
}

int main(){
    int N;
    cin>>N;
    pair<int,int>knightPos,targetPos;
    cin>>knightPos.first>>knightPos.second;
    cin>>targetPos.first>>targetPos.second;
    cout<<knightWalk(N, knightPos, targetPos)<<"\n";
}