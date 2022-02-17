#include<iostream>
#include<queue>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};
node* insert(node* root,int d){
	if(root==NULL){
		root=new node(d);
		return root;
	}
	if(d < root->data){
		root->left = insert(root->left, d);
	}
	else{
		root->right = insert(root->right,d);
	}
	return root;
}
node* build(int n){
	node* root = NULL;
	for(int i=0;i<n;i++){
		int d;
		cin>>d;
		root=insert(root,d);
	}
	return root;
}
void print(node* root){
	//base case
	if(root->left ==NULL && root->right == NULL){
		cout<<"END"<<" => "<<root->data<<" <= "<<"END"<<endl;
		return;
	}
	//recursive case
	if(root->left != NULL && root->right== NULL){
		cout<< root->left->data <<" => "<<root->data<<" <= "<<"END"<<endl;
		print(root->left);
	}
	else if(root->right!= NULL && root->left==NULL){
		cout<<"END"<<" => "<<root->data<<" <= "<<root->right->data<<endl;
		print(root->right);
	}
	else{
		cout<<root->left->data <<" => "<<root->data<<" <= "<<root->right->data<<endl;
		print(root->left);
		print(root->right);
	}
}
int sum=0;                         /*here First I'll reach the right most element
                                     of tree and put the element in the sum varaible 
									 and then replace that element with the 
									        sum -(that elelment)*/
void replaceSum(node*& root){
	//bzse case
	if(root== NULL){
		return;
	}
	//recursive case
	replaceSum(root->right);
	sum+=root->data;
	root->data= sum - root->data;
	replaceSum(root->left);
}
int main() {
	int N;
	cin>>N;
	node* root = build(N);
	replaceSum(root);
	print(root);
	return 0;
}