(define (factorize num)
  (define (prime? n)
    (if (<= n 3)
        #t
        (let loop ([i (floor (sqrt n))])
          (if (= i 1)
              #t
              (if (= (modulo n i) 0)
                  #f
                  (loop (sub1 i)))))))
  (let loop ([i 2] [n num] [result '()])
    (if (> i n)
        result
        (if (not (prime? i))
            (loop (add1 i) n result)
            (if (= 0 (modulo n i))
                ; keep decomposing
                (loop i (/ n i) (cons i result))
                (loop (add1 i) n result))))))


(factorize 19)
(factorize 4)
(factorize 77)
(factorize 300)
