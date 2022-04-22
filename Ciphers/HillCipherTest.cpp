#include<iostream>
#include<vector>

class HillCipher{

    private:
    std::string message;
    std::string cipher;
    int termFrequency;
    std::vector<std::vector<int>> keyMatrix;


    public: 

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
        return message;
    } 

    std::string getCipher(){
        return cipher;
    }

    int getTermFrequency(){
        return termFrequency;
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

}