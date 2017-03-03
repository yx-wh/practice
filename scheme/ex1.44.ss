#lang racket

(define dx 0.000001)

(define (smooth f)
  (lambda (x) (/ (+ (f (+ x dx)) (f x) (f (- x dx))) 
		 3)))

(define (repeated f n)
  (if (= n 1)
    (lambda (x) (f x))
    (lambda (x) (f ((repeated f (- n 1)) x)))))


(define (repeatedsmooth f n)
  ((repeated smooth n) f))
