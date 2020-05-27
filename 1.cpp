#include<bits/stdc++.h>

#define ll long long
#define parent(i) i/2;
#define left(i) 2*i+1;
#define right(i) 2*i+2;
using namespace std;

#include"heap.h"


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   	vector<int> x;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int y; cin>>y;
        x.push_back(y);
    }
    //build_max_heap(x);
    heap_sort(x,n);
    print_heap(x);
    return 0;
}