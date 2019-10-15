class Solution {
	static bool comp(const vector<int>& a, const vector<int>& b) {
		return a[1] < b[0];
	}

public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int i = lower_bound(intervals.begin(), intervals.end(), newInterval, comp) - intervals.begin();
		int j = 0;

		for (j = i; j < intervals.size() && newInterval[1] >= intervals[j][0]; ++j)
			newInterval = { min(newInterval[0],intervals[j][0]), max(newInterval[1],intervals[j][1]) };
		intervals.insert(intervals.begin() + j, newInterval);
		intervals.erase(intervals.begin() + i, intervals.begin() + j);
		return intervals;
	}
};
