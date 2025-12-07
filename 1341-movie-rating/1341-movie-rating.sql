(
    SELECT name AS results
    FROM Users u
    JOIN MovieRating m ON u.user_id = m.user_id
    GROUP BY u.user_id
    -- Sort by count high-to-low, then name A-Z
    ORDER BY COUNT(m.movie_id) DESC, name ASC
    LIMIT 1
)

UNION ALL

(
    SELECT title AS results   
    FROM Movies m
    JOIN MovieRating mr ON m.movie_id = mr.movie_id
    -- Filter for February 2020
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY m.movie_id
    -- Sort by average rating high-to-low, then title A-Z
    ORDER BY AVG(mr.rating) DESC, title ASC
    LIMIT 1
);