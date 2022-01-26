/*Q =
       find the smallest element in array greater or equal to the target elememt  */
#include <iostream>
using namespace std;
char CeillingOfANumber(int n,char* A,int t){
    int s=0;
    int e=n-1;
    char ans;
    while(s<=e){
        int m=s+(e-s)/2;
        if(A[m]==t){
            return A[m];
        }
        else if(A[m]>t){
            ans=A[m];
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
   // cout<<s;
    return ans;
}
int main() {
    int n;
    cin>>n;
    char* A=new char[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    char t;
    cin>>t;
    cout<<CeillingOfANumber(n,A,t);
    return 0;
}
