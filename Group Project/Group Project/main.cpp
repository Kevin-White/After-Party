#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <cstdlib> // this was added for the random function
#include <ctime> // this was added to seed the random function
#include<iomanip>
using namespace std;

int play_game_start();
void play_game_middle(int timeTT);
void get_to_library();
void play_library();
void go_back();
void good_end();
void bad_end();
void highScore(int);
int main()
{
	int choice;
	int timeT;

	do {
		system("cls");
		cout << "Hello And Wecome to 'After Party'\n"
			<< endl << "--Menu--\n";
		cout << "0. Quit Game" << endl << "1. Play Game\n";
		cin >> choice;
	} while (choice != 0 && choice != 1);
	switch (choice)
	{
	case 0:
		cout << "Goodbye!" << endl;
		return 0;
	case 1:
		timeT = play_game_start();
		play_game_middle(timeT);
		get_to_library();
		break;
	}
}

int play_game_start()
{
	string todo;
	int timeT = 0;
	bool start = true;
	cin.ignore();
	system("cls");
	cout << "You squint your eyes as the sun shines over you through the window. You have just finished" << endl
		<< "your second month as a student at TAMUCC. On top of that you got a 100 on your test" << endl
		<< "yesterday. You celebrated with movies and ice cream... all night. Next to you is a spilt melted" << endl
		<< "pint of ice cream staining your bed, clothes, and dripping on the floor. Your laptop is on your side" << endl
		<< "out of battery bathing in the puddle of ice cream." << endl << endl;

	cout << "You do not even remember what day it is. You do know you have a project due sometime this" << endl
		<< "week and its worth 20% of your final grade." << endl
		<< endl
		<< "'Oh god' you think to your self, what should I do first?" << endl;
	do
	{
		getline(cin, todo);


		if ((todo.find("clean") != string::npos || todo.find("Clean") != string::npos) && (timeT == 0))
		{
			cout << endl;
			cout << "You walk around cleaning the ice cream from everything and put your bedsheets into the washer." << endl
				<< "which is available to all residents at TAMUCC for free (if you do not count the crazy rent)" << endl
				<< "This takes up a lot of your time..." << endl
				<< endl << endl
				<< "What should you do next?" << endl;
			timeT += 10;
		}
		else if (todo.find("day") != string::npos || todo.find("date") != string::npos || todo.find("time") != string::npos || todo.find("phone") != string::npos)
		{

			cout << "You walk over to your phone and check the time, it is Thursday 9:" << setw(2) << setfill('0') << timeT << ", your next class is at" << endl
				<< "10:00 and you need to physically turn in a poster you have not printed out yet. On top of that" << endl
				<< "because of COVID-19 you do not know where the classroom is! Can you turn your work in on" << endl
				<< "time!?! Or will one of the most important assignments of the year go unfinished!" << endl
				<< endl
				<< "Hit enter to continue\n";
			cin.get();
			start = false;
		}
		else
		{
			cout << "Answer not accepted try something else\n";
		}
	} while (start);
	system("cls");
	cout << "This is: " << endl;
	cout <<
		"  ▄████████    ▄████████     ███        ▄████████    ▄████████         ▄███████▄    ▄████████    ▄████████     ███      ▄██   ▄" << endl <<
		"  ███    ███   ███    ███ ▀█████████▄   ███    ███   ███    ███        ███    ███   ███    ███   ███    ███ ▀█████████▄ ███   ██▄" << endl <<
		"  ███    ███   ███    █▀     ▀███▀▀██   ███    █▀    ███    ███        ███    ███   ███    ███   ███    ███    ▀███▀▀██ ███▄▄▄███" << endl <<
		"  ███    ███  ▄███▄▄▄         ███   ▀  ▄███▄▄▄      ▄███▄▄▄▄██▀        ███    ███   ███    ███  ▄███▄▄▄▄██▀     ███   ▀ ▀▀▀▀▀▀███" << endl <<
		"▀███████████ ▀▀███▀▀▀         ███     ▀▀███▀▀▀     ▀▀███▀▀▀▀▀        ▀█████████▀  ▀███████████ ▀▀███▀▀▀▀▀       ███           ███" << endl <<
		"  ███    ███   ███            ███       ███    █▄  ▀███████████        ███          ███    ███ ▀███████████     ███     ███   ███" << endl <<
		"  ███    ███   ███            ███       ███    ███   ███    ███        ███          ███    ███   ███    ███     ███     ███   ███" << endl <<
		"  ███    █▀    ███           ▄████▀     ██████████   ███    ███       ▄████▀        ███    █▀    ███    ███    ▄████▀    ▀█████▀" << endl <<
		"  ███" << endl;

	cin.get();
	system("cls");
	return timeT;
}

