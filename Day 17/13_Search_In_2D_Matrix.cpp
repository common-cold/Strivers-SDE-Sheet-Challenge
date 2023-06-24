///Brute
///T.C = O(N+M)
/// S.C = O(1)
class Solution{
  public: 
      bool searchMatrix(vector<vector<int>>& mat, int target) {
          int n = mat.size();
          int m = mat[0].size();
      
          int index = -1;
          for(int i = 0; i < n; i++){
              if (mat[i][0] <= target && target <= mat[i][m-1]) {
                  index = i;
                  break;
              }
          }
          if(index == -1) return false;
      
          for(int j = 0; j < m; j++){
              if(mat[index][j]==target)
                  return true;
          }
      
          return false;
      
      }  
};


///Better - go down if target is bigger than current elt, or go left if target is samller 
///T.C = O( min(M,N) )
///S.C = O(1)
class Solution{
  public: 
      bool searchMatrix(vector<vector<int>>& mat, int target) {
          
          int n = mat.size();
          int m = mat[0].size();
          
          int i = 0, j = m-1;
      
          while(i<=n-1 && j>=0){
              if(mat[i][j] == target)
                  return true;
              else if (target < mat[i][j])
                  j--;    
              else
                  i++;   
          }
          return false;
      
      }  
};



///optimal - Using binary search
///T.C = O(log M*N)
/// S.C = O(1)
class Solution{
  public: 
      bool searchMatrix(vector<vector<int>>& mat, int target) {
          
          int n = mat.size();
          int m = mat[0].size();
          int low = 0, high = (n*m)-1;
      
          while(low<=high){
              int mid = low + (high-low)/2;
      
              if(target ==  mat[mid/m][mid%m]) return true;
              
              else if (target < mat[mid/m][mid%m])
                  high = mid-1;
      
              else
                  low = mid+1;
          }
          return false;
      
      }  
};
