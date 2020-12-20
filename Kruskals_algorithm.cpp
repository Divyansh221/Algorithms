/* 
Kruskals Algorithm
It is for minimum sum spanning tree.
For minimum product spanning tree replace all the weights by log(weights) and
follow regular Kruskals algorithm which will try to minimize sum of log(weights) 
which in-turn minimizes weight product.
Time Complexity : T(n) = O(m * log(m)) ; m is the number of edges.
O(n * log(n));  for sparse graph or m = O(n).
O(n^2 * log(n));  for dense graph or m = O(n^2).
*/
#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

struct EDGE{
	int x;
	int y;
	int weight;
};
struct Node{ 
    int rank;
    Node *parent; 
};  
void makeset(int a, Node *C[]){ 
    Node *x = (Node *)malloc(sizeof(Node));  
    C[a] = x; 
    x->rank = 0;
    x->parent = x; 
} 
Node* findset(int key, Node *C[]){ 
    Node *ptr1 = C[key]; 
    Node *ptr2 = C[key];
    while(ptr1->parent != ptr1){
        ptr1 = ptr1->parent;
    } 
    while(ptr2->parent != ptr2){
        Node *temp = ptr2;
        temp->parent = ptr1;
        ptr2 = ptr2->parent;
    } 
    return(ptr1);
} 
void mergeset(Node *x, Node *y){ 
    if(x->rank < y->rank){
        x->parent = y;
    }
    else if(x->rank > y->rank){
        y->parent = x;
    }
    else{
        x->parent = y;
        y->rank = y->rank + 1;
    }
} 
void merge(EDGE *arr, int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    EDGE L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i].weight <= R[j].weight) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}
void mergeSort(EDGE *arr, int l, int r){ 
    if (l < r) {
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 
void kruskal(int n, int m, EDGE *edges, int **arr){
	int i, j;
	Node *p, *q;
	Node *C[n];
	for (int i = 0; i < n; ++i){
		makeset(i, C);
	}
	int count = 0, k = 0;
	while(count < n-1){
		int i = edges[k].x;
		int j = edges[k].y;
		p = findset(i, C); q = findset(j, C);
		if(p != q){
			mergeset(p, q);
			arr[i][j] = 1;
			arr[j][i] = 1;
			count++;
		} 
		k++;
	}
	cout<<"The MST edges are:"<<endl;
	for (int i = 0; i < n; ++i){
		for (int j = i+1; j < n; ++j){
			if(arr[i][j] == 1) cout<<i+1<<" "<<j+1<<endl;
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
	int **arr;
	arr = (int **)malloc(n*sizeof(int *));
	for (int i = 0; i < n; ++i){
		arr[i] = (int *)malloc(n*sizeof(int));
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			arr[i][j] = 0;
		}
	}
	EDGE *edges;
	edges = (EDGE *)malloc(m*sizeof(EDGE));
	for (int i = 0; i < m; ++i){
		int a, b, c;
		cin>>a>>b>>c;
		edges[i].x = a-1;
		edges[i].y = b-1;
		edges[i].weight = c;
	}
	mergeSort(edges, 0, m-1);
	kruskal(n, m, edges, arr);
    return 0;
}