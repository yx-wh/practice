(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a)
         (sum term (next a) next b))))
(define (cube x)
  (* x x x))
(define (inc n) (+ n 1))

(define (sum-cubes a b)
  (sum cube a inc b))

(define (identity x) x)
(define (sum-integers a b)
  (sum identity a inc b))

(define (pi-sum a b)
  (define (pi-term x)
    (/ 1.0 (* x (+ x 2))))
  (define (pi-next x)
    (+ x 4))
  (sum pi-term a pi-next b))

(define (integral f a b dx)
  (define (add-dx x) (+ x dx))
  (* (sum f (+ a (/ dx 2.0)) add-dx b)
     dx))

(define (simpson-integral f a b n)
  (define h (/ (- b a) n))
  (define (simpson-term x)
    (* (/ h 3) (+ (f x) (* 4 (f (+ x h))) (f (+ x h h)))))
  (define (simpson-next x)
    (+ x h h))
  (sum simpson-term a simpson-next (+ a (* (- n 2) h))))

(simpson-integral cube 0 1 100)
