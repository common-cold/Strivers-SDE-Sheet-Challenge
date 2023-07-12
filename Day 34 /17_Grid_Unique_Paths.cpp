//Brute Force (Recursion)
//T.C = O(2^(n*m))
//S.C = O(n*m)  recursion stackspace


int solve(int i, int j, int m, int n){
	if(i==m || j==n)
		return 0;
	if(i==m-1 && j==n-1)
		return 1;

	int d = solve(i+1,j,m,n);
	int l = solve(i,j+1,m,n);

	return d+l;	
}


int uniquePaths(int m, int n) {
	return solve(0,0,m,n);
}


//Better Soln (Recurion + DP)
//T.C = O(n*m)
//S.C = O(n*m) DP matrix

int solve(int i, int j, int m, int n, vector<vector<int>> &dp){
	if(i==m || j==n)
		return 0;
	if(i==m-1 && j==n-1)
		return 1;

	if(dp[i][j] != -1)
		return dp[i][j];

	return dp[i][j] = solve(i+1,j,m,n,dp) + solve(i,j+1,m,n,dp); 
}


int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m,(vector<int>(n,-1)));
	return solve(0,0,m,n,dp);
}




//Optimal Soln (Combinatorics)
//T.C = O(n-1) or O(m-1)
//S.C = O(1)

int uniquePaths(int m, int n) {
	int count = 1;
	for(int i = 0; i<m-1; i++){
		count = count*(m+n-2-i);
		count = count/(i+1);
	}
	return count;
}
