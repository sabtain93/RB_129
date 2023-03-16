# Class inheritance, Encapsulation, Polymorphism

## Encapsulation

Encapsulation is hiding of data and functionality so it is not available to the rest of the code in order to protect data from mainpulation without explicit intention. Through encapsulation we set boundries within our application.

In Ruby we achieve this by the creation of objects and exposing interfaces to interact with those objects. By doing so programmers can think on a new level of abstraction.

## Ploymorphism

It is the ability for different types of objects to respond to a common interface.

Method overriding is way to implement polymorphism as object oriented programming provides flexibilty to
use prewritten code for new objectives.

The concept of inheritance is used in Ruby where one class inherits behaviours of another class. The class that is inherited from is referred to as the superclass. The class which inherits is called a subclass. Superclasses are defined with basic functionalities or generic behaviours with vast resuability where subclasses are defined for more detailed behaviours.

Ploymorphic structure can also be implemented by the use of Module. Modules contain shared behaviours but objects cannot be instantiated from them. The behaviours defined in a modules can be made available to a class and its objects by mixin the module in the class by the used of include method invocation followed by the name of the module.
