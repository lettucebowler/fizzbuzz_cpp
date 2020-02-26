#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> words {"fizz", "buzz"}; //vector of strings
  std::vector<int> numbers = {3, 5}; //vector of numbers, should all be prime
  int counter = 1;
  int range = 1;
  std::string output = "";

  //Calculate range for loop
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
      output += std::to_string(counter);
    }

    //Output result
    std::cout << output << std::endl;
    output = "";
  }
}
