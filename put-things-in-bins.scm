(define (put-things-in-bins things bins)
  (define (helper rem pos lst)
    (cond
      ((>= pos bins)
       (list
        (cons rem (cdr lst))))
      ((<= rem 0)
       (list
        (append
         (build-list (- bins pos) (lambda (x) 0))
         lst)))
      (else
       (append
        (helper (- rem 1)
                pos
                (cons (add1 (car lst))
                      (cdr lst)))
        (helper rem
                (+ pos 1)
                (cons 0 lst))))))

  (define result
    (helper things 1 '(0)))

  ; check that all combinations add to <things>
  (let assert ((perms result))
    (unless (null? perms)
      (let ((curr (car perms)))
        (if (= (foldl + 0 curr) things)
            (assert (cdr perms))
            (error "bad permutation:" curr)))))

  result)

; 462
(length (put-things-in-bins 5 7))

; 15
(length (put-things-in-bins 4 3))
