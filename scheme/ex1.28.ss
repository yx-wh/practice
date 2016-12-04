#lang racket

(define (square x)
  (* x x))

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
	((divides? test-divisor n) test-divisor)
	(else (find-divisor n (+ test-divisor 1)))))

(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (= n (smallest-divisor n)))

(define (expmod base exp m)
  (cond ((= exp 0) 1)
	((even? exp)
	 (define t (expmod base (/ exp 2) m))
	 (cond ((and (= 1 (remainder (square t) m))
		     (not (or (= t 1) (= t (- m 1)))))
		0)
	       (else (remainder (square t) m))))
	(else
	  (remainder (* base (expmod base (- exp 1) m))
		     m))))

(define (fermat-test n)
  (define (try-it a)
    (= (expmod a (- n 1) n) 1))
  (try-it (+ 1 (random (- n 1)))))

(define (fast-prime? n times)
  (cond ((= times 0) true)
	((fermat-test n) (fast-prime? n (- times 1)))
	(else false)))

(define (fast-prime2? n a)
  (cond ((= a 1) true)
	((= (expmod a (- n 1) n) 1) (fast-prime2? n (- a 1)))
	(else false)))

(define (check-prime n)
  (fast-prime2? n (- n 1)))

(check-prime 561)
(check-prime 1105)
(check-prime 1729)
(check-prime 2465)
(check-prime 2821)
(check-prime 6601)


(prime? 561)
(prime? 1105)
(prime? 1729)
(prime? 2465)
(prime? 2821)
(prime? 6601)

(expmod 2 560 561)
(expmod 2 280 561)
(expmod 2 140 561)
(expmod 2 70 561)
(expmod 2 35 561)
(expmod 2 34 561)
(expmod 2 17 561)
(expmod 2 16 561)
(expmod 2 8 561)
(expmod 2 4 561)
(expmod 2 2 561)
(expmod 2 1 561)
(expmod 2 0 561)
