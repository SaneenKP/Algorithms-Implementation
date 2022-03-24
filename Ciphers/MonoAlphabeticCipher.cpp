#include<iostream>
#include <unordered_set>
#include<random>

std::string monoalphabeticCipher(std::string &message){

    std::unordered_set<int> randomCharactersPositions;

    std::random_device seed;
    std::mt19937 gen{seed()};
    std::uniform_int_distribution dist{65 , 90};

    for (int i = 0; i < 10; i++)
    {
        int randomAlphabetPosition = dist(gen);
        std::cout<<randomAlphabetPosition<<std::endl;
    }
    
    return message;

}

int main(){
    std::string message;
    std::string cipher;

    std::cout<<"Enter the message : ";
    std::cin>>message;

    cipher = monoalphabeticCipher(message);
    std::cout<<"Cipher message = "<<cipher<<"\n";

}