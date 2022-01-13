/*Q =
       find the largest element in array that is less than or equal to the target elememt  */
#include <iostream>
using namespace std;
int FloorOfANumber(int n,int* A,int t){
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e){
        int m=s+(e-s)/2;
        if(A[m]==t){
            return A[m];
        }
        else if(A[m]>t){
            e=m-1;
        }
        else{
            ans =A[m];
            s=m+1;
        }
    }
   // cout<<s;
    return ans;
}
int main() {
    int n;
    cin>>n;
    int* A=new int[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int t;
    cin>>t;
    cout<<FloorOfANumber(n,A,t);
    return 0;
}
