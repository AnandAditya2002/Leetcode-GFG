#include<iostream>
#include<queue>
using namespace std;
class node{
	public :
	   int data;
	   node* left;
	   node* right;
	   node(int data){
		   this->data= data;
		   this->left = this->right = NULL;
        }
};
node* build(){
	int data;
	cin>>data;
	node* root=new node(data);
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node* front= q.front();
		q.pop();
		int a,b;
		cin>>a>>b;
		if(a!=-1){
			node* l= new node(a);
			front->left=l;
			q.push(front->left);
		}
		if(b!=-1){
			node* r= new node(b);
			front->right=r;
			q.push(front->right);
		}
	}
	return root;
}
void levelOrder(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		node* front = q.front(); q.pop();
		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->data << " ";
			if(front->left) q.push(front->left);
			if(front->right)q.push(front->right);
		}
	}
}
void removeLeaf(node* root){
	//base case
	if(root== NULL){
		return;
	}
	//recursive case
	if(root->left == NULL && root->right == NULL){
		cout<<root->data<<" ";
	}
	removeLeaf(root->left);
	removeLeaf(root->right);
}
int main() {
	node* root=build();
	removeLeaf(root);
	return 0;
}