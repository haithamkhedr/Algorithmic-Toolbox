#include <iostream>
#include <vector>

using std::vector;

#define SMALLER_THAN_OR_EQ 0
#define LARGER_THAN_OR_EQ 1
template class std::vector<int>;
void merge(vector<int>& arr, int left, int mid, int right){
    vector<int> arr_cp(arr.begin()+left, arr.begin() + right + 1);
    mid -= left;
    right -= left;
    size_t i= left, p1 = 0 ,p2 = mid + 1;
    while( (p1 <= mid) || (p2 <= right) ){
        if(p1 > mid){
            arr[i++] = arr_cp[p2++];
        }
        else if(p2 > right){
            arr[i++] = arr_cp[p1++];
        }
        else {
            
            if(arr_cp[p1] <= arr_cp[p2])
                arr[i++] = arr_cp[p1++];
            else
                arr[i++] = arr_cp[p2++];
        }
    }
}

void merge_sort(vector<int>& arr, int left, int right){
    
    if(left >= right)
        return;
    int mid = (left + right)/2 ;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr,left,mid,right);
}

size_t binary_search_modified(const vector<int>& arr, int x, int left, int right, int mode){
    
    if(left > right)
        return left - 1;
    
    int mid = (left + right) / 2;
    if (mode == SMALLER_THAN_OR_EQ){
        if( x <  arr[mid]){
            return binary_search_modified(arr, x, left, mid-1,mode);
        }
        else{
            return binary_search_modified(arr, x, mid+1, right,mode);
        }
    }
    
    else{
        if( x <=  arr[mid]){
            return binary_search_modified(arr, x, left, mid-1,mode);
        }
        else{
            return binary_search_modified(arr, x, mid+1, right,mode);
        }
    }

}
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
    int  n = starts.size();
    merge_sort(starts,0,n-1);
    merge_sort(ends,0,n-1);
    for (int i = 0; i < cnt.size(); ++i) {
        int l = binary_search_modified(starts,points[i], 0, n-1, SMALLER_THAN_OR_EQ) + 1;
        int r = n - (binary_search_modified(ends,points[i], 0, n-1, LARGER_THAN_OR_EQ) + 1);
        cnt[i] = (l + r - n);
    }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}
//#define TEST_SORT
//#define TEST_B_SEARCH
//#define GEN_LARGE_INPUT

int main() {
    
#ifdef TEST_SORT
    std::cout<<"Testing Merge sort"<<std::endl;
    vector<int> a = {5,2,10,1,3,6,12,4};
    merge_sort(a, 0, a.size()-1);
    for (const int & i : a) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;


#elif defined (TEST_B_SEARCH)
    std::cout<<"Testing Binary search"<<std::endl;
    vector<int> b = {1,2,3,3,4,6,7};
    std::cout<<binary_search_modified(b, 3, 0, b.size()-1,SMALLER_THAN_OR_EQ)<< std::endl;
    std::cout<<binary_search_modified(b, 3, 0, b.size()-1,LARGER_THAN_OR_EQ)<< std::endl;

    
#elif defined (GEN_LARGE_INPUT)
    int n = 10000 , m =10000;
    vector<int> starts(n), ends(n);
    vector<int> points(m);

    for (size_t i = 0; i < starts.size(); i++) {
        starts[i] = rand() % 100000000;
        ends[i] = rand() % 100000000;
    }
    for (size_t i = 0; i < points.size(); i++) {
        points[i] = rand() % 100000000;
    }
    auto begin = std::clock();
    vector<int> cnt1 = naive_count_segments(starts, ends, points);
    auto diff = std::clock() - begin;
    std::cout<<std::endl<< (float)diff/CLOCKS_PER_SEC <<std::endl;
//    for (size_t i = 0; i < cnt1.size(); i++) {
//        std::cout << cnt1[i] << ' ';
//    }
    begin = std::clock();
    vector<int> cnt2 = fast_count_segments(starts, ends, points);
    diff = std::clock() - begin;
    std::cout<<std::endl<< (float)diff/CLOCKS_PER_SEC<<std::endl;
    for (size_t i = 0; i < cnt2.size(); i++) {
        std::cout << cnt2[i] << ' ';
    }
#else
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
#endif
}
