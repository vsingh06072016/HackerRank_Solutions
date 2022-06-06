#include <bits/stdc++.h>
using namespace std;
int G[1000][1000];
int visited[1000];
int dist[1000];
int n,m;
void BFS(int s){
    //cout<<s<<endl;
    int j;
    queue<int> q;   
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int temp;
        temp=q.front();
       // dist[temp]=prev;
        visited[temp]=1;
        q.pop();
    for(j=0;j<n;j++){
       
        if(G[temp][j]==1&&visited[j]==0){
            visited[j]==1;
            if(dist[j]==0)
             dist[j]=dist[temp]+6;
             //prev=dist[j];
             q.push(j);               
        }
        }
    }
         
    //cout<<v.size();
    // sort(v.begin(),v.end());
    // for(int i=0;i<v.size();i++)
    //     cout<<v[i].first<<" "<<v[i].second<<endl; 
    
    for(int i=0;i<n;i++){
        if(i==s)
            continue;
        if(dist[i]==0)
            cout<<"-1"<<" ";
        else
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return ;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T,i,j;
    
    //int n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        int a,b,s;
        for(i=0;i<1000;i++){
            visited[i]=0;
            dist[i]=0;
        }
        for(i=0;i<n;i++)
            {
            for(j=0;j<n;j++){
                G[i][j]=0;
            }
        }
 
        while(m--){
            cin>>a>>b;
            G[a-1][b-1]=1;
           G[b-1][a-1]=1;
        }
        cin>>s;
      BFS(s-1);
    }
    
    
    return 0;
}
