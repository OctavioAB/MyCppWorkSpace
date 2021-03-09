#include <string>
#include <iostream>
#include <random>
#include <functional>

using namespace std;


int main(){
  srand(time(0));
  string hello = "Hello World!";
  cout << hello << "\n";
  //int randomNum = rand();
  for(int i = 0;i<5;i++){
    cout << rand() << "\n";
  }
  std::mt19937 generator(time(0));
  std::uniform_int_distribution<int> distribution(1,6);
  int dice_roll = distribution(generator);

  cout<< "let's roll dome dice!\n";

  auto dice = std::bind(distribution, generator);
  for(int i = 0;i<3;i++){
    cout << "die "+to_string(i)+" = "<< dice() << "\n";
  }

}