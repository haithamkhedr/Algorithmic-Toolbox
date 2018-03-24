#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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

long long lcm_fast(int a, int b){
    if(a>b){
        a = a / gcd_fast(a,b);
    }
    else{
        b = b / gcd_fast(b,a);
    }
    return (long long)a*b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
