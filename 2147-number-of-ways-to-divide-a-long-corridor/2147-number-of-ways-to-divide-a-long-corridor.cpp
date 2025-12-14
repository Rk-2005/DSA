class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        int size = corridor.size();

        long long countNoofSeats = 0;

        for (int i = 0; i < size; i++) {
            if (corridor[i] == 'S') {
                countNoofSeats++;
            }
        }

        if (countNoofSeats % 2 != 0 || countNoofSeats == 0) {
            return 0;
        }
        if (countNoofSeats == 2) {
            return 1;
        }
        long long cntseats = 0;

        long long ans = 1;

        for (int i = 0; i < size; i++) {

            if (cntseats == 2) {
                int cnt = 0;
                while (i < size && corridor[i] != 'S') {
                    cnt++;
                    i++;
                }
                if (i < size)
                    ans = ((ans % mod) * (cnt + 1)) % mod;

                cntseats = 0;
            }

            if (corridor[i] == 'S') {
                cntseats++;
            }
            
        }
        return ans % mod;
    }
};

// if seats are odd so there is no way to divide it

//| PPSPSPSSpppppp |
//
