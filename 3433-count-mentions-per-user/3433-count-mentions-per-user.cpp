#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    void updateEventAtIndex(vector<vector<string>>& events, int index) {
        // Ensure the index is within bounds
        if (index < 0 || index >= events.size()) {
            cout << "Invalid index!" << endl;
            return;
        }

        // Find the event at the specified index
        auto& event = events[index];

        // Find the last element of the event (assuming it's the format to
        // change)

        string& lastElement = event.back();

        // Replace "id" with empty string and spaces with commas
        
        stringstream ss(lastElement);
        string temp, result = "";
        while (ss >> temp) {
            // Remove "id" and append the remaining number
            temp.erase(0, 2); // Remove first two characters ("id")
            if (!result.empty())
                result += ",";
            result += temp;
        }

        lastElement = result; // Update the last element of the event
    }

    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        // Sort events based on time, then by event type
        sort(events.begin(), events.end(),
             [](const vector<string>& a, const vector<string>& b) {
                 if (a[1] == b[1]) {
                     return a[0] > b[0]; // If times are equal, sort by event
                                         // type in reverse
                 }
                 return stoi(a[1]) < stoi(b[1]); // Otherwise, sort by time
             });

        int idx = 0;
        // Update the events where necessary
        for (auto& event : events) {
            if (event[0] == "MESSAGE") {
                if (event[2] != "HERE" && event[2] != "ALL") {
                    updateEventAtIndex(events, idx); // Update the event at idx
                }
            }
            idx++;
        }

        // Create a vector to store mentions
        vector<int> mention(numberOfUsers, 0);
        // Create a vector to store offline times
        vector<int> offline(numberOfUsers, 0);

        // Process each event
        for (auto& event : events) {
            string msg = event[0];
            string time = event[1];
            string ids = event[2];

            if (msg == "MESSAGE") {
                // If it's not a global message ("HERE" or "ALL")
                if (ids != "HERE" && ids != "ALL") {
                    stringstream ss(ids);
                    string temp;
                    while (getline(ss, temp, ',')) {
                        mention[stoi(
                            temp)]++; // Increment mention count for the user ID
                    }
                }
                // If it's a global message to all users ("ALL")
                else if (ids == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        mention[i]++; // Increment mention count for all users
                    }
                }
                // If it's a "HERE" message
                else {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (stoi(time) >= offline[i]) {
                            mention[i]++; // Increment mention count if the user
                                          // is online
                        }
                    }
                }
            }
            // If the event is "OFFLINE" (user goes offline)
            else if (msg == "OFFLINE") {
                offline[stoi(ids)] = 60 + stoi(time);
            }
        }

        return mention;
    }
};
