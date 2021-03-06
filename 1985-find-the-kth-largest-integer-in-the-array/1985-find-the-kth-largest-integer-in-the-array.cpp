class Solution {
public:
    
//     struct comparator{
        
//     bool operator()(string &s1, string&s2){
//         if(s1.length()>s2.length())
//             return true;
//         else if(s1.length()<s2.length())
//             return false;
        
//         else{
            
//             for(int i=0; i<s1.size(); i++){
//                 if(s1[i]-'0'>s2[i]-'0')
//                     return true;
//                 else if(s1[i]-'0'<s2[i]-'0')
//                     return false;
//             }
//         }
        
//         return false;
//     }
// };
    
//     string kthLargestNumber(vector<string>& nums, int k) {
        
//         //min heap
//         priority_queue<string, vector<string>, comparator>pq;
        
//         for(auto it:nums){
//             pq.push(it);
//             //cout<<it<<" "<<endl;
            
//             if(pq.size()>k){
//                 pq.pop();
//             }
//         }
        
//         return pq.top();
        
//     }
    
    struct comparator{
        
    bool operator()(string &s1, string&s2){
        if(s1.length()<s2.length())
            return true;
        else if(s1.length()>s2.length())
            return false;
        
        else{
            
            for(int i=0; i<s1.size(); i++){
                if(s1[i]-'0'<s2[i]-'0')
                    return true;
                else if(s1[i]-'0'>s2[i]-'0')
                    return false;
            }
        }
        
        return false;
    }
};
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        //min heap
        priority_queue<string, vector<string>, comparator>pq;
        
        for(auto x:nums){
            pq.push(x);
        }
        
        string ans="";
        
        while(!pq.empty() && k>0){
            ans=pq.top();
            //cout<<pq.top()<<endl;
            pq.pop();
            k--;
        }
        
        return ans;
        
    }
};