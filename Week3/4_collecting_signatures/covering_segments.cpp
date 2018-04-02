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
    bool ret = false;
    if(s1.start < s2.start)
        ret = true;
    else if( (s1.start == s2.start) && (s1.end < s2.end)){
        ret = true;
    }
    return ret;
}

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;
    //write your code here
    std::sort(segments.begin(), segments.end(), compare);
    points.push_back(segments[0].end);
    for (size_t i = 0; i < segments.size()-1; ++i) {
        if(points.back() >= segments[i+1].start)
            points.back() = std::min(points.back(), segments[i+1].end);
        else{
            points.push_back(segments[i+1].end);
        }
    }
    //handle last segment
    if(points.back() < segments.back().start){
        points.push_back(segments.back().end);
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
