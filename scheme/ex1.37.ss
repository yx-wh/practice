#lang racket

;(define (cont-frac n d k)
;  (define (sum j)
;    (if (= j k)
;      (/ (n j) (d j))
;      (/ (n j) (+ (d j) (sum (+ j 1))))))
;  (sum 1))
;
; this one works.

;(define (cont-frac n d k)
;  (define (sum j result)
;    (if (= j 1)
;      result
;      (sum (- j 1) (/ (n j) (+ (d j) result)))))
;  (sum k (/ (n k) (d k))))
;
; this is the wrong code. works in ex1.37 so i didn't detect it.

(define (cont-frac n d k)
  (define (sum j result)
    (if (= j 0)
      result
      (sum (- j 1) (/ (n j) (+ (d j) result)))))
  (sum (- k 1) (/ (n k) (d k))))


(cont-frac (lambda (i) 1.0) 
	   (lambda (i) 1.0)
	   10)
(cont-frac (lambda (i) 1.0) 
	   (lambda (i) 1.0)
	   11)
(cont-frac (lambda (i) 1.0) 
	   (lambda (i) 1.0)
	   12)
(cont-frac (lambda (i) 1.0) 
	   (lambda (i) 1.0)
	   13)
(cont-frac (lambda (i) 1.0) 
	   (lambda (i) 1.0)
	   14)

