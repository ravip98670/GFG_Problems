//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>>& vec, int iRow, int iCol) {
        vis[i][j] = 1;
        vec.push_back({i - iRow, j - iCol});

        int n = grid.size();
        int m = grid[0].size();

        int tRow[] = {-1, 0, 1, 0};
        int tCol[] = {0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
            int r = i + tRow[k];
            int c = j + tCol[k];
            if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 1) {
                dfs(r, c, grid, vis, vec, iRow, iCol);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int,int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends