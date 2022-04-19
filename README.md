 # VMATH: A header only library for numpy like operation on C++ vector. 
 
 ## Installation
 Copy header  file in your source directory and include into your cpp file. 
 
 ## Usages: 
 
 ### Overloading operators: 
 
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

## Vector initialization like numpy 

```cpp

// Get a vector/matrix initialized with 1 and sizde of n;
std::vector<float> vec = vmath::ones<float>(n); 
std::matrix<float> mat = vmath::ones<float>(n1,n2); 

// Get matrix  with randomly initialized  values (0.0 to 1.0)
std::vector<float> vec= vmath::random<float>(n); 
vmath::matrix<float> mat= vmath::random<float>(n1,n2); 

// Get a vector/matrix initialized with 0 and sizde of n;
std::vector<float> vec = vmath::zeros<float>(n); 
std::matrix<float> mat = vmath::zeros<float>(n1,n2); 

```





