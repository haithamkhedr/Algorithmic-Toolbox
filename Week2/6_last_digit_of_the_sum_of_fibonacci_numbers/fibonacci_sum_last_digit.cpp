#include <iostream>

unsigned long long fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current  = 1;
    unsigned long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long get_fibonacci_sum_fast(long long n){
    
    //Pisano period for mod 10 is 60
    if(n <= 1)
        return n;
    int period = 60;
    return (fibonacci_sum_naive((n-1) % period) + fibonacci_sum_naive((n-2) % period) + 1) % 10 ;
}

void test_solution() {
    
    for (int n = 2; n < 91; ++n){
        if(get_fibonacci_sum_fast(n) != fibonacci_sum_naive(n)) {
            std::cout<<"get_fibonacci_sum_fast("<< n<<") : "<< get_fibonacci_sum_fast(n)<<std::endl;
            std::cout<<"fibonacci_sum_naive("<< n<<") : "<< fibonacci_sum_naive(n)<<std::endl;
            break;
        }
    }
    
}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << get_fibonacci_sum_fast(n);
//    test_solution();
}
