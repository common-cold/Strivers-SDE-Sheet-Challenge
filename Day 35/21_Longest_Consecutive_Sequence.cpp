//Brute Force 
//T.C = O(N^2)
//S.C = O(1)

bool ls(int num, vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==num)
            return true;
    }
    return false;
}


int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int longest  = 1;
    for(int i=0; i<n; i++){
        int x = arr[i];
        int count = 1;
        while(ls(x+1,arr)==true){
            x = x+1;
            count++;
        }
        longest = max(longest,count);
    }
    return longest;
}


//Better Solution
//T.C = O(N) = O(N*Log N)
//S.C = O(1)

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(),arr.end());
    
    int longest = 1;
    int currCount = 0;
    int last = INT_MIN;

    for(int i=0; i<n; i++){
        if(last == arr[i]-1){
            currCount++;
            last = arr[i];
        }
        else if(last != arr[i]){
            currCount = 1;
            last = arr[i];
        }
        longest = max(longest,currCount);
    }
    return longest;
}


//Optimal Soln (Using Hash Set)
//T.C = O(2N) + O(N)
//S.C = O(N)

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> st;
    int longest = 1;
    
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int count = 1;
            int x = it;
            while(st.find(x+1)!=st.end()){
                count++;
                x = x+1;
            }
            longest = max(longest,count);
        }
    }
    return longest;
}
