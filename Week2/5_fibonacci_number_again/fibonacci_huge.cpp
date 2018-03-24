#include <iostream>

unsigned long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current  = 1;

    for (long long i = 0; i < n - 1  ; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return (unsigned long long) (current) % m;
}

unsigned long long fibonacci_mod_fast(long long n,long long m) {
    // write your code here
    if(n <= 1)
        return n;
    unsigned long long prev = 0;
    unsigned long long curr = 1;
    for(int i = 0; i < n-1; ++i){
        unsigned long long temp_prev  = prev;
        prev = curr;
        curr = (temp_prev + curr) % m;
    }
    return curr;
}

long long get_fibonacci_huge_fast(long long n, long long m){
    
    int period = 0;
    unsigned long long prev = 0;
    unsigned long long curr = 1;
    for(int i = 0; i < 6*m; ++i){
        unsigned long long temp_prev  = prev;
        prev = curr;
        curr = (temp_prev + curr) % m;
        if(prev == 0 && curr == 1){
            period = i + 1;
            break;
        }
    }
    return fibonacci_mod_fast(n % period,m);
}

void test_solution() {
    
    for (int n = 2; n < 100; ++n){
        for (int m = 2; m < 100; ++m){
            if(get_fibonacci_huge_fast(n,m) != get_fibonacci_huge_naive(n,m)) {
                std::cout<<"get_fibonacci_huge_fast("<< n<< "," << m << ") : "<< get_fibonacci_huge_fast(n,m)<<std::endl;
                std::cout<<"get_fibonacci_huge_naive("<< n<<"," << m << ") : "<< get_fibonacci_huge_naive(n,m)<<std::endl;
                break;
            }
        }
    }
    
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n,m) << '\n';
//    test_solution();
}
