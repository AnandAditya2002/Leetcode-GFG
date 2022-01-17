#include<iostream>
using namespace std;
int Search(int n,int* A,int t){
	int s=0;
	int e=n-1;
	while(s<=e){
		int m= s+(e-s)/2;
		 if(A[m]==t){
			return m;
		}
		 if(A[s]<A[m]){         /*this if statement checks wheather the left
		                          part is sorted or not */
			if(A[s]<= t && A[m]> t){    /*this make sure that our target lies 
			                              in the left part or not*/
                e=m-1;
            }
            else {
                s=m+1;
            }
		}
		else {
			if(A[m]<t && A[e]>=t){      /*this make sure that our target lies in
			                              the right part*/
                s=m+1;
            }
            else{
                e=m-1;
            }
		}
	}
	return -1;
}
int main() {
	int N;
	cin>>N;
	int* A=new int[N];
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	int t;
	cin>>t;
	cout<< Search(N,A,t);
	return 0;
}