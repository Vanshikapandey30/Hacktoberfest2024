#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
    int start;
    int end;

    Interval(int s, int e) : start(s), end(e) {}
};

bool compareInterval(Interval a, Interval b)
{
    return (a.start < b.start);
}

vector<Interval> mergeIntervals(vector<Interval> &intervals)
{
    vector<Interval> merged;

    if (intervals.empty())
    {
        return merged;
    }

    sort(intervals.begin(), intervals.end(), compareInterval);

    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {

        Interval &last = merged.back();

        if (intervals[i].start <= last.end)
        {
            last.end = max(last.end, intervals[i].end);
        }
        else
        {

            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main()
{

    vector<Interval> intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};

    vector<Interval> merged = mergeIntervals(intervals);

    cout << "Merged intervals: ";
    for (const Interval &interval : merged)
    {
        cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    cout << endl;

    return 0;
}
