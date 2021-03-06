#include <iostream>
#include <random>
#include <sstream>
#include <string>

using namespace std;


const string nokkel = "Dette er en noekkel";

int main() {
  // string key = "This is a key";

  //Create seed from key
  seed_seq seed(nokkel.begin(), nokkel.end());

  //Choice of pseudorandom number generator using the given seed
  minstd_rand0 generator(seed);

  //Choice of distribution with 1 byte values
  uniform_int_distribution<char> distribution;
  string kryptert_melding = "114b70745a521c57371f7a245d6440662d49";
  //string tekst = "";
  string out;
  int counter = 0;
    //Retrieve random numbers from the generator using the chosen distribution:
  for (size_t c = 0; c < 5; ++c) {
    string temp = "0x";
    temp += kryptert_melding[c];
    temp += kryptert_melding[c+1];
    
    int hexpart = stoul(temp, nullptr, 16);
    
    out.insert(counter,1,hexpart^(int)distribution(generator));

    //cout << (int)distribution(generator) << endl;
   // cout << (char)((int)distribution(generator)^kryptert_melding.at(c)) << endl;
    // cout << (char)distribution(generator) << endl;
    //int x = stoul(kryptert_melding, nullptr, 16);
    
    //cout << x^(int)distribution(generator) << endl;
    // char e = (char)distribution(generator);
    //tekst += e;
    counter++; 
  }

  cout << out << endl;

  
  
}

