class Solution {
public:
    int check(vector<int>& players, vector<int>& trainer) {
        int n = players.size();
        int m = trainer.size();
        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            if (players[i] <= trainer[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i;
    }
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();

        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));
        int ans = 0;

        return check(players, trainers);
    }
};
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// [3,4] , [5,2,3]
// 3>2 = > not pos