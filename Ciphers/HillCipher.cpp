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

std::vector<int> generateMessageValues(std::string &message , int &termFrequency){

    int remaining = message.length() % termFrequency;
    while (remaining-- != 0)
        message.push_back('X');
    
    std::vector<int> messageValues;

    for (int i = 0; i < message.length(); ++i)
        messageValues.push_back(message[i] - 65);
     
    return messageValues;
}

std::vector<int> multiplyMatrix(int termFrequency, std::vector<int> term , std::vector<std::vector<int>> &keyMatrix){

    std::vector<int> result(termFrequency,0);
    for (int i = 0; i < termFrequency; ++i)
    {
        for (int j = 0; j < keyMatrix.size(); ++j)
        {
            result[i] = result[i] + (term[j] * keyMatrix[j][i]); 
        }
    }

    return result;
}

void fillCipherValues(std::vector<int> term , std::vector<int> &cipherValues){
    
}

std::string hillCipher(std::string &message , int &termFrequency){

    
    std::vector<std::vector<int>> keyMatrix = generateKey(termFrequency);
    std::vector<int> messageValues = generateMessageValues(message , termFrequency);
    std::vector<int> cipherValues;

    std::vector<int> term(termFrequency,0);
    for (int i = 0; i < messageValues.size(); ++i)
    {
        if (i == (termFrequency-1))
        {
            term = multiplyMatrix(termFrequency ,  term , keyMatrix);
        }else{
            term.push_back(messageValues[i]);
        }
        
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