#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::to_string;

int main() {
  vector<string> words {"fizz", "buzz"}; //vector of strings
  vector<int> numbers = {3, 5}; //vector of numbers, should all be prime
  int counter = 1;
  int range = 1;
  string output = "";

  //Calculate lcm of numbers in numbers
  for(int x : numbers) {
    range *= x;
  }

  //Main loop
  for(counter = 1; counter <= range; counter++) {
    //Check multiples, and concat output with appropriate strings
    for(int i = 0; i < numbers.size(); i++) {
      if(counter % numbers[i] == 0) {
        output += words[i];
      }
    }

    //Concat the number if it is not a multiple of any numbers in numbers
    if(output == "") {
      output += to_string(counter);
    }

    //Output result
    cout << output << endl;
    output = "";
  }
}
