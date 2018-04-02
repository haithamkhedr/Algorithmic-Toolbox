#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
bool compare(const string & a,const string &b){
    return (std::stoi(a + b) > std::stoi(b+a));
}
string largest_number(vector<string> a) {
    //write your code here
    std::stringstream ret;
    std::sort(a.begin(), a.end(),compare);
    for (size_t i = 0; i < a.size(); i++) {
      ret << a[i];
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
