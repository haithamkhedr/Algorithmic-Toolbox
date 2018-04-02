#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
bool compare(const string & a,const string &b){
    bool ret = false;
    if(a[0] > b[0]){
        ret = true;
    }
    else if( a[0] == b[0] && a[0] > b[b.size() - 1] && a.length() <= b.length()){
        ret = true;
    }
    return ret;
}
string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
//    std::sort(a.begin(), a.end(),compare);
  for (size_t i = 0; i < a.size(); i++) {
      string max = "-1";
      size_t max_idx = -1;
      for(size_t j = 0; j < a.size(); ++j){
          if(compare(a[j],max)){
              max = a[j];
              max_idx = j;
          }
      }
      a[max_idx] = "-1";
      ret << max;
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
