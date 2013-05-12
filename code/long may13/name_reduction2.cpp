#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

int main(){

	int tc;
	scanf("%d",&tc);
	for(int i=0 ; i<tc;i++){
		char a[41000] , b[41000];
		scanf("%s %s",a,b);
		int n;
		scanf("%d",&n);
		char y[110000], t[41000];
		for(int j=0 ; j<n ; j++){
			scanf("%s",t);
			if(j==0)
				strcpy(y,t);
			else
				strcat(y,t);
		}
	
		char x[110000];
		strcpy(x,a);
		strcat(x,b);
	
		int count[26]={0};
		for(unsigned int j=0 ; j < strlen(x) ; j++){
			count[(int)x[j]-97]++;
		}
		//for(int j=0;j<26;j++)
			//printf("count[%d]=%d  ",j,count[j]);
		
		int ans=1;
		
		for(unsigned int j=0 ; j<strlen(y) ; j++){
			
			if(count[(int)y[j]-97]==0){
				ans=0;
				break;
			}
			else{
				count[(int)y[j]-97]--;
				continue;
			}		
		}
		if(ans==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
