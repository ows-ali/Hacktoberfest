/* Problem URL: https://leetcode.com/problems/employees-earning-more-than-their-managers/
*  Author: Cody Siegmann
*/

SELECT Name as Employee
FROM Employee as e1
WHERE Salary > (SELECT Salary FROM Employee as e2 WHERE e1.ManagerId = e2.Id );