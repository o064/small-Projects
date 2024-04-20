#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
class HangmanGame{
private:
    vector<string> word_list;
    string secret_word;
    vector<char> guessed_list;
    string displayed_word;
    int max_attmpts;
    int attempts_left;
public:
    HangmanGame(vector<string> words):word_list(words){
        max_attmpts = 6;
        attempts_left =max_attmpts;
        displayed_word="--";

    }
    ~HangmanGame() =default;
    void generate_word(){
        srand(time(NULL));
        int index = rand()%(word_list.size()- 1);
        secret_word = word_list[index];
//        cout << "Enter your secret word: \n";
//        string w;
//        cin >>w;
//        while(w.size() < 3){
//            cout << "the word at least should consist of three letters\n";
//            w.clear();
//            cin.ignore();
//            cin >> w ;
//        }
//        secret_word =w;
        // int s=0;
        // while(s != w.size() || !(cin>>s)){
        //     cout << "the size is not correct \n";
        // }
        // size =s ;
    }
    void display_word(){
        displayed_word.clear();
        for(char letter : secret_word){
            if(find(guessed_list.begin(),guessed_list.end(),letter) != guessed_list.end()){
                displayed_word += letter;
                cout << letter << " ";
            }else{
                displayed_word += '-';
                cout <<"- ";
            }
        }
        cout << endl;
    }
    bool guess_letter(char letter){
        guessed_list.push_back(letter);
        if(find(secret_word.begin(),secret_word.end(),letter) != secret_word.end()){
            return true;
        }else{
            attempts_left--;
            return false;
        }
    }
    bool game_over(){
        if(attempts_left <=0){
            cout << "Game over!You lose \n";
            cout << "The secret word was : " <<secret_word << endl;
            return true;
        }
        else if(find(displayed_word.begin(),displayed_word.end(),'-') == displayed_word.end()){
            cout << "Congratulations!You won\n";
            cout << "The secret word was : " <<secret_word << endl;
            return true;
        }
        return false;
    }
    void display_guesslist(){
        cout << "your guess list is : \n";
        for(char l : guessed_list){
            cout << l << " | ";
        }
        cout << endl;
    }
    void play(){
        cout << "------------------------\n";
        cout << "Welcome to hangman game \n";
        cout << "------------------------\n";
        generate_word();
        while(true){
            cout<< "------------------------------\n";
            cout << "attempts left : " << attempts_left <<endl ;
            display_word();
            display_guesslist();
            if(game_over()){
                break;
            }
            cout << "enter a letter : " ;
            char letter;
            cin >> letter;
            if(!isalpha(letter)){
                cout << "this is not a letter \n";
                continue;
            }
            letter = tolower(letter);
            if(find(guessed_list.begin(),guessed_list.end(), letter)
               != guessed_list.end()){
                cout << "You already guessed this letter\n";
                continue;
            }
            if(guess_letter(letter))
                cout << "your guess is correct \n" ;
            else
                cout << "not correct\n";
        }
        cout << "thanks for playing\n";
    }
int main(){
    vector<string> words = {
            "omar","physics","maths","newton","secret","yaso","energizer","pourshe","andro"
    };
    HangmanGame h1(words);
    h1.play();
    return 0;

}