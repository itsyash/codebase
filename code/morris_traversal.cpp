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
int gcd(int a,int b){
	    if(b>a) return gcd(b,a);
	        return b==0?a:gcd(b,a%b);
}

struct node{
    int data;
    node* left;
    node* right;
};

node* newnode(int data){
    node* temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(node *tree){
    if(tree==NULL)return;
    inorder(tree->left);
    cout<<tree->data<<" ";
    inorder(tree->right);
    return;
}

void morris(node *root){
    node *current=root, *pre;

    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->data<<" ";
            current = current->right;
        }
        else{
            pre = current->left;
            while(pre->right!=NULL && pre->right!=current)
                pre = pre->right;
            
            if(pre->right==NULL){
                pre->right=current;
                current = current->left;
            }
            else{
                pre->right=NULL;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }
}
            

int main(){
	
    node *root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(4);
    root->left->right = newnode(5); 

    inorder(root);
    cout<<endl;
    morris(root);
    cout<<endl;
    
    return 0;
}
