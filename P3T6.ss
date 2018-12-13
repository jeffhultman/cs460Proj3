(define (even_copy ls)
  (if (list? ls)
      (cond ( (null? ls) '())
            ( (null? (cdr ls)) '())
            (else (cons (car (cdr ls)) (even_copy (cddr ls))))
      )
  'even_copy_requires_a_list_argument
  )
)

(define (list_sum ls)
  (if (list? ls)
      (if (null? ls)
          0
          (if (number? (car ls))
              (+ (car ls) (list_sum (cdr ls)))
              (+ 0 (list_sum (cdr ls)))
          )
      )
      0
  )
)
