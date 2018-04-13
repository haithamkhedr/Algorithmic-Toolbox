#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
template class std::vector<int>;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

std::pair<int, int> partition3(vector<int> &a, int l, int r) {
    int x = a[l];
    int k = l+1;
    //group all elements equal to the pivot at the beginning
    for (int i=l+1; i <=r ; ++i) {
        if(a[i] == x){
            swap(a[i], a[k++]);
        }
    }
    int m1 =  partition2(a, l, r);
    for (int i = l+1; i < l+k; ++i) {
        swap(a[i],a[m1--]);
    }
    std::pair<int, int> ret(m1, m1 + k);
    return ret;

}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  std::pair<int, int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.first - 1);
  randomized_quick_sort(a, m.second + 1, r);
}
#define TEST

int main() {
#ifdef TEST
    // do something
    std::cout<<"Testing"<<std::endl;
    int n = 10000;
    vector<int> b(n);
    for(int i =0; i< n; ++i){
        b[i] = 10;
    }
    const clock_t begin_time = clock();
    randomized_quick_sort(b, 0, b.size() - 1);
    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
#else
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
#endif

}
