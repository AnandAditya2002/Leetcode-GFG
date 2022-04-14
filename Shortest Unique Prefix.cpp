#include <iostream>
#include<vector>
using namespace std;
class node{
    public : 
    int freq;
    node* child[26];
    node(){
        freq = 0;
        for(int i=0;i<26;i++){
        child[i] = NULL;
        }
    }
};
void buildTrie(string str,node* root){
    node* temp = root;
    for(int i=0;i<str.length();i++){
        int indx = str[i]-'a';
        if(temp->child[indx] == NULL){
            temp->child[indx]= new node();
        }
        temp->child[indx]->freq ++;
        temp = temp->child[indx];
    }
}
string buildPrefix(string str, node* root){
    node* temp = root;
    string ans ="";
    for(int i=0;i<str.length();i++){
        int indx = str[i] - 'a';
        if(temp->freq == 1){
            break;
        }
        ans += str[i];
        temp = temp->child[indx];
    }
    return ans;
}
vector<string> prefix(vector<string>&A , int n){
    node* root = new node();
    vector<string>ansVector;
    for(int i=0;i<n;i++){
        buildTrie(A[i], root);
    }
    for(int i=0;i<n;i++){
        ansVector.push_back(buildPrefix(A[i],root));
    }
    return ansVector;
}
int main() {
    int n;
    cin>>n;
    vector<string>A;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        A.push_back(str);
    }    
    vector<string>s = prefix(A,n);
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
}
