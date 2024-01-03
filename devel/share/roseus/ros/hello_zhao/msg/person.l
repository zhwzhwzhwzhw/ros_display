;; Auto-generated. Do not edit!


(when (boundp 'hello_zhao::person)
  (if (not (find-package "HELLO_ZHAO"))
    (make-package "HELLO_ZHAO"))
  (shadow 'person (find-package "HELLO_ZHAO")))
(unless (find-package "HELLO_ZHAO::PERSON")
  (make-package "HELLO_ZHAO::PERSON"))

(in-package "ROS")
;;//! \htmlinclude person.msg.html


(defclass hello_zhao::person
  :super ros::object
  :slots (_name _age _height ))

(defmethod hello_zhao::person
  (:init
   (&key
    ((:name __name) "")
    ((:age __age) 0)
    ((:height __height) 0.0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _age (round __age))
   (setq _height (float __height))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; int32 _age
    4
    ;; float32 _height
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; int32 _age
       (write-long _age s)
     ;; float32 _height
       (sys::poke _height (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int32 _age
     (setq _age (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _height
     (setq _height (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get hello_zhao::person :md5sum-) "0478132ca0c3bd1c734b5491000dabb1")
(setf (get hello_zhao::person :datatype-) "hello_zhao/person")
(setf (get hello_zhao::person :definition-)
      "string name
int32 age
float32 height
")



(provide :hello_zhao/person "0478132ca0c3bd1c734b5491000dabb1")


