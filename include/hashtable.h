#pragma once
#include <iostream>
#define MAXSIZEHTBL 1009

typedef struct data
{
    std::string key;
    std::string phonenum;
    data* nextdata;
    data()
    {
        key="";
        phonenum="";
        nextdata=NULL;
    }
    data(std::string p_key,std::string p_phonenum)
    {
        key=p_key;
        phonenum=p_phonenum;
        nextdata=NULL;
    }
}data;

class hashtable
{
protected:
        const long int maxsizehtbl=MAXSIZEHTBL;
        data* table[MAXSIZEHTBL];
        long int hashfunct(std::string key);
public:
        hashtable();
        ~hashtable();
                int clash=0;
        void insertdata(data& d);
        void deletedata(std::string key);
        data* searchdata(std::string key);
};
