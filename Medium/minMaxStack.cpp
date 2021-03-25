class minMaxStack{
public:
  stack<int> st = {};
  stack<unordered_map<string, int> > minMax = {};

// O(1) time | O(1) space
int peek()
{
  return st.top();
}

// O(1) time | O(1) space
void push(elem)
{
  unordered_map<string, int> newMinMax = {{"min", number}, {"max",number}};
  if(minMaxStack.size())
  {
    unordered_map<string, int> lastMinMax = minMax[minMax.size() - 1];
    newMinMax['min'] = min (lastMinMax ["min"], elem);
    newMinMax['max'] = max (lastMinMax ["max"], elem);
  }
  minMax.push_back(newMinMax);
  st.push_back(elem);
}

// O(1) time | O(1) space
int pop()
{
  int result = st.top();
  minMax.pop();
  st.pop();
  return result;
}

// O(1) time | O(1) space
int getMin()
{
  return minMax[minMax.size() - 1]["min"];
}

// O(1) time | O(1) space
int getMax()
{
  return minMax[minMax.size() - 1]["max"];
}
