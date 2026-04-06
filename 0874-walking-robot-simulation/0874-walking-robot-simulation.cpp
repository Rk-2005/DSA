class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int commandSize = commands.size();

        int obSize = obstacles.size();

        // NORTH - N , SOUTH - S, EAST - E , WEST - W

        char direction = 'N';

        int x = 0;
        int y = 0;

        set<pair<int, int>> st;

        for (auto ob : obstacles) {
            st.insert({ob[0], ob[1]});
        }

        int maxi = 0;

        for (int c = 0; c < commandSize; c++) {

            int currentCommand = commands[c]; // max 9

            if (currentCommand != -1 && currentCommand != -2) {

                if (direction == 'N') {
                    for (int o = 0; o < currentCommand; o++) {
                        y++;

                        if (st.find({x, y}) != st.end()) {
                            y--;
                            break;
                        }
                    }
                } else if (direction == 'S') {
                    for (int o = 0; o < currentCommand; o++) {
                        y--;

                        if (st.find({x, y}) != st.end()) {
                            y++;
                            break;
                        }
                    }
                } else if (direction == 'E') {
                    for (int o = 0; o < currentCommand; o++) {
                        x++;

                        if (st.find({x, y}) != st.end()) {
                            x--;
                            break;
                        }
                    }
                } else {
                    for (int o = 0; o < currentCommand; o++) {
                        x--;

                        if (st.find({x, y}) != st.end()) {
                            x++;
                            break;
                        }
                    }
                }

            } else if (currentCommand == -1) {
                if (direction == 'N') {
                    direction = 'E';
                } else if (direction == 'E') {
                    direction = 'S';
                } else if (direction == 'S') {
                    direction = 'W';
                } else {
                    direction = 'N';
                }
            } else {
                if (direction == 'N') {
                    direction = 'W';
                } else if (direction == 'E') {
                    direction = 'N';
                } else if (direction == 'S') {
                    direction = 'E';
                } else {
                    direction = 'S';
                }
            }

            maxi = max(maxi, (x * x) + (y * y));
        }
        return maxi;
    }
};