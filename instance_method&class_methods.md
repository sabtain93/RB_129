# Insatnce method vs class method

## Instance Method

Instance methods are defined in a class and they refer to the behviours that the objects of that class will posses. Objects of the same class share behviours though they may have different states

Example

```ruby
class CivilEngineer
  def initialize(name)
    @name = name
  end

  def draw
    "I can draw"
  end
end

engineer1 = CivilEngineer.new('sabtain')

puts engineer1.draw
```
In the above code `engineer1` is an object instantiated from the class `CivilEngineer`. When the instance method `draw` is called on the object `engineer1` the string `I can draw` is output by `puts`. This tells us that objects have access to the instance methods defined in the class from which it is instantiated.

If we had a second object, that object will also have access to the instance method `draw` as objects of the same class have same behaviours, though their state may differ, which in this case is the state name.

We can expose the state of the object by means of instance methods. The insatnce methods have access to the instance variables. So we can refer to the instance variable within the instance method.

> instance methods are methods that pretain to the objects of the class


## Class methods

class methods are defined on the class and are called directly on the class itself, without instantiating any objects

Defining a class method we prepend the reserved word `self.` to the class method name. Class method are where we put functionality that is not related to the insatnces of the class.
