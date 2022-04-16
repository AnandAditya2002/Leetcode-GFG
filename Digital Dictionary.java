#include<iostream>
#include<map>                 /*Here we use ordered map as we want to store elements
                                in lexicographical order */
#include<vector>
using namespace std;
class node{
	public:
	char ch;
	bool terminal;
	map<char, node*>childMap;
	node(char ch){
		this->ch = ch;
		terminal = false;
	}
};
class trie{
	node* root;
	public :
	trie(){
		root = new node('\0');
	}
	void insert(string str) {
			node* temp = root;
			for(char ch : str) {
				if(temp->childMap.find(ch) == temp->childMap.end()) {
					node* n = new node(ch);
					temp->childMap[ch] = n;
				}
				temp = temp->childMap[ch];
 			}
 			temp->terminal = true;
	}
	void print(node * temp,string str){
        if(temp->terminal == true){
           cout<<str<<endl;
        }
        node * t;
        string w;
        for(pair<char, node*>it : temp->childMap){
            t = it.second;
            w=str+it.first;
            print(t,w);  
        }
        return ;
    }
	bool search(string str){           /*this funbction check weather the string with 
	                                     the given prefix exist or not 
										 if it exists then it will automatically call
										 the print function to print all the strings 
										 which contain the given prefix
										 However if it doesn't exits then it will 
										 simply return FALSE and print "No suggestions"*/
		node* temp = root;
		for(char ch : str){
			if(temp->childMap.find(ch) == temp->childMap.end()){
				return false;
			}
			else{
				temp = temp->childMap[ch];
			}
		}
		print(temp,str);
		return true;
	}
	


};
int main() {
	trie t;
	int n;
	cin>>n;
    string s;
	for(int i=0;i<n;i++){
		cin>>s;
		t.insert(s);
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>s;
		bool val = t.search(s);
		if(val == false){
			cout<<"No suggestions"<<endl; 
			t.insert(s);
		}
	}

	return 0;
}