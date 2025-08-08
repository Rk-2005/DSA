class Solution {
public:
    double

    soupServings(int n)

    {

        // If n is large enough, the probability approaches 1.0. This
        // optimization significantly reduces computation time.

        if

            (n >

             4800)

            return

                1.0;

        // Use memoization to store calculated probabilities.

        vector<vector<double>>

            memo(n +

                     1,

                 vector<double>(n +

                                    1,

                                -1.0));

        return

            solve(n, n, memo);
    }

private:
    double

    solve(int a,

          int b, vector<vector<double>>& memo)

    {

        // Base cases:

        if

            (a <=

                 0

             && b <=

                    0)

            return

                0.5;

        // Both are empty at the same time

        if

            (a <=

             0)

            return

                1.0;

        // A is empty before B

        if

            (b <=

             0)

            return

                0.0;

        // B is empty before A

        // Check if the result is already memoized.

        if

            (memo[a][b]

             !=

             -1.0)

            return memo[a][b];

        // Calculate the probability recursively.

        double prob =

            0.0;

        prob +=

            0.25

            *

            solve(a -

                      100,
                  b, memo);

        prob +=

            0.25

            *

            solve(a -

                      75,
                  b -

                      25,
                  memo);

        prob +=

            0.25

            *

            solve(a -

                      50,
                  b -

                      50,
                  memo);

        prob +=

            0.25

            *

            solve(a -

                      25,
                  b -

                      75,
                  memo);

        // Memoize the result.

        memo[a][b]

            = prob;

        return prob;
    }
};