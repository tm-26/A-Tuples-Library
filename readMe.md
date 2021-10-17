# A Tuples Library

One common usage of C programming is that of creating runtimes for higher level languages. These runtimes at minimum consist of a language interpreter/compiler, as well as a number of readily-available functions and data types. Python’s tuples, for e.g, are native to the language itself and are loosely based on the mathematical definition. An n-tuple is defined as an ordered list of elements, and is typically written as a sequence of elements enclosed in non-curly brackets: e.g. (2, 8, 200, 7) or <"physics", 75, "chemistry", 80> or [a, 1, b, 2, c, 3]. As shown in these examples, individual elements may be of a different type. Also, as per definition, (2, 8, 200, 7) ≠ (7,
200, 8, 2).

## Associated Operations

- **createTuple()** - Creates a tuple, as identified by a string identifier and a sequence of element type/values. In the case of an existing identifier, the new tuple replaces the existing one.
- **getTupleByID()** - Returns a pointer to a tuple_t object through its identifier.
- **getTupleID()** - Returns a tuple_t identifier through its pointer.
- **showTuple()** - Displays the tuple’s content through its pointer to tuple_t.
- **deleteTuple()** - Deletes a tuple_t object through its identifier.
- **cmpTuples()** - Compares two compatible tuples based on their inorder comparison of their elements, returning a positive integer in case the first non-equal element pair is larger for the first tuple, a negative integer in the opposite case, or 0 if all elements are equal. Compatible tuples are those with the same element number and types, or where the element number/types of the first is a prefix of the second.
- **joinTuples()** - Creates a new tuple, as identified by its string identifier, out of two pointers to existing tuple_t objects.
- **saveAllTuples()** - Saves all existing (created but not deleted) tuple objects to disk.
- **loadAllTuples()** - Loads all tuples from a saved file.
