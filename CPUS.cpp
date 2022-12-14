#include <iostream>
#include <fstream>
#include <string>
#include <map>

// Function Prototypes
void read();
void direction(std::string, std::string&, std::string&);
void mov(std::string&, std::string&);
void add(std::string&, std::string&);
void sub(std::string&, std::string&);
void mul(std::string&, std::string&);
void inc(std::string&, std::string&);
void dec(std::string&, std::string&);
void cmp(std::string&, std::string&);

// Registers
struct Register
{
  int a1 = 0;
  int a2 = 0;
  int a3 = 0;
  int a4 = 0;
  int a5 = 0;
  int a6 = 0;
  int a7 = 0;
  int a8 = 0;
  int a9 = 0;
  int a10 = 0;
} Reggy;

//The entry point
int main()
{
  
  read();
   std::cout << Reggy.a1 << std::endl;
   std::cout << Reggy.a2 << std::endl;
   //std::cout << Reggy.a3 << std::endl;
  return 0;
}

void read()
{
  std::string token;
  std::string argument1;
  std::string argument2;
  std::ifstream inFile("file.txt");
  if (inFile.fail())
  {
    std::cout << "Unable to open file for reading." << std::endl;
    exit(1);
  }
  while (!inFile.eof())
  {
    inFile >> token;
    if (token == "mov" || token == "add" || token == "sub" || token == "mul" || token == "inc" || token == "dec" || token == "cmp")
    {
        inFile >> argument1;
        inFile >> argument2;
        direction(token, argument1, argument2);
    }
    else
    { 
      std::cout << "There is nosuch opcode!" << std::endl;
      break;
    }
  }
     
      inFile.close();
}

void direction(std::string token, std::string& argument1, std::string& argument2)
{
        if (token == "mov")
        {
          mov(argument1, argument2);
        }
        // else if (token == "add")
        // {
        //   add(argument1, argument2);
        // }

}


void mov(std::string &argument1, std::string &argument2)
 {
      char num = argument1[argument1.size() - 2];
      switch(num)
      {
        case '1':
        Reggy.a1 = stoi(argument2);
        break;
        case '2':
        Reggy.a2 = stoi(argument2);
        break;
        case '3':
        Reggy.a3 = stoi(argument2);
        break;
        case '4':
        Reggy.a4 = stoi(argument2);
        break;
        case '5':
        Reggy.a5 = stoi(argument2);
        break;
        case '6':
        Reggy.a6 = stoi(argument2);
        break;
        case '7':
        Reggy.a7 = stoi(argument2);
        break;
        case '8':
        Reggy.a8 = stoi(argument2);
        break;
        case '9':
        Reggy.a9 = stoi(argument2);
        break;
        case '0':
        Reggy.a10 = stoi(argument2);
        break;
      }
}
