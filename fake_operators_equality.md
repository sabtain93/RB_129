# Fake Operators and Equality

## Equivalence

The `==` is method that each class inherits from the `BasicObject` class. The `==` checks if the calling object and the object passed to it as an argument are the same objects. The classes in the Ruby core library for example the String or Integer class override this method and implement it in such a manner that the value of the calling object is compared to the value of the object passed to it. So, each class should implement its own `==` method to specify which values to compare.

When we define the `==` is our class the `!=` method comes with it.

This is why in the below code line 12 return `True` eventhough the string objects referenced by str1 and str2 are different objects.

```ruby
str1 = 'sabtain'
str2 = 'sabtain'

str1 == str2 # => True
```
## equal?

The `equal?` method checks if the calling object and the object passed to it as an argument are the same objects.

## === method

The `===` is also a method which is implicitly called by the case statement for comaprison.

Example

```ruby
String === 'sabtain' # => true
```
the above return true as `'sabtain'` is part of the group that is the String class. In other words `sabtain` is an instance of the calling object which is the `String` class. This implemetation can be seen in the `Module` class as `String` is an object of class `Class` which inherits from `Module`.

So we have to look into the object class in on which the `===` method is called.

But for Ranges the `===` method checks if the argument passed is inlcude in the group which is the calling Range obejct.

## eql?

The equality comparison method `eql?` checks if the two objects have the same value and that they belong to the same class. Used implicity by Hash.

## Fake operators

