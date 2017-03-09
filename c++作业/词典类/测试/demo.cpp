#include <iostream>  
#include "demo.h"  
  
//constructors  
  
demo::demo()  
{  
    var1 = 0x101;  
    std::cout<<"var1="<<var1<<std::endl;  
}  
  
demo::demo(int input)  
{  
    this->var1 = input;  
}  
void demo::show()  
{  
    std::cout<<"I am human being, you are computer~~\n"<<std::endl;  
    if(0==this->var1)  
        {  
            std::cout<<"error"<<std::endl;  
        }  
    else  
        std::cout<<"right"<<std::endl;  
    return;  
}  
  
demo::~demo()  
{  
}  
