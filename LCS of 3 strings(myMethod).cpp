#include<iostream>
#include<vector>
using namespace std;
int f(string str1, string str2,string str3,int i,int j,int k){
	//base case
	if(i==str1.length() || j==str2.length() || k==str3.length()){
		return 0;
	}
	//recursive case
	if(str1[i] == str2[j] && str1[i]==str3[k]){
		return 1 + f(str1,str2,str3,i+1,j+1,k+1);
	}
	    int a = f(str1,str2,str3,i+1,j,k);
		int b = f(str1,str2,str3,i,j+1,k);
		int c = f(str1,str2,str3,i,j,k+1);
		return max(a,max(b,c));
}
//USing DP
int fBottomUP(string str1,string str2,string str3){
	vector<vector<vector<int>>>dp(str1.length()+1,vector<vector<int>>(str2.length()+1,vector<int>(str3.length()+1)));
	for(int j=0;j<=str2.length();j++){
		for(int k=0;k<=str3.length();k++){
			dp[str1.length()][j][k]=0;
		}
	}
	for(int i=0;i<=str1.length();i++){
		for(int k=0;k<=str3.length();k++){
			dp[i][str2.length()][k]=0;
		}
	}
	for(int i=0;i<=str1.length();i++){
		for(int j=0;j<=str2.length();j++){
			dp[i][j][str3.length()]=0;
		}
	}
	for(int i=str1.length()-1;i>=0;i--){
		for(int j=str2.length()-1;j>=0;j--){
			for(int k=str3.length()-1;k>=0;k--){
				if(str1[i]==str2[j] && str2[j]==str3[k]){
					dp[i][j][k]=1 + dp[i+1][j+1][k+1];
				}
				else{
					dp[i][j][k]=max(dp[i+1][j][k],max(dp[i][j+1][k], dp[i][j][k+1]));
				}
			}
		}
	}
	return dp[0][0][0];
}
int main() {
	string str1,str2,str3;
	cin>>str1>>str2>>str3;
	cout<<fBottomUP(str1,str2,str3)<<endl;
	return 0;
}