//Brute Force Solution

class Solution {
  public:
    void setZeros(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int k;
      
        for (int i=0; i<m; i++) {
          for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0){
    	        for (k=0;k<n;k++) {
    	        	if(matrix[i][k] != 0) 
    	        		matrix[i][k] = -1;
              	}
    	          for (k=0;k<m;k++) {
    	          	if(matrix[k][j] != 0) 
    	          		matrix[k][j] = -1;
     	          }				  
    	      }
          }
        }
      
    	  for (int i=0; i<m; i++) {
              for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1 )
                  matrix[i][j] = 0;
              }
        }
    }
};


///Better Solution

class Solution{
  public:
      void setZeros(vector<vector<int>> &matrix)
      {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row[m] = {0};
        int col[n] = {0};
      
        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
              row[i] = 1;
              col[j] = 1;
            }
          }
        }
      
        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
            if(row[i]==1 || col[j]==1){
              matrix[i][j]=0;
            }
          }
        }
    }
};



///Optimal Solution

class Solution{
  public:
      void setZeros(vector<vector<int>> &matrix)
      {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0=1;
      
        //row[i] = matrix[i][0]
        //col[j] = matrix[0][j]
      
        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
            if (matrix[i][j] == 0 && j==0)
              col0=0;
      
            else if (matrix[i][j] == 0)
              matrix[0][j]=matrix[i][0]=0; 
          }
        }
      
        for(int i=1; i<m; i++){
          for(int j=1; j<n; j++){
            if(matrix[0][j]==0 || matrix[i][0]==0){
              matrix[i][j]=0;
            }
          }
        }
        
        if (matrix[0][0] == 0){
          for(int j=1;j<n;j++){
            matrix[0][j]=0;
          }
        }
      
        if (col0 == 0){
          for(int i=0;i<m;i++){
            matrix[i][0]=0;
          }
        }
   
      }    
};
