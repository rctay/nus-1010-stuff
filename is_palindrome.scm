(define (normalize-string str)
  (string-foldcase
   (apply string
          (filter char-alphabetic?
                  (string->list str)))))

(define (is_palindrome word)
  (let ((len (string-length word)))
    (if (<= len 1)
        #t
        (and (equal? (string-ref word 0)
                     (string-ref word (sub1 len)))
             (is_palindrome (substring word 1 (sub1 len)))))))

(set! is_palindrome
      (compose is_palindrome normalize-string))

(is_palindrome "hi")
(is_palindrome "hiih")
(is_palindrome "hihi")
(is_palindrome "Was it a rat I saw?")
(is_palindrome "Go home emo hog!")
(is_palindrome "Si Nummi immunis.")