#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */



vector<int>::const_iterator pos;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {

        vector<bool> visited (n, false);
        vector<int> distance(n, 0);
        //bool visited[n] = {false};
        //int distance[n] = {0};
        
        //vector<int>::iterator pos;
        queue<int> queue; 
        vector<int> res;
        vector<int>::iterator pos1;
        
         cout << "Printing s = " << s << " and edges.size() " << edges.size() << endl;
        vector<list<int>> adj;
        
        adj.resize(n);
        
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            cout << "Printing edges[i][0] " << edges[i][0] << " and " << edges[i][1] << endl;
        }

        // Add the starting vertex to the queue
        queue.push(s);
        visited[s] = true;
          
        // BREADTH-FIRST TRAVERSAL :)
        while(!queue.empty()) 
        {
            // Grab the first node in the queue
            int node = queue.front();
            
            cout << "printing node in while loop = " << node << endl;
            
            // Remove node from queue
            queue.pop();
            cout << "After pop " << endl;
           
           if(adj[node].size()!=0)
           {
                for(auto i : adj[node])
                {
                    if(!visited[i]) 
                    {
                        queue.push(i);
                    
                    cout << "Inside loop " << i << " and " << node << endl;
                   
                    distance[i] += (distance[node] + 6);
                    cout << "after distance[i] = " << distance[i] << endl;
                    visited[i] = true;
                    
                    }
                } 
            
           }
        }
        
        
        cout << "Printing number of vertices = " << n << endl;
        
        for(int i = 1; i <= n; i++) {
            cout << "Inside results loop " << i << endl;
            if(i != s) {
                if(distance[i] == 0) {
                    cout<<"-1 " << i << " ";
                    res.push_back(-1);
                } else {
                    cout<<distance[i]<<" "<< i;
                    res.push_back(distance[i]);
                }
            }
        }
        cout<<"\n";
        return res;
    }


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
