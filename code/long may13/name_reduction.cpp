#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

char y[100000];

void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n) 
{
//   printf("for a=%s, i=%d and n=%d\n",a,i,n);
	
   int j; 
   if (i == n){
	 //cout<<"i==j\n";
     printf("%s\n", a);
     if(strstr(a,y)!=NULL){
		 cout<<"yes,,a substring.."<<endl;
		 exit(1);
	 }
   }
   else
   {
       for (j = i; j <= n; j++)
       {
		 //cout<<"swapping "<<*(a+i)<<" and "<<*(a+j)<<endl;
          swap((a+i), (a+j));
          //cout<<"calling permute with "<<i+1<<" and "<<n<<endl;
          permute(a, i+1, n);
          //cout<<"returning from permute"<<", swapping again "<<*(a+i)<<" and "<<*(a+j)<<endl;
          swap((a+i), (a+j)); //backtrack
       }
   }
} 

int main(){

	int tc;
	scanf("%d",&tc);
	for(int i=0 ; i<tc;i++){
		char a[40000] , b[40000];
		scanf("%s %s",a,b);
		int n;
		scanf("%d",&n);
		char child[n][40000];
		for(int i=0 ; i<n ; i++)
			scanf("%s",child[i]);
		
		char x[100000];
		strcpy(x,a);
		strcat(x,b);
		cout<<x<<endl;
		
		
		strcpy(y,child[0]);
		for(int i=1;i<n;i++)
			strcat(y,child[i]);
		cout<<y<<endl;
		
		permute(x,0,strlen(x)-1);
		cout<<"not a substring\n";
	}
	
	return 0;
}


		
