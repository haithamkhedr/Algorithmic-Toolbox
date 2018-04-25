#include <iostream>
#include <string>
#include <vector>

using std::string;

template class std::vector< std::vector<int> >;
int edit_distance(const string &str1, const string &str2) {
    //write your code here
    int n1 = str1.length() + 1;
    int n2 = str2.length() + 1;
    std::vector< std::vector<int> > edit_distance(n1, std::vector<int>(n2,0));
    //initializing edit distances
    for (size_t i =0; i < n1; ++i) {
        edit_distance[i][0] = i;
    }
    for (size_t i =0; i < n2; ++i) {
        edit_distance[0][i] = i;
    }
    
    for (size_t i = 1; i < n1; ++i) {
        for (size_t j = 1; j < n2; ++j) {
            int d_ins = 1 + edit_distance[i-1][j];
            int d_del = 1 + edit_distance[i][j-1];
            int d_match = edit_distance[i-1][j-1];
            if(str1[i-1] != str2[j-1]){
                d_match += 1;
            }
            edit_distance[i][j] = std::min(d_match, std::min(d_ins,d_del));
        }
    }
    
    return edit_distance[n1 -1][n2-1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
