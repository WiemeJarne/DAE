// ParseSvgFile.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include "structs.h"
#include <sstream>
#include <fstream>

void ReadFromFile(const std::string filePath);

int main()
{
	ReadFromFile("Resources/Level.svg");
}

Point2f ToPoint2f(const std::string& point2fStr)
{
	std::stringstream stringstream{ point2fStr };

	std::string xValue{ };
	std::string yValue{ };

	std::getline(stringstream, xValue, ',');
	std::getline(stringstream, yValue, ',');

	return Point2f{ std::stof(xValue), std::stof(yValue) };
}

std::string GetAttributeValues(const std::string& attrName, const std::string& element)
{
	size_t attributeBeginPos{ element.find(R"(")") + 1 };
	size_t attributeEndPos{ element.find(" ", attributeBeginPos) };

	std::string attribute{ };
	std::stringstream elementStringstream{ element };

	while (attributeBeginPos < element.find("/"))
	{
		size_t PointLenght{ attributeEndPos - attributeBeginPos };

		attribute = element.substr(attributeBeginPos, PointLenght);

		if (attribute == "")
		{
			++attributeBeginPos;
			attributeEndPos = element.find(" ", attributeBeginPos);
		}
		else if (attribute.find("m") != std::string::npos)
		{
			std::cout << "\nCommand: m\n";
			++attributeBeginPos;
		}
		else if (attribute.find("M") != std::string::npos)
		{
			std::cout << "\nCommand: M\n";
			++attributeBeginPos;
		}
		else if (attribute.find("l") != std::string::npos)
		{
			std::cout << "\nCommand: l\n";
			++attributeBeginPos;
		}
		else if (attribute.find("L") != std::string::npos)
		{
			std::cout << "\nCommand: L\n";
			++attributeBeginPos;
		}
		else if (attribute.find("z") != std::string::npos)
		{
			std::cout << "\nCommand: z\n";
			++attributeBeginPos;
		}
		else if (attribute.find("Z") != std::string::npos)
		{
			std::cout << "\nCommand: Z\n";
			++attributeBeginPos;
		}
		else if (attribute.find("/>") == std::string::npos && attribute != R"(")")
		{
			std::cout << '[' << ToPoint2f(attribute).x << ", " << ToPoint2f(attribute).y << "]\n";

			attributeBeginPos = attributeEndPos + 1;
			attributeEndPos = element.find(" ", attributeBeginPos);
		}
	}

	return attribute;
}

void ReadFromFile(const std::string filePath)
{
	std::ifstream stringstream{ filePath };
	std::string element{ };

	std::string pattern{ "^d=" };
	
	while (stringstream)
	{
		std::getline(stringstream, element);

		if (element.find("<path") != std::string::npos)
		{
			std::getline(stringstream, element);
			std::getline(stringstream, element);
			std::getline(stringstream, element);

			GetAttributeValues("d=", element);
		}
	}
}