// bobjConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>

int main()
{
    std::ifstream inputFile("input.bobj", std::ios::binary); //open the input file
    
    if (!inputFile.is_open())
    {
        assert("failed to open input file");
    }

    std::ofstream outputFile{ "output.obj" }; //open or create output file

    if (!outputFile.is_open())
    {
        assert("failed to open output file");
    }

    //read the file
    char command{};
    while (!inputFile.eof())
    {
        inputFile.read((char*)&command, sizeof(command));

        if (command == 'v')
        {
            uint16_t amountOfVertices{};
            inputFile.read((char*)&amountOfVertices, sizeof(amountOfVertices));

            //read out all the vertices
            float number{};
            for (int vertexIndes{}; vertexIndes < amountOfVertices; ++vertexIndes)
            {
                //write a v and a space to the output file
                outputFile << "v ";

                //read in the x of the vertex
                inputFile.read((char*)&number, sizeof(number));

                //write the x value to the output file
                outputFile << std::scientific << number << ' ';

                //read in the y of the vertex
                inputFile.read((char*)&number, sizeof(number));

                //write the y value to the output file
                outputFile << std::scientific << number << ' ';

                //read in the z of the vertex
                inputFile.read((char*)&number, sizeof(number));

                //write the z value to the output file
                outputFile << std::scientific << number << ' ';

                //write an enter to the output file
                outputFile << "\n";
            }
        }

        if (command == 'f')
        {
            uint16_t amountOfFaces{};
            inputFile.read((char*)&amountOfFaces, sizeof(amountOfFaces));

            //read out all the vertices
            uint16_t number{};
            for (int faceIndex{}; faceIndex < amountOfFaces; ++faceIndex)
            {
                //write a v and a space to the output file
                outputFile << "f ";

                //read in the x of the vertex
                inputFile.read((char*)&number, sizeof(number));

                //write the x value to the output file
                outputFile << std::to_string(number) << ' ';

                //read in the y of the vertex
                inputFile.read((char*)&number, sizeof(number));

                //write the y value to the output file
                outputFile << std::to_string(number) << ' ';

                //read in the z of the vertex
                inputFile.read((char*)&number, sizeof(number));

                //write the z value to the output file
                outputFile << std::to_string(number) << ' ';

                //write an enter to the output file
                outputFile << "\n";
            }
        }

        if (command == 'c')
        {
            uint16_t commentLenght{};
            inputFile.read((char*)&commentLenght, sizeof(commentLenght));
            
            char* comment{ new char[commentLenght + 1] }; // + 1 for enter
            inputFile.read(comment, commentLenght);

            //add an enter to the end of the comment
            comment[commentLenght] = '\n';

            //write the comment to the output file
            outputFile.write(comment, commentLenght + 1);
        }
    }

    
}