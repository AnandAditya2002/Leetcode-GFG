#include <bits/stdc++.h> 
#include<stack>
using namespace std; 

// Function to print Next Greater Element for each element of the array
void nextGreater(int arr[], int n) 
{ 
    stack<int>s;                  /*Here I'm using an stack to store the next greater
                                    of a given element untill then stack is not
                                    empty if while searching the next greater element 
                                    of a particular element once stack become empty
                                    its means the answer is -1 for that particular 
                                    element*/
    int ans[n];    //this array stores our answer
    for(int i=n-1;i>=0;i--){       
        if(s.empty()){
            ans[i]=-1;
            s.push(arr[i]);
        }
        else{
            while(!s.empty()){
                if(arr[i]<s.top()){
                    ans[i]=s.top();
                    s.push(arr[i]);
                    break;
                }
                else{
                    s.pop();
                }
            }
            if(s.empty()){
                ans[i]=-1;
                s.push(arr[i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<","<<ans[i]<<endl;
    }
} 

// The Main Function
int main() 
{ 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        nextGreater(arr, n); 
    }
	
	return 0; 
} 

