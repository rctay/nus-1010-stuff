(define (set-remove set item)
  (define (loop rem result)
    (if (null? rem)
        result
        (let ((curr (car rem)))
          (if (eq? curr item)
              ; assume well-formed set
              (append (cdr rem) result)
              (loop (cdr rem) (cons curr result))))))
  (loop set '()))

; alternative set-remove
(define (set-remove set item)
  (remq item set))

(define (permutate set)
  (cond
    ((null? set)
     '())
    ((= 1 (length set))
     (list set))
    (else
     (apply append                                 ; flatten
            (map (lambda (item)
                   (map (lambda (combi)
                          (cons item combi))
                        (permutate
                         (set-remove set item))))
                 set)))))

(permutate '(1 2 3 4))

; return a boolean, not the rest of the list
(define (memq? lst item)
  (not (not (memq item lst))))

(define (make-set initial)
  (define self
    (let ((items '()))
      (lambda (message . args)
        (apply
         (case message
           ((contains?)
            (lambda (item)
              (memq? items item)))
           ((empty?)
            (lambda ()
              (null? items)))
           ((length)
            (lambda ()
              (length items)))
           ((add!)
            (lambda (item)
              (if (not (self 'contains? item))
                  (set! items (cons item items))
                  #f)))
           ((remove)
            (lambda (item)
              (make-set (remq item items))))
           ((items)
            (lambda ()
              items)))
         args))))
  
  ; add initial values
  (for-each (lambda (item)
              (self 'add! item))
            initial)
  
  ; return
  self)

(define (permutate set)
  (cond
    ((set 'empty?)
     '())
    ((= 1 (set 'length))
     (list (set 'items)))
    (else
     (apply append                                 ; flatten
            (map (lambda (item)
                   (map (lambda (combi)
                          (cons item combi))
                        (permutate
                         (set 'remove item))))
                 (set 'items))))))

(permutate
 ; intentional duplicate item
 (make-set '(1 2 3 4 1)))