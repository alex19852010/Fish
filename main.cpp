#include <iostream>
#include <exception>
#include <cassert>
#include <ctime>

using namespace std;

class Fish
{};

class Boot
{};

class Sector
{
  public:
  Fish * fish;
  Boot * boot;

  Sector() : fish(nullptr), boot(nullptr) {}

};



int main()
{
  srand(time(nullptr));
  Sector field[9];

  field[rand() % 9].fish = new Fish();

  for(int i = 0; i < 3; i ++)
  { 
    int sectorindex = rand() % 9;
    if(field[sectorindex].fish == nullptr && field[sectorindex].boot == nullptr)
    {
      field[sectorindex].boot = new Boot;
    }
    else{
      i --;
    }
  }

   
 
    return 0; 
}