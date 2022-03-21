#ifndef VMATH_H

#define VMATH_H

#include "math.h"
#include <vector>
#define ASSERT_EQUAL_SIZE()                                                    \
    assert(lhs.size() == rhs.size() &&                                         \
           "Fatal Error: Both vectors must have same size")

#define STATIC_ASSERT_ARITHMETIC()                                             \
    static_assert((std::is_arithmetic<T0>::value &&                            \
                   std::is_arithmetic<T1>::value) == true,                     \
                  "Non-arithmetic operands")

#define STATIC_ASSERT_INPLACE_INT_FLOT()                                       \
    static_assert((std::is_integral<T0>::value &&                              \
                   std::is_floating_point<T1>::value) == false,                \
                  "Inplace int (+=,-=,*=,/=) float (or double) is invaild");

/* -----------**(vector = vector + vector)**------------- */
template <typename T0, typename T1>
auto operator+(const std::vector<T0>& lhs, const std::vector<T1>& rhs)
    -> std::vector<decltype(T0() + T1())> {

    STATIC_ASSERT_ARITHMETIC();
    ASSERT_EQUAL_SIZE();

    std::vector<decltype(T0() + T1())> result(lhs.size(), 0);
    for (int i = 0; i < lhs.size(); ++i)
        result[i] = lhs[i] + rhs[i];
    return result;
}

/* -----------**(vector = scalar + vector)**------------- */
template <typename T0, typename T1>
auto operator+(const T0& lhs, const std::vector<T1>& rhs)
    -> std::vector<decltype(T0() + T1())> {

    STATIC_ASSERT_ARITHMETIC();

    std::vector<decltype(T0() + T1())> result(rhs.size(), 0);
    for (int i = 0; i < rhs.size(); ++i)
        result[i] = lhs + rhs[i];

    return result;
}

/* -----------**(vector = vector + scalar )**------------- */
template <typename T0, typename T1>
auto operator+(const std::vector<T0>& lhs, const T1& rhs)
    -> std::vector<decltype(T0() + T1())> {

    STATIC_ASSERT_ARITHMETIC();

    std::vector<decltype(T0() + T1())> result(lhs.size(), 0);
    for (int i = 0; i < lhs.size(); ++i)
        result[i] = lhs[i] + rhs;
    return result;
}

/* -----------**(vector += vector)**------------- */
template <typename T0, typename T1>
void operator+=(std::vector<T0>& lhs, const std::vector<T1>& rhs) {

    STATIC_ASSERT_ARITHMETIC();
    STATIC_ASSERT_INPLACE_INT_FLOT();
    ASSERT_EQUAL_SIZE();

    for (int i = 0; i < lhs.size(); ++i)
        lhs[i] += rhs[i];
}

/* -----------**(vector += scalar)**------------- */
template <typename T0, typename T1>
void operator+=(std::vector<T0>& lhs, const T1& rhs) {

    STATIC_ASSERT_ARITHMETIC();
    STATIC_ASSERT_INPLACE_INT_FLOT();

    for (int i = 0; i < lhs.size(); ++i)
        lhs[i] += rhs;
}

/* -----------**(vector = vector - vector)**------------- */
template <typename T0, typename T1>
auto operator-(const std::vector<T0>& lhs, const std::vector<T1>& rhs)
    -> std::vector<decltype(T0() - T1())> {

    STATIC_ASSERT_ARITHMETIC();
    ASSERT_EQUAL_SIZE();

    std::vector<decltype(T0() - T1())> result(lhs.size(), 0);
    for (int i = 0; i < lhs.size(); ++i)
        result[i] = lhs[i] - rhs[i];
    return result;
}

/* -----------**(vector = scalar - vector)**------------- */
template <typename T0, typename T1>
auto operator-(const T0& lhs, const std::vector<T1>& rhs)
    -> std::vector<decltype(T0() - T1())> {

    STATIC_ASSERT_ARITHMETIC();

    std::vector<decltype(T0() - T1())> result(rhs.size(), 0);
    for (int i = 0; i < rhs.size(); ++i)
        result[i] = lhs - rhs[i];
    return result;
}

/* -----------**(vector = vector - scalar )**------------- */
template <typename T0, typename T1>
auto operator-(const std::vector<T0>& lhs, const T1& rhs)
    -> std::vector<decltype(T0() - T1())> {

    STATIC_ASSERT_ARITHMETIC();

    std::vector<decltype(T0() - T1())> result(lhs.size(), 0);
    for (int i = 0; i < lhs.size(); ++i)
        result[i] = lhs[i] - rhs;
    return result;
}

/* -----------**(vector -= vector)**------------- */
template <typename T0, typename T1>
void operator-=(std::vector<T0>& lhs, const std::vector<T1>& rhs) {

    STATIC_ASSERT_ARITHMETIC();
    STATIC_ASSERT_INPLACE_INT_FLOT();
    ASSERT_EQUAL_SIZE();

    for (int i = 0; i < lhs.size(); ++i)
        lhs[i] -= rhs[i];
}

