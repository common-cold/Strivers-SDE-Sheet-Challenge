///Brute Force Solution
/// T.C = S.C = O(N^2)

class Solution{
  public: 
      vector<vector<int>> rotateMatrix(vector<vector<int>> &mat, int n, int m)
      {
          vector<vector<int>> newmat(n, vector<int>(m,0));
      
          for(int i = 0; i < n; i++){
              for( int j = 0; j < m; j++){
                  newmat[j][n-1-i] = mat[i][j];
              }
          }
          return newmat;
      
      }
};


///Optimal Solution
///T.C = O(N^2), S.C = O(1)

class Solution{
  public:
      void rotateMatrixx(vector<vector<int>> &mat, int n, int m)
      {
          for(int i = 0; i < n-1; i++){
              for(int j = i+1; j < m; j++){
                  swap(mat[i][j], mat[j][i]);
              }
          }
      
          for(int i = 0; i < n; i++){
              reverse(mat[i].begin(), mat[i].end());
          }
      
      }
};
