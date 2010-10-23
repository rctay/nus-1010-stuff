(define (elevator lst level)
  (define (gap l1 l2)
    (abs (- l1 l2)))
  (cond
    ((null? lst)
     -1)
    ((= 1 (length lst))
     0)
    (else
     (let ((rem-index (add1 (elevator (cdr lst) level))))
       (if (< (gap (car lst) level)
              (gap (list-ref lst rem-index) level))
           0
           rem-index)))))

(elevator '(1 2 3 4) 7)
(elevator '(1 9 12) 2)