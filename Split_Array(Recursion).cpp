#include<iostream>
using namespace std;
int count=0;
void f(int n,int* A,string s1,string s2,int i,int sum1,int sum2){
	//base case
	if(i==n){
        if(sum1==sum2){
            count++;
            cout<<s1.substr(1)<<" and "<<s2.substr(1)<<endl;;
        }
       // cout<<" "<<endl;
        return;

    }
    f(n,A,s1+" "+ to_string(A[i]),s2,i+1,sum1+A[i],sum2);
    f(n,A,s1,s2+" "+ to_string(A[i]),i+1,sum1,sum2+A[i]); 
}
int main() {
	int N;
	cin>>N;
	int A[100];
	for(int i=0;i<N;i++){
			cin>>A[i];
	}
	f(N,A,"","",0,0,0);
    cout<<count;
	return 0;
}