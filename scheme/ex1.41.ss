#lang racket
(define (double f)
    (lambda (x)
        (f (f x))))
(define (inc x)
  (+ x 1))
(define (a x)
  (+ x 2))

((double inc) 0)
(((double double) inc) 0)
(((double (double double)) inc) 0)
(((double (double (double double))) inc) 0)

((double a) 0)
(((double double) a) 0)
(((double (double double)) a) 0)
(((double (double (double double))) a) 0)