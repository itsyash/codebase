#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main(){

	int tc;
	scanf("%d",&tc);
	for(int i=0 ; i<tc;i++){
		int ans=0;
		char m[25010] , w[25010];
		scanf("%s %s",m,w);
		
		if(strlen(m)==strlen(w)){
			//cout<<"length equal"<<endl;
			if(strcmp(m,w)==0){
				//cout<<"strings equal"<<endl;
				ans=1;
			}
			else{
				//cout<<"strings not equal, ans = 0"<<endl;
				ans=0;
			}
		}
		else{
			ans=0; 
			//cout<<"length not equal"<<endl;
			char *s1 , *s2;
			if(strlen(m) > strlen(w) ){
			//	cout<<"m is greater"<<endl;
				s1=strdup(m);
				s2=strdup(w);
			}
			else{
				//cout<<"w is greater"<<endl;
				s1=strdup(w);
				s2=strdup(m);
			}
		
			//now check if s2 is a subseq of s1
			
			if(strstr(s1,s2) != NULL){
				//cout<<"found directly"<<endl;
				ans=1;
				goto label;
			}
			else{
				//cout<<"not found directly"<<endl;
				if(strlen(s2)==1){
					//cout<<"length=1, ans=0"<<endl;
					ans=0;
					goto label;
				}
				else{
				//cout<<"length!=1, checking otherwise"<<endl;
				}
			}
	
			int index2=0;
			for(int index1=0 ; index1<strlen(s1) ; index1++){
				//cout<<"index 1 = "<<index1<<endl;
				if(s1[index1]==s2[index2]){
					//cout<<"found equal at "<<index1<<" "<<index2<<endl;
					index2++;
				}
				if(index2==strlen(s2)){
					//cout<<"completely found, ans=1"<<endl;
					ans=1;
					break;
				}
				if( (strlen(s2) - index2) > (strlen(s1) - index1) ){
					//cout<<"cannot be found now, ans=0"<<endl;
					ans=0;
					break;
				}
			}
		}
		//cout<<"done"<<endl;
label:
		if(ans==1)
			cout<<"YES"<<endl;
		else if(ans==0)
			cout<<"NO"<<endl;
		
	}
	return 0;
}
