/*
https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int m = image.size();
        int n = image[0].size();
        int prevColor = image[sr][sc];
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int visited[m][n] = {};
        
        visited[sr][sc] = 1; 
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            image[p.first][p.second] = newColor;
            for( int i =0 ; i < 4 ; i++){
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                if( nx >=0  and nx < m and ny >= 0 and ny < n and visited[nx][ny] == 0 and  image[nx][ny] == prevColor ){
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends