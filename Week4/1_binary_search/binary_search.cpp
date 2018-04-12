#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search_recursive(const vector<int> &a, int x, int left, int right) {
    
    int ret = -1;
  //write your code here
    if(left <= right){
        
        int mid = (left + right) / 2;
        
        if(a[mid] == x){
            ret = mid;
        }
        else if( x < a[mid] ){
            ret = binary_search_recursive(a, x, left, mid-1);
        }
        else{
            ret = binary_search_recursive(a, x, mid+1, right);
        }
        
    }
    return ret;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return (int)i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
      std::cout << binary_search_recursive(a, b[i],0,(int) (a.size() -1) ) << ' ';

  }
}
