#include <vector>
#include <string>
#include <iostream>
using namespace std;
string getStringValue(int &a) {
  int val = 0; // number of columns with no more then given number of letters
  int number = 0;
  while (val <= a) {
    val = val*29 + 29;
    number++;
  }
  val = (val - 29)/29;
  a -= val; // subtract the number of columns with less letters 
  string res;
  for (int i = 0; i < number; ++i) {
    res.push_back(a%29 + 'A');
    a /= 29;
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  vector<int> enc_message = {22, 17, 19, 05, 21, 24, 20, 17, 24, 24, 17, 01, 20, 13, 14, 21, 18, 18};
  int k = 16;
  
  for(int &number:enc_message){
    int shiftedValue = (number+k)%29;
    cout << getStringValue(shiftedValue);
  }

  return 0;

}