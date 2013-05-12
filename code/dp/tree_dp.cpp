/*
Problem: given a tree, color nodes black as many as
possible without coloring two adjacent nodes
* status: not complete
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void degree_by_dfs(int **a, int vertex, int deg, int *degree,int ignore[],int parent);
void print();

using namespace std;

int n , e;
int **a;
int *degree;
int main(){
	
	
	scanf("%d",&n);
	scanf("%d",&e);
	
	

	a=(int **)malloc( sizeof(int *) * (n+1) );
	for(int i=0 ;i < n+1;i++)
		a[i]=(int *)malloc(sizeof(int) * (n+1) );
		
	degree=(int *)malloc( sizeof(int) * (n+1) );
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			a[i][j]=0;
		}
	}
	
	for(int i=0;i<e;i++){
		int m,n;
		scanf("%d %d",&m,&n);
		a[m][n]=1;
		a[n][m]=1;
	}
	
	
	for(int j=1;j<n+1;j++){
		degree[j]=0;
	}
	
	print();
	
	int ignore[n+1];
	for(int i=0;i<n+1;i++)
		ignore[i]=0;
	
	degree_by_dfs(a,1,1,degree,ignore,0);
	
	print();
	
	return 0;
}
				
void degree_by_dfs(int **a, int vertex, int deg, int *degree,int ignore[],int parent){
	
	ignore[vertex]=1;
	cout<<"for vertex "<<vertex<<endl;
	for(int i=1;i<n+1;i++){
		if(a[vertex][i]==1 && ignore[i]==0 && a[parent][i]==0){
			degree[i]=deg;
			degree_by_dfs(a,i,deg+1,degree,ignore,vertex);
		}
	}
	return ;
}

void print(){
	cout<<"a array\n";
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}	
	cout<<"degree array\n";
	for(int i=1;i<n+1;i++){
		cout<<degree[i]<<" ";
	}		
	cout<<endl;		
}			
				
				
	
	
	
	
	
	
		 

