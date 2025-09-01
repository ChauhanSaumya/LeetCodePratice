class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto& c : classes)
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        while (extraStudents--) {
            auto x = pq.top().second; pq.pop();
            x.first++, x.second++;
            pq.push({gain(x.first, x.second), {x.first, x.second}});
        }
        double ans = 0;
        int n = classes.size();
        while (!pq.empty()) {
            auto x = pq.top().second; pq.pop();
            ans += (double)x.first / x.second;
        }
        return ans / n;
    }
};