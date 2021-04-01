// leetcode hard: longest consecutive sequence

// O(n) time | O(n) space

int longestConsecutive(vector<int>& nums) {
       vector<int> bestRange;

       int longestLength = 0;

       unordered_map<int, bool> mp = {};

       for(int num : nums){
           mp[num] = true;
       }

       for(int num:nums){
           if(!mp[num])
               continue;

           mp[num] = false;

           int currLength = 1;
           int left = num - 1;
           int right = num + 1;

           while(mp.find(left) != mp.end()){
               mp[left] = false;
               currLength++;
               left--;
           }

            while(mp.find(right) != mp.end()){
               mp[right] = false;
               currLength++;
               right++;
           }

           if(currLength > longestLength)
           {
               longestLength = currLength;
               bestRange = {left + 1, right - 1};
           }
       }
           return bestRange;
   }
