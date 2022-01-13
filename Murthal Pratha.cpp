#include<iostream>
#include<climits>
using namespace std;
int NoOfPrathaCookByACook(int r,int timelimit){
	int partha=0;
	int time=0;
	int n=1;
	while(true){
		time+= n*r;
		if(time > timelimit){
			break;
		}
		n++;
		partha++;
	}
	return partha;
}
int NoOfPratha(int l,int* pos,int timelimit){
	int TotalPratha=0;
	for(int i=0;i<l;i++){
		TotalPratha+= NoOfPrathaCookByACook(pos[i],timelimit);
	}
	return TotalPratha;
}
int MinTime(int p,int l,int* pos){
	int s=0;
	int e=INT_MAX;
	int ans;
	while(s<=e){
		int m= s+(e-s)/2;
		int x= NoOfPratha(l,pos,m);
		if(x>=p){
			ans= m;
			e=m-1;
		}
		else{
			s=m+1;
		}
	}
	return ans;
}
int main() {
	int P;
	cin>>P;
	int L;
	cin>>L;
	int* pos=new int[L];
	for(int i=0;i<L;i++){
		cin>>pos[i];
	}
	cout<<MinTime(P,L,pos);
	return 0;
}