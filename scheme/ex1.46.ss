#lang racket

(define tolerance 0.00001)

(define (square x)
  (* x x))

(define (average . numbers)  
    (/ (apply + numbers) (length numbers)))

(define (iterative-improve good-enough? improve)
  (lambda (x)
    (define (try guess) 
      (if (good-enough? guess) 
	guess
	(try (improve guess))))
    (try x)))

(define (fixed-point f first-guess)
  (define (fixed-point-good-enough? guess)
    (let ((next (f guess)))
      (< (abs (- guess next)) tolerance)))
  (define (fixed-point-improve guess)
    (f guess))
  ((iterative-improve fixed-point-good-enough? fixed-point-improve) first-guess))

(define (sqrt1 x)
  (define (sqrt1-good-enough? guess)
    (< (abs (- (abs (/ (square guess) x)) 1.0)) 0.00001))
  (define (sqrt1-improve guess)
    (average guess (/ x guess)))
  ((iterative-improve sqrt1-good-enough? sqrt1-improve) 1.0))

(fixed-point cos 1.0)
(fixed-point (lambda (y) (+ (sin y) (cos y))) 
	     1.0)

(sqrt1 100)