void play_game_middle(int timeTT)
{
	string todo;
	bool getOut = false;
	bool wallet = false, keys = false, mask = false;
	int timeT = timeTT;
	ofstream outFile;
	outFile.open("info.txt");


	cout << "Do you need to grab anything before we make our way to the library, or do we not have the time?\n";

	while (!getOut) {

		getline(cin, todo);

		if (todo.find("wallet") != string::npos && !wallet)
		{
			cout << endl;
			cout << "You look around your room and grab your wallet" << endl
				<< "This takes up a little of your time..." << endl
				<< endl << endl
				<< "Do you need anything else?" << endl;
			timeT += 1;
			wallet = true;
		}
		else if (todo.find("keys") != string::npos && !keys) {
			cout << endl;
			cout << "You look around your room and grab your keys" << endl
				<< "This takes up a little of your time..." << endl
				<< endl << endl
				<< "Do you need anything else?" << endl;
			timeT += 1;
			keys = true;
		}
		else if (todo.find("mask") != string::npos && !mask) {
			cout << endl;
			cout << "You look around your room and grab your mask" << endl
				<< "This takes up a little of your time..." << endl
				<< endl << endl
				<< "Do you need anything else?" << endl;
			timeT += 1;
			mask = true;
		}
		else if (todo.find("leave") != string::npos || todo.find("library") != string::npos) {
			cout << endl;
			cout << "You leave your room to the library... hoping you didnt miss anything" << endl
				<< "It is currently 9:" << setw(2) << setfill('0') << timeT;
			getOut = true;
			cin.get();

		}
		else {
			cout << endl << "Answer not accepted try something else\n";

		}
	}
	timeT += 8;
	if (!mask && !keys)
	{
		cout << endl << endl
			<< "You leave your room for the first time in weeks. Having online classes has been both a blessing" << endl
			<< "and a curse. You walk down the stairs of your dorm to the exit and walk out the door. The door" << endl
			<< "closes and locks behind you. The only way back is your key." << endl
			<< endl
			<< "You walk towards the library, the sun is hotter than usual and you strategically move to the" << endl
			<< "closest place with shade.You repeat this process until you get to the library's front doors." << endl;
		cout << "It is currently 9:" << setw(2) << setfill('0') << timeT << endl;
		cin.get();
	}

	outFile << timeT << endl
		<< wallet << endl
		<< keys << endl
		<< mask;
	outFile.close();
}

void get_to_library()
{
	ifstream inFile;
	ofstream outFile;
	bool wallet, keys, mask;
	bool getout = false;
	int timeT;
	string todo;
	inFile.open("info.txt");
	inFile >> timeT >> wallet >> keys >> mask;
	inFile.close();

	if (!mask) {
		cout << "When you enter the library a few heads turn to look at you, you look around in confusion before" << endl
			<< "you realize... you left your mask in your dorm. Someone walks up to you and says:" << endl << endl
			<< "You can not enter the library without a mask." << endl
			<< "They ask you to kindly leave." << endl << endl
			<< "What do you do now?" << endl;

		while (!getout) {
			getline(cin, todo);
			cout << endl;
			if (todo.find("ask") != string::npos || todo.find("borrow") != string::npos) {
				cout << "You walk around asking people about masks to no avail. You are stressed because you know" << endl
					<< "your class starts soon. How else can you get a mask?" << endl;
				timeT += 5;

			}
			else if (todo.find("get") != string::npos || todo.find("room") != string::npos || todo.find("dorm") != string::npos) {
				cout << "You know what you need to do. Even though you're out of time you start walking towards your" << endl
					<< "dorm in a hurry. You need to get into the library ASAP so you can print your assignment." << endl;
				getout = true;
				outFile.open("info.txt");
				outFile << timeT << endl
					<< wallet << endl
					<< keys << endl
					<< mask;
				outFile.close();
				go_back();
			}
		}
		inFile.open("info.txt");
		inFile >> timeT >> wallet >> keys >> mask;
		inFile.close();
	}
	getout = false;
	if (!wallet) {
		cout << "When you ask to print your project, the librarian tells you that you will need some money in" << endl
			<< "order to use their printing services." << endl
			<< "What do you do now?" << endl;

		while (!getout) {
			getline(cin, todo);
			cout << endl;
			if (todo.find("ask") != string::npos || todo.find("borrow") != string::npos) {
				cout << "You walk around asking people about money to no avail. " << endl
					<< "How else can you get some money?" << endl;
				timeT += 5;

			}
			else if (todo.find("get") != string::npos || todo.find("room") != string::npos || todo.find("dorm") != string::npos) {
				cout << "You know what you need to do. Even though you’re out of time you start walking towards your" << endl
					<< "dorm in a hurry. You need to print your assignment ASAP." << endl;
				getout = true;
				outFile.open("info.txt");
				outFile << timeT << endl
					<< wallet << endl
					<< keys << endl
					<< mask;
				outFile.close();
				go_back();
			}
		}
		inFile.open("info.txt");
		inFile >> timeT >> wallet >> keys >> mask;
		inFile.close();
	}
	play_library();
}

