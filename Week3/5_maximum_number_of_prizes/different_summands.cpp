#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
    summands.push_back(1);
  //write your code here
    long long sum=1;
    for(int i=2; sum < n; ++i){
        sum += i;
        if(sum > n){
            summands.back() += (n - (sum - i));
            break;
        }
        else{
            summands.push_back(i);
        }
        
    }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
