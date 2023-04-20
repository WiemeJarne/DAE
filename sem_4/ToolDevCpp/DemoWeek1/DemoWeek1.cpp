// MinecraftTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <rapidjson.h>
#include <document.h>

int main()
{
    const char* jsonContents
    { 
        R"json(
            [
                { "loc":[10 , 23 , 20] },
                { "loc":[11 , 28 , 41] },
                { "loc":[15 , -1 , 65] }
            ]
        )json"
    };

    using namespace rapidjson;
    Document jsonDoc;
    jsonDoc.Parse(jsonContents);

    if (jsonDoc.IsArray())
    {
        for (Value::ConstValueIterator it = jsonDoc.Begin(); it != jsonDoc.End(); ++it)
        {
            const Value& cube{ *it };

            /*if (cube.HasMember("x") && cube.HasMember("y") && cube.HasMember("z"))
            {*/
                const Value& loc{ cube["loc"] };

                if (loc.IsArray() && loc.Size() == 3)
                {
                    const Value& x{ loc[0] };
                    const Value& y{ loc[1] };
                    const Value& z{ loc[2] };

                    if (x.IsInt() && y.IsInt() && z.IsInt())
                    {
                        //std::cout << "{" << x.GetDouble() << "," << y.GetDouble() << "}\n";

                        printf("{%d,%d,%d}\n", x.GetInt(), y.GetInt(), z.GetInt());
                    }
                }
            //}
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file