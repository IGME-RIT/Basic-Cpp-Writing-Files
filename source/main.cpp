/*
C++ Writing Files
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

// File writing also uses streams! What a surprise!

// First, we're going to include fstream form the standard librady.
#include <fstream>
#include <iostream>
#include <string>


int main()
{
    {
        std::string fileName = "../assets/test.txt";
        std::ofstream file = std::ofstream(fileName);   // ofstream is the opposite of ifstream, and lets us write to files.

        if (file.is_open()) // Check if the file is open!
        {
            std::cout << "File" << fileName << " opened for writing!" << std::endl;

            std::cout << "Type things! (q to quit)" << std::endl;

            std::string input;

            while (std::getline(std::cin, input))   // Loop and read from text input
            {                                       // We can do this because cin is a stream object
                if (input == "q")
                {
                    // If the only thing pressed is q, break out of the loop and quit
                    break;
                }
                else
                {
                    // Otherwise output to the file.
                    file << input << std::endl;
                }
            }
        }
    }
    std::cout << "Go check the file now!" << std::endl;
    std::cin.get();



    {
        std::string fileName = "../assets/test.txt";
        std::ofstream file = std::ofstream(fileName, std::ios_base::app);   // If you want to append to the end of a file isntead of overwriting it,
                                                                            // put ios_base::app in the constructor for ofstream.
        if (file.is_open()) // Check if the file is open!
        {
            std::cout << "File" << fileName << " opened for writing!" << std::endl;
            // This time we're just going to write out to the file.
            file << "TEST WRITE TO FILE." << std::endl;
        }
    }
    std::cout << "Done writing to file" << std::endl;
    std::cin.get();
}