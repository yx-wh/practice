(define (count-change amount)
  (cc amount 5))

(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
	((or (< amount 0) (= kinds-of-coins 0)) 0)
	(else (+ (cc amount
		     (- kinds-of-coins 1))
		 (cc (- amount
			(first-denomination kinds-of-coins))
		     kinds-of-coins)))))

(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
	((= kinds-of-coins 2) 5)
	((= kinds-of-coins 3) 10)
	((= kinds-of-coins 4) 25)
	((= kinds-of-coins 5) 50)))

(define (display-change amount)
  (display (cc amount 5))
  (display "	")
  (display (cc amount 4))
  (display "	")
  (display (cc amount 3))
  (display "	")
  (display (cc amount 2))
  (display "	")
  (display (cc amount 1))
  (newline)
  (if (= amount 0)
    0
    (display-change (- amount 1))))

(display-change 100)