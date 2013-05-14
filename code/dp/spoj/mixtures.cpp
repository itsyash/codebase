#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define debug 1
using namespace std;

int main(){
	int n;
	int count=0;
	//cin>>tc;
	while(cin>>n){
		cout<<"for count="<<count<<endl;
		count++;
		//int n;
		//scanf("%d",&n);
		vector<int> v;
		v.resize(n);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		int d[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j==i)
					d[i][j]=v[i];
				else if(j<i)
					d[i][j]=-1;
				else if(j==i+1)
					d[i][j]=(v[i]+v[j])%100;
			}
		}
		
		int smoke[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
					if(i==j)
						smoke[i][j]=0;
					else if(j<i)
						smoke[i][j]=-1;
					else if(j==i+1){
						smoke[i][j]=v[i]*v[j];
					}
			}
		}
		if(debug){
			cout<<"initially"<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<d[i][j]<<"     ";
				}
				cout<<endl;
			}
			cout<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<smoke[i][j]<<"     ";
				}
				cout<<endl;
			}
		}
		
		for(int t=2 ; t<n ; t++){
		
			for(int i=0, j=t ; j<n ; i++,j++){
				
				smoke[i][j]=min(smoke[i+1][j]+d[i+1][j]*v[i], smoke[i][j-1]+d[i][j-1]*v[j]); 
				
				if(smoke[i][j]==smoke[i+1][j]+d[i+1][j]*v[i])
					d[i][j]=(d[i+1][j]+v[i])%100;
				else
					d[i][j]=(d[i][j-1]+v[j])%100;
				
				
					
			//	printf("smoke[%d][%d]=%d and d[%d][%d]=%d\n",i,j,smoke[i][j],i,j,d[i][j]);
					
			}
		}				
		
		cout<<"finally"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<d[i][j]<<"     ";
			}
			cout<<endl;
		}
		cout<<endl;	
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<smoke[i][j]<<"     ";
			}
			cout<<endl;
		}
		cout<<smoke[0][n-1]<<endl;
	}
	return 0;
}

