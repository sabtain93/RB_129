class Animal
  def move
    "Walking"
  end
end

class Dog < Animal

end

class Cat < Animal

end


class Fish < Animal
  def move
    "Swimming"
  end
end

p Dog.new.move
p Cat.new.move
p Fish.new.move
