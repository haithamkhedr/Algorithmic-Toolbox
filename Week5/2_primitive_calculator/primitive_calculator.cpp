#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
    std::vector<int> sequence;
    std::vector<int> minSteps(n+1);
    std::vector<int> parents(n+1);
    for (size_t i = 2; i <=n ; ++i) {
        int parent = -1;
        int min_steps = 10000000000;
        if(i % 2 == 0){
            int m2 = 1 + minSteps[i/2];
            if(m2 < min_steps){
                min_steps = m2;
                parent = i/2;
            }
        }
        if(i % 3 == 0){
            int m3 = 1 + minSteps[i/3];
            if(m3 < min_steps){
                min_steps = m3;
                parent = i/3;
            }
        }
        if( i-1 > 0){
            int m1 = 1 + minSteps[i - 1];
            if(m1 < min_steps){
                min_steps = m1;
                parent = i - 1;
            }
        }
        minSteps[i] = min_steps;
        parents[i] = parent;
    }
    
    while(n > 0) {
        sequence.push_back(n);
        n = parents[n];
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
