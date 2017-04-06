//
// Created by Nate on 4/5/2017.
//

#ifndef DICTIONARY_KEYVALUE_H
#define DICTIONARY_KEYVALUE_H


template <class K, class V> class KeyValue
{
private:
    K key;
    V value;

public:
    K getKey() {return key;}
    V getValue() {return value;}

    KeyValue() {}
    KeyValue(K key, V value) : key(key), value(value) {}
    KeyValue(KeyValue* originalKV) : key(originalKV->getKey()), value(originalKV->getValue()) {}
};


#endif //DICTIONARY_KEYVALUE_H
