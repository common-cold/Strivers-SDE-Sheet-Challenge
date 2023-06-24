///Brute Force
///T.C = O(N)
/// s.c = O(1)

class Solution{
  public:
    int findDuplicate(vector<int> &arr, int n){
    	sort(arr.begin(),arr.end());
    	for(int i=0; i<n-1; i++){
    		if(arr[i]==arr[i+1]){
    			return arr[i];
    		}
    	}
    }
      
};


///Better Solution
///T.C = O(N)
///S.C = O(N)

class Solution{
  public:
      int findDuplicate(vector<int> &arr, int n){
      	
      	vector<int> freq(n+1, 0);
      
      	for(int i = 0; i < n; i++){
      		if(freq[arr[i]] == 1){
      			return arr[i];
      		}
      		freq[arr[i]]++;
      	}
      }      
};


///Optimal Solution - Linked List Cycle Method 
///T.C = O(N)
///S.C = O(1)
class Solution{
  public:
      int findDuplicate(vector<int> &arr, int n){
      	
      	int fast = arr[0];
      	int slow = arr[0];
      
          do{
            	slow = arr[slow];
            	fast = arr[arr[fast]];
          }while (slow != fast);
      	
      	fast = arr[0];
      
      	while(slow != fast){
      		slow = arr[slow];
      		fast = arr[fast];
      	}
      	return slow;
      }
};
