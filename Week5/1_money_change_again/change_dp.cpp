#include <iostream>
#include <vector>
int get_change(int m) {
  //write your code here
    int n_den = 3;
    std::vector<int> change(m+1);
    std::vector<int> den = {1,3,4};
    
    for(size_t i=1; i <= m; ++i){
        int minCoins = 1000000000;
        for(size_t j = 0; j < n_den; ++j){
            if(i >= den[j]){
                int nCoins = 1 + change[i - den[j]];
                if(nCoins < minCoins){
                    minCoins = nCoins;
                }
            }
        }
        change[i] = minCoins;
    }
    
  return change[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
