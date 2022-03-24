#include<iostream>
#include <unordered_set>
#include<random>

std::string monoalphabeticCipher(std::string &message){

    std::unordered_set<int> randomCharactersPositions;

    while (randomCharactersPositions.size() != 26)
    {
        int randomAlphabetPosition = (65 + (rand() % 90));
        randomCharactersPositions.insert(randomAlphabetPosition);
    }
    
    for(auto x : randomCharactersPositions){
        std::cout<<x<<std::endl;
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