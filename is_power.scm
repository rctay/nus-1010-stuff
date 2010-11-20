(define (is_power a b)
  (cond
    ((= a b)
     #t)
    (else
     (and (= (modulo a b) 0)
          (is_power (/ a b) b)))))

(is_power (expt 2 10) 2)
(is_power (* 2 (expt 3 3)) 3)