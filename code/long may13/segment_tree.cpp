#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

void initialize(long int node, long int b, long int e, long int M[], double A[], long int N)
{
	if (b == e)
		M[node] = b;
	else
	{
		int mid=(b+e)/2;
		initialize(2 * node, b,mid, M, A, N);
		initialize(2 * node + 1, mid + 1, e, M, A, N);
		if (A[M[2 * node]] <= A[M[2 * node + 1]])
			M[node] = M[2 * node];
		else
			M[node] = M[2 * node + 1]; 
	}
} 
void initializemax(long int node, long int b, long int e, long int M[], double A[], long int N)
{
	if (b == e)
		M[node] = b;
	else
	{
		int mid=(b+e)/2;
		initializemax(2 * node, b,mid, M, A, N);
		initializemax(2 * node + 1, mid + 1, e, M, A, N);
		if (A[M[2 * node]]>= A[M[2 * node + 1]])
			M[node] = M[2 * node];
		else
			M[node] = M[2 * node + 1]; 
	}
} 

long int querymin(long int node, long int b, long int e, long int M[], double A[], long int i, long int j)
{
	int p1, p2;


	if (i > e || j < b)
		return -1;

	if (b >= i && e <= j)
	{
		return M[node];
	}
	int mid=(b+e)/2;
	p1 = querymin(2 * node, b,mid, M, A, i, j);
	p2 = querymin(2 * node + 1,mid + 1, e, M, A, i, j);
	if (p1 == -1)
	{
		return p2;
	}
	if (p2 == -1)
	{
		return p1;
	}
	if (A[p1] <= A[p2])
	{
		return p1;
	}
	else
		return p2;

}
long int querymax(int node, long int b, long int e, long int M[], double A[], long int i, long int j)
{
	int p1, p2;
	if (i > e || j < b)
		return -1;

	if (b >= i && e <= j)
	{
		return M[node];
	}
	int mid=(b+e)/2;
	p1 = querymax(2 * node, b,mid, M, A, i, j);
	p2 = querymax(2 * node + 1,mid + 1, e, M, A, i, j);
	if(p1==-1)
		return p2;
	if(p2==-1)
		return p1;
	if (A[p1] >= A[p2])
	{
		return p1;
	}
	else
		return p2;
}

int main(){
	long int n;
	cin>>n;
	double a[n];
	for(long int i=0;i<n;i++)
		scanf("%lf",&a[i]);
		
	// Allocate memory for segment tree
    
    long int msize=4*n;
    long int m[msize];
    long int psize=4*n;
    long int p[psize];
    for(long int i=0;i<msize;i++)
	{
		m[i]=-1;
		p[i]=-1;
	}
	//~ cout<<"array\n";
	//~ for(long int i=0;i<n;i++)
		//~ cout<<a[i]<<"  ";
	//~ cout<<endl;
	
	initialize(1,0,n-1,m,a,n);
	initializemax(1,0,n-1,p,a,n);
	
	
	
	//cout<<"segmented array\n";
	//for(int i=0;i<msize;i++)
		//cout<<m[i]<<"  ";
	//cout<<endl;
	
	long int q;
	scanf("%ld",&q);
	for(int i=0;i<q;i++){
		long int l,r;
		//cout<<"query number: "<<i<<endl;
		scanf("%ld %ld",&l,&r);
		double min;
		double max1, max2 , max3;
		min=a[querymin(1,0,n-1,m,a,l,r)];
		max1=a[querymax(1,0,n-1,p,a,0,l-1)];
		max2=a[querymax(1,0,n-1,p,a,l,r)];
		max3=a[querymax(1,0,n-1,p,a,r+1,n-1)];
//		printf("min:%f max1:%f max2:%f max3:%f\n",min_val,max1,max2,max3);
		if(max1>=0)
		max1=min+max1;
		if(max2>=0)
		max2=min+(max2-min)/2.0;
		if(max3>=0)
		max3=min+max3;
		double tmp;
		tmp=max(max1,max2);
		tmp=max(tmp,max3);
		printf("%0.1lf\n",tmp);
	
	
	}
	
	return 0;
}

