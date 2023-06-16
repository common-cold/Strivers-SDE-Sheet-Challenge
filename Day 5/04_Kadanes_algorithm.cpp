//Brute Force
//O(N^3)

class Solution{
  public:
      long long maxSubarraySum(int arr[], int n)
      {
              
          int maxi = INT_MIN;    
          for(int i=0; i<n; i++){
              for(int j=i; j<n; j++){
                  
                  int sum = 0;
                  
                  for(int k=i; k<=j; k++){
                      sum += arr[k];
                  }
                  maxi = max(maxi,sum);
              }
          }
          return maxi;          
      }
}


///Better Approach
///O(N^2)

class Solution{
  public:
      long long maxSubarraySum(int arr[], int n)
      {
              
          int maxi = INT_MIN;    
          for(int i=0; i<n; i++){
              int sum = 0;
              for(int j=i; j<n; j++){
                  sum = sum + arr[j];
                  maxi = max(maxi,sum);
              }
          }
          return maxi; 
      }
}


///Optimal Approach - Kadane's Algorithm
///O(N)

class Solution{
  public:
    long long maxSubarraySum(int arr[], int n)
    {
        int maxi = INT_MIN;
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum = sum + arr[i];
            
            maxi = max(maxi,sum);
            
            if(sum < 0)
                sum = 0;
        }
        return maxi;
    }
}; 


///Follow Up Question
///Print the subarray too

class Solution{
  public:
    long long maxSubarraySum(int arr[], int n)
     {
         int maxi = INT_MIN;
         int sum = 0;
         int start;
         int subStart;
         int subEnd; 
         for(int i=0; i<n; i++){
             if(sum == 0){
                 start = i;
             }
             sum = sum + arr[i];
             
             if(sum >= maxi){
                 maxi = sum;
                 subStart = start;
                 subEnd = i;
             } 
             if (sum < 0) {
                 sum = 0;
             }
            
           for(int i=subStart; i<=subEnd; i++){
                cout<<arr[i]<<endl;
            }
         }
         return maxi;
     }
}
