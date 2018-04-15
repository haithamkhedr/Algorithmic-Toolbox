#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, vector<int> &b, size_t left, size_t middle, size_t right){
    size_t p1 = left;
    size_t p2 = middle + 1;
    size_t i = left;
    long long inversions = 0,temp = 0;
    while( (p1 <= middle) || (p2 <= right)){
        
        if(p1 > middle){
            b[i++] = a[p2++];
        }
        else if(p2 == (right+1)){
            
            inversions += ((middle - p1) * temp);
            temp = 0;
            b[i++] = a[p1++];
        }
        else{
            if(a[p1] <= a[p2]){
                inversions += ((middle - p1) * temp);
                temp = 0;
                b[i++] = a[p1++];
            }
            else{
                b[i++] = a[p2++];
                inversions++;
                temp++;
            }
        }
        
    }
    for (int i = left; i <= right; ++i) {
        a[i] = b[i];
    }
    return inversions;
}
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  number_of_inversions += merge(a,b,left,ave,right);
  //write your code here
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
