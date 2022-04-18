 # VMATH: A header only library for numpy like operation on C++ vector. 
 
 ## Installation
 Copy header  file in your source directory and include into your cpp file. 
 
 This library contains various operator overloading that helps reducing unneccessary for-looping, 
 
 ```cpp
 for (int i=0; i<n;++i){
    A[i] = B[i] + C; 
 }
 ```
 
 ```cpp
 #include "vmath.cpp" 
 A = B + C; 
 ```
 


