# Class inheritance, Encapsulation, Polymorphism

## Encapsulation

Encapsulation is hiding of data and functionality so it is not available to the rest of the code in order to protect data from mainpulation without explicit intention. Through encapsulation we set boundries within our application.

In general terms encapsulation is the hiding of some data and functionality from rest of the program.

In Ruby we achieve encapsulation by creating object that encapsulate their state and behaviour and only expose the properties and behaviours that user of the object requires. Using method access control it is possible to expose methods(behaviours) through the public interface of the class which is the class's public methods.


The point of encapsulation is that we get the desired output by interacting with the public interface of the class and abstarcting away the implementation.

Encapsulating data into objects has two chief benefits:

It protects data from unintentional manipulation. In other words, in order to change data within an object there must be obvious intention behind doing so. It also means that we can restrict the way in which data is manipulated.

It allows us to hide complex operations while leaving a simple public interface to interact with those more complex operations.

```ruby
class Teacher
  def initialize(name, salary)
    @name = name
    @salary = salary
  end

  def info
    puts "#{name} earns #{salary}"
  end

  def high_salary?
    salary > 100_000
  end

  private
  attr_accessor :name, :salary
end

bob = Teacher.new("Bob", 125_000)
tom = Teacher.new("Tom", 125_000)

bob.info # Bob earns 125000
tom.info # Tom earns 125000

bob.high_salary? # true

bob.name # NoMethodError
tom.salary # NoMethodError
```

# What is encapsulation?
# Why is it useful?
# With reference to below code, explain how is it implemented in Ruby?
  # - How objects encapsulate with reference to below code?
  # - How classes encapsulate with reference to below code?

Encapsulation is the hiding of data and functionality from rest of the code base.

Through encapsulation data is protected from unintentional mainpulation. Moreover, we can restrict the way the data is mainpulated.

Encapsulation allows us to define boundries within our program and introduce a new layer of abstraction in our program in the way that the implementation details are abstracted away from the programmer.

Ruby implements encapsulation by creating objects that hide away some attributes and behaviours and exposing only those attributes and behaviours that users of object require to interact with this object.

In the above code the we have two objects `bob` and `tom` instantiated from the `Teacher` class. Each object's state is unique and is hidden within the object. `bob` and `tom` object state is tracked by their own instance variables which are `@name` and `@salary` and are only accessible within the object's instance methods. The string returned by the `#info` method invocation on `bob` and `tom` shows that each object can only access its own instance variables and this is how objects encapsulate their own state.

The `Teacher` class encapsulate behaviour in the way that the `#info` method is public, meaning that is accessible to user of the object, the getter and setter method for `@name` and `@salary` are set to private which is why they are not accessible outside the class. This is why when we invoke `#salary` getter method on `tom` object it raises a `NoMethod error`. The methods that expose the attributes of the object are encapsulated within the class and by exposing the `#info` method as public the user of the object can only access the object as the `#info` method only returns the values referenced by instance variable inerpolated in a string. This also shows how the implementation details are hidden away from the users of the object and exposing `#info` method as part of the class's public interface we make sure that data is not mainpulated.


## Ploymorphism

It is the ability for different types of objects to respond to a common interface. When two or more classes have a method of the same name and we can call that method with any of those objects.

Method overriding is way to implement polymorphism as object oriented programming provides flexibilty to use prewritten code for new objectives.

Ploymorphic structure can also be implemented by the use of Module. Modules contain shared behaviours but objects cannot be instantiated from them. The behaviours defined in a module can be made available to a class and its objects by mixin the module in the class by the use of include method invocation followed by the name of the module.

### Polymorphism through inheritance

*Example*

```ruby
class Engineer
  def draw
  end
end

class Civil < Engineer
  def draw
    puts "I draw maps"
  end
end

class Electrical < Engineer
  def draw
    puts "I draw electrical circuits"
  end
end

class Chemical < Engineer; end

class Industrial < Engineer; end


engineers = [Civil.new, Electrical.new, Chemical.new, Industrial.new]

engineers.each {|engineer| engineer.draw}
```
In the above code the array referenced by `engineers` has objects from different classes. The code that is using those objects doesn't care what each object type is but only care that each object in the array has a `draw` method that takes no arguments. The public interface lets us work with all the objects in the same manner even though the implementation may differ. This is polymorphism.

In the above code the `Chemical` and `Industrial` classes do not have a `draw` method of their own so they use the inhertited `draw` method defined in the superclass `Engineer`. This in polymorphism through inheritance as instead of writing a specialized version of `draw` method we are using the behaviour defined in the superclass that is accessible through inheritance.

