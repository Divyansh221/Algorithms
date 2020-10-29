/* 
Prims Algorithm
It is for minimum sum spanning tree.
For minimum product spanning tree replace all the weights by log(weights) and
follow regular prims algorithm which will try to minimize sum of log(weights) 
which in-turn minimizes weight product.
nearest[i] = index of vertex in Y (set of current MST vertices) nearest to Vi
distance[i] = weight of the edge between Vi and vertex indexed by nearest[i]. 
Time Complexity : T(n) = O(n^2);
*/
#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

void prim(int n, int **W, int **arr){
	int i, vnear, min;
	int nearest[n], distance[n];
	for (int i = 1; i < n; ++i){
		nearest[i] = 0;
		distance[i] = W[0][i];
	}
	int count = 0;
	while(count != n-1){
		min = INF;
		for (int i = 1; i < n; ++i){
			if(distance[i] >= 0 && distance[i] < min){
				min = distance[i];
				vnear = i;
			}
		}
		arr[vnear][nearest[vnear]] = 1;
		arr[nearest[vnear]][vnear] = 1;
		distance[vnear] = -1;
		for (int i = 1; i < n; ++i){
			if(W[i][vnear] < distance[i]){
				distance[i] = W[i][vnear];
				nearest[i] = vnear;
			}
		}
		count++;
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
	int **W, **arr;
	W = (int **)malloc(n*sizeof(int *));
	arr = (int **)malloc(n*sizeof(int *));
	for (int i = 0; i < n; ++i){
		W[i] = (int *)malloc(n*sizeof(int));
		arr[i] = (int *)malloc(n*sizeof(int));
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			arr[i][j] = 0;
			if(i == j) W[i][j] = 0;
			else W[i][j] = INF;
		}
	}
	for (int i = 0; i < m; ++i){
		int x, y, z;
		cin>>x>>y>>z;
		W[x-1][y-1] = z;
		W[y-1][x-1] = z;
	}
	prim(n, W, arr);
    return 0;
}