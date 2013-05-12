#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	
	int sum;
	scanf("%d",&sum);
	int min[sum+1];
	for(int i=0;i<sum+1;i++)
		min[i] = 9999;
	min[0]=0;
	
	int num_coins;
	scanf("%d",&num_coins);
	int coins[num_coins];
	for(int i=0;i<num_coins;i++)
		scanf("%d",&coins[i]);
	
	for(int i=1 ; i < sum+1 ; i++){
		cout<<"for sum "<<i<<endl;
		for(int j=0 ; j < num_coins ; j++){
			cout<<"coin -> "<<coins[j]<<endl;
			if( i - coins[j] >=0 && min[i] > min[i-coins[j]] + 1 ){
				cout<<"yea..replace minimum"<<endl;
				min[i] = min[i-coins[j]] + 1;
				cout<<"min["<<i<<"]=="<<min[i]<<endl;
			}
		}
	} 
	printf("min number of coins is %d\n",min[sum]);	
	return 0;
}
