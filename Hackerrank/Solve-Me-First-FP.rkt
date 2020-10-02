#lang racket
#problem link https://www.hackerrank.com/challenges/fp-solve-me-first/problem
(define (sum-of-two-integers a b)
  (+ a b))

(let ([a (read)]
      [b (read)])
  (printf "~a~%" (sum-of-two-integers a b)))
