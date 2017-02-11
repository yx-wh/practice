(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a)
         (sum term (next a) next b))))
;(define (product term a next b)
;  (if (> a b)
;      1
;      (* (term a)
;         (product term (next a) next b))))
(define (product term a next b)
    (define (iter a result)
        (if (> a b)
            result
            (iter (next a)
                  (* (term a) result))))
    (iter a 1))

(define (factorial n)
  (product identity 1 inc n))

(define (pi-john-wallis n)
  (define (pi-term x)
    (if (= (remainder x 2) 1)
      (/ (+ x 1)
	 (+ x 2))
      (/ (+ x 2)
	 (+ x 1))))
  (define (pi-next x)
    (+ x 1))
  (* 4.0 (product pi-term 1 pi-next n)))


(define (cube x)
  (* x x x))
(define (inc n) (+ n 1))

(define (sum-cubes a b)
  (sum cube a inc b))

(define (identity x) x)
(define (sum-integers a b)
  (sum identity a inc b))


(pi-john-wallis 1000)

