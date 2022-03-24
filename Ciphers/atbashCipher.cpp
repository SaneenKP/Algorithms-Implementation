#include<iostream>
#include<algorithm>

std::string atbash(std::string &message){
    for (int i = 0; i < message.length();++i){
        if (message[i] > 90)
            message[i] = (90 - ((message[i] - 32)-65));
    }

    return message;
    

}



int main(){
    std::string message;
    std::string cipher;

    std::cout<<"Enter the message : ";
    std::cin>>message;

    cipher = atbash(message);
    std::cout<<"Cipher message = "<<cipher;

}