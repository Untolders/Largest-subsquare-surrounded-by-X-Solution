###################################################################################  Question  #########################################################################################################################################################################

Given a square matrix a of size n x n, where each cell can be either 'X' or 'O', you need to find the size of the largest square subgrid that is completely surrounded by 'X'. More formally you need to find the largest square within the grid where all its border cells are 'X'.

Example 1:

Input:
n = 2
a = [[X,X],
     [X,X]]
Output:
2
Explanation:
The largest square submatrix 
surrounded by X is the whole 
input matrix.
Example 2:

Input:
n = 4
a = [[X,X,X,O],
     [X,O,X,X],
     [X,X,X,O],
     [X,O,X,X]]
Output:
3
Explanation:
Here,the input represents following 
matrix of size 4 x 4
X X X O
X O X X
X X X O
X O X X
The square submatrix starting at 
(0,0) and ending at (2,2) is the 
largest submatrix surrounded by X.
Therefore, size of that matrix would be 3.
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestSubsquare() which takes the integer n and the matrix a as input parameters and returns the size of the largest subsquare surrounded by 'X'.

Expected Time Complexity: O(n2)
Expected Auxillary Space: O(n2)

Constraints:
1 <= n <= 1000
a[i][j] belongs to {'X','O'} 





###################################################################################  Solution  #########################################################################################################################################################################

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int largestSubsquare(int n, vector<vector<char>> a) {
       vector<vector<int>>bottom(n+1,vector<int>(n+1,0)),right(n+1,vector<int>(n+1,0));
    //   right
      for(int i=0;i<n;i++){
          for(int j=n-1;j>=0;j--){
              if(a[i][j]=='X'){
                  right[i][j]=right[i][j+1]+1;
              }
          }
      }
       
    //   bottom
      for(int j=0;j<n;j++){
          for(int i=n-1;i>=0;i--){
              if(a[i][j]=='X'){
                  bottom[i][j]=bottom[i+1][j]+1;
              }
          }
      }
       int ans=0;
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              int len = min(right[i][j],bottom[i][j]);
              while(len>0){
                  int x1=i;
                  int y1=j+len-1;
                  int x2=i+len-1;
                  int y2=j;
                  if(min(bottom[x1][y1],right[x2][y2])>=len){
                      ans=max(ans,len);
                      break;
                  }else len--;
              }
          }
      }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends

