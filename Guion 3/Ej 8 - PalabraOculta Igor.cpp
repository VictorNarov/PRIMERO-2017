#include <iostream>
#include <conio.h>
#include <cstring>
#include <string.h>
#include <cctype>
#include <stdlib.h>>

using namespace std;

class HiddenWorld{
    char secretWord[15],word[15];
    int points=9,points2=9,nletter;
public:
    void start();
    int play();
    void showsecret();
};

void HiddenWorld::start(){
    char c;
    cout << "\t Hidden World " << endl;
    cout << "Input the secret world,to finish use space: ";
    int i=0;
    do{
        c = getch();
        if(c != ' '){
            secretWord[i] = c;
            word[i]='-';
            cout << word[i];
        };
        i++;
    }while(c != ' ');
    nletter = i-2;
    strupr(secretWord);
    system("cls");
};

int HiddenWorld::play(){
    char letter;
    int mal = 0;
    do{
        cout << "\t Hidden World " << endl;
        cout << "Your points are: " << points << endl;
        for(int i=0;i<=nletter;i++){
        cout << word[i];
        }
        cout << "\nInput a letter: ";
        cin >> letter;
        int i =0;
        int correcto = 0;
        while(i<=nletter&&correcto == 0){
            if(secretWord[i]==toupper(letter)){
                correcto = 1;
            }else{i++;}
        }
        if(correcto == 1){
        for(int i=0;i<=nletter;i++){
            if(secretWord[i]==toupper(letter)){
                word[i] = toupper(letter);
            }
        }
        mal = 0;
        }else{
            points--;
            points2--;
        }
        int mal = 0;
        for(int i=0;i<=nletter;i++){
            if(secretWord[i] != word[i]){
                mal=1;
            }
        }
        if(mal==0){
            points2 = 0;
        }
        system("cls");
    }while(points2!=0);
};

void HiddenWorld::showsecret(){
    if (points==0){
        cout << "\t Hidden World " << endl;
        cout << "You fails, what a pitty. The secret word was: ";
        for(int i=0;i<=nletter;i++){
            cout << secretWord[i];
        }
    }else{
        cout << "\t Hidden World " << endl;
        cout << "Congrats,you guess the word: ";
        for(int i=0;i<=nletter;i++){
            cout << secretWord[i];
        }
        cout << "\nYour left points are: " << points;
    }
};

int main()
{
    HiddenWorld h;
    h.start();
    h.play();
    h.showsecret();
    return 0;
}
