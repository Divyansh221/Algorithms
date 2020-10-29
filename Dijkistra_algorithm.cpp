/*
Dijkistra algorithm
It is for finding shortest paths from source vertex to all other vertexes.
Time Complexity : T(n) = 2(n-1)^2 or O(n^2).
length[i] = length of the current shortest path from V1 (source) to Vi using only
vertices in set Y of current MST vertices as intermediate vertices.
touch[i] = index of vertex V in Y such that the edge <V, Vi> is the last edge on the
current shortest path from V1 (source) to Vi using only Y vertices as intermediate 
vertices.
*/
#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

void prim(int n, int **W, int **arr){
	int i, vnear, min;
	int touch[n], length[n];
	bool completed[n];
	for (int i = 1; i < n; ++i){
		touch[i] = 0;
		length[i] = W[0][i];
		completed[i] = false;
	}
	length[0] = 0;
	int count = 0;
	while(count != n-1){
		min = INF;
		for (int i = 1; i < n; ++i){
			if(length[i] >= 0 && length[i] < min && completed[i] == false){
				min = length[i];
				vnear = i;
			}
		}
		arr[vnear][touch[vnear]] = 1;
		arr[touch[vnear]][vnear] = 1;
		completed[vnear] = true;
		for (int i = 1; i < n; ++i){
			if(W[vnear][i] +  length[vnear] < length[i] && completed[i] == false){
				length[i] = W[vnear][i] +  length[vnear];
				touch[i] = vnear;
			}
		}
		count++;
	}
	cout<<"The minimum distances of vertexes from source are:"<<endl;
	for (int i = 0; i < n; ++i){
		cout<<i+1<<"  "<<length[i]<<endl;
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