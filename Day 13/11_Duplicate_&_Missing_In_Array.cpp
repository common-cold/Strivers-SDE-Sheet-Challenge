///Brute
///T.C = O(N^2)
///S.C = O(1)

class Solution{
  public:
      pair<int,int> missingAndRepeating(vector<int> &arr, int n)
      {
      	pair<int,int> ans;
      	int repeating =-1, missing =-1;
      	for(int i = 1; i<=n; i++){
      		int count=0;
      		for(int j = 0; j < n; j++){
      			if(arr[j] == i){
      				count++;
      			}
      		}
      		if(count==2)
      			repeating = i;
      		else if(count == 0)
      			missing = i;
      		if(missing != -1 && repeating != -1)
      			break;		
      	}
      	ans.first = missing;
      	ans.second = repeating;
      	return ans;		
      }
};



///Better - Using Hash Array
///T.C = O(N)
///S.C = O(N)

class Solution{
  public:
      pair<int,int> missingAndRepeating(vector<int> &arr, int n)
      {
      	pair<int, int> ans;
      	int repeating = -1, missing = -1;
      	vector<int> hash(n+1,0);
      	for(int i = 0; i < n; i++){
      		hash[arr[i]]++;
      	}
      	for(int i = 1; i < n+1; i++){
      		if(hash[i] == 0)
      			missing = i;
      		else if(hash[i] >= 2)
      			repeating = i;
      
      		if(repeating != -1 && missing != -1)
      			break;	
      	}
      	ans.first = missing;
      	ans.second = repeating;
      	return ans;	
      }
};




///Optimal - Using Maths
///T.C = O(N)
///S.C = O(1)

class Solution{
  public:
      pair<int,int> missingAndRepeating(vector<int> &arr, int n)
       {
       	pair<int,int> ans;
      
      	long long S2 = 0 , S = 0; 
      	
      	long long Sn = n*(n+1)/2;
      	long long S2n = n*(n+1)*(2*n+1)/6;
      
      	for(int i = 0; i < n; i++){
      		S = S + (long long) arr[i];
      		S2 = S2 + (long long) (arr[i]*arr[i]);
      	}
      
      	int val1 = S - Sn;
      	int val2 = S2 - S2n;
      	val2 = val2/val1;
      
      	long long x = (val1 + val2)/2;
      	long long y = x - val1;
      
      	ans.first = (int) y;
      	ans.second = (int) x;
      
      	return ans;
      }
};
