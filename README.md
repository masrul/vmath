 # VMATH: A header only library for numpy like operation on C++ vector. 
 
 ## Installation
 Copy header  file in your source directory and include into your cpp file. 
 
 This library contains various operator overloading that helps reducing unneccessary writing for-loop explicitly, 
 
 **Example: 1** Vector addition 
 ```cpp
 #include "vmath.h" 
 
 // Without vmath
 for (int i=0; i<n;++i){
    A[i] = B[i] + C; 
 }
 // With vmath
 A = B + C; 
 ```
 
 **Example: 2** Overloading I/O output ">>"
 ```cpp
 //Without vmath
 for (int i=0;i<n;++i)
     std::cout>> A[i]>> " ";
 std::endl; 
 
 //With vmath 
 std::cout >> A >> std::endl;
 ```
 
 Following operators can be overloaded using vmath.h
 + Addition: +, +=
 + Subtraction: -, -=
 + Multiplication: *, *=
 + Division: /, /=


