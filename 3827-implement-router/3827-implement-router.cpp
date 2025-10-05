#include <bits/stdc++.h>
using namespace std;

class Router {
public:
    int limit = 0;
    deque<pair<int, pair<int, int>>> dq; // stores packets
    unordered_map<string, int> dup;      // for duplicate checking
    map<int, vector<int>> mp;            // destination -> timestamps (sorted order)

    Router(int memoryLimit) { limit = memoryLimit; }

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        // check for duplicate
        if (dup.find(key) != dup.end())
            return false;

        // if queue full, remove oldest
        if (dq.size() == limit) {
            auto it = dq.front();
            dq.pop_front();

            // remove timestamp from mp
            auto &vec = mp[it.second.first];
            auto pos = lower_bound(vec.begin(), vec.end(), it.second.second);
            if (pos != vec.end()) vec.erase(pos);

            // remove from dup
            dup.erase(makeKey(it.first, it.second.first, it.second.second));
        }

        dq.push_back({source, {destination, timestamp}});
        dup[key] = 1;
        mp[destination].push_back(timestamp); // increasing timestamps

        return true;
    }

    vector<int> forwardPacket() {
        vector<int> ans;
        if (dq.empty())
            return ans;

        auto cur = dq.front();
        dq.pop_front();

        int src = cur.first;
        int dest = cur.second.first;
        int t = cur.second.second;

        // remove timestamp
        auto &vec = mp[dest];
        auto it = lower_bound(vec.begin(), vec.end(), t);
        if (it != vec.end()) vec.erase(it);

        // remove from dup
        dup.erase(makeKey(src, dest, t));

        ans = {src, dest, t};
        return ans;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = mp.find(destination);
        if (it == mp.end()) return 0;

        auto &vec = it->second;
        auto lower = lower_bound(vec.begin(), vec.end(), startTime);
        auto upper = upper_bound(vec.begin(), vec.end(), endTime);
        return upper - lower; // O(log n)
    }
};
