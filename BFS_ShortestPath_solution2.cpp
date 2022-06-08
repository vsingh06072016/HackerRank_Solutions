#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define SIZE 1005

void bfs(vector<int> adj[SIZE], int dist[SIZE], bool visit[SIZE], int start){
    list<int> queue;
    vector<int>::iterator iter;

    queue.push_back(start);
    visit[start] = true;

    while(!queue.empty()){
        start = queue.front();
        queue.pop_front();

        for(iter=adj[start].begin(); iter!=adj[start].end(); iter++){
            if(!visit[*iter]){
                queue.push_back(*iter);
                visit[*iter] = true;
                dist[*iter] = 6 + dist[start];
            }
        }
    }
}

void printDist(int dist[SIZE], int size, int s){
    for(int i=1; i<=size; i++){
        if(i==s)
            continue;
        if(dist[i]>0)
            cout << dist[i];
        else
            cout << -1;

        if(i!=size)
            cout << " ";
    }
    cout << endl;
}

int main(){
    int t, n, m, u, v, s;
    cin >> t;

    while(t--){
        vector<int> adj[SIZE];
        int dist[SIZE] = {0, };
        bool visit[SIZE] = {false, };
        cin >> n >> m;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        cin >> s;
        bfs(adj, dist, visit, s);
        printDist(dist, n, s);
    }

    return 0;
}
