#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

	int rows , cols;
	scanf("%d %d",&rows,&cols);
	int a[rows][cols];
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int max[rows][cols];
	max[0][0]=a[0][0];
	for(int i=0 ; i<rows ; i++){
		for(int j=0 ; j<cols ; j++){
			cout<<"for block "<<i<<" "<<j<<endl;
			int left = -1 , top = -1 ;
			if(i>0)
				top = max[i-1][j];
			if(j>0)
				left = max[i][j-1];
			int mx;
			if(top > left)
				mx=top;
			else
				mx=left;
			if(i!=0 || j!=0)
				max[i][j] = a[i][j] + mx;
			cout<<"max[i][j]="<<max[i][j];
		}
	}
	cout<<"max number of apples are==>"<<max[rows-1][cols-1]<<endl;
	return 0;
}
