//Approach-1
// O(m*n*log n) +O(n)

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	for(int i = 0; i < m; i++){
		if(arr1[i] > arr2[0]){
			swap(arr1[i],arr2[0]);
			sort(arr2.begin(),arr2.end());
		}
	}
	for(int i = 0; i<n; i++){
		arr1[m+i] = arr2[i];
	}
	return arr1;
}


//Approach-2
// O(n) + O((n+m)log(n+m))

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
	for(int i = 0; i<n; i++){
		arr1[m+i] = arr2[i];
	}
	sort(arr1.begin(),arr1.end());
	return arr1;
}


//Optimal Approach
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
	int left = m-1;
	int right = 0;
	while(left >= 0 && right <= n-1){
		if(arr1[left] > arr2[right]){
			swap(arr1[left], arr2[right]);
			left--,right++;
		}
		else{
			break;
		}
	}
	sort(arr1.begin(), arr1.begin()+m);
	sort(arr2.begin(), arr2.end());
	for(int i = 0; i<n; i++){
		arr1[m+i] = arr2[i];
	}
	return arr1;
}
