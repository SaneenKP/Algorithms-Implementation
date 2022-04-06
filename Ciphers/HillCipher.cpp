#include<iostream>
#include<algorithm>

std::string hillCipher(std::string &message){

    

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
    std::string key;

    std::cout<<"Enter the message : ";
    getline(std::cin , message);

    message = removeWhiteSpace(message);

    std::cout<<"\nEnter key : ";
    std::cin>>key;

    std::transform(key.begin() , key.end() , key.begin() , ::toupper);
    std::transform(message.begin() , message.end() , message.begin() , ::toupper);

    cipher = hillCipher(message);

    std::cout<<"\nCipher Text = "<<cipher<<std::endl;
}