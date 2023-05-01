# Questions


**Q. How do we create an object in Ruby?**

A. In Ruby an object is created by defining a class and then instantiating it by calling the `::new` method on the class

*Example*

```ruby
class Engineer
end

sabtain = Engineer.new

```

**Q. What is a module? What is it's purpose? How do we use it with classes?**

A. A module is a collection of shared behaviours. It's purpose is to section off reuseable code into one place. A module is mixed in to a class where required by invoking the `include` method following the module name and now the class and it's objects have access to the behaviours defined within the module.

 Modules are used for name sapcing purposes. We can group related classes within a module and use namespacing when instantiating objects from the classes defined in the module. This helps in beign specifc when instantiating objects if there is another class defined with the same name.



