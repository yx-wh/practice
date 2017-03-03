#lang racket

(define (square n)
  (* n n))

(define tolerance 0.00001)

(define (fixed-point f first-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
	next
	(try next))))
  (try first-guess))

(define (average . numbers)  
    (/ (apply + numbers) (length numbers)))

(define (repeated f n)
  (if (= n 1)
    (lambda (x) (f x))
    (lambda (x) (f ((repeated f (- n 1)) x)))))

(define (average-damp f)
  (lambda (x) (average x (f x))))

(define (fast-expt b n)
  (cond ((= n 0) 1)
	((even? n) (square (fast-expt b (/ n 2))))
	(else (* b (fast-expt b (- n 1))))))

;(fixed-point ((repeated average-damp 1) (lambda (y) (/ 100000000.0 (fast-expt y 1)))) 1.0)
;(fixed-point ((repeated average-damp 2) (lambda (y) (/ 100000000.0 (fast-expt y 3)))) 1.0)
;(fixed-point ((repeated average-damp 3) (lambda (y) (/ 100000000.0 (fast-expt y 7)))) 1.0)
(fixed-point ((repeated average-damp 4) (lambda (y) (/ 100000000.0 (fast-expt y 15)))) 1.0)
;可见，求解四次方根至少需要两次平均，求解8次方根需要三次，求解16次方根需要4次平均。
