#include<iostream>
#include<vector>
#include<algorithm>

void display(std::vector<std::vector<int>> &keyMatrix){
   for(auto x  : keyMatrix){
       for(auto y : x){
           std::cout<<y<<"  ";
       }
       std::cout<<"\n";
   }
}

std::vector<std::vector<int>> fillKeyMatrix(std::vector<std::vector<int>> &keyMatrix , std::string key){

   bool keyalphabetsoccurrence[26]{false};
   int noOfRestAlphabets = (26 - key.length());
   int restAlphabetList[noOfRestAlphabets];

   for (int i = 0; i < key.length(); ++i){
       keyalphabetsoccurrence[key[i] - 65] = true;
   }

   int j = 0;
   for (int i = 0; i < 26; ++i)
   {
       if (keyalphabetsoccurrence[i])
       {
           keyalphabetsoccurrence[i] = false;
       }else{
           restAlphabetList[j] = i+65;
           j++;
       }
   }
   
   int keyPointer = 0;
   int alphabetPointer = 0;
   for (int i = 0; i < keyMatrix.size(); i++)
   {
       for (int j = 0; j < keyMatrix[0].size(); ++j)
       {
                

                if (keyPointer != key.length())
                {
                    int keyPosition = key[keyPointer] - 65;
                    if (!keyalphabetsoccurrence[(key[keyPointer]-65)])
                    {
                        keyMatrix[i][j] = key[keyPointer];
                        keyalphabetsoccurrence[(key[keyPointer]-65)] = true;
                    }else{
                        keyPointer++;
                        keyMatrix[i][j] = key[keyPointer];
                    }
                    keyPointer++;
                }else{

                    if (i == 2 && j == 3)
                    {    
                        keyMatrix[i][j] = restAlphabetList[alphabetPointer]*100;
                        alphabetPointer++;
                        keyMatrix[i][j] += restAlphabetList[alphabetPointer];
                    }else{
                        keyMatrix[i][j] = restAlphabetList[alphabetPointer];
                    }
                    alphabetPointer++;
                }

                
       }
       
   }
   return keyMatrix;

}

std::string playFairCipher(std::string &message , std::string key){


    std::vector<std::vector<int>> keyMatrix(5 , std::vector<int>(5));
    keyMatrix = fillKeyMatrix(keyMatrix , key);
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

    std::transform(key.begin() , key.end() , key.begin() , ::toupper);
    std::transform(message.begin() , message.end() , message.begin() , ::toupper);
    cipher = playFairCipher(message , key);

    std::cout<<"\nCipher Text = "<<cipher<<std::endl;

}