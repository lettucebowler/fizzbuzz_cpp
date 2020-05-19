#include <iostream>
#include <vector>
#include <map>

typedef long long int ll; 

// Returns greatest common denominator of a and b
ll gcd(int a, int b) { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 

// returns least common multiple of elements in arr
ll find_lcm(std::vector<int> arr) { 
    ll ans = arr[0]; 
    for (int i = 1; i < arr.size(); i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
    return ans; 
}

// Returns a vector of the keys in a map
std::vector<int> get_keys(std::map<int, std::string> map) {
  std::vector<int> keys;
  std::map<int, std::string>::iterator it = map.begin();
  
  while(it != map.end()) {
    keys.push_back(it->first);
    it++;
  }

  return keys;
}

// Returns proper output based on fizzbuzz rules.
std::string prep_output(std::map<int, std::string> words, int n) {
  std::string output = "";
  std::map<int, std::string>::iterator it = words.begin();
  
  while(it != words.end()) {
    if(n % it -> first == 0) {
      output += it -> second;
    }
    it++;
  }

  if(output == ""){ 
    output = std::to_string(n);
  }

  return output;
}

// Driver Program
int main() {
  std::map<int, std::string> words = {{3, "Fizz"}, {5, "Buzz"}};
  int range = find_lcm(get_keys(words));

  for(int counter = 1; counter <= range; counter++) {
    std::cout << prep_output(words, counter) << std::endl;
  }
}
