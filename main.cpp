#include <iostream>
#include <PhoneBook.h>
#include <stdexcept>
#include <limits>
int main()
{
    PhoneBook book;
    book.loadfromfile();

    int option=0;bool quit=false;

    while(!quit)
    {
        std::cout<<"What would you like to do : "<<std::endl;;
        std::cout<<"1.)Print Phone Book"<<std::endl;
        std::cout<<"2.)Update/Insert a Record"<<std::endl;
        std::cout<<"3.)Delete a record"<<std::endl;
        std::cout<<"4.)Search "<<std::endl;
        std::cout<<"5.)Exit"<<std::endl;
        std::cout<<"Option : ";
        std::cin>>option;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch(option)
        {
        case 1:
            book.printphonebook("");
            std::cout<<book.clash;
            break;
        case 2:
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string key="",number="";
                std::cout<<"Enter the name of the Person to enter/update : ";
                getline(std::cin, key);
                std::cout<<"Enter the phone number of the person : ";
                getline(std::cin, number);
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else
                {
                    book.addperson(data(key,number));
                }
            }
            break;
        case 3:
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string key="";
                std::cout<<"Enter the name of the Person to delete : ";
                getline(std::cin, key);
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else
                {
                    book.deletedata(key);
                }
            }
            break;
        case 4:
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string key="";
                std::cout<<"Enter the name to search : ";
                getline(std::cin, key);
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else
                {
                    book.printphonebook(key);
                }
            }
            break;
        case 5:
            quit=true;
            break;
        default:
            break;
        }
    }
    book.loadintofile();
    return 0;
}
