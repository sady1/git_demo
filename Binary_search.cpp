#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include <conio.h>
#include <string>
#include <algorithm>
#include <ctime>
#include<vector>


using namespace std;
 int n=0;
const int CONSOLE_WIDTH = 80;

int arr[1000];
bool isSorted=false;

void writer(string text, int delay = 40) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }

}
double cgpacalculator(string grade){
    if(grade=="A+"||grade=="a+") return 4.00;
    if(grade=="A"||grade=="a") return 3.75;
    if(grade=="B+"||grade=="b+") return 3.50;
    if(grade=="B"||grade=="b") return 3.25;
    if(grade=="C+"||grade=="c+") return 3.00;
    if(grade=="C"||grade=="c") return 2.75;
    if(grade=="D"||grade=="d") return 2.50;
    if(grade=="F"||grade=="f") return 0.00;
    return -1; // Invalid input
}
void printCentered(const string& line) {
    int padding = (CONSOLE_WIDTH - line.length()) / 2;
    if (padding > 0)
        cout << string(padding, ' ');
    cout << line << endl;
    this_thread::sleep_for(chrono::milliseconds(180)); // Control bloom speed
}

void drawRoseCentered() {
    vector<string> rose = {
        "         .     .       ",
        "      ...  :``..':     ",
        "       : ````.'   :''::'",
        "     ..:..  :     .'' :",
        "``.    `:    .'     :",
        "    :    :   :        :",
        "     :   :   :         :",
        "     :    :   :..''''``::. ",
        "     : ...:..'     .'':  ",
        "     .'   .'  .::::'   ",
        "    :..'''``::::::'    ",
        "    '         `:::     ",
        "                `::    ",
        "                 :::.  ",
        "          ..:.:.::'`:. ",
        "        ..'      `:    ",
        "       .:        :     ",
        "       :       .:      ",
        "        `..:.:''       "
    };

    for (const string& line : rose) {
        printCentered(line);
    }

    printCentered("");
    printCentered("🌹 A Rose For You 🌹");
    printCentered("   — From Sady 💌");

}

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

bool contains(string text, string word) {
    return text.find(word) != string::npos;
}
void speak(string text) {
    // Escape single quotes in the text
    size_t pos = 0;
    while ((pos = text.find("'", pos)) != string::npos) {
        text.replace(pos, 1, "''");
        pos += 2;
    }

    // PowerShell command with Female voice hint
    string command =
        "PowerShell -Command \"Add-Type -AssemblyName System.Speech; "
        "$speak = New-Object System.Speech.Synthesis.SpeechSynthesizer; "
        "$speak.SelectVoiceByHints([System.Speech.Synthesis.VoiceGender]::Female); "
        "$speak.Speak('" + text + "');\"";

    system(command.c_str());
}





