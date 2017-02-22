#lang racket

;(define (square n)
;  (* n n))
;
;(define (fast-expt b n)
;  (cond ((= n 0) 1)
;	((even? n) (square (fast-expt b (/ n 2))))
;	(else (* b (fast-expt b (- n 1))))))
;
;(define (cont-frac n d k)
;  (define (sum j result)
;    (if (= j 0)
;      result
;      (sum (- j 1) (/ (n j) (+ (d j) result)))))
;  (sum (- k 1) (/ (n k) (d k))))
;
;(define (tan-cf x k)
;  (define (tann i)
;    (- (fast-expt x i)))
;  (define (tand i)
;    (- (* 2 i) 1))
;  (- (cont-frac tann tand k)))
;
;(tan 1.0)
;(tan-cf 1.0 100)
;
; 原来是x^2！不是x^1,x^2,x^3……我看花眼了……

(define (cont-frac n d k)
  (define (sum j result)
    (if (= j 0)
      result
      (sum (- j 1) (/ (n j) (+ (d j) result)))))
  (sum (- k 1) (/ (n k) (d k))))

(define (tan-cf x k)
  (define (tann i)
    (if (= i 1)
      x
      (- (* x x))))
  (define (tand i)
    (- (* 2 i) 1))
  (cont-frac tann tand k))

(tan 1.0)
(tan-cf 1.0 100)
(tan 1.5)
(tan-cf 1.5 100)
