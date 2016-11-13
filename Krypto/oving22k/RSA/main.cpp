#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;



cpp_int gcd(cpp_int a, cpp_int b) {
    cpp_int r;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}


cpp_int find_inverse(cpp_int a, cpp_int p) {
    cpp_int g, z;

    if (gcd(a, p) > 1) return 0;

    z = 1;

    while (a > 1) {
        z += p;
        if ((g=gcd(a, z))> 1) {
            a /= g;
            z /= g;
        }
    }
    return z;
}

int main()
{
  
  //OPPGAVE 1
  cpp_int x1(2991), c1(388), mod1(5912);
  
  cout << "x1^c1 (mod mod1) " << powm(x1,c1,mod1) << endl;
  
  
  // RSA
  cpp_int p(131), q(137), b(29);
  
  cpp_int Oen = (p-1)*(q-1);//17680

  //cpp_int a = powm((1/b),1,Oen);
  cpp_int a = find_inverse(b,Oen); // fra ab kongruent 1 ( mod ø(n))
  
  
  
  cpp_int message(42), private_key(b), public_key(a), modulus(p*q);
  
 // cpp_int private_key(2753), public_key(17), modulus(3233), message(42);

  std::cout << "Melding før kryptering: "<< message << std::endl;

  message =  powm(message, public_key, modulus);

  std::cout << "Melding etter kryptering: " << message << std::endl;

  message = powm(message, private_key, modulus);

  std::cout << "Melding etter dekryptering: " << message << std::endl;
  
  return 0;
}