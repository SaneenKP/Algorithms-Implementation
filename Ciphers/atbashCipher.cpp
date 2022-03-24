#include<iostream>
#include<algorithm>

std::string atbash(std::string &message){

}



int main(){
    std::string message;
    std::string cipher;

    std::cout<<"Enter the message : ";
    std::cin>>message;

    cipher = atbash(message);
    std::cout<<"Cipher message = "<<cipher;

}