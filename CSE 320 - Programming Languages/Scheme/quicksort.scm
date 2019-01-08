(define (quicksort array)
  (if (null? array) array
    (let ((pivot (car array))) 
      (let 
        ((lower 
           (quicksort (filter (lambda(x) (<  x pivot)) (cdr array))))
         (higher
           (quicksort (filter (lambda(x) (>= x pivot)) (cdr array)))))
          (append lower (list pivot) higher)))))

(define int-array 
  (call-with-input-file "IntArray.txt"
    (lambda (input-port)
      (let loop ((x (read-line input-port)) (int-arr ()))
        (if (not (eof-object? x))
            (begin
              (loop (read-line input-port) (cons (string->number x) int-arr)))
            int-arr)))))

(quicksort int-array)