/* -----------**(vector -= scalar)**------------- */
template <typename T0, typename T1>
void operator-=(std::vector<T0>& lhs, const T1& rhs) {

    STATIC_ASSERT_ARITHMETIC();
    STATIC_ASSERT_INPLACE_INT_FLOT();

    for (int i = 0; i < lhs.size(); ++i)
        lhs[i] -= rhs;
}

/* -----------**(vector = vector * vector)**------------- */
template <typename T0, typename T1>
auto operator*(const std::vector<T0>& lhs, const std::vector<T1>& rhs)
    -> std::vector<decltype(T0() * T1())> {

    STATIC_ASSERT_ARITHMETIC();
    ASSERT_EQUAL_SIZE();

    std::vector<decltype(T0() * T1())> result(lhs.size(), 0);
    for (int i = 0; i < lhs.size(); ++i)
        result[i] = lhs[i] * rhs[i];
    return result;
}

/* -----------**(vector = scalar * vector)**------------- */
template <typename T0, typename T1>
auto operator*(const T0& lhs, const std::vector<T1>& rhs)
    -> std::vector<decltype(T0() * T1())> {

    STATIC_ASSERT_ARITHMETIC();

    std::vector<decltype(T0() * T1())> result(rhs.size(), 0);
    for (int i = 0; i < rhs.size(); ++i)
        result[i] = lhs * rhs[i];
    return result;
}

/* -----------**(vector = vector * scalar )**------------- */
template <typename T0, typename T1>
auto operator*(const std::vector<T0>& lhs, const T1& rhs)
    -> std::vector<decltype(T0() * T1())> {

    STATIC_ASSERT_ARITHMETIC();

    std::vector<decltype(T0() * T1())> result(lhs.size(), 0);
    for (int i = 0; i < lhs.size(); ++i)
        result[i] = lhs[i] * rhs;
    return result;
}

/* -----------**(vector *= vector)**------------- */
template <typename T0, typename T1>
void operator*=(std::vector<T0>& lhs, const std::vector<T1>& rhs) {

    STATIC_ASSERT_ARITHMETIC();
    STATIC_ASSERT_INPLACE_INT_FLOT();
    ASSERT_EQUAL_SIZE();

    for (int i = 0; i < lhs.size(); ++i)
        lhs[i] *= rhs[i];
}

/* -----------**(vector *= scalar)**------------- */
template <typename T0, typename T1>
void operator*=(std::vector<T0>& lhs, const T1& rhs) {

    STATIC_ASSERT_ARITHMETIC();
    STATIC_ASSERT_INPLACE_INT_FLOT();

    for (int i = 0; i < lhs.size(); ++i)
        lhs[i] *= rhs;
}

/* -----------**(vector = vector / vector)**------------- */
template <typename T0, typename T1>
auto operator/(const std::vector<T0>& lhs, const std::vector<T1>& rhs)
    -> std::vector<decltype(T0() / T1())> {

    STATIC_ASSERT_ARITHMETIC();
    ASSERT_EQUAL_SIZE();

    std::vector<decltype(T0() / T1())> result(lhs.size(), 0);
    for (int i = 0; i < lhs.size(); ++i)
        result[i] = lhs[i] / rhs[i];
    return result;
}

/* -----------**(vector = scalar / vector)**------------- */
template <typename T0, typename T1>
auto operator/(const T0& lhs, const std::vector<T1>& rhs)
    -> std::vector<decltype(T0() / T1())> {

    STATIC_ASSERT_ARITHMETIC();

    std::vector<decltype(T0() / T1())> result(rhs.size(), 0);
    for (int i = 0; i < rhs.size(); ++i)
        result[i] = lhs / rhs[i];
    return result;
}

/* -----------**(vector = vector / scalar )**------------- */
template <typename T0, typename T1>
auto operator/(const std::vector<T0>& lhs, const T1& rhs)
    -> std::vector<decltype(T0() / T1())> {

    STATIC_ASSERT_ARITHMETIC();

    std::vector<decltype(T0() / T1())> result(lhs.size(), 0);
    for (int i = 0; i < lhs.size(); ++i)
        result[i] = lhs[i] / rhs;
    return result;
}

/* -----------**(vector /= vector)**------------- */
template <typename T0, typename T1>
void operator/=(std::vector<T0>& lhs, const std::vector<T1>& rhs) {

    STATIC_ASSERT_ARITHMETIC();
    static_assert(std::is_integral<T0>::value == false,
                  "Inplace integer division is invaild!");
    ASSERT_EQUAL_SIZE();

    for (int i = 0; i < lhs.size(); ++i)
        lhs[i] /= rhs[i];
}

/* -----------**(vector /= scalar)**------------- */
template <typename T0, typename T1>
void operator/=(std::vector<T0>& lhs, const T1& rhs) {

    STATIC_ASSERT_ARITHMETIC();
    static_assert(std::is_integral<T0>::value == false,
                  "Inplace integer division is invalid!");

    for (int i = 0; i < lhs.size(); ++i)
        lhs[i] /= rhs;
}

