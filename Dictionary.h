//
// Created by Nate on 4/5/2017.
//

#ifndef DICTIONARY_DICTIONARY_H
#define DICTIONARY_DICTIONARY_H

#include "KeyValue.h"
#include <string>
#include <iostream>

template <class K, class V> class Dictionary
{
private:
    unsigned int count;
    unsigned int maxIndex;
    KeyValue<K,V>* dictList;

public:
    Dictionary() : maxIndex(9), count(0)
    {
        dictList = new KeyValue<K,V>[10];
    }
    Dictionary(unsigned int size) : maxIndex(size - 1), count(0)
    {
        dictList = new KeyValue<K,V>[size];
    }

    Dictionary(Dictionary* originalDict) : count(originalDict->getCount()), maxIndex(originalDict->getMaxIndex())
    {
        dictList = new KeyValue<K,V>[maxIndex + 1];
        for (unsigned int i = 0; i <= maxIndex; i++)
        {
            try
            {
                dictList[i] = originalDict->getByIndex(i);
            }
            catch(const char* e)
            {
                if (e == "Index Out of Range")
                {
                    i = maxIndex + 1; //Breaks the for loop once an empty index is encountered.
                }
                else
                {
                    std::cout << e << std::endl;
                }
            }
        }
    }

    void add(K key, V value)
    {
        bool inserted = false;

        for (unsigned int i = 0; i <= maxIndex; i++)
        {
            try
            {
                getByIndex(i);
            }
            catch(const char* e)
            {
                if (e == "Index Out of Range")
                {
                    dictList[i] = KeyValue<K, V>(key, value); //Creates and assigns a new KeyValue when an empty index is encountered.
                    count++;
                    i = maxIndex + 1; //Breaks the for loop when the value has been assigned.
                    inserted = true;
                }
                else
                {
                    throw e;
                }
            }
        }

        if (!inserted)
        {
            resize((maxIndex + 1) * 2);
            add(key, value);
        }
    }

    unsigned int getCount(){return count;}
    unsigned int getMaxIndex(){return maxIndex;}

    KeyValue<K, V> getByKey(K key)
    {
        for (unsigned int i = 0; i <= maxIndex; i++)
        {
            try
            {
                return getByIndex(i);
            }
            catch(const char* e)
            {
                throw e;
            }
        }
    }

    KeyValue<K, V> getByIndex(unsigned int index)
    {
        if (index >= count)
        {
            throw "Index Out of Range";
        }
        else
        {
            return dictList[index];
        }
    }

    void removeByKey(K key)
    {
        for (unsigned int i = 0; i <= maxIndex; i++)
        {
            try
            {
                removeByIndex(i);
            }
            catch(const char* e)
            {
                throw e;
            }
        }
    }

    void removeByIndex(unsigned int index)
    {
        if (index >= count)
        {
            throw "Index Out of Range";
        }
        else
        {
            delete (dictList + index);
            count--;

            for (unsigned int i = index + 1; i <= maxIndex; i++)
            {
                dictList[i - 1] = dictList[i];
                delete (dictList + i);
            }
        }
    }

    void resize(unsigned int size)
    {
        KeyValue<K, V>* newDictList = new KeyValue<K, V>[size];

        for (unsigned int i = 0; i <= maxIndex; i++)
        {
            newDictList[i] = dictList[i];
        }

        delete dictList;
        dictList = newDictList;
        newDictList = nullptr;
    }

    ~Dictionary()
    {
        for (unsigned int i = 0; i <= maxIndex; i++)
        {
            delete (dictList + i);
        }

        delete dictList;
        dictList = nullptr;
    }
};


#endif //DICTIONARY_DICTIONARY_H
