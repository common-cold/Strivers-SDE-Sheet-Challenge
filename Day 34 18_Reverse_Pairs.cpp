//Brute Force (For every elt make pairs with all other elet in arrray except itself) 
//T.C = O(N^2)
//S.C = O(1)



//Optimal Solution (Using a modified merge sort)
//T.C = O(2*N*Log N)
//S.C = O(N)  (temp array in merge)


int countPairs(int low, int mid, int high, vector<int> &arr){
	int count = 0;
	int right = mid+1;

	for(int i = low; i<=mid; i++){
		while(right<=high && arr[i] > 2*arr[right])
			right++;
		count = count + (right - (mid+1));	
	}
	return count;
}

void merge(int low, int mid, int high, vector<int> &arr){
	int left = low;
	int right = mid+1;
    vector<int> temp;

	while(left<=mid && right<=high){
		if(arr[left] <= arr[right]){
			temp.push_back(arr[left]);
			left++;
		}
		else{
			temp.push_back(arr[right]);
			right++;
		}
	}
	while(left<=mid){
		temp.push_back(arr[left]);
		left++;
	}
	while(right<=high){
		temp.push_back(arr[right]);
		right++;
	}

	for(int i=low; i<=high; i++){
		arr[i] = temp[i-low];
	}
}

int mergeSort(int low, int high, vector<int> &arr){
	int count = 0;
	if(low>=high)
		return count;
	
	int mid = (low+high)/2;
	
	count += mergeSort(low,mid,arr);
	count += mergeSort(mid+1,high,arr);
	count += countPairs(low,mid,high,arr);
	merge(low,mid,high,arr);
	return count;
}

int reversePairs(vector<int> &arr, int n){
	return mergeSort(0,n-1,arr);
}
