//
// Created by Nate on 4/5/2017.
//

#include "TestSuites.h"

void TestMain::testConstructors() {
    std::cout << std::endl << "Testing Default Constructor" << std::endl;
    Dictionary<int, int> dict;
    try {
        if (dict.getCount() != 0)
            std::cout << "Failed to initialize count. Expected 0, got " << dict.getCount() << "." << std::endl;
        if (dict.getMaxIndex() != 9)
            std::cout << "Failed to initialize maxIndex. Expected 9, got " << dict.getMaxIndex() << "." << std::endl;
    }
    catch (char const* e) {
        std::cout << e << std::endl;
    }


    std::cout << std::endl << "Testing Constructor with unsigned int" << std::endl;
    delete &dict;
    dict = Dictionary<int, int>(15);
    try {
        if (dict.getCount() != 0)
            std::cout << "Failed to initialize count. Expected 0, got " << dict.getCount() << "." << std::endl;
        if (dict.getMaxIndex() != 14)
            std::cout << "Failed to initialize maxIndex. Expected 14, got " << dict.getMaxIndex() << "." << std::endl;
    }
    catch (char const* e) {
        std::cout << e << std::endl;
    }


    std::cout << std::endl << "Testing Copy Constructor" << std::endl;
    Dictionary<int, int> dict2(dict);

    try {
        if (dict2.getCount() != 0)
            std::cout << "Failed to initialize count. Expected 0, got " << dict2.getCount() << "." << std::endl;
        if (dict2.getMaxIndex() != 14)
            std::cout << "Failed to initialize maxIndex. Expected 14, got " << dict2.getMaxIndex() << "." << std::endl;
    }
    catch(char const* e)
    {
        std::cout << e << std::endl;
    }
}
void TestMain::testAdd()
{
    std::cout << std::endl << "Testing Add" << std::endl;
    Dictionary<int, int> dict;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Testing insert #" << i+1 << "." << std::endl;
        try
        {
            dict.add(i,2*i);
        }
        catch(char const* e)
        {
            std::cout << e << std::endl;
        }
    }

    std::cout << "Testing Automatic Resize" << std::endl;
    try
    {
        dict.add(10, 20);
    }
    catch(char const* e)
    {
        std::cout << e << std::endl;
    }

    try
    {
        if (dict.getMaxIndex() != 19)
            std::cout << "Failed to resize correctly. Expected new maxIndex of 19, but got " << dict.getMaxIndex() << "." << std::endl;
        for (int i = 0; i <= dict.getMaxIndex(); i++)
        {
            if (dict.getByIndex(i).getValue() != 2*i)
            {
                std::cout << "Failed to resize correctly. Expected value of " << 2*i << " at " << i << ", but got " << dict.getByIndex(i).getValue() << "." << std::endl;
            }
        }
    }
    catch(char const* e)
    {
        std::cout << e << std::endl;
    }
}

void TestMain::testFind()
{
    std::cout << std::endl << "Testing Find" << std::endl;

    std::cout << "Testing Get By Index" << std::endl;
    Dictionary<int, int> dict;
    for (int i = 0; i < 10; i++)
    {
        try
        {
            dict.add(i, i*2);
        }
        catch(char const* e)
        {
            std::cout << e << std::endl;
        }
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        try
        {
            if (dict.getByIndex(i).getValue() != i*2)
            {
                std::cout << "Failed to find KeyValue at index " << i << ". Expected value of " << i*2 << ", but got " << dict.getByIndex(i).getValue() << std::endl;
            }
        }
        catch(char const* e)
        {
            std::cout << e << std::endl;
        }
    }

    std::cout << "Testing Get By Key" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        try
        {
            if (dict.getByKey(i).getValue() != i*2)
            {
                std::cout << "Failed to find KeyValue at index " << i << ". Expected value of " << i*2 << ", but got " << dict.getByKey(i).getValue() << std::endl;
            }
        }
        catch(char const* e)
        {
            std::cout << e << std::endl;
        }
    }
}

void TestMain::testRemove()
{
    std::cout << std::endl << "Testing Remove" << std::endl;

    Dictionary<int, int> dict;
    for (int i = 0; i < 10; i++)
    {
        try
        {
            dict.add(i, i*2);
        }
        catch(char const* e)
        {
            std::cout << e << std::endl;
        }
    }

    std::cout << "Testing Remove by Index" << std::endl;

    try
    {
        dict.removeByIndex(6);
    }
    catch(char const* e)
    {
        std::cout << e << std::endl;
    }

    try
    {
        if (dict.getByIndex(6).getValue() != 14)
            std::cout << "Failed to remove index 6. Expected index 6 to have value 14, but got " << dict.getByIndex(6).getValue() << "." << std::endl;
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    }

    try
    {
        dict.removeByIndex(5);
    }
    catch(char const* e)
    {
        std::cout << e << std::endl;
    }

    try
    {
        if (dict.getByIndex(5).getValue() != 14)
            std::cout << "Failed to remove index 5. Expected index 5 to have value " << 14 << ", but got " << dict.getByIndex(5).getValue() << "." << std::endl;
    }
    catch(char const* e)
    {
        std::cout << e << std::endl;
    }

    std::cout << "Testing Remove By Key" << std::endl;
    bool didntRemove = true;

    try
    {
        dict.removeByKey(1);
    }
    catch(char const* e)
    {
        std::cout << e << std::endl;
    }

    try
    {
        dict.getByKey(1);
    }
    catch(char const* e)
    {
        if (e == "Index Out of Range")
        {
            didntRemove = false;
        }
    }

    if (didntRemove)
        std::cout << "Failed to remove key 1." << std::endl;

    didntRemove = true;

    try
    {
        dict.removeByKey(5);
    }
    catch(char const* e)
    {
        std::cout << e << std::endl;
    }

    try
    {
        dict.getByKey(5);
    }
    catch(char const* e)
    {
        if (e == "Index Out of Range")
        {
            didntRemove = false;
        }
    }

    if (didntRemove)
        std::cout << "Failed to remove key 5." << std::endl;
}

void TestMain::testResize()
{
    std::cout << std::endl << "Testing Resize" << std::endl;
    Dictionary<int, int> dict;

    try
    {
        dict.resize(20);
    }
    catch(const char * e)
    {
        std::cout << e << std::endl;
    }

    if (dict.getMaxIndex() != 19)
        std::cout << "Failed to resize. Expected new max index of 19, but got " << dict.getMaxIndex() << "." << std::endl;
}
