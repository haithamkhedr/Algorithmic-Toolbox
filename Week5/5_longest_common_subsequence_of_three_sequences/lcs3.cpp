#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
    //write your code here
    int n1 = a.size() + 1;
    int n2 = b.size() + 1;
    int n3 = c.size() + 1;
    
    std::vector< std::vector<std::vector<int>>> lcs(n1, std::vector<std::vector<int>>(n2,std::vector<int>(n3,0)));
    for (size_t i = 1; i < n1; ++i) {
        for (size_t j = 1; j < n2; ++j) {
            for (size_t k = 1; k < n3; ++k) {
    
                int d_ins_i = lcs[i-1][j][k];
                int d_ins_j = lcs[i][j-1][k];
                int d_ins_k = lcs[i][j][k-1];
                int d_match = lcs[i-1][j-1][k-1];
                if((a[i-1] == b[j-1]) && (a[i-1] == c[k-1])){
                    d_match += 1;
                }
                lcs[i][j][k] = std::max(d_match, std::max(d_ins_i,std::max(d_ins_j,d_ins_k)));
                
            }
        }
    }
    
    return lcs[n1 -1][n2-1][n3-1];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
