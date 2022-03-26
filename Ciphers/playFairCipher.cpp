#include<iostream>
#include<vector>

void display(std::vector<std::vector<char>> &keyMatrix){
   for(auto x  : keyMatrix){
       for(auto y : x){
           std::cout<<y<<"  ";
       }
       std::cout<<"\n";
   }
}

std::string playFairCipher(std::string &message , std::string key){


    std::vector<std::vector<char>> keyMatrix(5 , std::vector<char>(5));
    display(keyMatrix);

    return message;

}


int main(){
    std::string message;
    std::string cipher;
    std::string key;

    std::cout<<"Enter the message : ";
    std::cin>>message;

    std::cout<<"\nEnter key : ";
    std::cin>>key;

    cipher = playFairCipher(message , key);

    std::cout<<"\nCipher Text = "<<cipher<<std::endl;

}