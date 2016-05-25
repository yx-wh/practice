(define (F a b c)
  (cond ((and (> a c) (> b c)) (+ (* a a) (* b b)))
	((and (> c a) (> b a)) (+ (* c c) (* b b)))
	((and (> a b) (> c b)) (+ (* a a) (* c c)))))
