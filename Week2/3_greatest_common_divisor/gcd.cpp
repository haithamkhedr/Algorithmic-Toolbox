#include <iostream>
#include <cassert>
#include <cstdlib>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b){
    int gcd = 1;
    if(b == 0){
        gcd = a;
    }
    else{
        a = a % b;
        gcd = gcd_fast(b,a);
    }
    
    return gcd;
}

void test_solution(){
    assert( gcd_fast(18,35) == 1);
    assert( gcd_fast(28851538,1183019) == 17657);
    for(int i = 0; i < 10000; ++i){
        int a = rand() % 10000;
        int b = rand() % 10000;
        if(a>b)
            if(gcd_fast(a,b) != gcd_naive(a, b)){
                std::cout<<"Test failed with input " << a <<" , "<<b<<std::endl;
                std::cout<<"Naive algorithm output " << gcd_naive(a, b) << std::endl;
                std::cout<<"Fast algorithm output " << gcd_fast(a, b) << std::endl;

                break;
            }
            else{
                if(gcd_fast(b,a) != gcd_naive(a, b)){
                    std::cout<<"Test failed with input " << a <<" , "<<b<<std::endl;
                    std::cout<<"Naive algorithm output " << gcd_naive(a, b) << std::endl;
                    std::cout<<"Fast algorithm output " << gcd_fast(b, a) << std::endl;
                    break;
                }
            }

    }

}

int main() {
  int a, b;
  std::cin >> a >> b;
  if(a > b)
      std::cout << gcd_fast(a, b) << std::endl;
  else
      std::cout << gcd_fast(b, a) << std::endl;
//    test_solution();
    return 0;
}
