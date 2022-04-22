#include<iostream>
#include<vector>
#include<random>

class HillCipher{

    private:
    std::string message;
    std::string cipher;
    int termFrequency;
    std::vector<std::vector<int>> keyMatrix;


    public: 

    void generateKey(){

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
        setKeyMatrix(keyMatrix);
    }

    void display(){

        for(auto x : keyMatrix){

            for(auto y : x){

                std::cout<<y<<" ";
            }
            std::cout<<std::endl;
        }
        
    }

    std::string tranformMessage(std::string message){

        std::string finalMessage = "";
        for (int i = 0; i < message.length(); ++i)
        {
            //Change small to capital
            if (message[i] >= 97 && message[i] <= 122)
                message[i] = message[i] - 32;
            
            //remove spaces
            if (message[i] == ' ')
                continue;
            finalMessage += message[i];
        }

        return finalMessage;

    }


    //getters and setters
    void setMessage(std::string message){
        this->message = message;
    }

    void setCipher(std::string cipher){
        this->cipher = cipher;
    }

    void setTermFrequency(int termFrequency){
        this->termFrequency=termFrequency ;
    }

    void setKeyMatrix(std::vector<std::vector<int>> keyMatrix){
        this->keyMatrix = keyMatrix;
    }

    std::string getMessage(){
        return this->message;
    } 

    std::string getCipher(){
        return this->cipher;
    }

    int getTermFrequency(){
        return this->termFrequency;
    }

    std::vector<std::vector<int>> getKeyMatrix(){
        return this->keyMatrix;
    }


};

int main(){

    std::string message;
    std::string cipher;
    int termFrequency;

    HillCipher hillcipher;
    std::cout<<"Enter the message : ";
    getline(std::cin , message);

    hillcipher.setMessage(message);


    std::cout<<"Enter the termFrequency : ";
    std::cin>>termFrequency;

    hillcipher.setTermFrequency(termFrequency);

    hillcipher.generateKey();
    hillcipher.display();

}