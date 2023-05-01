# Specific Topics of Interest

1. Classes and objects

  - classes are like molds, and what come out of the mold is an object.
  - classes create objects
  - classes define the attributes and behaviours of its objects
  - objects insatntiated from the same class contain different information
  - objects of the same class share the behaviours deined in the class.

2. Use attr_* to create setter and getter methods
  - setter and getter methods are required to access or modify state of an object.
  - The attr_accessor method takes a symbol as an argument, which is used to create the name for the setter and getter methods
  - attr_reader, this gives us only a getter method, so the value referenced by the instance variable can only be retrieved.
  - attr_writer, this give us only a setter method,  now the instance variable can be set to a new value.
  - By calling the getter method instead of referencing the instance variable we can expose only a part of the value referenced by that-  instance variable by tweaking the value in the getter method and returning the tweaked value.
  - By calling the setter method we can validate the data that is passed in before assigning the value passed in to the instance variable.

3. How to call setters and getters
  - getter methods are implicity called on `self`, the calling object
  - when calling setter method we explicitly call it on `self`, this so that ruby can differentiate between calling the setter method and initializing a local variable.
  - setter methods always return the argument passed to it.

4. Instance variables, class variables, and constants, including the scope of each type and how.
  ### instance variable
    - instance variables are defined by putting an `@` in front of their name.
    - objects are connected to data through instance variables
    - each object has a unique state, and an object's state is tracked through its instance variables
    - object cannot access instance variables of another object
    - Instance variables are scoped at the object level, they are available in an objects instance method even if the instance variable was not initialized in that instance method
    - instance variables are accessible in the object's instance method even if was not initialized in it or passed to it
    this is a difference between local variables and instance variables
    - referencing an uninitialzied instance variables returns `nil`.

  ### class variables
    - class variables are defined by putting two `@@`
    - class varibles are used to track class level details that concern the class only and not indiviual objects.
    - class variables are scoped at the class level

    - All objects share a signle copy of the class variables and so object can access class variables by mean of instance methods.
    - A class method can access a class variables if it is initialized before the class method is called.
    - Referencing an uninitialized class variable raises an error.

    ### constants
      - consatnts are variables that reference values that will not change.
      - They are defined with all letters in its name upcassed
      - constant have lexical scope, where it is defined determines where it it available
      - Ruby resolves a constant by searching lexically, that is it searches the surronding structure of the constant reference.

      - when a constant is referenced in an unrelated class a name error is thrown as the consatnt is not included in the lexical search and not in the consatnt lookup path
      - unlike class variables and instance variables we can reference a constant defined in an unrelated class by the consatnt resolution operator, this is how we tell Ruby where to search for the constant that is referenced.


5. inheritance can affect that scope
  ### instance variables
    - instance variables and their values are not inherited, the instance variable must be initialized first by calling the instance method in which it is initialized and only then it can be accessed by the instance.

  ### class variables
    - class variables initialized in a superclass is availables in the subclass.
    - there is 1 copy of the class variable that is available across all subclasses.
    - if a class variable is initialized outside an instance method, it is loaded when the class is evaluated by Ruby.

  ### constants
    - Ruby resolves the consatnt by first searching lexically where the consatnt is referenced, then in the inheritance heirarcy of the structure where the consatnt is referenced, and the top level scope.

6. Instance methods vs. class methods

  ### Instance methods
    - instance methods are method that are defined in the class and they refer to the behaviors of the objects of that class.
    - instance methods are methods that pretain to the objects of the class.
    - As objects of the same class have same behaviors that are defined as instance methods in the class, all objects of that class can access the instance methods even though each object has a unique state.

    - we can expose the state of the object by means of instance methods. instance methods have access to instance variables so by referring to the instance variables within the instance method we can expose the state of the calling object.

  ### class methods
    - class methods are methods that are defined on the class, they are called on the class itself without instantiating any object

    - class methods are defined by prefixing `self` to their name.
    - class methods are where we put functionality that is not related to the instances of the class.

7. Method Access Control
  - it is a way to allow or restrict access to methods defined in the class.
  - it is implemmented with the help of access modifiers
  - access modifiers are `public`, `private` and `protected`

  - public methods
    - which are accessible to anyone who either knows the name of the class or name of the objects of that class
    - the public interface of the class comprises of the public mthods defined in that class.
    - this is how other objects and classes interact with this class and its objects
    .(they are available to be used by the rest of the program.)

  - private methods
    - If a method is working in our class but is not required to be access from outside the class it can be defined as private
    - private methods are defined by invoking the `private` method and any method defined underneath are set to private.
    - private methods are only accessible through other methods that are public and can only be called on the current object.

  - protected
    - protected methods are similar to private methods that they cannot be called from outside the class
    - they are accessible through other methods that are public
    - they are different from private methods as they allow access between the instance of the class or subclass.

