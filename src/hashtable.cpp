#include "hashtable.h"
bool iskeypresent(data* ptr,std::string key);
void deleterow(data* ptr);
hashtable::hashtable()
{
    for(int i=0;i<maxsizehtbl;i++)
    {
        table[i]=NULL;
    }
}
hashtable::~hashtable()
{
    for(int i=0;i<maxsizehtbl;i++)
    {
        if(table[i]!=NULL)
        {
            deleterow(table[i]);
        }
    }
}
long int hashtable::hashfunct(std::string key)
{
    long int index=0;int multiplier=0;
    for(char k : key)
    {
        index+=(int)k+(k-'a')*multiplier;
        multiplier++;
    }
    return index%maxsizehtbl;
}

void hashtable::insertdata(data& d)
{
    long int index=hashfunct(d.key);
    data *ptr = new data;
    ptr->key=d.key;
    ptr->phonenum=d.phonenum;
    if(table[index]==NULL)
    {
            table[index]=ptr;
            ptr->nextdata=NULL;
    }
    else
    {
            if(iskeypresent(table[index],d.key))
            {
                //std::cout<<"Data Already Present, Data Updated\n"<<d.key<<std::endl;
                searchdata(d.key)->phonenum=d.phonenum;
                delete ptr;
                return;
            }
            ptr->nextdata=table[index];
            table[index]=ptr;
            clash++;
            //std::cout<<"Clashes :"<<clash<<std::endl;
    }
}

void hashtable::deletedata(std::string key)
{
    long int index = hashfunct(key);
    data* ptr = table[index];
    data* prev = NULL;
    while (ptr != NULL)
    {
        if (ptr->key == key)
        {
            if (prev == NULL)
            {
                table[index] = ptr->nextdata;
            }
            else
            {
                prev->nextdata = ptr->nextdata;clash--;
            }
            delete ptr;
            return;
        }
        prev = ptr;
        ptr = ptr->nextdata;
    }
}

data* hashtable::searchdata(std::string key)
{
    long int index=hashfunct(key);
    data* ptr=table[index];
    while(ptr!=NULL)
    {
        if(ptr->key==key)
            return ptr;
        else
            ptr=ptr->nextdata;
    }
    return NULL;
}

bool iskeypresent(data* ptr,std::string key)
{
    while (ptr != NULL)
    {
        if (ptr->key == key)
        {
            return true;
        }
        ptr = ptr->nextdata;
    }
    return false;
}

void deleterow(data* ptr)
{
    data* prev=NULL;
    while (ptr != NULL)
    {
        prev=ptr;
        ptr = ptr->nextdata;
        delete prev;
    }
}
