#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value_slow(int capacity, vector<int> weights, vector<int> values) {
    
    double value = 0.0;
    int total_weight = 0;
    for(int i=0; i < weights.size(); ++i){
        total_weight += weights[i];
    }
    capacity = std::min(capacity,total_weight);
    while(capacity > 0){
        double max_v_per_w  = -1;
        int max_i = 0;
        for(int i = 0; i < values.size(); ++i){
            if(weights[i] == 0)
                continue;
            double v_per_w = (double) values[i] / weights[i] ;
            if(v_per_w > max_v_per_w){
                max_v_per_w = v_per_w;
                max_i = i;
            }
        }
        int fraction = std::min(capacity, weights[max_i]);
        capacity -= fraction;
        value += fraction * (double) values[max_i] / weights[max_i];
        weights[max_i] -= fraction;
    }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  double optimal_value = get_optimal_value_slow(capacity, weights, values);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
