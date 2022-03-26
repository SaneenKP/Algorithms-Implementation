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

std::vector<std::vector<char>> fillKeyMatrix(std::vector<std::vector<char>> &keyMatrix , std::string key){

   bool keyalphabetsoccurrence[26]{false};

   for (int i = 0; i < key.length(); ++i){
       if (key[i] <= 92)
           keyalphabetsoccurrence[key[i] - 65] = true;
       if (key[i] >= 97)
           keyalphabetsoccurrence[key[i] - 97] = true;
   }
    
    for (int i = 0; i < 26; ++i)
    {
        std::cout<<keyalphabetsoccurrence[i]<<std::endl;
    }
    
   
//    int keyCount = 0;
//    for(auto x  : keyMatrix){
//        for(auto y : x){
//            if (keyCount < key.length())
//            {
//                 if (!keyalphabetsoccurrence[y])
//                 {
//                     y = key[keyCount];
//                     keyalphabetsoccurrence[y] = true;
//                     keyCount++;
//                 }
//            }else{

//            }
           
//        }
//    }


    return keyMatrix;

}

std::string playFairCipher(std::string &message , std::string key){


    std::vector<std::vector<char>> keyMatrix(5 , std::vector<char>(5));
    keyMatrix = fillKeyMatrix(keyMatrix , key);
    


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