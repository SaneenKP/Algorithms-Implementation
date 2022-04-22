#include<iostream>

class HillCipher{

    private:
    std::string message;
    std::string cipher;
    int termFrequency;

    public: 

    


    //getters and setters
    void setMessage(std::string value){
        message = value;
    }
    void setCipher(std::string value){
        cipher = value;
    }
    void setTermFrequency(int value){
        termFrequency = value;
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