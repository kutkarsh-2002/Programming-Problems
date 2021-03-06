// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
struct node{
    int u, v, wt;
    node(int first, int second, int weight){
        u=first;
        v=second;
        wt=weight;
    }
};

	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    int dis[n];
	    memset(dis,INT_MAX,sizeof(dis));
	    dis[0]=0;
	    vector<node>v;
	    
	    for(int i=0; i<edges.size(); i++){
	        v.push_back(node(edges[i][0], edges[i][1], edges[i][2]));
	    }
	    
	    dis[0]=0;
	    
	    for(int i=0; i<n; i++){
	        for(auto it:v){
	            if(dis[it.u]+it.wt<dis[it.v]){
	                dis[it.v]=dis[it.u]+it.wt;
	            }
	        }
	    }
	    
	    for(auto it:v){
	        if(dis[it.u]+it.wt<dis[it.v]){
	                return 1;
	            }
	    }
	    
	    return 0;
	    
	    /*int dis[n];
	    memset(dis,INT_MAX,sizeof(dis));
	    dis[0]=0;
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<edges.size(); j++){
	            vector<int>curr=edges[j];
	            int u=curr[0], v=curr[1], wt=curr[2];
	            
	            if(dis[u]+wt<dis[v]){
	                dis[v]=dis[u]+wt;
	            }
	        }
	    }
	    for(int j=0; j<edges.size(); j++){
	            vector<int>curr=edges[j];
	            int u=curr[0], v=curr[1], wt=curr[2];
	            
	            if(dis[u]+wt<dis[v]){
	                return 1;
	            }
	        }
	    return 0;*/
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends