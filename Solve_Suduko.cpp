#include<iostream>
#include<cmath>
using namespace std;
bool canplace(int puzzle[][9],int i,int j,int n,int d){
	for(int k=0;k<n;k++){
		if(puzzle[k][j]==d || puzzle[i][k]==d){
			return false;
		}
	}
	int rx= sqrt(n);
	int sx=(i/rx)*rx;
	int sy=(j/rx)*rx;
	for(int x=sx;x<sx+rx;x++){
		for(int y=sy;y<sy+rx;y++){
			if(puzzle[x][y]==d){
				return false;
			}
		}
	}
	return true;
}
void f(int puzzle[][9],int i,int j,int n){
	if(i==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<puzzle[i][j]<<" ";
			}
			cout<<endl;
		}
        return;
	}
	if(j==n){
		f(puzzle,i+1,0,n);
		return;
	}
	if(puzzle[i][j]!=0){
		f(puzzle,i,j+1,n);
		return;
	}
	for(int d=1;d<=9;d++){
		if(canplace(puzzle,i,j,n,d)){
			puzzle[i][j]=d;
			f(puzzle,i,j+1,n);
			puzzle[i][j]=0;
		}
	}
	
}
int main() {
	int N;
	cin>>N;
	int puzzle[9][9];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>puzzle[i][j];
		}
	}
	f(puzzle,0,0,N);
	return 0;
}