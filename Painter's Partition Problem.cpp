#include<iostream>
#include<climits>
using namespace std;
int NoOfPaintersRequire(int n,int* len,int timelimit){
	int time=0;
	int painters=1;
	for(int i=0;i<n;i++){
		time+= len[i];
		if(time > timelimit){
			painters++;
			time=0;
			time=len[i];
		}
	}
	return painters;
}
int MinTime(int k,int n,int* len){
	int s=INT_MIN;
	int e=0;
	for(int i=0;i<n;i++){
		e+= len[i];
		if(s< len[i]){
			s=len[i];
		}
	}
	int ans;
	while(s<=e){
		int m=s+(e-s)/2;
		int x=NoOfPaintersRequire(n,len,m);
		if(x<=k){
			ans=m;
			e=m-1;
		}
		else{
			s=m+1;
		}
	}
	return ans;
}
int main(){
	int K;
	cin>>K;
	int N;
	cin>>N;
	int* len=new int[N];
	for(int i=0;i<N;i++){
		cin>>len[i];
	}
	cout<<MinTime(K,N,len);
	return 0;
}