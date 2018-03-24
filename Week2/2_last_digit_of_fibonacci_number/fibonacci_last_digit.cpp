#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int get_fibonacci_last_digit_fast(int n) {
    
    if (n <= 1)
        return n;
    
    int previous = 0;
    int current  = 1;
    
    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }
    
    return current;
}

void test_solution() {
    
    assert(get_fibonacci_last_digit_fast(3) == 2);
    assert(get_fibonacci_last_digit_fast(10) == 5);
    for (int n = 0; n < 50; ++n)
        if(get_fibonacci_last_digit_fast(n) != get_fibonacci_last_digit_naive(n)){
            std::cout << "Test failed with input "<<n<<std::endl;
            break;
        }
}

int main() {
    int n;
    std::cin >> n;
//    int c = get_fibonacci_last_digit_naive(n);
    int d = get_fibonacci_last_digit_fast(n);
//    test_solution();
    std::cout << d << '\n';
    }
