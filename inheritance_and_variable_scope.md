# Inheritance and variable scope

## instance variables

Instance variables behave similar to instance method when inherited, but the instance variables must be initialized first by calling the instance method that initializes it and only then the insatnce can access it. This implies that unlike insatnce methods, instance variables and their values are not inherited.

Example

```ruby
class Engineer
  def initialize(name)
    @name = name
  end
end

class Electrical < Engineer
  def info
    puts "#{@name} is an electrical engineer"
  end
end

engineer1 = Electrical.new('sabtain')

engineer1.info # => sabtain is an electrical engineer
```
In the above code we have a class `Engineer` and `Electrical` class which subclasses from `Engineer`.
We instantiate `engineer1` and call `Electrical.new`. As `Electrical` class does not have an `initialize` instance method, Ruby executes the inherited version which is in the `Engineer` class. That is how the `@name` instance variable is initialized and that is how we can access it from the `info` instance method within the `Electrical` class.

```ruby
module Draw
  def enable_drawing
    @can_draw = true
  end
end

class Engineer
  include Draw

  def draw
    puts "drawing" if @can_draw
  end
end

engineer1 = Engineer.new

engineer1.draw # nil

```
line 46 return `nil` because the insatnce variable `@can_draw` returns `nil` and the `if` caluse evaluates to false. The `@can_draw` return `nil` as the instance method `enable_drawing` in `Draw` module was not called and so the `@can_draw` instance variable was not initialized.

## class variables

A class variable initialized in a superclass is is available in the subclass. If the class variable is initialized outside an instance method, the class variable gets loaded when the class is evaluated by Ruby. If an unintalized class variable is referenced a `NameError` is raised.

There is only one copy of a class variable that is available across all sub-classes.

```ruby
class Engineer
  @@engineer = 2

  def self.info
    @@engineer
  end
end

class Civil < Engineer
  @@engineer = 3
end

puts Engineer.info # 3
```
line xx outputs `3` as on line `67` within the `Civil` class the `@@engineer` class variable is reassigned. This is because there is only copy of the class variable that is available across all the sub-classes. In the code above the class variable is initialized in the class so we do not need to call a method explicitly to initialize the class variable and it is loaded when Ruby evaluates the class.

Why use of class variables should be avoided. - eencapsulation and dependencies are threatned by class variables (and the way they are implemented in Ruby);  hard to contain and control the values of class variables - it's hard to track and control the values of class variables;  can create dependencies (creates 'couplings') in code base (where code is)

## consatnts

Ruby resolves consatnts by first searching the lexical scope of constant reference then the inheritance heirarcy of the structure that references the constant then finally the top level scope that is the main scope.

Lexical scope does not include the main scope.