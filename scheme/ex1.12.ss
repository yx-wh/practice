(define (c a b)
  (cond ((= b 1) 1)
	((= b a) 1)
	(else (+ (c (- a 1) (- b 1)) (c (- a 1) b)))))

(define (print-row n a)
  (if (= a 0) 
    (newline)
    (begin 
      (display (c n a))
      (display "	")
      (print-row n (- a 1)))))

(define (print-pascal n)
  (if (> n 0)
    (begin 
      (print-pascal (- n 1))
      (print-row n n))))

(print-pascal 5)
;迭代版本使用二项式展开公式以及阶乘的迭代版本来进行计算。
