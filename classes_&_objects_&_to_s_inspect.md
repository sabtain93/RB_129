# 1. Classes and Objects

## Benfits of OO programming

Object Oriented programming is a programming pattern that deals with the growing complexity of large software systems by putting code into different sections that interact with each other and are not dependent on one another. So, if one section is manipulated it does not affect the rest of the program.

OOP is a programming pattern of programming that deals with the increasing complexity of large software application by creating sections of code that interact with each other rather than depnding on each other.

Using OOP we benifit from concepts like inheritance which lets us define basic classes which can used in various scenarios and defining subclasses are more detailed useabilty.

OOP helps in breaking down complex problems in a sysmatic manner. By defining classes sepcific to the problem and using real world nouns to name objects helps programmers to think on a higher level of abstraction.

Creating objects allows programmers to think more abstractly about the code they are writing.
Objects are represented by nouns so are easier to conceptualize.
It allows us to only expose functionality to the parts of code that need it, meaning namespace issues are much harder to come across.

It allows us to easily give functionality to different parts of an application without duplication.
We can build applications faster as we can reuse pre-written code.
As the software becomes more complex this complexity can be more easily managed.

## What is an object?

In Ruby everything is said to be an object. But not everything is an object. Anything that is can have a value is an object such as array, strings, numbers and even classes and modules. A few things that are not objects are blocks, methods and variables.

Objects are created from classes and we can think of classes as cast from which objects are produced from. objects instantiated from a class contain different infromation from other objects of the same class.

## Classes define objects

A class in Ruby defines the attributes and behaviours of its objects. So by looking at a class we know what its objects are made of and what are the behaviours they will have.

A class is defined by writing `class` followed by the name of the class. Class name are in CamelCase naming convention. Then we use the reserved word `end` to end the definition. The file name should reflect the name of the class in sanke_case.

```ruby
class Engineer
end

sabtain = Engineer.new
```
In the above code the Engineer class is defined and on line 23 an object of Engineer class is created and is stored in variable `sabtain`. `sabtain` is an object of the `Engineer` class. The entire process of object creation is known as `instantiation` and we can say that we have instantiated an object called `sabtain` from the `Engineer` class. An object is returned by calling the class method `::new`.


## State and Behaviours

Classes are used to create objects. When a class is defined two main points are of focus, the state and behaviours. The state refers to the data that is associated with the instance of the class and behaviour is what the object of the class have the ability to do.

The state of an object is tracked by instance variables. If there are two objects instantiated from a class, they are both objects of the same class but may contain different information for the indiviual object, such as name, height, weight. ==So, instance variables are used to track the state of indiviual object and this tells us that instance variables are scoped at the object or instance level==.

The two objects are seprate objects but are instances of the same class and so the they share behaviours that are defined as insatnce methods in a class. ==Instance methods defined in class are accessible to the objects of that class==.

> Instance methods are used to expose behaviours for objects & instance variable track the state of the object.

## Initializing a new object

An object is created by defining a class and instantiating from it by calling the `::new` class method on the class. By calling `new` the `initialize` instance method gets called. The `initialize` method is refered to as the **constructor**, as it builds the object when an object is insatntiated.

We can pass arguments into the `initialize` method through the `new` method.

## to_s method

The `to_s` instance method is built in to every class in Ruby.
calling `puts` automatically invokes the `to_s` method on its argument. By default the `to_s` method returns the name of the object's class and an encoding of object_id. We can override the instance method `to_s` by defining it in our custom class.

The `to_s` method is autoamtically called in string interpolation.

## p and inspect

When we invoke `p` the built in instance method `inspect` is called on its argument. By default the `inspect` instance method returns the string representation of the object which includes the class name, object_id, the instance variables and their values associated with that object.

