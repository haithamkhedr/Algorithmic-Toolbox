#include <iostream>
#include <vector>

using std::vector;

#define SMALLER_THAN_OR_EQ 0
#define LARGER_THAN_OR_EQ 1
//template class std::vector<int>;
void merge(vector<int>& arr, size_t left, size_t mid, size_t right){
    vector<int> arr_cp(arr);
    size_t i=0, p1=0 ,p2=mid+1;
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

void merge_sort(vector<int>& arr, size_t left, size_t right){
    
    if(left >= right)
        return;
    size_t mid = (left + right)/2 ;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr,left,mid,right);
}

size_t binary_search_modified(vector<int> arr, int x, size_t left, size_t right, int mode){
    
    if(left > right)
        return left - 1;
    
    size_t mid = (left + right) / 2;
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
    size_t  n = starts.size();
    merge_sort(starts,0,n-1);
    merge_sort(ends,0,n-1);
    for (int i = 0; i < cnt.size(); ++i) {
        size_t l = binary_search_modified(starts,points[i], 0, n-1, SMALLER_THAN_OR_EQ) + 1;
        size_t r = n - (binary_search_modified(ends,points[i], 0, n-1, LARGER_THAN_OR_EQ) + 1);
        cnt[i] = (int)(l + r - n);
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
  vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
#endif
}
