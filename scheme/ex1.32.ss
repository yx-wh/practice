(define (accumulate combiner null-value term a next b)
  (if (> a b)
    null-value
    (combiner (term a) 
	      (sum term (next a) next b))))
(define (sum term a next b)
  (accumulate + 0 term a next b))
(define (product term a next b)
  (accumulate * 1 term a next b))


(define (cube x)
  (* x x x))
(define (inc n) (+ n 1))

(define (sum-cubes a b)
  (sum cube a inc b))

(define (identity x) x)
(define (sum-integers a b)
  (sum identity a inc b))


