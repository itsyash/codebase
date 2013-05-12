#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main(){
	
	int n;
	scanf("%d",&n);
	long long int b[n];
	for(int i=0;i<n;i++)
		scanf("%lld",&b[i]);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int l,r;
		//cout<<"query number: "<<i<<endl;
		scanf("%d %d",&l,&r);
		//printf("l=%d r=%d\n",l,r);
		long long int mt=99999;//minimum time b/w l & r
		int mtindex=-1;
		for(int j=l;j<=r;j++){
			if(b[j] < mt){
				mt=b[j];
				mtindex=j;
			}
		}
		//printf("mt=%lld mmtindex=%d\n",mt,mtindex);
		
		//printf("calculating maximum\n");
		double maxtime=-1.0;
		for(int j=0;j<n;j++){
			//printf("for j=%d",j);
			if(j<l || j>r){
				//printf("outside lr with b[j]=%lld\n",b[j]);
				double time=mt+b[j];
				//printf("time is %lf\n",time);
				if(time > maxtime){
					//printf("greater than maximum\n");
					maxtime=time;
				}
			}
			else if(j>=l && j<=r){
				//printf("inside lr\n");
				double time;
				if(j==mtindex)
					time = mt;
				else
					time = mt + (double)(b[j]-mt)/2;
				//printf("time is %lf\n",time);
				if(time > maxtime){
					//printf("greater than maximum\n");
					maxtime = time;
				}
			}
		}
		printf("%.1f\n",maxtime);
	}
	
	return 0;
}
