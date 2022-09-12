# Write your MySQL query statement below


# select id from weather w1 where temperature > (select temperature from weather w2 where DATEDIFF(w1.recordDate , w2.recordDate) = 1)

SELECT w1.id
FROM Weather AS w1 , Weather AS w2
WHERE w1.Temperature > w2.Temperature AND DATEDIFF(w1.recordDate , w2.recordDate) = 1