// overloading: //
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> vec) {
    os << "vector({ ";

    for (auto v : vec)
        os << v << ", ";

    os << "})\n";

    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os,
                         const std::vector<std::vector<T>> mat) {
    os << "matrix(\n";

    for (int i = 0; i < mat.size(); ++i) {
        os << "{ ";
        for (int j = 0; j < mat[0].size(); ++j) {
            os << mat[i][j] << ", ";
        }
        os << "},\n";
    }

    os << ")\n";

    return os;
}

// Name space for useful function
namespace vmath {

template <typename T> using matrix = std::vector<std::vector<T>>;

template <typename T> matrix<T> transpose(matrix<T>& A) {
    int nrows = A.size();
    int ncols = A[0].size();

    matrix<T> A_trans(ncols, std::vector<T>(nrows, 0));

    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            A_trans[j][i] = A[i][j];
        }
    }
    return A_trans;
}

template <typename T0, typename T1>
auto matmul(matrix<T0>& A, matrix<T1>& B) -> matrix<decltype(T0() * T1())> {

    int r1 = A.size();
    int c1 = A[0].size();

    int r2 = B.size();
    int c2 = B[0].size();

    assert(c1 == r2);

    matrix<decltype(T0() * T1())> C(
        r1, std::vector<decltype(T0() * T1())>(c2, 0.0));

    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            decltype(T0() * T1()) sum = 0;
            for (int k = 0; k < c1; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}

template <typename T>
inline auto norm(std::vector<T> v) -> decltype(sqrt(T())) {

    decltype(sqrt(T())) vec_mag = 0;
    for (int i = 0; i < v.size(); ++i)
        vec_mag += v[i] * v[i];
    vec_mag = sqrt(vec_mag);
    return vec_mag;
}

template <typename T0, typename T1>
auto dot_product(std::vector<T0>& u, std::vector<T1>& v)
    -> decltype(T0() * T1()) {

    assert(u.size == v.size);

    decltype(T0() * T1()) result = 0;
    for (int i = 0; i < u.size(); ++i)
        result += u[i] * v[i];

    return result;
}

template <typename T0, typename T1>
auto cross_product(std::vector<T0> u, std::vector<T1> v)
    -> std::vector<decltype(T0() * T1())> {

    assert(u.size()==3 && v.size()==3);

    std::vector<decltype(T0() * T1())> cross;

    cross.push_back(u[1] * v[2] - u[2] * v[1]);
    cross.push_back(u[2] * v[0] - u[0] * v[2]);
    cross.push_back(u[0] * v[1] - u[1] * v[0]);

    return cross;
}

template <typename T> void unit_vec(std::vector<T>& v) {

    static_assert(std::is_floating_point<T>::value,"Vector must contains floating-point");

    v /=norm(v);
}

template <typename T> matrix<T> eye(int len) {
    matrix<T> mat(len, std::vector<T>(len, 0.0));

    for (int i = 0; i < len; ++i)
        mat[i][i] = 1;

    return mat;
}

template <typename T> int argmin(std::vector<T> x) {
    return distance(x.begin(), min_element(x.begin(), x.end()));
}

template <typename T> int argmax(std::vector<T> x) {
    return distance(x.begin(), max_element(x.begin(), x.end()));
}

template <typename T> inline T get_rand() {
    static_assert(std::is_floating_point<T>::value,"Random value must be floating_point");
    T rnd = (T)rand() / RAND_MAX;
    return rnd;
}

template <typename T > std::vector<T> zeros(int len) {
    std::vector<T> vec(len, 0);
    return vec;
}

template <typename T > matrix<T> zeros(int len0, int len1) {
    matrix<T> mat(len0, std::vector<T>(len1, 0));
    return mat;
}

template <typename T > std::vector<T> ones(int len) {
    std::vector<T> vec(len, 1);
    return vec;
}

template <typename T> matrix<T> ones(int len0, int len1) {
    matrix<T> mat(len0, std::vector<T>(len1, 1));
    return mat;
}

// scalar random
template <typename T> T random() {
    static_assert(std::is_floating_point<T>::value,"Random value must be floating_point");
    T rnd = get_rand<T>();
    return rnd;
}

// array random
template <typename T >
std::vector<T> random(int len) {

    static_assert(std::is_floating_point<T>::value,"Random value must be floating_point");

    std::vector<T> result(len, 0);
    for (int i = 0; i < len; ++i)
        result[i] = get_rand<T>();
    return result;
}

// matrix version of random
template <typename T > 
matrix<T> random(int len0, int len1) {

    static_assert(std::is_floating_point<T>::value,"Random value must be floating_point");

    matrix<T> mat(len0, std::vector<T>(len1, 0));

    for (int i = 0; i < len0; ++i)
        for (int j = 0; j < len1; ++j)
            mat[i][j] = get_rand<T>();
    return mat;
}

template <typename T> auto sum(std::vector<T> vec)->decltype(T()+T()) {

    decltype(T()+T()) result = 0;
    for (auto a : vec)
        result += a;
    return result ;
}

template <typename T> auto mean(std::vector<T> vec)->decltype(T()/float()) {

    decltype(T()/float()) result = 0;
    for (auto a : vec)
        result += a;

    return result / float(vec.size());
}

} // namespace vmath
#endif /* end of include guard VMATH_H */
