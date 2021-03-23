//leetcode medium

bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int col = matrix[0].size()-1;
       int row = 0;
       while(row<matrix.size() && col>=0)
       {
           if(matrix[row][col] == target) return true;
           if(matrix[row][col]<target)
           {
               row++;
           }
           else 
           {
               col--;
           }
       }
       return false;
   }

   // O(n) time | O(1) space
