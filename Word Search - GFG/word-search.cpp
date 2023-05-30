//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   bool dfs(int i,int j,vector<vector<char>>& board,string word,int n, int m,int ind,vector<vector<int>>& vis){
     
       vis[i][j]=1;
       int x[4]={-1,0,1,0};
       int y[4]={0,-1,0,1};
       if(ind==word.size()) return true;
       for(int z=0;z<4;z++){
           int nrow=x[z]+i; 
           int ncol=y[z]+j;
           if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && board[nrow][ncol]==word[ind] && !vis[nrow][ncol]){
             
               if(dfs(nrow,ncol,board,word,n,m,ind+1,vis))return true;
              
           }
       }
       vis[i][j]=0;
       return false;
   }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    if(dfs(i,j,board,word,n,m,1,vis))return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends