# POPL Project Group 7
Project to fulfil partial requirements of course CSF301 under Professor Dr. Kunal Korgaonkar.

Group Members:  
Arnav Goyal - 2021A7PS2596G  
Pranav Bajpai - 2021A7PS2062G  
Aryan Nambiar - 2021A7PS2619G  
Amey Patil - 2021A7PS2740G  

## Problem Statement

As a part of this project, we have implemented **Multithreaded File Server** in Rust and used its features to overcome problems generally encountered in C based client-server architecture such as Buffer Overflow Attack, Dangling Pointer Vulnerability, Size of Code and Concurrency advantages.  
Rust offers several features such as memory safety, ownership system, borrowing and lifetimes and safe concurreny without data races which makes Rust much safer and easier to maintain in case of client-server architecture.  
This project is a collaborative effort by Arnav, Aryan, Amey, and Pranav, under the guidance of Professor Kunal Korgaonkar.

## Project Description

The project focuses on developing a client-server interaction system for file servers using the Rust programming language. The server is designed to handle file operations, such as reading, writing, and deleting files, while the client interacts with the server to perform these operations.

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

