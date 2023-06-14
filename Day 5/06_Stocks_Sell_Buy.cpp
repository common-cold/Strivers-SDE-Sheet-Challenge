///Brute Force Solution
/// O(N^2)

class Solution{
  public:
    int maximumProfit1(vector<int> &prices){
        int maxProfit = 0;
        int diff;
        int n = prices.size();
    
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                diff = 0;
                diff = prices[j] - prices[i];
                maxProfit = max(maxProfit, diff);
            }
        }
        return maxProfit;
    }
}



///Optimal SOlution
/// O(N)

class Solution{
  public:
      int maximumProfit(vector<int> &prices){
          
          int n = prices.size();
          int mini = prices[0];
          int cost, maxProfit = 0;
          for(int i = 1; i < n; i++){
              cost = prices[i] - mini;
              maxProfit = max(maxProfit, cost);
              mini = min(mini , prices[i]);
          }
          return maxProfit;
      }
}
