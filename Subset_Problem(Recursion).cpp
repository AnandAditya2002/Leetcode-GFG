#include<iostream>
using namespace std;
int count=0;
void f(int* A,int n,int i,int t,int* out,int j){
	if(i==n){
		int sum=0;
		for(int k=0;k<j;k++){      /*when we reach there we have created an out(array)*/
			sum+=out[k];
		}
		if(sum==t){                /* check if sum of elements of out matches with
		                              target or not*/
			count++;
			for(int k=0;k<j;k++){
				cout<<out[k]<<" ";
			}
		};
		return;
	}
	out[j]=A[i];                /*first i select whether to include the ith indx
	                             element of array A to our out(array)*/

	f(A,n,i+1,t,out,j+1);
	f(A,n,i+1,t,out,j);         /*if i won't include the elememt
	                            ALSO NOTE that here we overwrite the 
							    jth indx element of out(array) when we return
								from the above called function*/

	
}
int main() {
	int N;
	cin>>N;
	int *A=new int[N];
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	int t;
	cin>>t;
	//int out[N];
	int out[N];
	f(A,N,0,t,out,0);
	cout<<endl<<count;

	return 0;
}