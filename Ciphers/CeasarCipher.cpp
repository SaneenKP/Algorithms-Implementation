#include<iostream>

std::string ceasarCipher(std::string &message){

    int cipherElementPos = 0;
    for (int i = 0; i < message.length(); ++i){

        int shift = (message[i] + 3);
        if (message[i] > 90)
            cipherElementPos = ( (shift > 122) ? (shift - 122) : shift);
            
        if (message[i] < 90)
            cipherElementPos = ( (shift > 90) ? (shift - 90) : shift);
        
        message[i] = cipherElementPos;
    }
    
    return message;
}

int main(){
    std::string message;
    std::string cipher;

    std::cout<<"Enter the message : ";
    std::cin>>message;

    cipher = ceasarCipher(message);
    std::cout<<"Cipher message = "<<cipher<<"\n";

}