void play_library()
{
	int timeT;
	ifstream inFile;
	ofstream outFile;
	inFile.open("info.txt");
	inFile >> timeT;
	inFile.close();
	if (timeT < 60) {
		cout << endl << "You made it to the Mary & Jeff Bell library! You check your phone. The time reads 9:" << timeT << "." << endl;
	}
	else {
		cout << endl << "You made it to the Mary & Jeff Bell library! You check your phone. The time reads 10:" << setw(2) << setfill('0') << timeT << "." << endl;
	}
	cout << "It doesn't take long to find the printer in the library. Luckily enough, nobody is using it. You" << endl;
	cout << "pull out your wallet, grab your SandDollar$ card, and start printing out your assignment." << endl;
	cin.get();

	const int min = 1, max = 4;
	int ct = 0, numRand;
	unsigned seed = time(0);

	srand(seed);

	numRand = min + rand() % max;

	for (ct; ct <= numRand; ct++)
	{
		cout << "Printing...\n";
		Sleep(2500);
	}
	if (numRand < 3)
	{
		cout << "You got your assignment printed out! Now to turn it in!" << endl;
	}
	else
	{
		cout << "Geez, that took forever. Hopefully you have enough time left to turn in the assignment." << endl;
	}
	timeT += numRand;
	timeT += 4;
	outFile.open("info.txt");
	outFile << timeT;
	outFile.close();
	cin.get();

	if (timeT < 60)
	{
		good_end();
	}

	else
	{
		bad_end();
	}
	highScore(timeT);
}
void go_back() {

	bool wallet, keys, mask;
	int timeT;
	bool getout = false;
	string todo;
	ifstream inFile;
	ofstream outFile;
	inFile.open("info.txt");
	inFile >> timeT >> wallet >> keys >> mask;
	inFile.close();

	cout << "you finaly get up to your room, you go to open the door and find out the door is locked." << endl << endl;
	timeT += 7;
	cin.get();

	if (!keys) {
		cout << "You forgot your keys as well and time is ticking!!!You need to get the missing stuff from your" << endl
			<< "room! Lucky you know where to get a new key... by campus mail, but its far! You start running" << endl
			<< "as fast as you can to get there. The clock is ticking!" << endl << endl
			<< "The person at campus mail tells you that you’ll need $40 to get a new key." << endl << endl;
		cin.get();
		timeT += 8;
		if (!wallet) {
			cout << "This is when you realize you forgot your wallet, you start to bargain with the person at campus" << endl
				<< "mail. They let you take a key, but you promised to return later that day to give them $40." << endl;
			timeT += 5;
		}
		cout << "After you get your key do you want to head to the library or the dorm?" << endl;
		while (!getout) {
			getline(cin, todo);
			cout << endl;
			if (todo.find("library") != string::npos) {
				cout << "You head back to the library only to relize you never got what you needed... this takes up a lot of time" << endl
					<< "You head back to your dorm" << endl;
				timeT += 10;
				getout = true;
			}
			else if (todo.find("dorm") != string::npos) {
				cout << "You head back to your dorm" << endl;
				getout = true;
				timeT += 5;
			}
			keys = true;
		}
		cout << "You get back to your dorm room and unlock the door" << endl;
	}
	else {
		cout << "Lucky you got your keys before you left and just unlock the door." << endl;
	}
	cout << "Now that you are back grab anything you think you need, and leave when you are ready" << endl;
	getout = false;
	while (!getout) {

		getline(cin, todo);

		if (todo.find("wallet") != string::npos && !wallet)
		{
			cout << endl;
			cout << "You look around your room and grab your wallet" << endl
				<< "This takes up a little of your time..." << endl
				<< endl << endl
				<< "Do you need anything else?" << endl;
			timeT += 1;
			wallet = true;
		}
		else if (todo.find("keys") != string::npos && !keys) {
			cout << endl;
			cout << "You look around your room and grab your keys" << endl
				<< "This takes up a little of your time..." << endl
				<< endl << endl
				<< "Do you need anything else?" << endl;
			timeT += 1;
			keys = true;
		}
		else if (todo.find("mask") != string::npos && !mask) {
			cout << endl;
			cout << "You look around your room and grab your mask" << endl
				<< "This takes up a little of your time..." << endl
				<< endl << endl
				<< "Do you need anything else?" << endl;
			timeT += 1;
			mask = true;
		}
		else if (todo.find("leave") != string::npos || todo.find("library") != string::npos) {
			cout << endl;
			cout << "You leave your room to the library... hoping you didnt miss anything again" << endl;
			if (timeT >= 60)
			{
				cout << "It is currently 10:" << setw(2) << setfill('0') << timeT - 60 << endl;
			}
			else {
				cout << "It is currently 9:" << timeT << endl;
			}
			getout = true;
			cin.get();

		}
		else {
			cout << endl << "Answer not accepted try something else\n";

		}
	}
	outFile.open("info.txt");
	outFile << timeT << endl
		<< wallet << endl
		<< keys << endl
		<< mask;
	outFile.close();

}

