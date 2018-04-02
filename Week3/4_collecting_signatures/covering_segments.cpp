#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;



struct Segment {
  int start, end;
};
template class std::vector<int>;
template class std::vector<Segment>;
bool compare(const Segment& s1, const Segment& s2){
    return (s1.start < s2.start);
}

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;
    //write your code here
    std::sort(segments.begin(), segments.end(), compare);
    for (size_t i = 0; i < segments.size(); ++i) {
        if(i !=0 && points.back() >= segments[i].start)
            continue;
        else if(segments[i].end > segments[i+1].start){
            points.push_back(std::min(segments[i].end, segments[i+1].end));
            }
        else{
            points.push_back(segments[i].end);
        }
    }
    return points ;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
    
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
