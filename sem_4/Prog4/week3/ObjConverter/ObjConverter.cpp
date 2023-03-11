// ObjConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>
#include <vector>

int main()
{
    std::string filePath{ "input.obj" };

    std::ifstream inputFile{ filePath }; //open the input file
    
    if (!inputFile.is_open())
    {
        assert("failed to open file");
    }

    std::ofstream outputFile{ "output.bobj", std::ios::binary }; //open or create output file

    if (!outputFile.is_open())
    {
        assert("failed to open output file");
    }

    //read the file
    std::string command{};
    uint16_t amountOfVertices{};
    uint16_t amountOfNormals{};
    uint16_t amountOfFaces{};
    std::streampos firstVPos{ -1 }; //the position in the file of the first v
    std::streampos firstFPos{ -1 }; //the position in the file of the first f
    std::streampos firstNvPos{ -1 }; //the position in the file of the first vn
    std::vector<float> vertices{};
    std::vector<uint16_t> faces{};
    std::vector<float> normals{};
    while (!inputFile.eof()) //loop over the input file
    {
        inputFile >> command; //get the next word

        if (command == "v")
        {
            if (firstVPos == -1)
            {
                firstVPos = outputFile.tellp();
            }

            ++amountOfVertices;

            //read in the 3 floats
            float x, y, z;

            inputFile >> x >> y >> z;

            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
        }
        else if (command == "f")
        {
            if (firstFPos == -1)
            {
                firstFPos = outputFile.tellp();
            }
        
            ++amountOfFaces;
        
            //read in 3 ints
            uint16_t x, y, z;
            
            inputFile >> x >> y >> z;

            faces.push_back(x);
            faces.push_back(y);
            faces.push_back(z);
        }
        else if (command == "vn")
        {
            if (firstNvPos == -1)
            {
                firstNvPos = outputFile.tellp();
            }

            ++amountOfNormals;

            //read in the 3 floats
            float x, y, z;

            inputFile >> x >> y >> z;

            normals.push_back(x);
            normals.push_back(y);
            normals.push_back(z);
        }

        if (command.find("#") != std::string::npos)
        {
            std::string line{};
            std::getline(inputFile, line); // get the comment line
            std::string comment{ "#" + line }; // add the hashtag to the front of the comment line
        
            //write a c to the output file
            const char c{ 'c' };
            outputFile.write(reinterpret_cast<const char*>(&c), sizeof(c));

            //write how long the string is to the output file
            uint16_t commentLenght{static_cast<uint16_t>(comment.size()) };
            outputFile.write(reinterpret_cast<const char*>(&commentLenght), sizeof(commentLenght));
        
            //write the comment to the output file
            outputFile.write(comment.c_str(), sizeof(char) * commentLenght);
        
            std::stringstream ss{ line };
            std::string temp{};
            uint16_t num{};
        
            while (!ss.eof())
            {
                ss >> temp; //take the next word in the ss
        
                if (std::stringstream(temp) >> num)
                    break;
            }
        }
    }

    //write a v and the amount of vertices to the output file
     const char v{ 'v' };
     outputFile.write(reinterpret_cast<const char*>(&v), sizeof(v));
     outputFile.write(reinterpret_cast<const char*>(&amountOfVertices), sizeof(amountOfVertices));

     for (const auto& number : vertices)
     {
         outputFile.write(reinterpret_cast<const char*>(&number), sizeof(number));
     }

     //write an f and the amount of faces to the output file
     const char f{ 'f' };
     outputFile.write(reinterpret_cast<const char*>(&f), sizeof(f));
     outputFile.write(reinterpret_cast<const char*>(&amountOfFaces), sizeof(amountOfFaces));

     for (const auto& number : faces)
     {
         outputFile.write(reinterpret_cast<const char*>(&number), sizeof(number));
     }

     //write an n and the amount of normal to the output file
     const char n{ 'n' };
     outputFile.write(reinterpret_cast<const char*>(&n), sizeof(n));
     outputFile.write(reinterpret_cast<const char*>(&amountOfNormals), sizeof(amountOfNormals));

     for (const auto& number : normals)
     {
         outputFile.write(reinterpret_cast<const char*>(&number), sizeof(number));
     }

     std::cout << "conversion form obj to bobj succeded\n";
}
