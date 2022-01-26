#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void f(queue<int>&q,int k,int n){
	stack<int>s;
	for(int i=0;i<k;i++){
		s.push(q.front());
		q.pop();
	}
	for(int i=0;i<k;i++){
		q.push(s.top());
		s.pop();
	}
	for(int i=0;i<n-k;i++){
		int temp=q.front();
		q.pop();
		q.push(temp);
	}
}
void print(queue<int>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
}
int main () {
	int T;
	cin>>T;
	int N,K,data;
    int A[100];
	for(int i=1;i<=T;i++){
		cin>>N>>K;
		queue<int>q;
		for(int j=0;j<N;j++){
			cin>>data;
			q.push(data);
		}
		f(q,K,N);
		print(q);
		cout<<endl;

	}

	return 0;
}