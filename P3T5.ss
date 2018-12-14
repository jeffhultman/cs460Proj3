(define (square n)
        (if ( number? n) (* n n) 'invalid_parameter))

        
(define (reciprocal n)
 (if (and (number? n) (not (= n 0)))
 (/ 1 n)
'invalid_parameter
 )
)
(square 5)
