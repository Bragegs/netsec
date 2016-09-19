#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using namespace boost::multiprecision;

int main() {
  //cpp_int b(2), p(3), m(4);
  
  cpp_int km(66514), e(17), n(86609);
  
  
  // (p-th power of b) mod m = (3rd power of 2) mod 4 = 8 mod 4 = 0
  cout << powm(km, e, n) << endl;
}