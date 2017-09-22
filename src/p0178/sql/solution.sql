SELECT
    Score,
    (SELECT COUNT(*) FROM (
        SELECT DISTINCT Score s FROM Scores) AS t WHERE s >= Score) Rank
FROM
    Scores
ORDER BY Score DESC;