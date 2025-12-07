#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//FUNCTION DECLARATIONS
void createAccount(string &name, string &password);
bool login(string name, string password);

void mainMenu(string username);
string detectMood();
void moodRecommendations(string mood);

void recommendMovies(string mood, string favMovies[], int &favIndex);
void recommendBooks(string mood, string favBooks[], int &favBookIndex);

void showFavourites(string favMovies[], int favIndex, string favBooks[], int favBookIndex);

void gameMenu();
void playScrambleGame();
void playWordChainGame();


int main() {
    string username, password;
    int choice;

    cout<<"\n========================================";
    cout<<"\n     MOOD BASED MEDIA SYSTEM";
    cout<<"\n========================================\n";

    while(true){
        cout<<"1. Create Account"<<endl;
        cout<<"2. Login"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>choice;

        if(choice==1)
            createAccount(username, password);

        else if(choice==2){
            if(login(username, password)){
                cout<<"Login Successful!"<<endl;
                mainMenu(username);
            } else{
                cout<<"\nIncorrect username or password."<<endl;
            }
        }
        else if(choice==3){
            cout<<"\nThanks for using the program!"<<endl;
            break;
        }
        else{
            cout<<"\nInvalid choice."<<endl;
        }
    }

    return 0;
}
// ACCOUNT CREATION 
void createAccount(string &name, string &password) {
    cout<<"\nCreate Username: "<<endl;
    cin>>name;
    cout<<"Create Password: ";
    cin>>password;
    cout<<"\nAccount Created!"<<endl;
}
// LOGIN
bool login(string name, string password) {
    string inputName, inputPass;
    cout<<"\nEnter Username: ";
    cin>>inputName;
    cout<<"Enter Password: ";
    cin>>inputPass;

    return(inputName==name&&inputPass==password);
}
// MAIN MENU
void mainMenu(string username){

    string favMovies[50];
    string favBooks[50];
    int favMovieIndex = 0;
    int favBookIndex = 0;

    int choice;

    while(true){
        cout<<"Welcome, " << username << "!"<<endl;
        cout<<"1. Detect Mood & Get Recommendations"<<endl;
        cout<<"2. Show Favourite List"<<endl;
        cout<<"3. Play Games"<<endl;
        cout<<"4. Logout"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>choice;

        if(choice==1){
            string mood = detectMood();
            moodRecommendations(mood);

            recommendMovies(mood, favMovies, favMovieIndex);
            recommendBooks(mood, favBooks, favBookIndex);
        }
        else if(choice==2){
            showFavourites(favMovies, favMovieIndex, favBooks, favBookIndex);
        }
        else if(choice==3){
            gameMenu();
        }
        else if(choice==4){
            cout << "\nLogging out..."<<endl;
            break;
        }
        else{
            cout<<"\nInvalid choice."<<endl;
        }
    }
}
// MOOD DETECTION
string detectMood(){
    int scoreHappy=0, scoreSad=0, scoreExcited=0, scoreRomantic=0, scoreScared=0;
    int ans;

    cout<<"\nAnswer these questions (1 = Yes, 0 = No):"<<endl;

    cout<<"\n1. Are you feeling energetic? ";
    cin>>ans;
    if(ans) scoreExcited++;

    cout<<"2. Do you feel sad or low? ";
    cin>>ans;
    if(ans) scoreSad++;

    cout<<"3. Do you want to watch something emotional? ";
    cin>>ans;
    if(ans) scoreRomantic++;

    cout<<"4. Are you feeling afraid or tense? ";
    cin>>ans;
    if(ans) scoreScared++;

    cout<<"5. Do you feel positive or cheerful? ";
    cin>>ans;
    if(ans) scoreHappy++;

    if(scoreHappy>=1) return "happy";
    if(scoreSad>=1) return "sad";
    if(scoreExcited>=1) return "excited";
    if(scoreRomantic>=1) return "romantic";
    return "scared";
}

// SHOW USER'S MOOD
void moodRecommendations(string mood) {
    cout<<"\nYour mood seems to be: **" << mood << " **";
}

// MOVIE RECOMMENDATIONS
void recommendMovies(string mood, string favMovies[], int &favIndex) {
    string movies[5];

    if(mood=="happy"){
        string temp[]={"Lego Movie", "Zootopia", "Paddington", "La La Land", "Soul"};
        for(int i=0;i<5;i++) movies[i] = temp[i];
    }
    else if(mood=="sad"){
        string temp[]={"Me Before You", "Fault in Our Stars", "A Silent Voice", "Five Feet Apart", "The Pursuit of Happyness"};
        for(int i=0;i<5;i++) movies[i] = temp[i];
    }
    else if(mood=="excited") {
        string temp[] = {"John Wick", "Avengers Endgame", "Mad Max", "Inception", "Baby Driver"};
        for(int i=0;i<5;i++) movies[i] = temp[i];
    }
    else if(mood == "romantic") {
        string temp[]={"Your Name", "The Notebook", "Titanic", "Pride & Prejudice", "A Walk to Remember"};
        for(int i=0;i<5;i++) movies[i] = temp[i];
    }
    else {
        string temp[]={"Conjuring", "Insidious", "Smile", "The Nun", "Annabelle"};
        for(int i=0;i<5;i++) movies[i] = temp[i];
    }

    int idx=rand() % 5;
    cout<<"\n🎬 Movie Recommendation: " << movies[idx];

    cout<<"\nAdd to Favourites? (1 = Yes, 0 = No): ";
    int choice;
    cin>>choice;

    if(choice==1){
        favMovies[favIndex] = movies[idx];
        favIndex++;
        cout<<"Added to Favourites!"<<endl;
    }
}

