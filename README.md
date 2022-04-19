 # VMATH: A header only library for numpy like operation on C++ vector. 
 
 ## Installation
 Copy header  file in your source directory and include into your cpp file. 
 
 This library contains various operator overloading that helps reducing unneccessary for-looping, 
 
 ```cpp
 #include "vmath.h" 
 
 // Without vmath
 for (int i=0; i<n;++i){
    A[i] = B[i] + C; 
 }
 // With vmath
 A = B + C; 
 
 
 // Without vmath
 for (int i=0,i<n1,++i){
     for (int j=0;j=n2;++j){
         A[i,j] = B[i,j] + C; 
     }
 }
 // With vmath
 A = B + C; 
 ```
 
 ```cpp
 
 ```
 
 Following operators can be overloaded using vmath.h
 + Addition: +, +=
 + Subtraction: -, -=
 + Multiplication: *, *=
 + Division: /, /=


