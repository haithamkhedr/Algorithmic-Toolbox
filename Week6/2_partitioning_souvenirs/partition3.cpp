#include <iostream>
#include <vector>

using std::vector;

template class std::vector< std::vector<int> >;
template class std::vector<int>;

int optimal_weight(int W, const vector<int> &w, vector<bool> &used) {
    //write your code here
    int n = w.size() + 1;
    int m = W + 1;
    vector< vector<int> > values(n, vector<int>(m,0));
    for (size_t i = 1; i < n ; ++i) {
        
        for (size_t j = 1; j < m; ++j) {
            values[i][j] =  values[i-1][j];
            if(w[i-1] <= j){
                int val = values[i-1][j - w[i-1]] + w[i-1];
                values[i][j] = std::max(val,values[i][j]);
            }
        }
    }
    for (int i = w.size()-1 ,j = n-1,k = m-1; i >= 0; --i) {
        if(values [j][k] == (values[j-1][k-w[i]] + w[i])){
            used[i] = true;
            j = j-1;
            k = k-w[i];
        }
        else{
            j = j-1;
        }
        
    }
    return values[n-1][m-1];
}
void removeUsedElements(vector<int> & a, const vector<bool> & used){
    for (int i = 0; i < a.size(); ++i) {
        if(used[i] == true)
            a.erase(a.begin() + i);
    }
}
int partition3(vector<int> &A) {
    
    int ret = 1;
    int sum = 0;
    for (auto i : A) {
        sum += i;
    }
    if( sum % 3 != 0){
        ret = 0;
    }
    
    else{
        vector<bool> used(A.size());
        int W = sum / 3;
        for (int i=0; i < 3; ++i) {
            int v = optimal_weight(W, A, used);
            if(v != W && i !=0){
                ret = 0;
            }
            removeUsedElements(A, used);
            used = vector<bool>(A.size());
        }
    }
    return ret;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
