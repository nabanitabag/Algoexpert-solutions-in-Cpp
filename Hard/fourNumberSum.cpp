//leetcode medium: 4Sum
//O(n^3) time complexity | O(1) space complexity
vector<vector<int>> fourSum(vector<int>& num, int target) {
            vector<vector<int>> res;
           if(num.empty()) return res;

           sort(num.begin(), num.end());

           for(int i = 0 ; i < num.size() - 1; i++){
               for(int j = i + 1 ; j < num.size() ; j++)
               {
                   int target2 = target - num[i] - num[j];

                   int left = j + 1;
                   int right = num.size() - 1;

                   while(left<right){
                       int two_sum = num[left] + num[right];
                       if(two_sum  < target2) left++;
                       else if (two_sum > target2) right--;

                       else
                       {
                           vector<int> quad(4, 0);
                           quad[0] = num[i];
                           quad[1] = num[j];
                           quad[2] = num[left];
                           quad[3] = num[right];
                           res.push_back(quad);

                           while(left < right && num[left] == quad[2])
                               ++left;

                           while(left < right && num[right] == quad[3])
                               --right;   
                       }
                   }

                   while(j+1 < num.size() && num[j + 1] == num[j])
                       ++j;
               }
               while(i+1 < num.size() && num[i + 1] == num[i])
                       ++i;
               }
return res;
       }
//another approach (non efficient)
// Average: O(n^2) time | O(n^2) space
// Worst: O(n^3) time | O(n^2) space
vector<vector<int>> fourSum(vector<int>& array, int targetSum) {
           unordered_map<int, vector<vector<int>>> allPairSums;
           vector<vector<int>> quadruplets{};
           if (array.size() == 0)
               return quadruplets;
           for (int i = 1; i < array.size() - 1; i++) {
               for (int j = i + 1; j < array.size() ; j++) {
                   int currentSum = array[i] + array[j];
                   int difference = targetSum - currentSum;
                   if (allPairSums.find(difference) != allPairSums.end()) {
                       for (vector<int> pair : allPairSums[difference]) {
                           pair.push_back(array[i]);
                           pair.push_back(array[j]);
                           sort(pair.begin(), pair.end());
                           quadruplets.push_back(pair);
                        }
                   }
                }
                for (int k = 0; k < i; k++) {
                   int currentSum = array[i] + array[k];
                   allPairSums[currentSum].push_back(vector<int>{array[k], array[i]});
                }
           }
          sort(quadruplets.begin(), quadruplets.end());
          vector<vector<int>>::iterator ip;
          ip = unique(quadruplets.begin(), quadruplets.end());
          quadruplets.resize(distance(quadruplets.begin(), ip));
          return quadruplets;
      }
