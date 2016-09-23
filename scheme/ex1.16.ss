;(define (even? n)
;  (= (remainder n 2) 0))

(define (square n)
  (* n n))

(define (fast-expt b n)
  (cond ((= n 0) 1)
	((even? n) (square (fast-expt b (/ n 2))))
	(else (* b (fast-expt b (- n 1))))))

(define (find-2^n m n)
  (if (= m 0)
    0
    (if (> (* 2 n) m) 
	    n    
	    (find-2^n m (* 2 n)))))

(define (fast-expt-iter b n a p)
  (if (= a 0.5)
    p
    (if (>= (- n a) 0)
      (fast-expt-iter b (- n a) (/ a 2) (* p p b))
      (fast-expt-iter b n (/ a 2) (* p p)))))

(define (fast-expt1 b n)
  (if (= n 0)
    1
    (fast-expt-iter b n (find-2^n n 1) 1)))

(define (get-binary-digit number digit)
  ;(display number)
  ;(newline)
  (cond ((= (find-2^n number 1) (fast-expt1 2 digit)) 1)
	((< (find-2^n number 1) (fast-expt1 2 digit)) 0)
	(else (get-binary-digit (- number (find-2^n number 1)) digit))))

(define (fib n)
  (fib-iter1 1 0 0 1 n 0 0))
(define (fib-iter1 a b p q n m l)
  (cond ((= n m) b)
	((= (get-binary-digit n l) 1)
	 (fib-iter1 (+ (* b q) (* a q) (* a p))
		    (+ (* b p) (* a q))
		    (+ (* p p) (* q q))
		    (+ (* q q) (* 2 p q))
		    n
		    (+ m (fast-expt1 2 l))
		    (+ l 1)))
	 (else (fib-iter1 a 
			  b
			  (+ (* p p) (* q q))
			  (+ (* q q) (* 2 p q))
			  n
			  m
			  (+ l 1)))))






