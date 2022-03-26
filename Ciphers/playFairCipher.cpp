#include<iostream>

std::string playFairCipher(std::string &message , std::string key){



}

int main(){
    std::string message;
    std::string cipher;
    std::string key;

    std::cout<<"Enter the message : ";
    std::cin>>message;

    std::cout<<"\nEnter key : ";
    std::cin>>key;

    cipher = playFairCipher(message , key);

    std::cout<<"\n Cipher Text = "<<cipher<<std::endl;

}