int main() {
    // Start the speaking in a separate thread
thread speakerThread(speak, "Hello, I am SADY'AI How can I help you?");

// Meanwhile, write the same message on screen
writer("Hello I am SADY's AI, how can I help you?",75);

// Wait for the speaker to finish
speakerThread.join();

    while (true) {
        string help;
        cout << "\nWrite: ";
        getline(cin, help);
        help = toLower(help);

        if (contains(help, "date") || contains(help, "today")) {
            cout << "Analyzing ";
            for (int i = 0; i < 7; i++) {
                this_thread::sleep_for(chrono::milliseconds(50));
                cout << "." << flush;
            }
            cout << endl;

            time_t now = time(0);
            tm* localTime = localtime(&now);

            char dateStr[20];
            strftime(dateStr, sizeof(dateStr), "%d/%m/%Y", localTime);

            writer(string("Today's date is: ") + dateStr);
        }

        else if (contains(help, "timer")) {
            writer("Timer is being prepared. Please wait ");
            for (int i = 0; i < 7; i++) {
                this_thread::sleep_for(chrono::milliseconds(50));
                cout << "." << flush;
            }
            cout << endl;

            int minutes, seconds;

            cout << "Enter minutes: ";
            cin >> minutes;

            cout << "Enter seconds: ";
            cin >> seconds;
            cin.ignore();  // ✅ Clear input buffer for next getline

            int totalTime = minutes * 60 + seconds;

            for (int i = totalTime; i > 0; i--) {
                int m = i / 60;
                int s = i % 60;



                cout << "\r The time remaining is ";
                if (m < 10) cout << "0";
                cout << m << ":";
                if (s < 10) cout << "0";
                cout << s << flush;

                this_thread::sleep_for(chrono::seconds(1));

            }

            cout << "\n\n******************* Time Ended in: " << totalTime << " seconds *******************" << endl;
            Beep(750, 5000);
        }

        else if (contains(help, "paragraph") || contains(help, "myself")) {
            string name, fname, mname, Class, hobby, aim;

            writer("Please provide some information, based on that I will make a paragraph.");

            cout << "Enter Your Name: ";
            getline(cin, name);

            cout << "Enter Your Father's Name: ";
            getline(cin, fname);

            cout << "Enter Your Mother's Name: ";
            getline(cin, mname);

            cout << "Enter Your Class: ";
            getline(cin, Class);

            cout << "Enter Your Hobby: ";
            getline(cin, hobby);

            cout << "Enter Your Aim in Life: ";
            getline(cin, aim);

            cout << "Please wait, the paragraph is generating ";
            for (int i = 0; i < 7; i++) {
                this_thread::sleep_for(chrono::milliseconds(400));
                cout << "." << flush;
            }
            cout << endl;

            string paragraph = "I am " + name + ". I study in class " + Class + ". ";
            paragraph += "My father's name is " + fname + " and my mother's name is " + mname + ". ";
            paragraph += "My favorite hobby is " + hobby + ", which keeps me happy and motivated. ";
            paragraph += "In the future, I aspire to become a " + aim + " and make my parents proud. ";
            paragraph += "I believe that with hard work and dedication, I can achieve my dreams.";

            writer(paragraph);
        }else if(contains(help,"calculator")||contains(help,"calculations")||contains(help,"value")){

                 writer("Please provide two values ");
                 cout<<endl;
                 double a,b;
                 cout<<"Enter value 1 :";
                 cin>>a;
                 cout<<"Enter value 2 :";
                 cin>>b;
                 double sum=a+b;
                 double min=a-b;
                 double mul=a*b;
                 double div=a/b;


                 char op;
                 writer("Which operation you want to perform (+ - * / )");
                 cin>>op;
                 cin.ignore();
                 if(op=='+'){
                    writer("Your summation is : "+to_string(sum));
                 }else if(op=='-'){
                 writer("your deduct value is : "+to_string(min));
                 }else if(op=='*'){
                 writer("your deduct value is : "+to_string(mul));
                 }else{
                  writer("your divide value is : "+to_string(div));
                 }


        }else if(contains(help,"clear")){
          writer("Clearing .......");
           this_thread::sleep_for(chrono::milliseconds(100));
           system("cls");


        }else if (contains(help,"youtube")||contains(help,"Youtube")){
          writer("Opening youtube");
          this_thread::sleep_for(chrono::milliseconds(150));
          system("start https://www.youtube.com/");
        }else if (contains(help,"facebook")||contains(help,"Facebook")){
          writer("Opening Facebook");
          this_thread::sleep_for(chrono::milliseconds(150));
          system("start https://web.facebook.com/?_rdc=1&_rdr#");
        }else if(contains(help,"sorting")||contains(help,"sort")){

            writer("please enter how many numbers you are going to sort ");
            cin>>n;
            cout<<"Enter "<<n<<" elements "<<endl;
            for(int i=0;i<n;i++){
                    cin>>arr[i];
            }
            cin.ignore();

            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-i-1;j++){
                    if(arr[j]>arr[j+1]){
                        swap(arr[j],arr[j+1]);
                    }
                }
            }
           writer("After sorting in ascending order : ");
           for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
           }
           isSorted=true;
           cout<<endl;


           }else if(contains(help,"descending")){
              if(isSorted){
                           if(contains(help,"descending")){

            for(int i=n-1;i>=0;i--){
                cout<<arr[i]<<" ";
            }
           }
              }
           }else if(contains(help,"code")){
            writer("#include<iostream>");
            writer("using namespace std;");
            writer("int main(){ ");
            writer("cout<<'Hello world';");
             writer("return 0 ");
              writer("}");


           }else if (contains(help, "time")) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char timeStr[9];
    strftime(timeStr, sizeof(timeStr), "%H:%M:%S", ltm);  // y

    writer(string("Current time is: ") + timeStr);
}



   else if (contains(help, "games") || contains(help, "game")) {
    writer(" Welcome to the 'Guess the Hidden Number' Game!\n");
    writer("I have selected a number between 1 and 100.\n");
    writer("You have 7 chances to guess it.\n");

    srand(time(0));
    int target = 1 + rand() % 100;
    int guess;
    int attempts = 7;
    bool found = false;

    while (attempts--) {
        cout << "\nEnter your guess (" << (attempts + 1) << " tries left): ";
        cin >> guess;

        if (guess == target) {
            writer(" Correct! You guessed the number.");
            thread speakerThread(speak,"Congrats You guess the correct number");
            speakerThread.join();





    writer(R"(
     __     ______  _    _   _
     \ \   / / __ \| |  | | | |
      \ \_/ / |  | | |  | | | |
       \   /| |  | | |  | | | |
        | | | |__| | |__| |_|_|
        |_|  \____/ \____/ (_)
              __        ___ _   _
\ \      / (_) | | |
 \ \ /\ / / _| |_| |
  \ V  V / | |  _  |
   \_/\_/  |_|_| |_|
    )",20);












            Beep(1000, 1000);
         Beep(1200, 150);
          Beep(1500, 200);
            found = true;
            break;
        } else if (guess < target) {
            writer(" Too low!");
        } else {
            writer(" Too high!");
        }
    }

    if (!found) {
        writer(" Game Over. The correct number was: " + to_string(target));
        thread speakerThread(speak ,"Game over , The correct answer is "+to_string(target));
        speakerThread.join();
        writer(R"(
__     ______  _    _   _      ____   _____ ______
\ \   / / __ \| |  | | | |    / __ \ / ____|  ____|
 \ \_/ / |  | | |  | | | |   | |  | | (___ | |__
  \   /| |  | | |  | | | |   | |  | |\___ \|  __|
   | | | |__| | |__| | | |___| |__| |____) | |____
   |_|  \____/ \____/  |______\____/|_____/|______|


)",20);
        Beep(500,1000);
                Beep(400,1000);
    }

    cin.ignore();
}











