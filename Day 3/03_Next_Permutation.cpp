///BruteForce solution
///Using STL library

class Solution{
  public:
    vector<int> nextPermutation(vector<int> &permutation, int n)
    {
        
        vector<vector<int>>lst;
        vector<int> v = permutation;
        
        sort(v.begin(),v.end());
        do{
            lst.emplace_back(v);
        }while(next_permutation(v.begin(),v.end()));
    
        for(int i=0; i<lst.size();i++){
        
            if(permutation == lst[i] && i==(lst.size()-1))
                return lst[0];
    
            if(permutation == lst[i]){
                return lst[i=i+1];
            }
        
        }
    }
} 



///Optimal Approach
///Implementing the next_permutation() function

class Solution:
public:
  vector<int> nextPermutations(vector<int> &permutation, int n)
  {
      int index = -1;
      for(int i=n-2; i>=0; i--){
          if(permutation[i] < permutation[i+1]){
              index = i;
              break;
          }
      }
  
      if (index == -1) {
        reverse(permutation.begin(), permutation.end());
        return permutation;
      }
  
      for(int i=n-1; i>=0; i--){
          if(permutation[index] < permutation[i]){
              swap(permutation[index],permutation[i]);
              break;
          }
      }
  
      sort(permutation.begin()+index+1,permutation.end());
  
      return permutation;
  }
}
