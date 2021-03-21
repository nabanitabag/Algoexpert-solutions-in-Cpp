bool hasSingleCycle(vector<int> nums)
{
  int numElemsVisited = 0;
  int currentIdx = 0;

  while(numElemsVisited<nums.size())
  {
      if(numElemsVisited > 0 && currentIdx == 0)
        return false;

      numElementsVisited++;

      currentIdx = getNextIdx(currentIdx, nums);
  }

  return currentIdx == 0;
}

int getNextIdx(int currentIdx, vector<int> nums)
{
  int jump = nums[currentIdx];
  int nextIdx = (currentIdx + jump) % (int)nums.size();
  return nextIdx >= 0 ?nextIdx : nextIdx + nums.size();
}

// O(n) time | O(1) space - where n is the length of the input array
