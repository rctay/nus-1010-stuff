(define (push lst val)
  (append lst (list val)))

(define n-choose-k
  (let* ([<=1deep? (lambda (lst)
                     (and (list? lst)
                          (not (list? (car lst)))))]
         [append-2d (lambda (lst1 lst2)
                      (if (<=1deep? lst1)
                          (append (list lst1) lst2)
                          (append lst1 lst2)))])
    (lambda (n k)
      (define (choose-at-pos left pos comb)
        (cond ((> pos k) ; we shouldn't reach here, but just in case
               comb)
              ((= pos k) ; ensure that *all* are used
               (push comb left))
              (else
               ; at this position, iterate all possible counts
               (let loop ([j left] [result '()])
                 (if (< j 0)
                     result
                     (loop (sub1 j)
                           (append-2d
                            ; advance position
                            (choose-at-pos (- left j)
                                           (add1 pos)
                                           (push comb j))
                            result)))))))
      ; entry point
      (choose-at-pos n 1 '()))))

(n-choose-k 5 4)