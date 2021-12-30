#include<iostream>
using namespace std;
int main() {
	string S;
	cin>>S;
	for(int i=0;i<S.length()-1;i++){
		cout<<S[i];
		
		int diff=S[i+1]-S[i];
        cout<< diff;
	 }
	cout<<S[S.length()-1];
	return 0;
}