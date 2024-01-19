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

  int attempts = 0;
 
  while(1)
  {
    try
    {
    cout << "enter number sectot from 1 to 9: ";
    int sectornumber;
    cin >> sectornumber;

    if(sectornumber < 1 || sectornumber > 9)
    {
      throw invalid_argument("Invalid sector number");
    }

    Sector& sector = field[sectornumber - 1];

    if(sector.fish != nullptr)
    {
      delete sector.fish;
      sector.fish = nullptr;
      throw Fish();
    }

    else if(sector.boot != nullptr)
    {
      throw Boot();
    }

    else
    {
      cout << "keep catching" << endl;
    }

   
  attempts ++;
    
    }
    
    catch(const Fish& e)
    {
      cout << "you catch a fish !!!" << endl;
      cout  << "you have used attempts: " << attempts << endl;
      break;
    }

    catch(const Boot& e)
    {
      cout << "you catch a boot !!!" << endl;
      break;
     
    }

    catch(const invalid_argument& e)
    {
      std::cerr << e.what() << '\n';
      continue;
    }
    
   
  }

  for (int i = 0; i < 9; ++i)
   {
      delete field[i].fish;
      delete field[i].boot;
  }
    return 0; 
}


