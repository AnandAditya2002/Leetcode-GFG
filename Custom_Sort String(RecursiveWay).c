#include<iostream>
#include<algorithm>
using namespace std;
int c = 0;
void f(string s1,string s2,int i){
    if(s1[i]=='\0'){
        sort(s2.begin() + c,s2.end());   /*sort the remaining string 2 using
		                                   sort function*/
        cout<<s2;
        return;
    }
    char ch=s1[i];                      /*I make changes in string 2 according
	                                     corresponding to the first
										  element of string 1 */
    for(int j=c;j<s2.length();j++){
        if(s2[j]==ch){
            swap(s2[j],s2[c]);
            c++;
        }
    }
    f(s1,s2,i+1);                       /*Then I call my friend to make changes in
	                                      string 2 corresponding to the rest of
										  element of string 1*/
}
int main () {
	string str1; 
	cin>>str1; 
	string str2;
	cin>>str2;
    f(str1,str2,0);
	return 0;
}