8. Referencing and setting instance variables vs. using getters and setters

9. Class inheritance, encapsulation, and polymorphism
  - ### class inheritance
    - It is the concept where one class inherits the behaviours from another class
    - The class that inherits is the subclass and the class from which it inherits is the superclass
    - superclasses are defined with basic behaviors with a vast reusability
    - subclasses are defined with a more fine granied behavior
    - It helps in eliminating duplication by extracting logic into one place.

  - ### interface inheritance
    - interface inheritance is the mixing in of modules.
    - in this case one type does not inherit from another type, but inherits the interface given by the mixin module.
    - in this case the result is not a specialized type with resepct to the module

  - we can only subclass from one class but mix in as many modules
  - If there is a `is-a` realtionship then class inheritrance is the best choice
  - if there is a `has-a` relationship then interface inheritance is the choice to be made

  ### encapsulation
    - In general terms encapsulation is the hiding  of some data and functionality from rest of the program.
    - In ruby encapsulation is implemented through creation of objects that hide some attributes and behaviors and exposing only those attributes and behaviors that the users of the object require to interact with the object.

    - Through encapsulation data is protected from unintentional mainpulation. Moreover we can restrict the way data is mainpulated
    - encapsulation allows us to define boundries within our program and introduce a new layer of abstraction in the way that the implementation details are abstracted away from the user of the class.
    - Objects encapsulate their own state
    - classes encapsulate behavior

  ### polymorphism
    - It is the ability for different types of objects to respond to a common interface.
    - It occurs when two or more classes have a method of the same name and we can call that method with any of those objects.

        #### polymorphism through inheritance
        **polymorphiem through class inheritance**
        - If we have different object that all respond to the same method call in the same way and they are related through inhertitance. Now these object types have the common method through either directly inherting the method from superclass or overriding the inherited method. This way we achieve polymorphism through inhertitance
        **polymorphims through interface inheritance**
        - This is when different object types can call a method of the same name in the same manner. Now the methods are accessible to the object types through mixing in a module which defines that method.

       #### polymorphism through ducktyping
       - Duck typing is an unofficial way of categorizing different unrealted objects types based on a common behavior that all those object types have. It occurs when different unrealted objects are able to call the same method in the same manner.

       ### Benefits
      - Code reusability and flexibility
        - can invoke methods on groups of objects without worrying about caller's object type
      - less dependency
      - increased maintainability
      - more extensible code
        - can extend behavior of code without breaking functionality.

10. Modules
  ### mixin
     - a mixin module is a collection of shared behaviors
     - The behaviors defined in the module are inculded in the class by invoking the `include` method invocation

     - It helps us keeping the code dry
     - we can mixin as manyb modules as required
     - if we have a class inheritance and there is a behavior that is not required by all the subclasses and so cannot be 
       defined in the superclass. So we define that method within a mixin module and include the module in the classes that require that behavior.
     - if we have classes that are not realated through class inheritance but there is behavior that is common between these 
       unrelated classes, by definig that behavior within a module and including the module in those classes we elminate duplication of code.


  ### modules used for namespacing
    - namespacing is to define similar classes under a module
    - This helps in recognizing classes that are related and it eliminates the probabilty of similarly named classes collinding in our program
    - we refer to the classes define under a module by prepending the class name with the module name and `::`.

  ### modules as containers for method
  - We can house methods that seem out of place within the module. These methods are defined on the module by prefixing `self.` to their names. They are called module methods and they are called directly from the module.

11. Method lookup path 
  - The order in which Ruby inspects the classes when a method is invoked is the methods lookup path
  - By invoking the `ancestors` method on a class we can see its method lookup chain
  - when a method is invoked Ruby first looks for the method in the class of the calling object, then in the modules included in the class starting with the last module that was included, then it looks in the superclass and then further up the inheritance hierarcy.

12. self

  Inside the class within the insatnce method `self` refers to the calling object
  Inside the calss but outside the instance method `self` refers to the class itself.

13. Calling methods with self

14. More about self

15. Reading OO code

16. Fake operators and equality

17. Working with collaborator objects

  A collaborator object is an object that is stored within the state of another object. An object's state is tracked by its instance variable, so an object that is assigned to an instance variable of an object is a collaborator object

  collaboration is a way of modelling relationship between object types that have an associative raltionship. collaborator objects have a `has-a` realtionship. e.g. a libarary has books, a team has memebers, a deck of cards has cards.

  collaborator object is an important aspect of oo design as it represents the connection between various building blocks within our program. It lets us breakdown the problem into a smaller problem. By doing we can work on the smaller problems sepratley. Then brigning each building block togather to solve the problem at hand.

18. Create a code spike