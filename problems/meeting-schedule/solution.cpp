// https://neetcode.io/problems/meeting-schedule

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<Interval> schedules(intervals);
        sort(schedules.begin(), schedules.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        for (int i = 0; i < schedules.size() - 1; ++i) {
            if (schedules[i].end > schedules[i + 1].start)
                return false;
        }
        return true;
    }
};
