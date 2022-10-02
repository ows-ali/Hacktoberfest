SELECT DISTINCT
    CITY
FROM STATION
WHERE NOT (
              (
                  CITY LIKE 'a%'
                  OR CITY LIKE 'e%'
                  OR CITY LIKE 'i%'
                  OR CITY LIKE 'o%'
                  OR CITY LIKE 'u%'
              )
              OR (
                     CITY LIKE '%a'
                     OR CITY LIKE '%e'
                     OR CITY LIKE '%i'
                     OR CITY LIKE '%o'
                     OR CITY LIKE '%u'
                 )
          );
