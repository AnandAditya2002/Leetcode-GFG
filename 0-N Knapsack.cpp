#include<iostream>
#include<vector>
using namespace std;
//using Recursion
int KnapSack(int* val,int n,int* weigths,int W){
	//base case 
	if(W==0){
		return 0;
	}
	//recursive case
	int maxprofit=0;
	for(int i=0;i<n;i++){
		if(weigths[i] <=W){
			maxprofit=max(maxprofit, val[i] + KnapSack(val,n,weigths,W-weigths[i]));
		}
	}
	return maxprofit;
}
//using DP
int KnapSackBottomUp(int* val,int n,int* weights,int W){
	vector<int>dp(W+1);
	dp[0]=0;
	for(int i=1;i<=W;i++){
		for(int j=0;j<n;j++){
			if(weights[j]<=i){
				dp[i]=max(dp[i],val[j] + dp[i-weights[j]]);
			}
		}
	}
	return dp[W];
}
int main() {
	int n;
	cin>>n;
	int cap;
	cin>>cap;
	int wt[n];
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	int val[n];
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	//cout<<KnapSack(val,n,wt,cap)<<endl;
	cout<<KnapSackBottomUp(val,n,wt,cap)<<endl;
	
	return 0;
}