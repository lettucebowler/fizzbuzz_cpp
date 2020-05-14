#include <iostream>
#include <vector>
#include <math.h>

typedef long long int ll; 

int gcd(int a, int b) { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 

ll find_lcm(std::vector<int> arr, int n) { 
    ll ans = arr[0]; 
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
    return ans; 
} 

std::string prep_output(std::vector<int> numbers, std::vector<std::string> words, int n) {
  std::string output = "";
  for(int i = 0; i < numbers.size(); i++) {
      if(n % numbers[i] == 0) {
        output += words[i];
      }
    }
    if(output == "") {
      output += std::to_string(n);
    }
    return output;
}

int main() {
  std::vector<std::string> words {"fizz", "buzz", "fuzz"};
  std::vector<int> numbers = {3, 5, 7}; //Works best if all are prime, don't have to be though
  int range = find_lcm(numbers, numbers.size());

  if (words.size() == numbers.size()) {
    for(int counter = 1; counter <= range; counter++) {
      std::cout << prep_output(numbers, words, counter) << std::endl;
    }
  } else {
    std::cout << "wordlist and numList not equal length" << std::endl;
  }
}
