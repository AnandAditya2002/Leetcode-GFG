#include<iostream>
#include<algorithm>
using namespace std;
int main () {
	string str1; 
	cin>>str1; 
	string str2;
	cin>>str2;
    int i;
    int count=0;
	for( i=0;i<str1.length();i++){                 //for each element of string 1,I'll iterate over the element of string 2
		for(int j=count;j<str2.length();j++){
			if(str2[j]==str1[i]){
				swap(str2[j],str2[count]);
				count++;
			}
		}
	}
	sort(str2.begin()+count,str2.end());          //then sort the rest of element of string 2
	cout<<str2<<endl;
	return 0;
}