void bad_end()
{
	int timeT;
	ifstream inFile;
	inFile.open("info.txt");
	inFile >> timeT;
	inFile.close();
	cout << "You slide the assignment into your bag, zip it up, and book it out of the library. You don’t even" << endl;
	cout << "bother checking your phone, you gotta get this thing turned in ASAP! The moment your shoes" << endl;
	cout << "hit the pavement, you start sprinting off, stop at the nearest map, remember which building your" << endl;
	cout << "class is in, and then sprint off in the opposite direction to where your class actually is." << endl << endl;
	cin.get();

	cout << "Something feels off once you’re in the building. There’s no bustle of students going about the" << endl;
	cout << "halls, despite this being the first day of in-person classes. Regardless, you pull out your phone" << endl;
	cout << "to check the time. What you see on the lock screen makes your blood run cold." << endl << endl;
	cout << "The time reads 10:" << setw(2) << setfill('0') << timeT - 60 << "." << endl << endl;
	cin.get();

	cout << "Your time ran out. You ask yourself “Was it the party? Did I put it off too much? Was it all those" << endl;
	cout << "mishaps I had in the past hour?”  Whatever the case, there’s now there’s a gaping hole where a" << endl;
	cout << "respectable project grade could have been. You gently push the door to the lecture hall open." << endl;
	cout << "Class is already in session, but nobody seems to pay any mind to your arrival. You walk to an" << endl;
	cout << "open chair and take a seat, hoping that the professor at least accepts late work." << endl << endl;
	cin.get();

	cout << "--BAD END--";
	cin.get();

}

void good_end()
{
	int timeT;
	ifstream inFile;
	inFile.open("info.txt");
	inFile >> timeT;
	inFile.close();
	cout << "You slide the assignment into your bag, zip it up, and book it out of the library. You don’t even" << endl;
	cout << "bother checking your phone, you gotta get this thing turned in ASAP! The moment your shoes" << endl;
	cout << "hit the pavement, you start sprinting off, stop at the nearest map, remember which building your" << endl;
	cout << "class is in, and then sprint off in the opposite direction to where your class actually is." << endl << endl;

	cout << "You nearly stumble at each door you push open until you stop at the door to your professor’s" << endl;
	cout << "class. Just about out of breath, you check the time on your phone as you push open the door." << endl << endl;
	cout << "The time reads 9:" << setw(2) << setfill('0') << timeT << "." << endl << endl;

	cout << "Your professor greets you as you walk in, noting your earliness, before you reply between" << endl;
	cout << "exhausted breaths. In a moment of quiet triumph, you walk up to your professor, leave the" << endl;
	cout << "assignment at their desk, and find a seat. You almost feel a weight lifted off your shoulders as" << endl;
	cout << "you let out a sigh of relief, slide down the chair, and wait for the rest of the class to show up." << endl << endl;
	cin.get();

	cout << "|| GOOD END||";
	cin.get();
}

void highScore(int newScore) {
	int count;
	ifstream inFile;
	ofstream outFile;
	inFile.open("HighScore");
	int scores[3];
	string names[3];
	cout << "High Scores:" << endl
		<< "---------------" << endl;
	for (int i = 0; i < 3; i = i++) {
		inFile >> names[i];
		inFile >> scores[i];
		cout << names[i] << "\t" << scores[i] << endl;
	}
	inFile.close();

	cout << endl << endl << "Your score was: " << newScore << endl << endl;
	for (int i = 0; i < 3; i = i++) {
		if (newScore < scores[i]) {
			cout << "You beat " << names[i] << " High Score!!\n What is your name: ";
			
			count = i + 1;
			if(i == 1) {
				scores[2] = scores[1];
				names[2] = names[1];
				count++;
			}
			if (i == 0) {\
				scores[2] = scores[1];
				names[2] = names[1];
				scores[1] = scores[0];
				names[1] = names[0];
				
			}
			cin >> names[i];
			scores[i] = newScore;
			break;
		}
	}
	outFile.open("HighScore");
	cout << endl << endl << "High Scores:" << endl
		<< "---------------" << endl;
	for (int i = 0; i < 3; i = i++) {
		cout << names[i] << "\t" << scores[i] << endl;
		outFile << names[i] << endl;
		outFile << scores[i] << endl;

	}
}