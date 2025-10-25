#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
void swapChars(char &a, char &b) {
    char temp=a;
    a=b;
    b=temp;
}

string scrambleWord(string word) {
    int len= word.length();
    for (int i=0; i<len; i++) {
        int randIndex = rand() % len;
        swapChars(word[i], word[randIndex]);    //eg:'rat' xa, ani randIndex ko value 3 xa bhane, 'r' ra 't' swap hunxa, again, 'a' ra 'randIndex' swap hunxa ra word ma basxa.
    }
    return word;						//original word lai liyera, scrambled word pathauxa
}

int getHighestScore() {					//euta naya txt file banauxa ra tesma sabai points haru rakhxa, ani yo fn call bhaye paxi greatest point in that file return garxa 
    ifstream file("allpoints.txt");
    int score, highest = 0;
    while (file >> score) {
        if (score > highest) {
            highest = score;
        }
    }
    file.close();
    return highest;
}

void ScrambledGame() {  				//words ko txt file bata access garera sab words euta array ma rakhxa
    string words[100];
    ifstream file("scrambled.txt");
    for (int i=0; i<100; i++) {
        file >> words[i];
    }
    file.close();

    int index[100];
    for (int i=0; i<100; i++) {
        index[i] = i;
    }

    // Shuffle index array
    for (int i=0; i<100; i++) {       //if suffle nagarera sidai random index leko bhaye words repeating huna sakthyo. so, index[0-99] suffle bho tara repeating bhayena
        int r = rand() % 100;
        int temp = index[i];
        index[i] = index[r];
        index[r] = temp;
    }

    int points = 0;
    string input;
    for (int i=0; i<100; i++) {
        string original = words[index[i]];			//jun words ko array xa of 100 words, tesbata random position ko word linxa. ( index[i] ma already 100 ota random position xa)
        string scrambled = scrambleWord(original);

        cout << "\nScrambled word: " << scrambled << "\nYour guess: ";
        cin >> input;

        if (input == original) {
            cout << " Right Answer!\n";
            points++;
        } else if (input == "stop" || input == "STOP") {
            cout << "\n TOTAL POINTS: " << points;
            cout << "\n HIGHEST SCORE: " << getHighestScore();
            cout << "\n\nThank You for playing!";
            
            ofstream out("allpoints.txt", ios::app);		//to add new points
            out << points << endl;
            out.close();

            int choice;
            cout << "\n\nPress 1 to restart or any other key to exit: ";
            cin >> choice;
            if (choice == 1) {
                 system("cls");  	//clears screeen
                ScrambledGame(); 	// restart fresh
            }
            return;    				//or, break; pani lekhda hunxa
        } else {
            cout << " Wrong Answer! Correct word: " << original << endl;
            points--;
        }
    }

   
    cout << "\n  TOTAL POINTS: " << points;
    cout << "\n  HIGHEST SCORE: " << getHighestScore();

    ofstream out("allpoints.txt", ios::app);		//'points' lai txt file ma put garxa
    out << points << endl;
    out.close();
}

int main() {
    srand(time(0));  					//seed for random (device ko time ko basis ma random no. generate garne ho

    cout << "\t\t\t Welcome to the Word Scramble Game!\n\n";
    cout << "\t Rules:\n";
    cout << "1. Type the correct unscrambled word.\n";
    cout << "2. Type 'stop' anytime to quit and view your score.\n";
    cout << "3. +1 point for right, -1 for wrong. No skipping.\n";

    ScrambledGame();
    return 0;
}

