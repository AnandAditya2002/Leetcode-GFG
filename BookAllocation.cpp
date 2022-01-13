#include<iostream>
using namespace std;
int NoOfStudentsReadPages(int n,int* size,int limit){
	int NoOfStudents=1;
	int pages=0;
    for(int i=0;i<n;i++){
		pages+=size[i];
		if(pages > limit){
			NoOfStudents++;
			pages=0;
			pages+=size[i];
		}		
	}
	return NoOfStudents;   /*return no of students who can read pages such that max pages
                              read by the students is m*/
}
int MinDistribution(int st,int n,int* size){
	int s=0;
	int e=0;
	for(int i=0;i<n;i++){
		e+=size[i];
	}
	int ans;
	while(s<=e){
		int m= s+(e-s)/2;   //can m be the min no of pages that a student read
		int x= NoOfStudentsReadPages(n,size,m);  /*x be the number of students who can read book
                                                   such that max pages assigned to a student is 
                                                   minimum */
		if(x<=st){
			ans=m;        /*if m be that min no of pages then it may be our answer but we have
                             look for the min no of pages so search space become [s,m-1]  */
			e=m-1;
		}
		else{
			s=m+1;         /* if m is not that min pages that a student read so search space 
                               become [m+,e]*/
		}
	}
	return ans;
}
int main() {
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
	int n;
	cin>>n;
	int m;
	cin>>m;
	int* size=new int[n];
	for(int i=0;i<n;i++){
		cin>>size[i];
	}
	cout<<MinDistribution(m,n,size)<<endl;
	}
	return 0;
}