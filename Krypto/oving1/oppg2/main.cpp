#include <iostream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void highestFrequencies(vector<int> &enc_message){
  // A map to store num => freq 
  map <int, int> freq;
  
  // A map to store freq(can be duplicate) => num 
  multimap <int, int> freqCounts;
  
  // Store num => frequency
  size_t size = enc_message.size();
  for (size_t i = 0 ; i < size; i++)
  {
      freq[enc_message[i]] += 1;
  }
  
  // Now Store freq => num
  for(auto const & iter : freq)
  {
      freqCounts.insert (std::pair<int,int>(iter.second, iter.first)); 
  }



  for (multimap<int,int>::reverse_iterator rit=freqCounts.rbegin(); rit!=freqCounts.rend(); ++rit)
  {
      cout << rit->second << " : " << rit->first << '\n';

      
  }

}
int main() {
vector<int> enc_message = {4, 5, 15, 1, 4, 26, 1, 26, 26, 1, 15, 14, 13, 14, 1, 6, 13, 14, 1, 15, 6, 13, 14, 1, 15, 26, 1, 26, 26, 1, 15, 6, 13, 14, 1, 15, 14, 13, 14, 1,15, 20, 13, 15, 0, 13, 4, 23, 12, 15, 10, 20, 1, 4, 10, 20, 1, 14, 1, 27,15, 20, 20, 1, 9, 27, 1, 4, 14, 24, 22, 9, 18, 13, 15, 27, 13, 15, 24, 4};
highestFrequencies(enc_message);
// 1 = e , 15 = t, 14 = r, 13 = s, 26 = n, 4=a

for(int number: enc_message){
  switch (number){
  case 1:
    cout << "e";
    break;
  case 15:
    cout << "r";
    break;
  case 14:
    cout << "k";
    break;
  case 13:
    cout << "a";
    break;
  case 26:
    cout << "p";
    break;
  case 4:
    cout << "n";
    break;
  case 6:
    cout << "b";
    break;
  case 5:
    cout << "å";
    break;
  case 20:
    cout << "t";
    break;
  case 0:
    cout << "h";
    break;
  case 23:
    cout << "f";
    break;
  case 12:
    cout << "ø";
    break;
  case 10:
    cout << "s";
    break;
  case 27:
    cout << "g";
    break;
  case 24:
    cout << "i";
    break;
  case 18:
    cout << "m";
    break;
  case 9:
    cout << "o";
    break;
  case 22:
    cout << "l";
    break;
  default:
    cout << number;
    break;
  }
}
  
}
