#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

unsigned long long fibonacci_sum(long long n) {
    if (n <= 1)
        return n;
    
    unsigned long long previous = 0;
    unsigned long long current  = 1;
    
    for (long long i = 0; i < n - 1; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current + 1) % 10;
    }
    
    return current;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to){
    if (from ==0)
        from = 1;
    //Pisano period for mod 10 is 60
    int period = 60;
    unsigned long long s_to = fibonacci_sum((to) % period);
    unsigned long long s_from = fibonacci_sum((from-1) % period);
    long long diff = s_to - s_from;
    return (diff + 10) % 10 ;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
