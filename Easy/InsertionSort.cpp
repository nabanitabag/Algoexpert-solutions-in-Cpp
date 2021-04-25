vector<int> insertionSort(vector<int> arr){
  if(arr.empty()){
    return {};
  }

  for(int i = 1 ; i < arr.size() ; i++){
    int j = i;
    while(j > 0 && arr[j] < arr[j-1]){
      swap(arr[j], arr[j-1]);
      j--;
    }
  }
  return arr;
}
// Best: O(n) time | O(1) space
// Average: O(n^2) time | O(1) space
// Worst: O(n^2) time | O(1) space
