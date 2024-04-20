#include<iostream>
#include<string>
#include<vector>
#include <cstdlib>
using namespace std;
class to_do_item{
    private:
        int id;
        string description;
        bool completed;
    public :
    to_do_item(): id(0), description(""), completed(false){};
    ~to_do_item()=default;
    int getid(){return id;}
    string getdescription(){return description;}
    bool iscompleted(){return completed;}
    void create(string new_description){
        description =new_description;
        // id = rand()%100 + 1;
        id = rand()%100 +1 ;
    }
    void compeleted(){
        completed =true ;
    }


};

int main(){
    char input_option;
    int input_id;
    string input_description;
    vector<to_do_item> todoitems;
    vector<to_do_item> ::iterator it;
    while(true){
        system("cls");
        cout << "----------------------------------------------\n";
        cout << "----------------------------------------------\n";
        cout<< "Welcome to the v.0.3.0 of my to do list program\n";
        cout << "----------------------------------------------\n";
        cout << "----------------------------------------------\n";
        if(todoitems.empty()){
            cout << "let us add your first To do\n\n";
        }
        for(it = todoitems.begin() ; it != todoitems.end(); it++){
            string completed = it->iscompleted() ? "done" : "not done";
            cout <<  it->getid() << " | " << it->getdescription() << " | " <<completed <<endl;
        }
        cout << "------------------\n";
        cout << "[a] add a Todo\n"; 
        cout << "[b] complete a Todo\n";
        cout << "[c] remove a Todo\n"; 
        cout << "[q] Quit\n"; 
        cout << "------------------\n";
        cout << "choice : "; 
        cin >> input_option;
        if(input_option == 'q'){
            cout << "have a nice day\n--------------\nprogram finished\n";
            break;
        }else if(input_option == 'b'){
            cout << "Enter your to do id: ";
            cin >> input_id;
            for(it = todoitems.begin() ; it != todoitems.end(); it++){
                if(input_id == it->getid()){
                    if(it->iscompleted()){
                        cout <<"you have already marked this as completed"<< endl;
                    }else{
                        it->compeleted();
                    }
                    break;
                }
                if(it == todoitems.end()-1){
                    cout << "this id doesn't exist, please enter valid id \n";
                    cout << "Enter your to do id: ";
                    cin >> input_id;
                    it = todoitems.begin();
                }
            }
        }else if(input_option == 'a'){
            cout<<"enter your task name: "<< endl;
            cin.clear();
            cin.ignore();
            getline(cin,input_description);
            if(input_description.empty()){
                cout << "you can't enter empty string\n";
            }else{
                to_do_item newitem;
                newitem.create(input_description);
                todoitems.push_back(newitem);
            }
        }else if(input_option == 'c'){
            cout << "enter the todo id: ";
            cin >> input_id;
            for(it = todoitems.begin() ; it != todoitems.end(); it++){
                if(input_id == it->getid()){
                    todoitems.erase(it);
                    break;
                }
            }
        }else{
            cout << "this option doesn't exist\n";
        }
    }


}