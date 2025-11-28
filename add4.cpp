#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (r<0 || r>=m || c<0 || c>=n || grid[r][c]=='0') return;
    grid[r][c] = '0';
    dfs(r+1, c, grid);
    dfs(r-1, c, grid);
    dfs(r, c+1, grid);
    dfs(r, c-1, grid);
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin >> grid[i][j];
    int count = 0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j]=='1') {
                count++;
                dfs(i,j,grid);
            }
    cout << count;
}
