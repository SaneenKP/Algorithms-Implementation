#include<iostream>
#include<unordered_map>
#include<random>

std::unordered_map<int , int> randomCharacterOrderGenerator(){

    std::unordered_map<int,int> randomCharactersPositions;
    std::random_device seed;
    std::mt19937 gen{seed()};
    std::uniform_int_distribution distributionForCapital{65 , 90};
    std::uniform_int_distribution distributionForSmall{97 , 122};

    int alphabets = 65;
    while (alphabets <= 90)
    {
        int randomAlphabet = distributionForCapital(gen);
        if (randomCharactersPositions.find(randomAlphabet) == randomCharactersPositions.end())
        {
            randomCharactersPositions[randomAlphabet] = alphabets;
            alphabets++;
        }
    }

    alphabets = 97;
    while (alphabets <= 122)
    {
        int randomAlphabet = distributionForSmall(gen);
        if (randomCharactersPositions.find(randomAlphabet) == randomCharactersPositions.end())
        {
            randomCharactersPositions[randomAlphabet] = alphabets;
            alphabets++;
        }
    }

    return randomCharactersPositions;

}

std::string monoalphabeticCipher(std::string &message){

    std::unordered_map<int , int> characterMap = randomCharacterOrderGenerator();
    // for (int i = 0; i < message.length(); i++)
    // {
    //     std::cout<<characterMap[(int)message[i]]<<std::endl;
    // }

    std::cout<<characterMap.size();
    
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