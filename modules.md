# Modules

## What is a module?

A Module is a collection of shared behaviours. Behaviours contained by a module can be used in other classes by mixing in the module. A mixin module is included in a class by the `include` method invocation followed by the module name. Poloymorphism is also implemented by the use of modules.

Example:

```ruby
module Draw
  def draw
    puts "I can draw"
  end
end

class CivilEngineer
  include Draw
end

class TextileDesigner
  include Draw
end

sabtain = CivilEngineer.new
sabtain.draw # I can draw
misbah = TextileDesigner.new
misbah.draw # I can draw

```
In the above example we have a `CivilEngineer` object `sabtain` and a `TextileDesigner` object that we `misbah`. Now both objects can access the instance method `draw`. This is because the `draw` instance method is defined in `Draw` module which is mixed in both of the classes.

## Modules used for namespacing

Namespacing is to define similar classes within a module. This helps in recognizing classes that are related and minimizes the probability of our classes colliding with other classes of the same name in our program.

Example

```ruby
module Engineer
  class Electrical
    def build
      'I can build Electrical circuits'
    end
  end

  class Civil
    def draw
      "I can draw"
    end
  end
end

engineer1 = Engineer::Electrical.new

engineer2 = Engineer::Civil.new

puts engineer1.build
puts engineer2.draw
```

The classes defined within a module are called by appending the class name to the module name with two colons(::).

## Modules as containers for methods

Another use of modules is to use them to house methods that seem out of place in our code. These methods are called *module methods*. module methods are defined with prefixing `self.` to the method name and so they are called directly on the module itself.

```ruby
module Engineer
  def self.some_out_of_palce_method(string)
    puts string.upcase
  end
end

Engineer.some_out_of_palce_method('this is a module method')
# can also be called
# Engineer::some_out_of_place_method('string')
```