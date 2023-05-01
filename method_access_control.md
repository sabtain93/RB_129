# Method Access Control

Method access control is a way to allow or restrict access to methods defined in a class. We can limit access to methods defined in our class with the help of access modifier, that are `public`, `private` and `protected`.

Public method are available to anyone who either knows the class name or object's name, they comprise the public interface of the class. Public methods are available to be used by the rest of program and that is how other classes and objects interact with this class and its objects.

If a method is working in our class but is not required to be accessed outside the class it can be defined as `private` method. We define private methods in our class by calling the `private` method and any methods defined under it are set to private. Private methods are only accessible through other methods that are public, and can only be called for the current object.

protected methods are similar to private method that they cannot be called from outside the class but can only be called from within the class through public methods. Protected methods are different from private methods in the way that protected methods allow access between objects of the class (or subclass).