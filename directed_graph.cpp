// Basics of Directed Graphs
#include <bits/stdc++.h>
#include <algorithm>
#define int long long
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define mod 1000000007
#define F first
#define S second
#define printer(v) for(auto f: v) cout<<f<<" "
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define ipair pair<int,int>
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

class Graph{ 
    void topological_sort_node(int v, stack<int> &s,vector<bool> &vis); 
    public: 
        int V;
        vector<vector<int>> gr;
        Graph(int n){
            V=n;
            gr = vector<vector<int>> (n, vector<int>());
        }
        void addEdge(int v, int w);
        void shortest_path(int a,int b); 
        void topological_Sort();
        bool is_cyclic_node(int v,vector<bool> &vis,vector<bool> &ris);
        bool is_cyclic();
        void bfs(int s);
        void dfs_visit(int s,vector<bool> &vis);
        void dfs(int s);
};
void Graph::addEdge(int v, int w){
    gr[v].push_back(w);
}
void initialize(int V,vector<bool> &vis){
    for(int i = 0;i < V;++i) vis[i] = false;
}
void Graph::bfs(int s){
    vector<int> level(1000);
    vector<bool> vis(V);
    initialize(V,vis);
    queue <int> q;
    q.push(s);
    level[s] = 0;
    vis[s] = true;
    while(!q.empty()){
        int p = q.front();
        cout<<p<<" ";
        q.pop();
        for(int i = 0;i < gr[p].size();i++){
                if(vis[gr[p][i]] == false){
                    level[gr[p][i]] = level[p]+1;                 
                    q.push(gr[p][i]);
                    vis[gr[p][i]] = true;
      			}
        }
    }
}
void Graph::dfs_visit(int s,vector<bool> &vis){
    vis[s] = true;
    cout<<s<<" ";
    for(int i = 0;i < gr[s].size();++i){
        if(vis[gr[s][i]] == false)
            dfs_visit(gr[s][i],vis);
    }
}
void Graph::dfs(int s){
    vector<bool> vis(V);
    initialize(V,vis);
    for (int i = 0; i < V; i++) vis[i] = false; 
    dfs_visit(s, vis);
}
void Graph::shortest_path(int s,int b){
	vector<int> level(1000);
    vector<bool> vis(V);
    initialize(V,vis);
    queue <int> q;
    q.push(s);
    level[s] = 0;
    vis[s] = true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i = 0;i < gr[p].size();i++){
                if(vis[gr[p][i]] == false){
                    level[gr[p][i]] = level[p]+1;                 
                    q.push(gr[p][i]);
                    vis[gr[p][i]] = true;
                }
        }
    }
    cout<<level[b]<<endl; 
}
bool Graph::is_cyclic_node(int v,vector<bool> &vis,vector<bool> &ris){ 
    vis[v] = true;
    ris[v] = true;   
    // Recur for all the vertices adjacent to this vertex 
    for (int i = 0; i < gr[v].size(); ++i){ 
        // If an adjacent is not visited, then recur for that adjacent 
        if (!vis[gr[v][i]]){ 
           	if (is_cyclic_node(gr[v][i],vis,ris)) return true; 
        } 
        // If an adjacent is visited and not parent of current vertex, 
        // then there is a cycle. 
        else if (ris[gr[v][i]]) 
           return true; 
    } 
    ris[v]=false;
    return false; 
}
bool Graph::is_cyclic(){
    vector<bool> vis(V);
    vector<bool> ris(V);
	initialize(V,vis);
    initialize(V,ris);
	for (int u = 0; u < V; u++) 
        if (!vis[u]) // Don't recur for u if it is already visited 
          if (is_cyclic_node(u,vis,ris)) 
             return true; 
    return false;
}
void Graph::topological_sort_node(int v, stack<int> &s,vector<bool> &vis){  
    vis[v] = true; 
    for (int i = 0; i < gr[v].size(); ++i) 
        if (!vis[gr[v][i]]) 
            topological_sort_node(gr[v][i],s,vis); 
    // Push current vertex to stack which stores result 
    s.push(v); 
} 
void Graph::topological_Sort(){ 
    stack<int> s;   
    // Mark all the vertices as not visited
    vector<bool> vis(V); 
    initialize(V,vis);
    // Call the recursive helper function to store Topological sort starting from all vertices one by one 
    for (int i = 0; i < V; i++) 
      	if (vis[i] == false)  topological_sort_node(i,s,vis); 
  	// Print contents of stack
    while (s.empty() == false){ 
        cout << s.top() << " "; 
        s.pop(); 
    } 
} 
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; //number of nodes
    cin>>n;
    int m;
    cin>>m; // number of edges
    Graph gr(n);
    for(int i=0;i<m;i++){
    	int x,y;
    	cin>>x>>y;
    	gr.addEdge(x,y);
    }
    gr.shortest_path(2,4);
    //gr.bfs(2);
    //gr.topological_Sort();
    //gr.dfs(1);//dfs
    // int connected_Components=0;         // for connected components
    // for(int i = 1;i <= n;++i){
    //     if(vis[i] == false){
    //         gr.dfs(i);
    //         connected_Components++;
    //     }
    // }
    //cout<<gr.is_cyclic()<<endl;
    return 0;
}