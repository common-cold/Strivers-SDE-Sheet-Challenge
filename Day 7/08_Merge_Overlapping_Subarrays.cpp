//// Brute Force Approach
/// O(N Log N) + O(2 N)

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    
    int n = intervals.size();
    
    sort(intervals.begin(), intervals.end());
    for(int i = 0; i<n; i++){
        
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (!ans.empty() && start <= ans.back()[1]) {
          continue;
        }

        for(int j = i+1; j < n; j++){
          
          if( end >= intervals[j][0])
            end = max(intervals[j][1],end);

          else 
            break;
          
        }

        ans.push_back({start,end});
    }

    return ans;
}


////Optimal Approach
/// O(N)

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());
    
    for(int i=0; i<n; i++){

        if(ans.empty() || ans.back()[1] < intervals[i][0]){
            ans.push_back(intervals[i]);
        }

        else{
          ans.back()[1] = max(intervals[i][1], ans.back()[1]); 
        }
    }

    return ans;
}
