///Brute Force
///T.C = O(N^2)
///S.C = O(1)

class Solution{
  public:
      vector<int> majorityElementII(vector<int> &arr)
      {
          int n = arr.size();
          vector<int> ans;
          for(int i = 0; i < n; i++){
              int count = 0;
              
              if(ans.size()==0 || arr[i] != ans[0]){
                  for(int j = 0; j < n; j++){
                      if (arr[j] == arr[i]) {
                          count++;
                      }
                  }
                  if (count > n / 3)
                      ans.push_back(arr[i]);
                  
                  if (ans.size() == 2)
                      return ans;
              }
          }
      
      }
};


///Better Solution
///T.C = O(N * Log N)
///S.C = O(N) (worst case)

class Solution{
  public:
      vector<int> majorityElementII(vector<int> &arr)
      {
          map<int, int> mpp;
          vector<int> ans;
          int n = arr.size();
          
          for(int i = 0; i < n; i++){
              mpp[arr[i]]++;
      
              if(mpp[arr[i]] == (n/3)+1)
                  ans.push_back(arr[i]);
              
              if(ans.size() == 2)
                  return ans;
          }
      }
};


///Optimal Solution
///T.C = O(N)
///S.C = O(1)

class Solution{
  public:
      vector<int> majorityElementII(vector<int> &arr)
      {
          int ele1 = 0, ele2 = 0;
          int count1 = 0, count2 = 0;
          int n = arr.size();
          vector<int> ans;
      
          for(int i = 0; i < n; i++){
      
              if (count1 == 0 && arr[i] != ele2) {
                  ele1 = arr[i];
                  count1++;
              }
      
              else if (count2 == 0 && arr[i] != ele1){
                  ele2 = arr[i];
                  count2++;
              }
      
              else if (arr[i] == ele1)
                  count1++;
      
              else if (arr[i] == ele2)
                  count2++;
      
              else{
                  count1--;
                  count2--;
              }
          }
          
          count1 = 0;
          count2 = 0;
          for(int i = 0; i < n; i++){
              if(arr[i] == ele1)
                  count1++;
              else if(arr[i] == ele2)
                  count2++;                 
          }
      
          if(count1 > n/3)
              ans.push_back(ele1);
          if(count2 > n/3)
              ans.push_back(ele2);    
      
          return ans;     
        }
};
