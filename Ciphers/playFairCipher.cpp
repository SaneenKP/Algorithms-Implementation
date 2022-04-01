#include<iostream>
#include<vector>
#include<algorithm>

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
                        //keyMatrix[i][j] = restAlphabetList[alphabetPointer]*100;
                        keyMatrix[i][j] += restAlphabetList[alphabetPointer];
                        alphabetPointer++;
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

    for (int i = 0; i < keyMatrix.size(); ++i)
    {
        for (int j = 0; j < keyMatrix[0].size(); ++j) {

            if (keyMatrix[i][j] == first)
            {
                firstLetterPosition_i = i;
                firstLetterPosition_j = j;
            }
            else if (keyMatrix[i][j] == second)
            {
                secondLetterPosition_i = i; 
                secondLetterPosition_j = j;
            }
            
        }
        
    }
    
}

std::string encrypt(std::vector<char> &digrams , std::vector<std::vector<int>> &keyMatrix){

    int firstLetterPosition_i = 0;
    int firstLetterPosition_j = 0;

    int secondLetterPosition_i = 0;
    int secondLetterPosition_j = 0;

    std::string cipher = "";

    int firstCipherPosition_i = 0;
    int firstCipherPosition_j = 0;

    int secondCipherPosition_i = 0;
    int secondCipherPosition_j = 0;

    for (int i = 0; i < digrams.size(); i+=2)
    {
       searchKeyPosition(digrams[i] , digrams[i+1] , firstLetterPosition_i , firstLetterPosition_j , secondLetterPosition_i , secondLetterPosition_j , keyMatrix);


       if (firstLetterPosition_i != secondLetterPosition_i && firstLetterPosition_j != secondLetterPosition_j)
       {

           firstCipherPosition_i = firstLetterPosition_i;
           firstCipherPosition_j = secondLetterPosition_j;

           secondCipherPosition_i = secondLetterPosition_i;
           secondCipherPosition_j = firstLetterPosition_j;
       }

       if (firstLetterPosition_i == secondLetterPosition_i && firstLetterPosition_j != secondLetterPosition_j)
       {
           firstCipherPosition_i = firstLetterPosition_i;
           firstCipherPosition_j = (firstLetterPosition_j + 1) > 4 ? 0 : (firstLetterPosition_j + 1);

           secondCipherPosition_i = secondLetterPosition_i;
           secondCipherPosition_j = (secondLetterPosition_j + 1) > 4 ? 0 : (secondLetterPosition_j + 1);
       }

       if (firstLetterPosition_i != secondLetterPosition_i && firstLetterPosition_j == secondLetterPosition_j)
       {
           firstCipherPosition_i = (firstLetterPosition_i + 1) > 4 ? 0 : (firstLetterPosition_i + 1);
           firstCipherPosition_j = firstLetterPosition_j;

           secondCipherPosition_i = (secondLetterPosition_i + 1) > 4 ? 0 : (secondLetterPosition_i + 1);
           secondCipherPosition_j = secondLetterPosition_j;
       }
       
       
       cipher = cipher + (char)(keyMatrix[firstCipherPosition_i][firstCipherPosition_j]) + (char)(keyMatrix[secondCipherPosition_i][secondCipherPosition_j]);

    }
    
    return cipher;
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