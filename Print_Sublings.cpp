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
node*createtree(string s){
	if(s=="true"){
		int data;
		cin>>data;
		node *n=new node(data);
		string le;
		cin>>le;
		n->left=createtree(le);
		string re;
		cin>>re;
		n->right=createtree(re);
		return n;
	}
	return  NULL;
}
void sibling(node*head1){
     if(head1==NULL)return;

     if(head1->left and head1->right){
         cout<<head1->left->data<<" "<<head1->right->data<<endl;
     }

     sibling(head1->left);
     sibling(head1->right);
}
int main() {	
    node*head=createtree("true");
    sibling(head);
	return 0;
}