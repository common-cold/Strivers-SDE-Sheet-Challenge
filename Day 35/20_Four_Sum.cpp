//Brute Force (Trying Every Possible combn using 4-Pointer)
//T.C = O(N^4)
//S.C = O(1)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k=1; l<n; l++){
                    if(nums[i]+nums[j]+nums[k]+nums[l] == target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}


//Better Soln (Hashing)
//T.C = O(N^2 * Log M)
//S.C = O(N) + O(no. of triplets * 2)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<int> hashset;
            for(int k=j+1; k<n; k++){
                int bal = target - (nums[i]+nums[j]+nums[k]);
                if(hashset.find(bal)!=hashset.end()){
                        vector<int> temp = {nums[i],nums[j],nums[k],bal};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);                    
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}


//Optimal Soln (2-Pointer Approach)
//T.C = O(N^3)
//S.C = O(1)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++){
        if(i!=0 && nums[i]==nums[i-1])
            continue;        

        for(int j=i+1; j<n; j++){
            if(j>i+1 && nums[j]==nums[j-1])
                continue;
            
            int k = j+1;
            int l = n-1;

            while(k<l){
                int sum = nums[i]+nums[j]+nums[k]+nums[l];

                if(sum<target){
                    k++;
                }

                else if(sum>target){
                    l--;
                }
                else if(sum == target){
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    while(k<l && nums[k]==nums[k-1])
                        k++;
                    while(k<l && nums[j]==nums[j+1])
                        j--;    
                }
            }
        }
    }
    return ans;
}
