(define (cbrt-iter guess x)
  (if (good-enough? guess x)
    guess
    (cbrt-iter (improve guess x)
	       x)))
(define (square x)
  (* x x))
(define (cube x)
  (* x x x))
(define (improve guess x)
  (/ (+ (/ x (square guess)) (* 2 guess)) 3))
(define (good-enough? guess x)
  (< (abs (- (cube guess) x)) 0.001))
;注意，除了improve，good-enough?也需要修改。
(define (cbrt1 x)
  (cbrt-iter 1.0 x))
(cbrt1 27.0)
(cbrt1 1000000000000)