// BOOK RECOMMENDATIONS 
void recommendBooks(string mood, string favBooks[], int &favBookIndex) {
    string books[5];

    if (mood=="happy") {
        string temp[]={"Wonder", "Matilda", "Anne of Green Gables", "The Alchemist", "Harry Potter"};
        for(int i=0;i<5;i++) books[i] = temp[i];
    }
    else if(mood=="sad") {
        string temp[]={"It Ends With Us", "The Kite Runner", "Thirteen Reasons Why", "The Book Thief", "A Little Life"};
        for(int i=0;i<5;i++) books[i] = temp[i];
    }
    else if(mood=="excited") {
        string temp[]={"Maze Runner", "Divergent", "Percy Jackson", "Da Vinci Code", "Hunger Games"};
        for(int i=0;i<5;i++) books[i] = temp[i];
    }
    else if (mood=="romantic"){
        string temp[]={"Twilight", "Me Before You", "Love Hypothesis", "Your Name", "Red White Royal Blue"};
        for(int i=0;i<5;i++) books[i]=temp[i];
    }
    else {
        string temp[]={"Dracula", "Coraline", "The Shining", "Bird Box", "Frankenstein"};
        for(int i=0;i<5;i++) books[i] = temp[i];
    }

    int idx = rand() % 5;
    cout<<"\n📚 Book Recommendation: " << books[idx];

    cout<<"\nAdd to Favourites? (1 = Yes, 0 = No): ";
    int choice;
    cin>>choice;

    if(choice==1){
        favBooks[favBookIndex] = books[idx];
        favBookIndex++;
        cout<<"Added to Favourites!"<<endl;
    }
}
//SHOW FAVOURITES 
void showFavourites(string favMovies[], int favIndex, string favBooks[], int favBookIndex) {

    cout << "\n       YOUR FAVOURITES";
    cout << "\nMovies:";
    if(favIndex==0) cout<<"\n(No favourite movies yet)";
    else{
        for(int i=0;i<favIndex;i++)
            cout<<"\n- " << favMovies[i];
    }

    cout << "\n\nBooks:";
    if(favBookIndex==0) cout<<"\n(No favourite books yet)";
    else{
        for(int i=0;i<favBookIndex;i++)
            cout << "\n- " << favBooks[i];
    }

    cout<<endl;
}


//GAME MENU
void gameMenu() {
    int choice;

    while (true) {
        cout<<"\n         FUN GAME ZONE";
        cout<<"\n1. Movie Scramble Game";
        cout<<"\n2. Word Chain Game";
        cout<<"\n3. Back to Main Menu";
        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice==1)
            playScrambleGame();
        else if(choice==2)
            playWordChainGame();
        else if(choice==3)
            break;
        else
            cout<<"\nInvalid choice. Try again."<<endl;
    }
}
//SCRAMBLE GAME 
void playScrambleGame(){

    string movies[10]={
        "Titanic", "Inception", "Interstellar", "Avatar",
        "Joker", "Coco", "Frozen", "Moana", "Up", "Mulan"
    };

    string original = movies[rand() % 10];
    string scrambled = original;

    // manual scramble using swapping
    for (int i = 0; i < scrambled.length(); i++) {
        int j = rand() % scrambled.length();
        char temp = scrambled[i];
        scrambled[i] = scrambled[j];
        scrambled[j] = temp;
    }

    cout<<"\nMOVIE SCRAMBLE GAME";
    cout<<"\nUnscramble this movie title: " << scrambled << endl;

    cin.ignore();
    string guess;

    while(true){
        cout<<"Your guess: ";
        getline(cin, guess);

        if(guess == original){
            cout<<"Correct! It was: " << original <<endl;
            break;
        }
        cout<<"Wrong! Try again."<<endl;
    }
}
//WORD CHAIN GAME
void playWordChainGame(){

    string words[6]={"apple", "sun", "river", "music", "movie", "tiger"};
    string word=words[rand() % 6];

    cout<<"\n WORD CHAIN GAME ";
    cout<<"\nForm a word starting with the LAST letter of my word.";
    cout<<"\nEnter 'exit' to stop."<<endl;

    while(true){
        cout<<"\nWord: " << word << endl;
        char last = word[word.length() - 1];
        cout<<"Enter a word starting with '" << last << "': ";
        string userWord;
        cin >> userWord;

        if(userWord == "exit")
            break;

        if(userWord[0] == last){
            cout<<"Good! Continue."<<endl;
            word=userWord;
        } else{
            cout<<"Wrong! Word must start with '" << last << "'.\n";
        }
    }

    cout << "\nThanks for playing!\n";
}