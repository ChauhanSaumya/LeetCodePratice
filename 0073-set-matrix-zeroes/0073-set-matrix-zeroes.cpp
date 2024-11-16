class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        //step -1 making hash arrays inside the matrix onyl
        int col0=1;//for avioding the overlapping of the elements in the hash array
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {  //marking ith row & jth column
                    matrix[i][0]=0;
                    if(j!=0)
                    matrix[0][j]=0;
                    else col0=0;
                }
            }
        }
        //step-2 for marking elements to 0 in output array
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]!=0)
                {
                    //we will check for row & col
                    if(matrix[i][0]==0 || matrix[0][j]==0)
                    {
                             matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0)
        {
            for(int j=0;j<m;j++)matrix[0][j]=0;//1st row
        }
        if(col0==0)
        {
            for(int i=0;i<n;i++)matrix[i][0]=0;  
        }
        return;
    }
};