# Exercises

1. "Print members"
    
    Write a function that takes a struct type as a template parameter and prints the names and types of all its non-static data members to the console. For example, given a struct `Person` with members `name` (of type `std::string`), `age` (of type `int`), and `is_student` (of type `bool`), the function should output:
```
name: std::string
age: int
is_student: bool
```

2. "Serialize object"
    
    Write a function that takes an object of a struct type as a parameter and serializes its non-static data members to a JSON string. For example, given a struct `Person` with members `name` (of type `std::string`), `age` (of type `int`), and `is_student` (of type `bool`), the function should output a string like this:
```
{"name": "John Smith", "age": 25, "is_student": false}
```

3. "Generic factory"
    
    Write a generic factory function that takes a string representing the name of a struct type and a set of arguments, creates an object of that struct type with the given arguments, and returns a pointer to the object. For example, given a struct `Person` with a constructor that takes a `std::string` and an `int` argument, the factory function should be able to create a `Person` object like this:
```
auto person_ptr = factory<Person>("John Smith", 25);
``` 

Note that the second and third exercises require more advanced knowledge of static reflection and may be more difficult to implement.