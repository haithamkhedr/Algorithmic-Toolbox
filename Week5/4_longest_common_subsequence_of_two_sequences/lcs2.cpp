#include <iostream>
#include <vector>

using std::vector;
template class std::vector< std::vector<int> >;

int lcs2(vector<int> &a, vector<int> &b) {
    //write your code here
    int n1 = a.size() + 1;
    int n2 = b.size() + 1;
    std::vector< std::vector<int> > lcs(n1, std::vector<int>(n2,0));
    for (size_t i = 1; i < n1; ++i) {
        for (size_t j = 1; j < n2; ++j) {
            int d_ins = lcs[i-1][j];
            int d_del = lcs[i][j-1];
            int d_match = lcs[i-1][j-1];
            if(a[i-1] == b[j-1]){
                d_match += 1;
            }
            lcs[i][j] = std::max(d_match, std::max(d_ins,d_del));
        }
    }
    
    return lcs[n1 -1][n2-1];
}
int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
