# Self

Inside the class when `self` is used by an insatnce method it references the calling object. This is why when we use `self.` when invoking the setter method.

Using `self` inside the class but outside the insatnce method references the class itself. When we define class method `def self.this_is_a_class_method` is equivalent to
`def classname.this_is_a_class_method`.

We use `self` to be explicit about our intentions within code. within a class and inside an instance method `self` references the calling object. However, outside instance methods but still within the class `self` references the class itself. And within class methods, `self` also references the class.