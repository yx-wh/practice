#lang racket
;(require (file "/home/yx/practice/scheme/ex1.28.ss"))
;(enter! (file "ex1.28.ss"))
(define (square x)
  (* x x))

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

(define (fast-prime2? n a)
  (cond ((= a 1) true)
	((= a 0) false)
	((= (expmod a (- n 1) n) 1) (fast-prime2? n (- a 1)))
	(else false)))

(define (check-prime n)
  (fast-prime2? n (- n 1)))


(define (accumulate valid? combiner null-value term a next b)
  (define (iter a result)
    (if (> a b)
      result
      (if (valid? a) 
	(iter (next a) (combiner result (term a)))
	(iter (next a) result))))
  (iter a null-value))

(define (sum term a next b)
  (accumulate always-true + 0 term a next b))
(define (product term a next b)
  (accumulate always-true * 1 term a next b))

(define (sum-prime a b)
  (accumulate check-prime + 0 identity a inc b))
(define (product-gcd n)
  (define (check-gcd m)
    (= (gcd m n) 1))
  (accumulate check-gcd * 1 identity 1 inc (- n 1)))


(define (always-true x)
  #t)

(define (cube x)
  (* x x x))
(define (inc n) (+ n 1))

(define (sum-cubes a b)
  (sum cube a inc b))

(define (identity x) x)
(define (sum-integers a b)
  (sum identity a inc b))

(sum-prime 1 10)
(product-gcd 10)
