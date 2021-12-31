#include<iostream>
using namespace std;
int count=0;
void f(int n,int* out,int r,int j){
	if(r==n){
		for(int i=0;i<n;i++){
			cout<<"{"<<i+1<<"-"<<out[i]+1<<"}"<<" ";
		}
        cout<<" ";
		count++;
		return;
	}
	for(int j=0;j<n;j++){
		bool canplace=true;
		for(int i=0;i<r;i++){
			if(out[i]==j || out[i]==j-(r-i) || out[i]==j+(r-i)){
				canplace=false;
				break;
			}
		}
		if(canplace){
			out[r]=j;
            f(n,out,r+1,j+1);
		}
	}
}
int main() {
	int N;
	cin>>N;
	//int out= new int[N];
	int out[1000];
	f(N,out,0,0);
	cout<<endl<<count;
	return 0;
}