#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int withdraw=0;
	float balance=0.00,left=0.00;
	scanf("%d",&withdraw);
	scanf("%f",&balance);
	if(withdraw % 5 != 0 || withdraw > (balance - 0.50) || balance==0.0){
		left=balance;
	}
	else{
		left=balance-withdraw;
		left=left-0.5;
	}
	printf("%.2f\n",left);
	return 0;
}
	
