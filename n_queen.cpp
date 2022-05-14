#include<bits/stdc++.h>
using namespace std;


bool safe(vector<vector<int>> &b,int i,int j){
    int n = b.size();
    for(int k = 0; k<i; k++){
        if(b[k][j]) return 0;
    }
    int a = i-1;
    int f = j+1;
    while(a>-1 && f<n){
        if(b[a][f]) return 0;
        a--;
        f++;
    }
    a = i-1;
    f = j-1;
    while(a>-1 && f>-1){
        if(b[a][f]) return 0;
        a--;
        f--;
    }
    return 1;
}

void print(vector<vector<int>> &b){
    int n = b.size();
    cout<<endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;     
    }
}

bool helper(vector<vector<int>> &b,int i){
    int n = b.size();
    if(i>=n) return 1;
    for(int k = 0; k<n; k++){
        if(safe(b,i,k)){
            b[i][k]=1;
            if(helper(b,i+1)){
                print(b);
            }
            b[i][k]=0;
        }
    }
    return 0;
}

 
void n_queen(){
    int n;
    cin>>n;
    vector<vector<int>> b(n,vector<int>(n,0));
    int a = helper(b,0);
    if(!a){
        cout<<"NO";
        return;
    }
    cout<<endl<<"final: ";
    print(b);
}

int main(){
    n_queen();
}
