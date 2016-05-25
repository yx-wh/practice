(define (inc n)
  (+ n 1))

(define (dec n)
  (- n 1))

(define (plus1 a b)
    (if (= a 0)
        b
        (inc (plus1 (dec a) b))))

(define (plus2 a b)
    (if (= a 0)
        b
        (plus2 (dec a) (inc b))))
