# Method lookup

Whenever a method is called Ruby has a specific lookup path that it follows. By calling the `ancestors`
method on the class we can find out the method lookup chain.

## method lookup path

when a method is called the order in which ruby looks into classes is the method lookup path.

When inspecting the classes and modules in the method lookup path Ruby first looks into the calling object class then it looks into the module if any were included. The last module that was inculded in the class is looked into first.

Any modules included in the superclass is available to its subclasses.



