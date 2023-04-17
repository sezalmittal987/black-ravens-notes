/*
https://leetcode.com/problems/find-median-from-data-stream/description/
*/
class MedianFinder {
public:
    priority_queue<int> s1;
    priority_queue<int, vector<int>, greater<int>> s2;
    
    MedianFinder() {

    }
    
    void addNum(int num) {
        if( s1.empty() or s1.top() > num ) s1.push(num);
        else s2.push(num);
        if( s1.size() == s2.size() + 2 ){
            int t = s1.top();
            s2.push(t);
            s1.pop();
        }
        else if(s2.size() == s1.size() + 1){
            int t = s2.top();
            s1.push(t);
            s2.pop();
        }
    }
    
    double findMedian() {
        if( s1.size() == s2.size()) {
            return (double(s1.top()) + double(s2.top()))/ double(2);
        }
        else return s1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */