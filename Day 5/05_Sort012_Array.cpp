///Brute Force Solution (Not using Merge sort)
/// O(N^2)

class Solution{
  public:
      void sort012(int *arr, int n)
      {
         for(int i = 0; i<n; i++){
            for(int j=i+1; j<n; j++){
               if(arr[i] > arr[j])
                 swap(arr[i],arr[j]);
            }
         }
      }
}


///Better Solution
///O(2N)

class Solution{
  public:
      void sort012(int *arr, int n)
      {
         int count0 = 0;
         int count1 = 0;
         int count2 = 0;
      
         for(int i = 0; i<n; i++){
            if(arr[i]==0)
               count0++;
            else if(arr[i]==1)
               count1++;
            else
               count2++;                  
         }
      
         for(int i=0; i<count0; i++){
            arr[i] = 0;
         }
         for(int i=count0; i<count1+count0; i++){
            arr[i] = 1;
         }
         for(int i=count0+count1; i<count0+count1+count2; i++){
            arr[i] = 2;
         }      
      
      }
}


///Optimal Solution (Dutch National Flag Algorithm)
/// O(N)

class Solution{
  public:
      void sort012(int *arr, int n)
      {
         int low = 0;
         int mid = 0;
         int high = n-1;
      
         while(mid <= high){
            if(arr[mid] == 0){
               swap(arr[mid],arr[low]);
               low++;
               mid++;
            }
            else if(arr[mid] == 1){
               mid++;
            }
            else{
               swap(arr[mid],arr[high]);
               high--;
            }
         }

      }      
}
