#include<iostream>
using namespace std;
int newN = 0;
int sum = 1;
void f(int n){
if(n==0){
	cout<<newN;
	return ;
}
int digit=n%10;            /*I make decision for the unit place digit of given 
                                number tha wheather it is '0 or not '*/
                                       
if(digit==0){                   /*if the unit place digit is found to be 0
                                then i replace it with 5 and start forming
								a new number as variabe(newN)*/
	digit=5;
	newN = newN + digit*sum;
	sum*=10;
}
else{                              /*if it is not 0 then i don't replace it
                                     and again store this digit in partially 
									 form number(newN)*/
	newN += digit*sum;
	sum*=10;
}
 f(n/10);                       /*the I call my friend to make decision in the 
                                    remaining part of inputed number(n)*/
}
int main () {
	int N;
	cin>>N;
	f(N);
	return 0;
}