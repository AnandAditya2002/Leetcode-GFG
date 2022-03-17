#include<iostream>
#include<vector>
using namespace std;
bool subset(int* A,int target,int n){
    //base case
    if(n<0){
        return false;
    }
    if(target==0){
       return true;
    }
    //recursive case
    if(A[n-1] > target){
        return subset(A,target,n-1);
    }
    bool x=subset(A,target - A[n-1], n-1);
    bool y=subset(A,target, n-1);
    return x||y;
}
 bool subsetBottomUp(int n,int* A,int target){
    vector<vector<bool>> dp(n+1 , vector<bool>(target+1));
    for(int j=1;j<=target;j++){
        dp[0][j]= false;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++) {
        if(j<A[i-1]){
            dp[i][j]= dp[i-1][j];
            }
            if(j>=A[i-1]){
                dp[i][j]= dp[i-1][j] || dp[i-1][j-A[i-1]];
                }
        }
    }
    return dp[n][target];
}
int main() {
	int n;
	cin>>n;
	int sum;
	cin>>sum;
	int A[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	subsetBottomUp(n,A,sum) ? cout<<"Yes"<<endl : cout<<"No"<<endl;
	return 0;
}