#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	int max[n];
	for(int i=0;i<n;i++)
		max[i]=1;
	
	for(int i=0;i<n;i++){
		cout<<"for number "<<i<<endl;
		for(int j=0;j<i;j++){
			cout<<"comparing for number "<<j<<endl;
			if(arr[j] <= arr[i] && max[i] < max[j]+1){
				cout<<"yea..replace maxmum"<<endl;
				max[i]=max[j]+1;
				cout<<"max["<<i<<"]=="<<max[i]<<endl;
			}
		}
	}
	
	cout<<"length of longest non-decreasing sequence is "<< max[n-1]<<endl;
	
	return 0;
}
