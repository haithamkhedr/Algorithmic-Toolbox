#include <iostream>

int get_change(int m) {
  //write your code here
    if(m <=4)
        return m;
    if(m >= 10){
        m -=10;
    }
    else if(m >=5){
        m -=5;
    }
    return 1 + get_change(m);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
