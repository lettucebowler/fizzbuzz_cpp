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

int main() {
  std::vector<std::string> words {"fizz", "buzz"}; //vector of strings
  std::vector<int> numbers = {3, 5}; //vector of numbers, should all be prime
  int counter = 1;
  int range = findlcm(numbers, numbers.size());
  std::string output = "";

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
