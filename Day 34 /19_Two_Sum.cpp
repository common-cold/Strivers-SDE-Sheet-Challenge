//Brute Force
//T.C = O(N^2)
//S.C = O(1)

string read(int n, vector<int> book, int target)
{
    for(int i = 0; i < book.size(); i++){
        for(int j = i+1; j < book.size(); j++){
            if(book[i]+book[j]==target)
                return "YES";
        }
    }
    return "NO";
}

//Better Solution (Hashing)
//T.C = O(N*log N)
//S.C = O(N)

string read(int n, vector<int> book, int target)
{
    map<int,int> mpp;
    for(int i = 0; i<book.size(); i++){
        int balance = target - book[i];
        if(mpp.find(balance)!=mpp.end())
            return "YES";   // return {mpp[balance],i};//

        mpp[book[i]] = i;    
    }
    return "NO";
}



//Optimal Soln (2 - Pointer approach)
//T.C = O(N) + O(N*log N)
//S.C = O(1)

string read(int n, vector<int> book, int target)
{
    int left = 0;
    int right = book.size()-1;

    sort(book.begin(),book.end());

    while(left<right){
        int sum = book[left]+book[right];
        if(sum==target)
            return "YES";
        else if(sum<target)
            left++;
        else
            right--;
    }
    return "NO";
}
