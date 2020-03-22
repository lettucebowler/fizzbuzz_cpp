#include <iostream>
#include <vector>
#include <math.h>

typedef long long int ll; 

int gcd(int a, int b) { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 

ll findlcm(std::vector<int> arr, int n) { 
    ll ans = arr[0]; 
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
    return ans; 
} 

std::string prepOutput(std::vector<int> numbers, std::vector<std::string> words, int n) {
  std::string output = "";
  for(int i = 0; i < numbers.size(); i++) {
      if(n % numbers[i] == 0) {
        output += words[i];
      }
    }
    //Concat the number if it is not a multiple of any numbers in numbers
    if(output == "") {
      output += std::to_string(n);
    }
    return output;
}

int main() {
  std::vector<std::string> words {"fizz", "buzz"}; //vector of strings
  std::vector<int> numbers = {3, 5}; //vector of numbers, should all be prime
  int range = findlcm(numbers, numbers.size());

  if (words.size() == numbers.size()) {
    //Main loop
    for(int counter = 1; counter <= range; counter++) {
      std::cout << prepOutput(numbers, words, counter) << std::endl;
    }
  } else {
    std::cout << "wordlist and numList not equal length" << std::endl;
  }
}
