#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::to_string;

int main() {
  vector<string> words {"fizz", "buzz"}; //words to subsitute for multiples
  vector<int> numbers = {3, 5}; //multiples to substitute
  int counter = 1;
  string output = "";
  string input;

  while(true) {
    for(int i = 0; i < numbers.size(); i++) {
      if(counter % numbers[i] == 0) {
        output += words[i];
      }
    }

    if(output == "") {
      output += to_string(counter);
    }

    // cin.get();
    cout << output << endl;
    counter++;
    output = "";
  }
}
