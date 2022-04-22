#include<iostream>

class HillCipher{

    std::string message;
    std::string cipher;
    int termFrequency;


};

int main(){

    std::cout<<"Enter the message : ";
    getline(std::cin , message);

    std::cout<<"Enter the termFrequency : ";
    std::cin>>termFrequency;
}