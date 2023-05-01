# Accessor Methods

If we wanted to just print out the state of an object e.g. name, so we need an instance method that just returns the value associated with the `@name` instance variable which can be called from outside the class. By convention we define the getter method with same name of the instance variable that it is exposing.

Example

```ruby
class CivilEngineer
  def initialize(name)
    @name = name
  end

  def name
    @name
  end

  def draw
    "I can draw"
  end
end

engineer1 = CivilEngineer.new('sabtain')

puts engineer1.draw
puts engineer1.name
```

In the above code on line 25 we are calling the getter method for the instance variable @name, which is defined on line 13.

Now if we wanted to change value associated with the state name for the object `engineer1`, we have to define a setter method from which we can reassign the instance variable `@name`.

Example

```ruby
class CivilEngineer
  def initialize(name)
    @name = name
  end

  def name
    @name
  end

  def name=(new_name)
    @name = new_name
  end

  def draw
    "I can draw"
  end
end

engineer1 = CivilEngineer.new('Sabtain')

puts engineer1.draw
puts engineer1.name
engineer1.name = 'Ali'
puts engineer1.name
```

In the above code we are calling the setter method `name=` for the instance method `@name` on line 57.
The way that we call the setter method is Ruby syntactical sugar.

> **setter methods always return the value that is passed in as an argument, not caring about what happens within the method. If we try to return something else Ruby ignores it.**

## attr_*

In Ruby there is a built in way to create getter and setter methods by using the `attr_accessor` method.

```ruby
class CivilEngineer
  attr_accessor :name

  def initialize(name)
    @name = name
  end

  def draw
    "I can draw"
  end
end

engineer1 = CivilEngineer.new('Sabtain')

puts engineer1.draw
puts engineer1.name
engineer1.name = 'Ali'
puts engineer1.name
```
The `attr_accessor` method take a symbol as an argument, which is used to create the method name for setter and getter methods.

`attr_reader` is used to only create getter method, now the instance variable can only be retieved

`attr_writer` is used to only create setter method, now the instance variable can be set to a new value.

## Accessor method uses

Instead of referencing the instance variable in instance method we can reference the getter method for that instance variable. By not referencing the instance variable directly we can chose to only expose the part of the value referenced by the instance variable that is required by tweaking the value in the getter method.

The setter methods can be used in the same manner, wherever we want to change the value of the instance variable within the class use the setter method.

When calling the setter method we call it on `self` as this tells Ruby that a method is begin called and we are not setting a local variable.

Prefixing `self.` is not restricted to calling setter and getter methods but can be used to call any instance method.