The `Electrical` objects draw electrical circuits when we call `draw` on its objects and `Civil` class objects draw maps when `draw` is called on its objects. Here polymorphic sturucture can be observed as two different object respond to the same method call by overriding the method inherited from the superclass `Engineer`. As overriding is a feautre of inheritance so this is polymorphism through iheritance.

### polymorphism through duck typing

Duck Typing is an informal way of categorizing different unrelated object types based on a common behaviour that all those object types have. It occurs when objects of different unrelated types are able to respond to the same method invocation in the same manner.

Duck typing is a form of polymorphism. Duck typing is what happens when objects of unrelated classes can call a method of the same name with the same number of arguments. Duck typing lets us cagtegorize objects based on the methods calls they respond to.

Example

```ruby
class EngineeringProject
  attr_accessor :civil_work, :electrical_work, :piping_work
  def engineering_departments(departments)
    departments.each do |department|
      department.start_project(self)
    end
  end
end

class Civil
  def start_project(engineering_project)
    civil_work(project.civil_work)
  end

  def civil_work(civil_work)
    puts "started working on civil work"
  end
end

class Electrical
  def start_project(engineering_project)
    electrical_work(project.electrical_work)
  end

  def electrical_work(civil_drawin)
    puts "started working on electrical work"
  end
end

class Piping
  def start_project(engineering_project)
    piping_work(project.piping_drawings)
  end

  def piping_work(piping_drawings)
    puts "started working on piping drawings"
  end
end

project1 = EngineeringProject.new

project1.work([Civil.new, Electrical.new, Piping.new])

```
In the above example each of the class `Electrical`, `Civil`, and `Piping` have a `start_project` instance method.

From within the instance method `engineering_departments` defined in the `EngineeringProject` class we are calling the `start_project` on objects without concerning ourselves what the object type is, as long as the object can repsond to `start_project` method and take the same number of arguments. The classes defined in the above code are not related. But we know that whatever the object type is as long as it is `Electrical`, `Civil` or`Piping` project department it has the ability to work on the project. This is polymrphism through duck typing.

Duck Typing is an informal way of categorizing different unrelated object types based on a common behaviour that all those object types have. It occurs when objects of different unrelated types are able to respond to the same method invocation.

**One is polymorphism through inheritance. It is when there is a hierarical structure and the interface of the class hierarchy aids in working with the object types in the same way even though the implementation details may vary drastically.**

**second is polymorphism through duck typing. This is when objects of unrelated types repsond to the same method call. Here we are concerened if an object has a certain behaviour and not concerened with the object type. As long as the objects respond to the same method call and take the same number of arguments, we can categorize the objects to a specific type**

## Class Inheritance

The concept of inheritance is used in Ruby where one class inherits behaviours of another class. The class that is inherited from is referred to as the superclass. The class which inherits is called a subclass. Superclasses are defined with basic functionalities or generic behaviours with vast resuability where subclasses are defined for more detailed behaviours.

Inheritance is to put common behaviours from classes into one place, which is the superclass.

We use `<` symbol to show that a class inherits from a class. `class Dog < Animal` here the `Dog` class inherits from the `Animal` class.

When an instant method is called on an object, the calling object's class is looked into first for the instant method before Ruby checks the superclass. If a method in the superclass in defined in the subclass then this is called method **overriding**.

Class inheritance helps is eliminating duplication in code by extracting logic in one place.

### super

`super` keyword is used to call the method earlier in the method lookup path. When `super` is invoked from inside a method, it looks for a method with the same name in the method lookup path, and invokes it.

`super` is invoked 
1. with no arguments

example

```ruby
class Engineer
  def initialize(name)
    @name = name
  end
end

class Electrical < Engineer
  def initialize(age)
    super
    @age = age
  end
end
```
In the above code `super` is invoked with no arguments. In addition to its default behaviour it forwards all the arguments that were passed in to method from which `super` is called.

2. with appending `()`
  When called with empty paranthese, the method in the superclass is called with no arguments.

3. with fix arguments `(name, age)`
  When called with a specific set of arguments, the specified arguments will be forwarded up the method lookup chain.


## Class inheritance vs Interface Inheritance

Class inheritance is that one type inherits behaviour of another type. This results in a new type that specializes the type of the superclass.

Interface inheritance is the mixing in of modules. In this case the class does not inherit from another type but, inherits the interface that is given by the mixin module. In this case the result is not a specialized type with respect to the module.

Some pointers when choosing between class inheritance and interface inheritance

1. we can only subclass from one class, but mixin as many modules as we would want.

2. if there's an 'is-a' relationship then class inhertitance is best choice. if there's a 'has-a' relationship then interface inheritance is the choice to make.

