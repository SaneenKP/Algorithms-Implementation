#include<iostream>
#include<unordered_map>
#include<random>

std::unordered_map<int , int> randomCharacterOrderGenerator(){

    std::unordered_map<int,int> randomCharactersPositions;
    std::random_device seed;
    std::mt19937 gen{seed()};
    std::uniform_int_distribution dist{65 , 90};

    int alphabets = 65;
    while (alphabets <= 90)
    {
        int randomAlphabet = dist(gen);
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
    for(auto x : characterMap){
        std::cout<<x.first<<"   "<<x.second<<std::endl;
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