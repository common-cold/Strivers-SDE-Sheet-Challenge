class Solution{
  public:

    //Variation 1
    //Print an (r,c)th element
    
    long long givePascalElt(int r, int c){
    
        r=r-1;
        c=c-1;
        long long num = 1;
        
        for(int i=0; i<c; i++){
            num = num*(r-i);
            num = num/(i+1);
        }
        return num;
    }
    
    
    //Variation 2
    //Print r th row
    
    vector<int> givePascalRow(int n){
        long long ans = 1;
        vector<int> v;
        v.emplace_back(ans);
        for(int i=1; i<n; i++){
            ans = ans*(n-i);
            ans = ans/i;
            v.push_back(ans);
        }
        return v;
    }
    
    
    //Variation 3
    //Print the whole triangle upto n rows
    
    vector<vector<long long int>> printPascal(int n) 
    {
      vector<vector<long long int>> pascalVector;
      vector<long long int> v;
      int ans;
      
      for(int r=1; r<=n; r++){
        ans=1;
        v={1};
        for (int c=1; c<r; c++) {
          ans = ans*(r-c);
          ans = ans/c;
          v.emplace_back(ans);
        }
        pascalVector.emplace_back(v);
      }
      return pascalVector;
    }
}  
