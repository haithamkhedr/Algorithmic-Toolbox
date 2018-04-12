#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    
  if (left == right)
      return a[left];
    
    int n = (right - left) + 1;
    int mid = (left + right) / 2;
    int m1 = get_majority_element(a,left,mid);
    int m2 = get_majority_element(a,mid+1,right);
    int cnt1 = 0, cnt2 = 0;
    for(size_t i = 0; i < n; ++i){
        if (a[i + left] == m1){
            cnt1++;
        }
        else if(a[i + left] == m2){
            cnt2++;
        }
    }
    if(cnt1 > n/2)
        return m1;
    else if(cnt2 > n/2)
        return m2;
    else{
        return -1;
    }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
