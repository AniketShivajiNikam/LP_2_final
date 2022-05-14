#include<bits/stdc++.h>
using namespace std;

bool helper(vector<vector<int>> &adj,vector<int> &color,int v, int c){
    for(auto i:adj[v]){
        if(color[i]==c){
            return 0;
        }
    }
    return 1;
}

bool graphColoring(vector<vector<int>> &adj, vector<int> &color, int v,int &m){
    int n = adj.size();
    if(v>=n) return 1;
    for(int i= 0; i<m; i++){
        if(!helper(adj,color,v,i)) continue;
        color[v] = i;
        if(graphColoring(adj,color,v+1,m)){
            return 1;
        }
        color[v] = -1;
    }
    return 0;
}

int main(){
    int n,m,e;
    cin>>n>>m>>e;
    vector<vector<int>> adj(n);
    for(int i = 0; i<e; i++){
        int a,b;
        cin>>a>>b; a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> color(n,-1);

    cout<<endl<<graphColoring(adj,color,0,m)<<endl;

    return 0;
}


/*
4
3
5
1 2 2 3 3 4 4 1 1 3
*/
