#include <iostream>
#include <fstream>
#include <string>
#include <map>

// Function Prototypes
void read(std::ifstream);
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
  int a1;
  int a2;
  int a3;
  int a4;
  int a5;
  int a6;
  int a7;
  int a8;
  int a9;
  int a10 = 0;
  std::map<std::string, int>R;
} Reggy;

int main()
{
    R["a1"] = Register::a1;
    R["a2"] = Register::a2;
    R["a3"] = Register::a3;
    R["a4"] = Register::a4;
    R["a5"] = Register::a5;
    R["a6"] = Register::a6;
    R["a7"] = Register::a7;
    R["a8"] = Register::a8;
    R["a9"] = Register::a9;
    R["a10"] = Register::a10;
    std::ifstream inFile("file.txt");
  if (inFile.fail())
  {
    std::cout << "Unable to open file for reading." << std::endl;
    exit(1);
  }
  read(inFile);
  inFile.close();
  return 0;
}

void read(std::ifstream inFile)
{
  std::string token;
  std::string argument1;
  std::string argument2;
  std::map<std::string, std::string (*)(std::sring)> Box;
  Box["mov"] = &mov;
  Box["add"] = &add;
  Box["sub"] = &sub;
  Box["mul"] = &mul;
  Box["inc"] = &inc;
  Box["dec"] = &dec;
  Box["cmp"] = &cmp;

  while (!inFile.EOF())
  {
    inFile >> token;
    if (token == "mov" || token == "add" || token == "sub" || token == "mul" || token == "inc" || token == "dec" || token == "cmp")
    {
      inFile >> argument1;
      inFile >> argument2;
      Box[token](argument1, argument2);
    }
    else
    {
      std::cout << "There is no such opcode!" << std::endl;
      return;
    }
  }
  /* std::string nextToken;
   while (inFile >> nextToken) {
     std::cout << "Token: " << nextToken << std::endl;
  }*/
}

void mov(std::string &argument1, std::string &argument2)
{
   if (R.find(argument1) == R.end())
   {
      std::cout << "There is no such "
   }
   if (R.find(argument2) == R.end())
   {
      *R[argument1] = stoi(argument2);
   }
   else
   {
      *R[argument1] = *R[argument2];
   }



   /* if (argument1 == "a1,")
    {
      Reggy.a1 = stoi(argument2);
    }
    if (argument1 == "a2,")
    {
      Reggy.a2 = stoi(argument2);
    }
    if (argument1 == "a3,")
    {
      Reggy.a3 = stoi(argument2);
    }
    if (argument1 == "a4,")
    {
      Reggy.a4 = stoi(argument2);
    }
    if (argument1 == "a5,")
    {
      Reggy.a5 = stoi(argument2);
    }
    if (argument1 == "a6,")
    {
      Reggy.a6 = stoi(argument2);
    }
    if (argument1 == "a7,")
    {
      Reggy.a7 = stoi(argument2);
    }
    if (argument1 == "a8,")
    {
      Reggy.a8 = stoi(argument2);
    }
    if (argument1 == "a9,")
    {
      Reggy.a9 = stoi(argument2);
    }
    if (argument1 == "a10,")
    {
      Reggy.a10 = stoi(argument2);
    }
    
  }*/
}