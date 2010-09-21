(define (count-candles n k)
  (let loop ([rem n] [count n])
    (let ([curr (- rem k)])
      (if (positive? curr)
          ; continue
          (loop (add1 curr) (add1 count))
          ; stop
          count))))

(count-candles 6 3)
