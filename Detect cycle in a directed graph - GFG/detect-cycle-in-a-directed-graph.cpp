// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int s, vector<int> adj[], bool visited[], bool recst[]){
        
        visited[s]=true;
        recst[s]=true;
        
        for(int x:adj[s]){
            if(visited[x]==false && dfs(x, adj, visited, recst)){
                return true;
            }
            else if(recst[x]==true){
                return true;
            }
            
        }
        recst[s]=false;
        
        
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool visited[V];
        bool recst[V];
        
        
        for(int i=0; i<V; i++){
            visited[i]=false;
            recst[i]=false;
        }
        
        for(int i=0; i<V; i++){
            if(visited[i]==false){
                if(dfs(i, adj, visited, recst)==true)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends