vector<int> bubbleSort(vector<int> arr){
  if(arr.empty())
    return {};

  bool isSorted = false;
  int counter = 0;

  while(!isSorted){
    isSorted = true;
    for(int i = 0 ; i < arr.size() - 1 -counter ; i++ ){
      if(arr[i] > arr[i+1]){
        swap(arr[i], arr[i+1]);
        isSorted = false;
      }
    }
    counter++;
  }
  return arr;
}
// Best: O(n) time | O(1) space
// Average: O(n^2) time | O(1) space
// Worst: O(n^2) time | O(1) space
