#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product_slow(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
      
      long long a_max = -100000;
      long long b_max = -100000;
      size_t a_idx = 0;
      size_t b_idx = 0;
      
      for(size_t j =0; j < a.size(); ++j){
          if(a[j] > a_max){
              a_max  = a[j];
              a_idx = j;
          }
      }
      for(size_t k = 0; k < b.size(); ++k){
          if(b[k] > b_max){
              b_max  = b[k];
              b_idx = k;
          }
      }
      
    result += ((long long) a[a_idx]) * b[b_idx];
    a[a_idx] = -100000;
    b[b_idx] = -100000;
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product_slow(a, b) << std::endl;
}
