/* Problem: given a string x = x1...n , find the minimum
number of characters that need to be inserted to
make it a palindrome
*/


#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	
	char s[50];
	scanf("%s",s);
	int n;
	n=strlen(s);
	
	int d[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j || j<i)
				d[i][j]=0;
		}
	}
	
	cout<<"initially"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<d[i][j]<<"     ";
		}
		cout<<endl;
	}
	
	for(int t=1 ; t<n ; t++){
		
		for(int i=0, j=t ; j<n ; i++,j++){
			
			printf("for d[%d][%d]\n",i,j);
			
			if(s[i]==s[j]){
				cout<<"equal with d[i][j]= ";
				d[i][j] = d[i+1][j-1];
				cout<<d[i][j];
			}
			
			else{
				cout<<"not equal"<<endl;
				printf("checking d[%d][%d]=%d and d[%d][%d]=%d\n",i+1,j,d[i+1][j],i,j-1,d[i][j-1]);
				int min;
				if(d[i+1][j] >= d[i][j-1])
					min = d[i][j-1];
				else
					min = d[i+1][j];
				d[i][j] = 1 + min;
				printf("finally d[%d][%d] is %d\n",i,j,d[i][j]);
			}
		}
	}
	
	
	cout<<"after"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<" "<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
				
