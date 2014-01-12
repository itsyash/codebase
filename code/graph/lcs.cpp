/* Author : Yashasvi girdhar
*/

/* Data Structure Includes */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>

/*other Includes */
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>

/* C Includes */
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef vector<int > vi;
typedef vector<long long int > vl;
typedef vector<bool > vb;
typedef vector<char > vc;
typedef vector<vi > vvi;

#define pb push_back
#define si(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",n)
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define all(a) a.begin(),a.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin() ; it != container.end() ; it++) //to traverse any container
#define present(container,element) (container.find(element)!=container.end()) //should be used for set,map etc.
#define vpresent(container,element) (find(all(container),element)!=container.end()) //should be used for vectors.
#define PI 3.14159265359
#define DegToRad(a) PI/180*a
#define RadToDeg(a) 180/PI*a
#define debug 1 

struct node{
	int data;
	node *left;
	node *right;
};

void swap(int *m,int *n){
    int temp = *n;
    *n = *m;
    *m = temp;
}

node* newnode(){
	//cout<<"new node\n";
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void insert(node **root,int n){
	//cout<<"inserting "<<n<<endl;
	if((*root)==NULL){//root
		(*root)=newnode();
		(*root)->data=n;
		return ;
	}
	if(n <= (*root)->data){
		//cout<<"to left of "<<(*root)->data<<endl;
		insert(&((*root)->left),n);
	}
	else{
		//cout<<"to right of "<<(*root)->data<<endl;
		insert(&((*root)->right),n);
	}
}

void printtree(node **root){ 
	if((*root)==NULL)
		return;
	printtree(&((*root)->left));
	//cout<<"printing "<< (*root)->data <<endl;
	cout<< (*root)->data <<" ";
	printtree(&((*root)->right));
}

int lcs(node **root, int m,int n){
    node *temp = *root;
    if(m==temp->data || n==temp->data)
        return temp->data;
    if(m<=temp->data && n>temp->data)
        return temp->data;
    if(m<=temp->data && n<=temp->data)
        return lcs(&(temp->left),m,n);
    if(m>temp->data && n>temp->data)
        return lcs(&(temp->right),m,n);

}



int main(){
	int t;
	si(t);
	
	node *root;
	//initialize(&bst);
	REP(i,t){
		int temp;
		si(temp);
		insert(&root,temp);
	}
		
    printtree(&root);
    cout<<endl;
    int tc;
    si(tc);
    REP(i,tc){
        int m,n;
        si(m);
        si(n);
        if(m>n){
            swap(&m,&n);
        }
        int ans;
        ans = lcs(&root,m,n);   
        cout<<ans<<endl;	
    }
    return 0;
}
