# C++ Module 06 - C++ Casts

## Overview
This module explores the four different types of type casting introduced in C++, moving away from the dangerous and implicit C-style casting (`(type)value`). 

The exercises are designed to teach you exactly when and how to use `static_cast`, `reinterpret_cast`, and `dynamic_cast`.

## Key Concepts

### 1. `static_cast` (Exercise 00)
**What it does:** Performs conversions between compatible types at compile-time.
**When to use it:** When converting between scalar types (e.g., `float` to `int`, `char` to `double`), or when upcasting/downcasting in an inheritance hierarchy where you are 100% sure the types are compatible (though `dynamic_cast` is safer for downcasting).
**Why it's better than C-style cast:** It is checked by the compiler. If you try to `static_cast` completely unrelated types (like a `float*` to an `int*`), the compiler will throw an error, preventing dangerous memory operations.

### 2. `reinterpret_cast` (Exercise 01)
**What it does:** Reinterprets the raw bit pattern of a value as another type at compile-time.
**When to use it:** When doing low-level memory manipulation, networking, or serialization. For example, converting a pointer to an integer (`uintptr_t`) so it can be transmitted, and then casting it back to a pointer later.
**Why it's dangerous:** It performs absolutely no checks. It simply tells the compiler "treat these bits as if they were this other type." If used incorrectly, it will cause segmentation faults.

### 3. `dynamic_cast` (Exercise 02)
**What it does:** Safely downcasts polymorphic base pointers/references to derived class pointers/references at run-time.
**When to use it:** When you have a `Base*` and you need to know if it's actually pointing to a `DerivedA` or `DerivedB` object before calling a method specific to the derived class.
**Requirements:** The base class *must* have at least one virtual function (making it polymorphic) because `dynamic_cast` relies on RTTI (Run-Time Type Information) stored in the vtable.
**Handling Failure:**
- If casting a **pointer**, it returns `NULL` on failure.
- If casting a **reference**, it throws a `std::bad_cast` exception on failure (since NULL references do not exist).

### 4. `const_cast` (Not covered in an exercise)
**What it does:** Adds or removes the `const` qualifier from a variable.
**When to use it:** When you have a `const` pointer or reference, but you absolutely need to pass it to an older API or function that expects a non-const parameter (but you know for a fact the function won't actually modify it).
