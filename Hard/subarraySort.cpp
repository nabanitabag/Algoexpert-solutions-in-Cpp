//leetcode medium: shortest unsorted continuous subarray

// O(n) time | O(1) space
class Solution {
public:
    int findUnsortedSubarray(vector<int>& array) {
        int minOutOfOrder = INT_MAX;
        int maxOutOfOrder = INT_MIN;

        if(array.size() == 1)
            return 0;

        for(int i = 0 ; i < array.size() ; i++)
        {
            int num = array[i];
            if(isOutOfOrder(i, num, array)){
                minOutOfOrder = min(minOutOfOrder, num);
                maxOutOfOrder = max(maxOutOfOrder, num);
            }
        }
        if(minOutOfOrder == INT_MAX)
            return 0;//vector<int> {-1, -1};

        int subarrayLeftIdx = 0;

        while(minOutOfOrder >= array[subarrayLeftIdx])
            subarrayLeftIdx++;

        int subarrayRightIdx = array.size() - 1;

        while(maxOutOfOrder <= array[subarrayRightIdx])
            subarrayRightIdx--;

        return (subarrayRightIdx - subarrayLeftIdx + 1);
    }

    bool isOutOfOrder(int i, int num, vector<int> array){
        if(i == 0)
            return num > array[i+1];

        if(i == array.size() - 1)
            return num < array[i-1];

        return num > array[i + 1] || num < array[i - 1];
    }
};

// O(n) time | O(1) space
/* The idea behind this method is that the correct position of the minimum element in the unsorted subarray helps
to determine the required left boundary. Similarly, the correct position of the maximum element in the unsorted subarray
helps to determine the required right boundary.Thus, firstly we need to determine when the correctly sorted array goes wrong.
We keep a track of this by observing rising slope starting from the beginning of the array. Whenever the slope falls, we know
that the unsorted array has surely started. Thus, now we determine the minimum element found till the end of the array numsnums, given by minmin.
Similarly, we scan the array numsnums in the reverse order and when the slope becomes rising instead of falling, we start looking
for the maximum element till we reach the beginning of the array, given by maxmax.Then, we traverse over numsnums and determine the correct
position of minmin and maxmax by comparing these elements with the other array elements. e.g. To determine the correct position of minmin,
\we know the initial portion of numsnums is already sorted. Thus, we need to find the first element which is just larger than minmin.
Similarly, for maxmax's position, we need to find the first element which is just smaller than maxmax searching in numsnums backwards.
*/
int findUnsortedSubarray(vector<int>& nums) {
       int mini = INT_MAX, maxi = INT_MIN;
       bool flag = false;
       for (int i = 1; i < nums.size(); i++) {
           if (nums[i] < nums[i - 1])
               flag = true;
           if (flag)
               mini = min(mini, nums[i]);
       }
       flag = false;
       for (int i = nums.size() - 2; i >= 0; i--) {
           if (nums[i] > nums[i + 1])
               flag = true;
           if (flag)
               maxi = max(maxi, nums[i]);
       }
       int l, r;
       for (l = 0; l < nums.size(); l++) {
           if (mini < nums[l])
               break;
       }
       for (r = nums.size() - 1; r >= 0; r--) {
           if (maxi > nums[r])
               break;
       }
       return r - l < 0 ? 0 : r - l + 1;
   }
