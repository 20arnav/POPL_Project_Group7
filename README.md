# POPL Project Group 7
Project to fulfil partial requirements of course CSF301 under Professor Dr. Kunal Korgaonkar.

Group Members:  
Arnav Goyal - 2021A7PS2596G  
Pranav Bajpai - 2021A7PS2062G  
Aryan Nambiar - 2021A7PS2619G  
Amey Patil - 2021A7PS2740G  

## Problem Statement

As a part of this project, we have implemented a **Multithreaded File Server** in Rust and used its features to overcome problems generally encountered in C-based client-server architecture, such as Buffer Overflow Attacks, Dangling Pointer Vulnerability, Size of Code and Concurrency advantages.  
  
Rust offers several features such as memory safety, ownership system, borrowing and lifetimes and safe concurrency without data races, making Rust much safer and easier to maintain in the case of client-server architecture.

## Project Description

The project focuses on developing a client-server interaction system for file servers using the Rust programming language. The server is designed to handle file operations, such as reading, writing, and deleting files, while the client interacts with the server to perform these operations.

## Software Architecture  


## POPL Aspects
Rust and C are both programming languages, but they have different design philosophies and features. Here are some advantages of Rust over C:

1. **Memory Safety:**
   - One of the key advantages of Rust is its strong emphasis on memory safety without sacrificing performance. Rust has a robust ownership system and a borrow checker that prevents common programming errors like null pointer dereferencing, buffer overflows, and data races.

2. **Ownership System:**
   - Rust introduces a unique ownership system that enforces strict rules on how memory is accessed and modified. This helps prevent issues like dangling pointers and data races. The ownership system enables automatic memory management without garbage collection.

3. **Borrowing and Lifetimes:**
   - Rust uses a system of borrowing and lifetimes to manage references to data. This ensures that references are valid for the appropriate scope and prevents dangling references. The borrow checker analyzes code at compile time to ensure these rules are followed.

4. **Concurrency without Data Races:**
   - Rust provides concurrency support without the risk of data races. The ownership and borrowing system, along with the absence of shared mutable state by default, makes it easier to write concurrent code that is safe and free from race conditions.

5. **Community and Ecosystem:**
   - Rust has a vibrant and growing community with an active ecosystem. The package manager, Cargo, simplifies dependency management and project setup. The community promotes best practices, and there is a focus on documentation and tooling.

6. **Modern Language Features:**
   - Rust includes modern programming language features, such as pattern matching, algebraic data types, and traits (similar to interfaces in other languages). These features contribute to more expressive and readable code.

7. **Tooling and Package Management:**
   - Cargo, Rust's package manager, simplifies dependency management and project build processes. It also encourages standardized project layouts and makes it easy to build, test, and package Rust projects.

8. **No Undefined Behavior by Default:**
   - Rust aims to eliminate undefined behavior by default. This is achieved through the ownership system, bounds checking, and other safety features. In C, undefined behavior can lead to unpredictable results and security vulnerabilities.

9. **Compatibility and Interoperability:**
   - Rust is designed to be compatible with C, allowing for easy integration with existing C code. Rust can call C functions directly, and C code can call Rust functions through a foreign function interface (FFI).

While Rust offers these advantages, it's important to note that the choice between Rust and C depends on the specific requirements of a project. C remains a powerful language with a long history, and in some contexts, it may still be the preferred choice. Rust, however, addresses many modern programming challenges and provides a safer alternative, especially for systems programming.


## Features
Secure Communication: The communication between the client and server is secured to prevent unauthorized access.

File Operations: The system supports essential file operations, including reading, writing, and deleting files.

Concurrency: Rust's ownership system and concurrency features are utilized to ensure efficient and safe concurrent access to the server.

Error Handling: Comprehensive error handling is implemented to provide meaningful feedback to users in case of issues.

## Comparison with C

This project aims to showcase the advantages of Rust over C in the context of file server interactions. Some key points of comparison include:

Memory Safety: Rust's ownership system helps prevent common memory-related issues, providing a safer environment compared to C.

Concurrency: Rust's ownership and borrowing system facilitates easy and safe implementation of concurrency, enhancing performance without sacrificing safety.

Error Handling: Rust's Result type and exhaustive pattern matching make error handling more explicit and manageable compared to C's error codes.

## Acknowledgments
We would like to express our gratitude to Professor Dr. Kunal Korgaonkar for his guidance and support throughout the development of this project.

