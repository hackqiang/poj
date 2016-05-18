class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) 
            return 0;  
        
        int matrixRowSize = matrix.size(), matrixColSize = matrix[0].size(), res = 0; 
        vector<vector<int>> dp(matrixRowSize, vector<int>(matrixColSize, 0));  
        int i,j;
        for(i=0;i<matrixRowSize;i++)
            if(matrix[i][0]=='1')
            {
                dp[i][0] = 1;
                res = 1;
            }
        for(j=0;j<matrixColSize;j++)
            if(matrix[0][j]=='1')
            {
                dp[0][j] = 1;
                res = 1;
            }
        
        for(i=1;i<matrixRowSize;i++)
            for(j=1;j<matrixColSize;j++)
            {
                if(matrix[i][j]=='1')
                {
                    int t=dp[i-1][j-1];
                    if(t>dp[i][j-1])
                         t = dp[i][j-1];
                    if(t>dp[i-1][j])
                         t = dp[i-1][j];
                    
                    dp[i][j] = t + 1;
                    if(res<dp[i][j])
                        res=dp[i][j];
                }
            }
        
        return res*res;
    }
};