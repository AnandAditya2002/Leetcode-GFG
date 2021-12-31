#include <iostream>
using namespace std;
void f(int n,int open_bracket,int close_bracket,string str){
    if(open_bracket==n && close_bracket==n){
        cout<<str<<endl;
        return;
    }
    if(close_bracket<open_bracket){                  /*this close bracket 
	                                                   should be run till the it
													   become equal to the no of
													   open bracket*/
        f(n,open_bracket,close_bracket+1,str+")");
    }
     if(open_bracket<n){
        f(n,open_bracket+1,close_bracket,str+"(");
    }
}
int main() {
    int N;
    cin>>N;
    f(N,1,0,"(");       /*I pass this string "(" because ist i want to start
	                      making parenthesis with this string "("  */

    return 0;
}
