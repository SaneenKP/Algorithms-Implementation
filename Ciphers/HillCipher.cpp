#include<iostream>
#include<algorithm>
#include<vector>
#include<random>

std::vector<std::vector<int>> generateKey(int termFrequency){

    std::vector<std::vector<int>> keyMatrix(termFrequency,std::vector<int>(termFrequency,0));

    std::random_device seed;
    std::mt19937 gen{seed()};
    std::uniform_int_distribution distributionForKey{1,99};

    for (int i = 0; i < termFrequency; ++i)
    {
        for (int j = 0; j < termFrequency; ++j)
        {
            keyMatrix[i][j] = distributionForKey(gen);
        }
    }

    return keyMatrix; 

}

std::string hillCipher(std::string &message , int &termFrequency){

    std::vector<std::vector<int>> keyMatrix = generateKey(termFrequency);
    
    for(auto x : keyMatrix){
        for(auto y : x){
            std::cout<<y<<" ";
        }
        std::cout<<"\n";
    }
    return "";
}

std::string removeWhiteSpace(std::string message){

    std::string finalMessage = "";
    for (int i = 0; i < message.length(); ++i)
    {
        if (message[i] == ' ')
            continue;
        finalMessage += message[i];
    }
    return finalMessage; 
}

int main(){
       
    std::string message;
    std::string cipher;
    int termFrequency;

    std::cout<<"Enter the message : ";
    getline(std::cin , message);

    std::cout<<"Enter the termFrequency : ";
    std::cin>>termFrequency;

    message = removeWhiteSpace(message);

    std::transform(message.begin() , message.end() , message.begin() , ::toupper);

    cipher = hillCipher(message , termFrequency);

    std::cout<<"\nCipher Text = "<<cipher<<std::endl;
}