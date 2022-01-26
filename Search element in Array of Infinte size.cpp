/* Q=
    find the indx of target element in the array of infinite size(or array of unknown size)*/

#include <iostream>
#include<cmath>
using namespace std;
int ApplyBinarySearch(int s,int e,int t,int* A){
    int start=s;
    int end=e;
    while(start<=end){
        int m=start+(end-start)/2;
        if(A[m]==t){
            return m;
        }
        else if(A[m]>t){
            end=m-1;
        }
        else{
            start=m+1;
        }
    }
    return -1;
}
int SearchElement(int* A,int t){
    int s=0;
    int n=1;
    int e=0;
    while(s<=e){
        if(A[s]<=t && A[e]>=t){
            int x= ApplyBinarySearch(s,e,t,A);
            return x;
        }
        else{
            s=e+1;
            e=e + (pow(2,n)-1);
            n++;
        }
    }
    return -1;
}
int main(){
    int A[]={2,3,5,6,7,8,10,11,12,13,15,20,23,30};
    int t=5;
    cout<<SearchElement(A,t);
    return 0;
}
