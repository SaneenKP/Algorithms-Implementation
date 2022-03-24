#include<iostream>
#include <unordered_set>
#include<random>

std::string monoalphabeticCipher(std::string &message){

    std::unordered_set<char> randomCharactersPositions;

    std::random_device seed;
    std::mt19937 gen{seed()};
    std::uniform_int_distribution dist{65 , 90};

    while (randomCharactersPositions.size() != 26)
    {
        int randomAlphabet = dist(gen);
        randomCharactersPositions.insert(randomAlphabet);
    }

    for(auto x : randomCharactersPositions)
        std::cout<<x<<std::endl;
    

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