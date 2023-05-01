# Instance variable, class variables & Constants

## Instance variables

Instance variable has a `@` symbol infront of its name, e.g. `@age` is an instance variable. Objects are connected to data through instance variables.

An instance variable initialize in the `initialize` method can be referenced and used within the class as long as the object is not destroyed. 

### Scope of instance variable

Instance variable has a `@` symbol infront of its name, e.g. `@age` is an instance variable. Objects are connected to data through instance variables.Every object's state is disticnt, and we track indiviual objects' state through instance variables. 

An object cannot access the instance variable of another object. Instance variables are scoped at the object level, this means that an instance variable is accessible in an object's insatance method, even if it was initialized outside of that instance method.

```ruby
class Engineer
  def initialize(type)
    @type = type
  end

  def type
    @type             # @type insatnce variable is accessible here
  end
end

engineer1 = Engineer.new('Electrical')
puts engineer1.type # PRINTS OUT - Electrical
```

Instance variables can be accessed within an instance method even if it they are not initialized or passed to it, which is a behaviour different from local variables. Another distiction from local variables is that if an uninitialize instance variable is referenced we get `nil` but in case of unintialize local variable we would get a `NameError`.

Instance variables are initialize within instance methods. If a instance variable is intialized at class level it is an entirely different thing called a class instance variable.


## Class variable

Class variables are used to track class level detail that only concern the class and not indiviual objects. Class variables are scoped at the class level.

Class variables are created using two `@` symbols `@@number_of_objects` is a class variable.

```ruby
class Engineer
  @@number_of_engineers = 0         # initialized at class level

  def self.total_number_of_engineers
    @@number_of_engineers               #accessible from class method
  end

  def initialize
    @@number_of_engineers += 1        # reassigned from instance method
  end

  def total_engineers
    @@number_of_engineers             # accessible from instance method
  end
end

puts Engineer.total_number_of_engineers # => 0

engineer1 = Engineer.new
engineer2 = Engineer.new

puts Engineer.total_number_of_engineers # => 2
puts engineer1.total_engineers # => 2
puts engineer2.total_engineers # => 2
```

In the above code we create a class `Engineer`. In it we initialize the class variable 
`@@number_of_engineers` to `0`. Then in our constructor we increment it by 1, as the `initialize` method is called each time we instantiate a new object through the `new` method. **this demonstrates that we can access class variables inside the instance method (`initialize` is an instance method)**.
Then we just return the value of the class variable in the class method `self.total_number_of_engineers`. We have used class variable and class method to track class level detail that do not concern the indiviual objects of the class.

In the above code it can be seen that we have two different objects `engineer1` and `engineer2` and we are accessing and updating one copy of the `@@number_of_engineers` class variable. Only calss variables have the ability to share state between objects.

### Behaviours of class variables

1. All objects share 1 copy of a class variable and so an object can access class variable by means of instance method.

2. A class method can access a class variable if it is initialized before the method is called.

## Constants

constants are variables that reference value that will not change. Constants are defined using an uppercase letter at the begining but Rubyist tend to make all the letters in the constant name upcassed.

Consatnts have a lexical scope. Lexcial scope implies that where the constant is defined in the code determines where it is available. Ruby resolves a constant by searching lexically, that is it searches the surrounding structure of the constant reference.

```ruby
class EngineeringOffice
  DEPARTMENTS = ['civi', 'electrical', 'mechanical']

  def self.departments
    DEPARTMENTS.join(', ')
  end

  def department
    DEPARTMENTS.sample
  end
end

puts EngineeringOffice.departments

puts EngineeringOffice.new.department

```

In the above code the `DEPARTMENTS` constant is referrenced on line 91 and 95, so to resolve the consatnt RUBY searches the surrounding source code and as it is initialized on line `88` inside the `EngineeringOffice` class it is can be accessible in both `EngineeringOffice::departments` class method and the `EngineeringOffice#department` instance method.

When a constant is referenced in a unrelated class a`NameError` is thrown as the constant is not included in the lexical search and also not included in the consatnt lookup path.

Unlike class variables and instance variables we can reference to a consatnt that is initialized in an unrelated class by using the `::` Namespace resolution operator. This is how we tell RUBY where to search for the consatnt that is referenced.



