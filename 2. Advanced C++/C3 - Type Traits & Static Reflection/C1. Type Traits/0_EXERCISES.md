# Exercises

1. "Is Vector Trait" (Easy)
   - Create a custom type trait named "is_vector" that detects whether a type is a `std::vector`.
   - The trait should be defined as a public static constexpr bool member variable named "value", where the value is true if the type is a `std::vector`, and false otherwise.
   - Test the trait with a few sample types, including a `std::vector`, and verify that the value is correctly detected.

2. "Type Size Trait" (Moderate)
   - Create a custom type trait named "type_size" that determines the size (in bytes) of a given type.
   - The trait should be defined as a public static constexpr size_t member variable named "value", where the value is the size of the type in bytes.
   - Test the trait with a few sample types, including fundamental types and custom classes, and verify that the size is correctly determined.

3. "Enable If Trait" (Difficult)
   - Create a custom type trait named "enable_if" that conditionally enables a template function based on a boolean expression.
   - The trait should be defined as a public template with a single typename parameter named "T" and a boolean parameter named "B".
   - If "B" is true, the template should define a public typedef named "type" that is equivalent to "T". If "B" is false, the template should not define a "type".
   - Use the trait in a template function that takes two arguments of type "T" and an additional template argument of type "B". The function should only be enabled if "B" is true, and should return the sum of the two arguments.
   - Test the trait with various boolean values and types, and verify that the function is correctly enabled and disabled based on the trait's condition.