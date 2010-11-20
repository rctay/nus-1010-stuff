(define (is_ascending . args)
  (if (<= (length args) 1)
      #t
      (and (<= (car args) (cadr args))
           (apply is_ascending (cdr args)))))

(is_ascending 1 1)
(is_ascending 1 2 3 4)
(is_ascending 1 3 2)