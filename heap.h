int heap_size(vector<int> x){
    int n=x.size();
    return(n);
}
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void max_heapify(vector<int> &x, int n, int i){
    int l=left(i);
    int r=right(i);
    int largest=i;
    if(l<n && x[l]>x[i]) largest=l;
    if(r<n && x[r]>x[largest]) largest=r;
    if(largest!=i){
        swap(&x[i],&x[largest]);
        max_heapify(x,n,largest);
    }
}
void insert(vector<int> &x, int key){
  int n=x.size();
  if (n==0) x.push_back(key);
  else{
    x.push_back(key);
    for(int i=n/2-1;i>=0;i--){
      max_heapify(x,n,i);
    }
  }
}
void deleteNode(vector<int> &x, int num){
  int n=x.size(); int i;
  for (int i=0;i<n;i++){
    if (num==x[i]) break;
  }
  swap(&x[i],&x[n-1]);
  x.pop_back();
  for (int i=n/2-1;i>=0;i--){
    max_heapify(x,n,i);
  }
}
void build_max_heap(vector<int> &x){
    int n=x.size();
    for(int i=n/2-1;i>=0;i--){
        max_heapify(x,n,i);
    }
}
void print_heap(vector<int> &x){
    for(int i=0;i<x.size();i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
int max(vector<int> &x){
    int n=x.size();
    for(int i=n/2-1;i>=0;i--){
        max_heapify(x,n,i);
    }
    return(x[0]);
}
int extract_max(vector<int> &x){
    int n=x.size();
    for(int i=n/2-1;i>=0;i--){
        max_heapify(x,n,i);
    }
    int t=x[0];
    deleteNode(x,t);
    return(t);
}
void increase_key(vector<int> &x, int i, int k){
    x[i]=k;
}
void heap_sort(vector<int> &x, int n){
    for(int i=n/2-1;i>=0;i--){
        max_heapify(x,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(&x[0],&x[i]);
        max_heapify(x,i,0);
    }
}