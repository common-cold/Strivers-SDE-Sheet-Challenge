///Brute Force
///T.C = O(N^2)
///S.C = O(1) 

class Solution{
  public:
      int findMajorityElement(int arr[], int n) {
      	for (int i = 0; i < n; i++) {
      		int count = 0;
      		for(int j = 0; j < n; j++){
      			if(arr[j] == arr[i])
      				count++;
      		}
      		if(count > n/2)
      			return arr[i];
      	}
      
      	return -1;	
      }
};


///Batter Solution
///T.C = O(N * Log N)
///S.C = O(N) (worst case)

class Solution{
  public:
      int findMajorityElement(int arr[], int n) {
      	
      	map<int,int> hashmap;
      	for(int i = 0; i < n; i++){
      		hashmap[arr[i]]++;
      	}
      	
      	for(auto it = hashmap.begin(); it!=hashmap.end(); it++){	
      		if(it->second > n/2){
      			return  it->first;
              }
      	}
      	return -1;
      }

};


///Brute Force
///T.C = O(N)
///S.C = O(1)

class Solution{
  public:
      int findMajorityElement(int arr[], int n) {
      	int ele;
      	int count = 0;
      	for(int i = 0; i < n; i++){
      		if(count == 0){
      			ele = arr[i];
      			count = 1;
      		}
      		if(arr[i] == ele)
      			count++;
      		else
      			count--;
      	}
      	int cnt = 0;
      	for(int i = 0; i < n; i++){
      		if(arr[i] == ele){
      			cnt++;
      		}
      	}
      	if(cnt > n/2)
      		return ele;
      	
      	return -1;	
      }

};
