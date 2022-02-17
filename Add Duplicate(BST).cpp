#include<iostream>
#include<queue>
#include<vector>
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
void addDuplicate(node* root){                   /*First male new node with the data
                                                  of root node and add that new node
												  to the left of root node then ask
												  your friend to make duplicate for
												  the left and right sub-tree*/
	//base case
	if(root== NULL){
		return;
	}
	//recursive case
	node* duplicate = new node(root->data);
	duplicate->left = root->left;
	root->left = duplicate;
	addDuplicate(root->left->left);           /*Here ask your friend to make duplicate
	                                            for the left sub-tree but also make 
												sure that note to make duplicate for
												the new node added by me....
												if you not do that then the code will 
												fall in an infinite loop*/
	addDuplicate(root->right);
}
int main() {
	int N;
	cin>>N;
	node* root = build(N);
	addDuplicate(root);
	print(root);
	return 0;
}