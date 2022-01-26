// 1GD23N Wieme Jarne 
// StringBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>
#include <string>

int main()
{
    std::string gutenBergString{ "One morning, when Gregor Samsa woke from troubled dreams, he found himself" 
	 							 " transformed in his bed into a horrible vermin. He lay on his armour-like"
							     " back, and if he lifted his head a little he could see his brown belly,"
								 " slightly domedand divided by arches into stiff sections. The bedding was"
						   	     " hardly able to cover itand seemed ready to slide off any moment. His many"
							     " legs, pitifully thin compared with the size of the rest of him, waved"
								 " about helplessly as he looked."                                            };

   std::cout << "-- Explore string class --\n" << gutenBergString << '\n';
   
   //std::string::size and std::string::lenght
   std::cout << "\nsize: " << gutenBergString.size() << "\nlenght: " << gutenBergString.length() << '\n';

   //std::string::c_string
   //char* cgutenBergString = new char[gutenBergString.length() * 2];
   //std::strcpy(cgutenBergString, gutenBergString.c_str());

   //char* p = std::strtok(cgutenBergString, " ");
   //while (p != 0)
   //{
	  // std::cout << p << '_';
	  // p = std::strtok(NULL, " ");
   //}

   //delete[] cgutenBergString;

   //std::string::capacity
   std::cout << "Capacity: " << gutenBergString.capacity() << '\n';

   //std::string::operator[]
   std::cout << "\nFirst character using []: " << gutenBergString[0]
			 << "\nLast character using []: " << gutenBergString[gutenBergString.length() - 1];

   //std::string::at
   std::cout << "\nFirst character using at: " << gutenBergString.at (0)
			 << "\nLast character using at: " << gutenBergString.at (gutenBergString.length() - 1);

   //std::string::find and std::string::rfind
   std::string userInput{};
   std::cout << "\n\nThe string to search in the above text? ";
   std::cin >> userInput;

   std::cout << "\nOccurances of '" << userInput << "' at:\n";

   std::size_t found = gutenBergString.find(userInput);
   for (int index{}; index < 4; ++index)
   {
	   found = gutenBergString.find(userInput, found + index);
	   if (found != std::string::npos)
		   std::cout << found << ' ';
   }

   std::cout << "\nIn reverse order:\n";
   found = gutenBergString.rfind(userInput);
   for (int index{}; index < 4; ++index)
   {
	   found = gutenBergString.rfind(userInput, found - index);
	   if (found != std::string::npos)
		   std::cout << found << ' ';
   }

   //std::string::replace
   std::cout << "\n\nThe string you want to replace by *** in the above text? ";
   std::cin >> userInput;

   found = gutenBergString.find(userInput);
   for (unsigned int index{}; index < gutenBergString.size(); ++index)
   {
	   found = gutenBergString.find(userInput, found + index);
	   if (found != std::string::npos) gutenBergString.replace(found, userInput.size(), "***");
   }
   std::cout << gutenBergString;

   //std::string::erase
   std::cout << "\n\nThe string you wnat to erase from the above text? ";
   std::cin >> userInput;

   found = gutenBergString.find(userInput);
   for (unsigned int index{}; index < gutenBergString.size(); ++index)
   {
	   found = gutenBergString.find(userInput, found + index);
	   if (found != std::string::npos) gutenBergString.erase(found, userInput.size());
   }
   std::cout << gutenBergString;
   std::cout << "\nsize: " << gutenBergString.size() << "\nlenght: " << gutenBergString.length();
   std::cout << "\nCapacity: " << gutenBergString.capacity() << '\n';
}