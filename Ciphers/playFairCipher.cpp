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

std::vector<char> generateDigrams(std::string message){

    std::vector<char> digrams; //Vector array to store the digrams.
    char a , b;                //Pointers to check for similarity.


    for (int i = 0; i < message.length(); i+=2)
    {
        //if pointer at the end and only 1 character left . Then add 'z' at the end.
        if (i < message.length() - 1)
        {
            a = message[i];
            b = message[i+1];

        }else{
            a = message[i];
            b = 'Z';
        }

        //if both pointers have same characters then push the first character and 'x'.
        //else push both the characters as they can form a digram.
        if (a == b)
        {
            digrams.push_back(message[i]);
            digrams.push_back('x');
            i-=1;
        }else{
            digrams.push_back(a);
            digrams.push_back(b);
        }
        
    }
    
    return digrams;

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

void searchKeyPosition(int first , int second , int &firstLetterPosition_i , int &firstLetterPosition_j , int &secondLetterPosition_i , int &secondLetterPosition_j , std::vector<std::vector<int>> &keyMatrix){
    
}


std::string encrypt(std::vector<char> &digrams , std::vector<std::vector<int>> &keyMatrix){

    int firstLetterPosition_i = 0;
    int firstLetterPosition_j = 0;

    int secondLetterPosition_i = 0;
    int secondLetterPosition_j = 0;

    for (int i = 0; i < digrams.size(); i+=2)
    {
       searchKeyPosition(digrams[i] , digrams[i+1] , firstLetterPosition_i , firstLetterPosition_j , secondLetterPosition_i , secondLetterPosition_j , keyMatrix);
    }
    
    return "";

}



std::string playFairCipher(std::string &message , std::string key){

    std::string cipher;

    std::vector<std::vector<int>> keyMatrix(5 , std::vector<int>(5));
    std::vector<char> digrams;

    keyMatrix = fillKeyMatrix(keyMatrix , key);
    digrams = generateDigrams(message);
    cipher = encrypt(digrams , keyMatrix);

    
    return cipher;

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