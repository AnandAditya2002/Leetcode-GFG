#include <bits/stdc++.h> 
#include<stack>
using namespace std; 

// Function to print Next Greater Element for each element of the array
void nextGreater(int* arr, int n){
	stack<int>s;
	int ans[n]={0};
	for(int i= 2*n -n/2 ;i>=0;i--){
		while(! s.empty() && arr[i%n] >= s.top()){
			s.pop();
		}
		if(i>=n){                           /*In both yhe conditions when i>=n and
		                                      i<n we've to push the element in the
											  stack. */
			s.push(arr[i%n]);            /*here no need to insert element in the 
			                               ans array*/
		}
		else{
			if(s.empty()){               /*here is need to insert element in the 
			                               ans array*/
				ans[i]=-1;
			}
			else{
				ans[i]=s.top();
			}
			s.push(arr[i]);
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	return;
}
    
// The Main Function
int main() 
{ 
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        nextGreater(arr, n);
	return 0; 
} 

