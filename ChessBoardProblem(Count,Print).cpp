#include<iostream>
using namespace std;
int count=0;
void f(int n,char path[100][100],int i,int j){
	//base case
    if(i==n-1 && j==n-1){
        count++;
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                if(path[x][y]!='A'){
                    cout<<"{"<<x<<"-"<<y<<"}"<<path[x][y];
                }
            }
        }
        cout<<"{"<<i<<"-"<<j<<"}"<<" ";
        return;
    }
	//recursive case

    //to move like knight
	if(i+2<n && j+1<n){            //move 2 steps down and 1 step right
		path[i][j]='K';
		f(n,path,i+2,j+1);
        path[i][j]='A';           //backtracking
	}
    if(i+1<n && j+2<n){              //move 1 step down and 2 step right
		path[i][j]='K';
		f(n,path,i+1,j+2);
        path[i][j]='A';            //backtracking 
	}
	//to move like rook
    if(i==0 || j==0 || i==n-1 || j==n-1){           /*rook move only in border rows
	                                                 and columns.*/
        for(int k=1;k<n;k++){
            if(j+k<n){
                path[i][j]='R';
                f(n,path,i,j+k);
                path[i][j]='A';        //backtracking
            }
		}
		 for(int k=1;k<n;k++){
            if(i+k<n){
                path[i][j]='R';
                f(n,path,i+k,j);
                path[i][j]='A';         //backtracking
            }
		 }
        }

    //to move like bishop
    if(i==j || i+j==n-1){                 //bishop can move in two diagonal
        for(int k=1;k<n;k++){
            if(i+k<n && j+k<n){
                path[i][j]='B';
                f(n,path,i+k,j+k);
                path[i][j]='A';            //backtracking
            }
        }
    }
}
int main() {
    int N;     //size of chessboard
    cin>>N;
    char path[100][100];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            path[i][j]='A';
        }
    }
    f(N,path,0,0);
    cout<<endl<<count<<endl;
	return 0;
}