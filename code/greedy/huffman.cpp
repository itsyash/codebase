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

typedef struct nod{
    char ch;
    int freq;
    nod *left;
    nod *right;
}node;

typedef struct heap{
    int size;
    int capacity;
    node **array;
}minheap;

minheap *heap;

void print(){
    cout<<endl;
    for(int i=1;i<=heap->size;i++)
        cout<< heap->array[i]->ch << " " << heap->array[i]->freq <<endl;
    cout<<endl;
}

void swap(node **a,int i,int j){
    node *temp = a[i];
    a[i]=a[j];
    a[j]=temp;
   // cout<<"\nswapped "<<a[i]->freq << "  and "<<a[j]->freq<<endl;
}

int parent(int i){
    return i/2;
}

void minHeapify(node **a,int i,int n){


    int l = 2*i;
    int r = 2*i + 1;

    int largest = i;

    if(l<=n && a[l]->freq < a[largest]->freq) largest = l;
    if(r<=n && a[r]->freq < a[largest]->freq) largest = r;

    // printf("a[i=%d]=%d a[l=%d]=%d a[r=%d]=%d largest=%d\n",i,a[i],l,a[l],r,a[r],largest);

    if(largest!=i){
        // cout<<"changed\n";
        node *temp = a[i];
        a[i]=a[largest];
        a[largest]=temp;
        //a[i] = (a[largest]=a[i])-a[i]+a[largest];   
        //REP(i,n+1)
        //  cout<<a[i]<<" ";
        // cout<<endl;
        minHeapify(a,largest,n);
    }
}

void buildminHeap(node** a,int n){

    for(int i = n/2 ; i > 0 ; i--){
        minHeapify(a,i,n);
    }
}

int returnmin(int a[]){
    return a[1];
}

node* extractMin(minheap *heap){
    node *min = heap->array[1];
    heap->array[1]=heap->array[heap->size];
    buildminHeap(heap->array,heap->size-1);
    heap->size--;
    return min;
}


void increaseKey(minheap *heap,node *top,int i){
   // cout<<"\nincreasekey\n"; 
    heap->array[i]=top;
    //print();
    while(i>=1 && heap->array[parent(i)]->freq > heap->array[i]->freq){
     //   cout<<"in whle\n";
        swap(heap->array,i,parent(i));
        i=parent(i);
    }
}

void insert(minheap *heap,node *top){
   // cout<<"\nsize= "<<heap->size<<endl;
    // heap->array[heap->size+1]->freq = top->freq;
    increaseKey(heap,top,heap->size+1);
    heap->size++;
}

int isSizeOne(minheap *heap){
    return (heap->size<=1);
}

void HuffmanCodes(char c[],int f[],int n){

    //heap array initialized
    heap = ( minheap *)malloc(sizeof(minheap));
    heap->capacity = n;
    heap->size=n;
    heap->array = (node **)malloc(sizeof(node*) * heap->capacity+1);

    heap->array[0] = (node *)malloc(sizeof(node));
    //heap array filled
    for(int i=1;i<=n;i++){
        heap->array[i] = (node *)malloc(sizeof(node));
        heap->array[i]->ch = c[i-1];
        heap->array[i]->freq = f[i-1];
        heap->array[i]->left=NULL;
        heap->array[i]->right=NULL;
    }
  //  print();
    //build heap
    buildminHeap(heap->array,heap->size);

   // print(); 
    //build tree
    node *left , *right, *top;

    while (!isSizeOne(heap))
    {
        // Step 2: Extract the two minimum freq items from min heap
        left = extractMin(heap);
        right = extractMin(heap);

       // cout<< left->ch <<" "<< left->freq<<endl;
       // cout<< right->ch <<" "<< right->freq<<endl;

     //   print();
        top = (node *)malloc(sizeof(node));
        top->ch = '$';
        top->freq = left->freq + right->freq;
        top->left = left;
        top->right = right;
        insert(heap, top);
       // print();
    }
}

void printCodes(node* root, int arr[], int top)
{
    // Assign 0 to left edge and recur
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    // Assign 1 to right edge and recur
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
    if (root->left==NULL && root->right==NULL)
    {
        printf("%c: ", root->ch);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main(){
    //int n=14;
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    print();
    int top=0;
    int Arr[100];
    printCodes(heap->array[1], Arr, top);
    return 0;
}
