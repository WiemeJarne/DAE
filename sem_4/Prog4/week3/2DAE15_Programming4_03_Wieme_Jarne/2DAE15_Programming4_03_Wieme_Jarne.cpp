// 2DAE15_Programming4_03_Wieme_Jarne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>
#include <vector>

void ObjToBobj();
void BobjToObj();

int main()
{
    ObjToBobj();
    BobjToObj();
}

void ObjToBobj()
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
            uint16_t commentLenght{ static_cast<uint16_t>(comment.size()) };
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

void BobjToObj()
{
    std::ifstream inputFile("output.bobj", std::ios::binary); //open the input file

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
        inputFile.read(reinterpret_cast<char*>(&command), sizeof(command));

        if (command == 'v')
        {
            uint16_t amountOfVertices{};
            inputFile.read(reinterpret_cast<char*>(&amountOfVertices), sizeof(amountOfVertices));

            //read out all the vertices
            float number{};
            for (int vertexIndex{}; vertexIndex < amountOfVertices; ++vertexIndex)
            {
                //write a v and a space to the output file
                outputFile << "v ";

                //read in the x of the vertex
                inputFile.read(reinterpret_cast<char*>(&number), sizeof(number));

                //write the x value to the output file
                outputFile << std::scientific << number << ' ';

                //read in the y of the vertex
                inputFile.read(reinterpret_cast<char*>(&number), sizeof(number));

                //write the y value to the output file
                outputFile << std::scientific << number << ' ';

                //read in the z of the vertex
                inputFile.read(reinterpret_cast<char*>(&number), sizeof(number));

                //write the z value to the output file
                outputFile << std::scientific << number;

                //write an enter to the output file
                outputFile << "\n";
            }
        }
        else if (command == 'f')
        {
            uint16_t amountOfFaces{};
            inputFile.read(reinterpret_cast<char*>(&amountOfFaces), sizeof(amountOfFaces));

            //read out all the vertices
            uint16_t number{};
            for (int faceIndex{}; faceIndex < amountOfFaces; ++faceIndex)
            {
                //write a v and a space to the output file
                outputFile << "f ";

                //read in the x of the face
                inputFile.read(reinterpret_cast<char*>(&number), sizeof(number));

                //write the x value to the output file
                outputFile << std::to_string(number) << ' ';

                //read in the y of the face
                inputFile.read(reinterpret_cast<char*>(&number), sizeof(number));

                //write the y value to the output file
                outputFile << std::to_string(number) << ' ';

                //read in the z of the face
                inputFile.read(reinterpret_cast<char*>(&number), sizeof(number));

                //write the z value to the output file
                outputFile << std::to_string(number);

                //write an enter to the output file
                outputFile << "\n";
            }
        }
        else if (command == 'n')
        {
            uint16_t amountOfNormals{};
            inputFile.read(reinterpret_cast<char*>(&amountOfNormals), sizeof(amountOfNormals));

            //read out all the vertices
            float number{};
            for (int normalIndex{}; normalIndex < amountOfNormals; ++normalIndex)
            {
                //write a v and a space to the output file
                outputFile << "vn ";

                //read in the x of the vertex
                inputFile.read(reinterpret_cast<char*>(&number), sizeof(number));

                //write the x value to the output file
                outputFile << std::scientific << number << ' ';

                //read in the y of the vertex
                inputFile.read(reinterpret_cast<char*>(&number), sizeof(number));

                //write the y value to the output file
                outputFile << std::scientific << number << ' ';

                //read in the z of the vertex
                inputFile.read(reinterpret_cast<char*>(&number), sizeof(number));

                //write the z value to the output file
                outputFile << std::scientific << number;

                //write an enter to the output file
                outputFile << "\n";
            }
        }
        else if (command == 'c')
        {
            uint16_t commentLenght{};
            inputFile.read(reinterpret_cast<char*>(&commentLenght), sizeof(commentLenght));

            char* comment{ new char[commentLenght + 1] }; // + 1 for enter
            inputFile.read(comment, commentLenght);

            //add an enter to the end of the comment
            comment[commentLenght] = '\n';

            //write the comment to the output file
            outputFile.write(comment, commentLenght + 1);
        }
    }

    std::cout << "conversion form bobj to obj succeded\n";
}