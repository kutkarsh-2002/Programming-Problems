class Solution {
public:
    int memo[38]={0};
    
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        
        if(memo[n]){
            return memo[n];
        }
        
        return memo[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};