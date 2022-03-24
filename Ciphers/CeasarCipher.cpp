#include<iostream>

int main(){
    std::string message;
    std::string cipher;

    std::cout<<"Enter the message : ";
    std::cin>>message;

    cipher = ceasarCipher(message);
    std::cout<<"Cipher message = "<<cipher<<"\n";

}