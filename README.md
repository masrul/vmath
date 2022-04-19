 # VMATH: A header only library for numpy like operation on C++ vector. 
 
The main goal of this library is to offer a light-weight tool which mimics NUMPY like operation on C++ vector. For simple addition and subtration, we always need to write for-loops in C++. It would be nice to do these operation like NUMPY. This library also contains some useful math operations, e.g. matmul, cross_product, dot_product, transpose etc. 
 
 ## Installation
 Copy header  file in your source directory and include into your cpp file. 
 
 ## Usages: 
 
 ### 1. Overloading operators
 
 This library contains various operator overloading that helps reducing unneccessary writing for-loop explicitly, 
 
 **Example-1:** Vector addition 
 ```cpp
 #include "vmath.h" 
 
 // Without vmath
 for (int i=0; i<n;++i){
    A[i] = B[i] + C; 
 }
 // With vmath
 A = B + C; 
 ```
 
 **Example-2:** Overloading console output "<<"
 ```cpp
 //Without vmath
 for (int i=0;i<n;++i)
     std::cout<< A[i]<< " ";
 std::endl; 
 
 //With vmath 
 std::cout<< A << std::endl;
 ```
 
 Following operators can be overloaded using vmath.h
 + Addition: +, +=
 + Subtraction: -, -=
 + Multiplication: *, *=
 + Division: /, /=

### 2. Vector initialization like Numpy 

```cpp

// Get a vector/matrix initialized with 1 and size of n;
std::vector<float> vec = vmath::ones<float>(n); 
std::matrix<float> mat = vmath::ones<float>(n1,n2); 

// Get vector/matrix  with randomly initialized  values (0.0 to 1.0)
std::vector<float> vec= vmath::random<float>(n); 
vmath::matrix<float> mat= vmath::random<float>(n1,n2); 

// Get a vector/matrix initialized with 0 and size of n;
std::vector<float> vec = vmath::zeros<float>(n); 
std::matrix<float> mat = vmath::zeros<float>(n1,n2); 
```

### 3. Vector cross_product, dot_product, sum, argmin, argmax 
```cpp
vector<float> u = {1,2,3};
vector<int> v = {3,2,1};


//cross_product
std::cout << vmath::cross_product(v,u) <<std::endl;

//dot_product
std::cout << vmath::dot_product(v,u) <<std::endl;

//sum  
std::cout << vmath::sum(u) << std::endl; 

//argmin 
std::cout << vmath::argmin(v) <<std::endl;

//argmax
std::cout << vmath::argmax(v) <<std::endl;
```


### 4. Matrix multiplication/transpose

```cpp
// Defining matrix     
vmath::matrix<float> mat0=vmath::random<float>(5000,300);
vmath::matrix<float> mat1=vmath::random<float>(300,600);

// Multiply    
vmath::matrix<float> reslt= vmath::matmul(mat0,mat1);

// Transpose 
vmath::matrix<float> reslt= vmath::transpose(mat0);
```







