#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> highestFrequencies(vector<int> &enc_message){
  // A map to store num => freq 
  map <int, int> freq;
  
  // A map to store freq(can be duplicate) => num 
  multimap <int, int> freqCounts;
  
  // Store num => frequency
  for (int i = 0 ; i < 8; i++)
  {
      freq[enc_message[i]] += 1;
  }
  
  // Now Store freq => num
  for(auto const & iter : freq)
  {
      freqCounts.insert (std::pair<int,int>(iter.second, iter.first)); 
  }


  vector<int> topThree;
  for (multimap<int,int>::reverse_iterator rit=freqCounts.rbegin(); rit!=freqCounts.rend(); ++rit)
  {
      cout << rit->second << " : " << rit->first << '\n';
      topThree.emplace_back(rit->second);
      
  }
  return topThree;
}

int findk(int actualNumber, int numberWeWant){
  int difference;

  if(actualNumber <= 24){
      difference = actualNumber-numberWeWant;
  }else{
    difference = (actualNumber-29) + (numberWeWant-1);
  }
    cout << difference << ",";
  return difference;
}


string getStringValue(int &a) {
  a--; // Reduce by one to make the values with 1 letter 0..25, 
       // with two - 26.. 26^2-1 and so on
  int val = 0; // number of columns with no more then given number of letters
  int number = 0;
  while (val < a) {
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
  vector<int> highestFrequencyNumbers = highestFrequencies(enc_message);
  vector<int> message;
  int k = findk(highestFrequencyNumbers.at(0),1);
  
  for(int number:enc_message){
    int theNumber = number+k;
    if(theNumber > 29){
      theNumber -= 29;
    }
    message.emplace_back(theNumber);
  }
  cout << "\n---------------" << endl;
  string strengen = "";
  for(int &number:message){
    strengen += getStringValue(number)+ " ";
    cout  << number;
  }
  cout << "\n"+strengen<<endl;
  return 0;

}

