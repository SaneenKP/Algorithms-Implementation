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
   int noOfRestAlphabets = (26 - key.length());
   char restAlphabetList[noOfRestAlphabets];

   for (int i = 0; i < key.length(); ++i){
       keyalphabetsoccurrence[key[i] - 97] = true;
   }

   int j = 0;
   for (int i = 0; i < 26; ++i)
   {
       if (keyalphabetsoccurrence[i])
       {
           keyalphabetsoccurrence[i] = false;
       }else{
           restAlphabetList[j] = i+97;
           j++;
       }
   }
   
   int keyPointer = 0;
   int alphabetPointer = 0;
   for (int i = 0; i < keyMatrix.size(); i++)
   {
       for (int j = 0; j < keyMatrix[0].size(); ++j)
       {
                if (i == 2 && j == 4)
                    alphabetPointer++;
                
                if (keyPointer != key.length())
                {
                    int keyPosition = key[keyPointer] - 97;
                    if (!keyalphabetsoccurrence[(key[keyPointer]-97)])
                    {
                        keyMatrix[i][j] = key[keyPointer];
                        keyalphabetsoccurrence[(key[keyPointer]-97)] = true;
                    }else{
                        keyMatrix[i][j] = restAlphabetList[alphabetPointer];
                        alphabetPointer++;
                    }
                    keyPointer++;
                }else{
                    keyMatrix[i][j] = restAlphabetList[alphabetPointer];
                    alphabetPointer++;
                }
       }
       
   }
   display(keyMatrix);
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