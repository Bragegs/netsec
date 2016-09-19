#include <iostream>

using namespace std;
const string kryptert_melding = "judwxohuhuCghuhCkduCixqqhwCphoglqjhqD";
int main() {

  string dekryptert_melding_caps = "";
  string dekryptert_melding = "";
  
  for(int i=0; i<(int)kryptert_melding.size(); ++i){
    char w = (char)(kryptert_melding.at(i)) - 3;
    dekryptert_melding += w;
    
    char e = (char)(kryptert_melding.at(i)) - 35;
    dekryptert_melding_caps += e;
  }
  
  cout << dekryptert_melding_caps << endl;
  cout << dekryptert_melding;
}
