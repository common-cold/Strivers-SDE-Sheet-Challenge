//Brute Force 
//T.C = O(N^3)
//S.C = O(1)


int LongestSubsetWithZeroSum(vector < int > arr) {
    int n = arr.size();
    int longest = 0;
    for(int i=0; i<n; i++){
      for(int j=i; j<n; j++){
        int sum = 0;
        for(int k=i;k<=j;k++){
          sum = sum + arr[k];
        }
        if(sum==0)
          longest = max(longest,j-i+1);
      }
    }
    return longest;

}



//Better Soln
//T.C = O(N^2)
//S.C = O(1)

int LongestSubsetWithZeroSum(vector < int > arr) {
    int n = arr.size();
    int longest = 0;
    for(int i=0; i<n; i++){
      int sum = 0;
      for(int j=i; j<n; j++){
        sum = sum + arr[j];
        if(sum==0)
          longest = max(longest,j-i+1);
      }
    }
    return longest;

}


//Optimal Soln (Using Hashing + a trick)
//T.C = O(N * Log N)
//S.C = O(N)

int LongestSubsetWithZeroSum(vector < int > arr) {
  
  int n = arr.size();
  int maxi = 0;
  int sum = 0;
  unordered_map<int,int> mpp;
  for(int i=0; i<n; i++){
    sum = sum + arr[i];
    if(sum==0){
      maxi = i+1;
    }
    else{
      if(mpp.find(sum)!=mpp.end()){
        maxi = max(maxi,i-mpp[sum]);
      }
      else{
        mpp[sum]=i;
      }
    }
  }
  return maxi;
}
