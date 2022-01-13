#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
bool CanPlace(int n,int c,int* pos,int m){
	int NoOfCowsPlace=1;
	int prevCowPos=pos[0];
	for(int i=1;i<n;i++){
		if(pos[i]-prevCowPos >=m){
			prevCowPos= pos[i];
			NoOfCowsPlace++;
			if(NoOfCowsPlace==c){
				return true;
			}
		}
	}
	return false;
}
int GreatestMinDistance(int n,int c,int* pos){
	int s=INT_MAX;
	int e=pos[n-1]-pos[0];
	for(int i=1;i<n;i++){
		if(pos[i]-pos[i-1] < s){
			s=pos[i]-pos[i-1];
		}
	}
	int ans;
	while(s<=e){
		int m= s + (e-s)/2;
		if(CanPlace(n,c,pos,m)){
			ans=m;
			s=m+1;
		}
		else{
			e=m-1;
		}
	}
	return ans;
}
int main() {
	int N;
	cin>>N;
	int C;
	cin>>C;
	int* pos=new int[N];
	for(int i=0;i<N;i++){
		cin>>pos[i];
	}
	sort(pos,pos+N);
	cout<<GreatestMinDistance(N,C,pos);

	return 0;
}