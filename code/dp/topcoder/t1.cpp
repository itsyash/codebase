/*
ZigZag - 2003 TCCC Semifinals 3
*/


#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int maxDonations(vector<int> donations);



int main(){
	
	int n;
	scanf("%d",&n);
	vector<int> a;
	a.resize(n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	int ans=0;
	ans = maxDonations(a);
	cout<<"max total = "<<ans<<endl;
	return 0;
}

int maxDonations(vector<int> donations){
	int size;
	size = donations.size();
	int w[size] , v[size];
	w[0]=donations[0];
	v[0]=0;
	for(int i=1 ; i<size ;i++){
		w[i]=donations[i] + v[i-1];
		v[i]=max(w[i-1],v[i-1]);
	}
	for(int i=0;i<size;i++)
		printf("w[%d]=%d v[%d]=%d\n",i,w[i],i,v[i]);
	return max(w[size-1]-donations[0],v[size-1]);
	
}


		
