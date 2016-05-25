(define (f1 n)
  (if (< n 3)
    n
    (+ (f1 (- n 1)) 
       (* 2 (f1 (- n 2)))
       (* 3 (f1 (- n 3))))))

(define (f2-iter a b c i n)
  (if (= i n)
    (+ a
       (* 2 b)
       (* 3 c))
    (f2-iter (+ a (* 2 b) (* 3 c)) a b (+ i 1) n)))

(define (f2 n)
  (if (< n 3)
    n
    (f2-iter (+ (- n (floor n)) 2) (+ (- n (floor n)) 1) (- n (floor n)) 0 (- (floor n) 3))))

;;; 11-iter.scm

(define (f n)
    (f-iter (+ (- n (floor n)) 2) (+ (- n (floor n)) 1) (- n (floor n)) 0 (floor n)))

(define (f-iter a b c i n)
    (if (= i n)
        c
        (f-iter (+ a (* 2 b) (* 3 c))   ; new a
                a                       ; new b
                b                       ; new c
                (+ i 1)
                n)))
