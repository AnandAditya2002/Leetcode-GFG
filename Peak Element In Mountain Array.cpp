#include <iostream>
#include<climits>
using namespace std;
int MountainIndx(int n,int* A){
    int s=0;
    int e=n-1;
    int ans=INT_MIN;
    while(s<=e){
        int m=s+(e-s)/2;
            if(A[m]>ans){
                ans=m;
            }
            if(A[m-1]<A[m]){
                s=m+1;
            }
            else{
                e=m-1;
            }
    }
    return ans;
}
int main() {
    
    int A[]={2,4,7,9,10,6,3,1};
    int n=8;
    cout<<MountainIndx(n,A);
    return 0;
}