else if(contains(help,"cgpa")||contains(help,"Cgpa")){



    writer("Okh lets calculate your CGPA ");
    cout << endl;
    writer("Before that I need to gather some information ");
    cout << endl;

    double recent;
    writer("Please enter your current 'CGPA' : ");
    cin >> recent;

    int credit;
    writer("Please enter your completed 'CREDIT' : ");
    cin >> credit;

    int courses;
    writer("Please enter your total courses this semester : ");
    cin >> courses;

    double totalNewPoints = 0;
    int totalNewCredits = 0;

    for(int i=1; i<=courses; i++){
        string grade;
        int courseCredit;

        cout << endl;
        writer("Enter grade for course " + to_string(i) + " : ");
        cin >> grade;

        writer("Enter credit for this course : ");
        cin >> courseCredit;

        double point = cgpacalculator(grade);
        if(point == -1){
            writer("Invalid grade entered. Please restart.");
            return 1;
        }

        totalNewPoints += (point * courseCredit);
        totalNewCredits += courseCredit;
    }

    double newCGPA = ((recent * credit) + totalNewPoints) / (credit + totalNewCredits);

    cout << endl;
    writer("Calculating your new CGPA...", 20);
    for(int i=0; i<5; i++){
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << ".";
    }

    cout << endl;
    writer("Your updated CGPA is : " + to_string(newCGPA).substr(0, 5));

    cin.ignore();

}else if(contains(help,"color")||contains(help,"change")||contains(help,"magic")){
    string op;
    writer("Are you ready for the magic : ");
    cin>>op;
    cin.ignore();
    if(op=="yes"||op=="yeah"){
            string write;
            writer("Write something here : ");
            getline(cin,write);

            writer("Converting your words into red ");

            for (int i=0;i<6;i++){
                this_thread::sleep_for(chrono::milliseconds(100));
                cout<<".";
            }
            cout<<endl;


            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
             SetConsoleTextAttribute(hConsole, 12);
             writer(write);
              SetConsoleTextAttribute(hConsole, 7);
    }



   cin.ignore();



  }else if(contains(help,"flower")||contains(help,"for me")||contains(help,"rose")){

    writer("Generating ");
    for(int i = 0; i < 7; i++) {
        this_thread::sleep_for(chrono::milliseconds(50));
        cout << ".";
    }
    cout << endl;

    drawRoseCentered();

    thread speakerThread(speak, std::string("A rose has been created"));
    speakerThread.detach();
}
else if (contains(help,"becholor")||contains(help,"natok")){
  system("start https://www.youtube.com/watch?v=TLMVwuUJT94");
}else if(contains(help,"who")||contains(help,"creator")){

    thread speakerThread(speak, "My Creator is Imran Salehin SADY");
    writer("My Creator is Imran salehin Sady");
    speakerThread.join();

}







        else {
            writer("Sorry, I didn’t understand that. ");
        }
    }

    getch();
    return 0;
}
