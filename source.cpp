#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
struct player {
	string team, position;
	string fName, lName;
	int rbi, wins, hr, yearsActive;
	string rThrow, rBat;
	double obp;
};
void readStats(player[]);
void updateStats(player[], int );
void printPlayers(player[]);
void showStats(player[],int);
void printTeams(player[]);
void changeStat(player[], int);
void menu(player[]);
int main() {
	cout << fixed << showpoint << setprecision(3);
	player players[10];
	readStats(players);
	menu(players);
	return 0;
}
void printTeams(player players[]) {
	for(int x=0;x<10;x++)
		cout << "Team: " << players[x].team << endl;
}
void menu(player players[]) {
	while (true) {
		cout << "Choose an option!!\n";
		cout << "1: Print Players.\n";
		cout << "2: Print teams.\n";
		cout << "3: Show stats of specific player.\n";
		cout << "4: Change stat of player.\n";
		//cout << "5: Exit.";
		int option;
		cin >> option;
		switch (option) {
		case 1:
			printPlayers(players);
			break;
		case 2:
			printTeams(players);
			break;
		case 3:
			int player;
			cout << "Which player?\n";
			printPlayers(players); //prints players for players choice
			cin >> player; //player choice
			showStats(players, player);
			break;
		case 4:
			cout << "Which player?\n";
			printPlayers(players); //prints players for players choice
			cin >> player; //player choice
			changeStat(players, player);
			break;
		case 5:
			//return 0;
			break;
		}
	}
	//cout << players[2].lName << endl;
}
void changeStat(player players[] , int option){
	option -= 1;
	cout << "Which stat do you want to change for " << players[option].fName << " " << players[option].lName << endl;
	cout << "1: Team" << endl;
	cout << "2: Position " << endl;
	cout << "3: RBI " << endl;
	cout << "4: Wins " << endl;
	cout << "5: Home Runs" << endl;
	cout << "6: Throws " << endl;
	cout << "7: Bats " << endl;
	cout << "8: OBP " << endl;
	int stat;
	cin >> stat;
	string teamName, pos,bat,rthorw;
	int rbi2,wins2,hr2;
	double obp2;
	switch (stat) {
	case 1:
		cout << "What do you want to change the team to? ";
		
		cin >> teamName;
		players[option].team = teamName;
		
		break;
	case 2:
		cout << "What do you want to change the position to? ";		
		cin >> pos;
		players[option].position = pos;
		
		break;
	case 3:
		cout << "What do you want to change the RBI to ? ";
		cin >> rbi2;
		players[option].rbi = rbi2;
		
		break;
	case 4:
		//wins
		cout << "What do you want to change the wins to? ";
		cin >> wins2;
		players[option].wins = wins2;
		break;
	case 5:
		//homeruns
		cout << "What do you want to change the homeruns to? ";
		cin >> hr2;
		players[option].hr = hr2;
		break;
	case 6:
		//bats
		cout << "What do you want to change the batting to? (Left or right) ";
		cin >> bat;
		players[option].rBat = bat;
		break;
	case 7:
		//throws
		cout << "What do you want to change the throwing to? (Left or right) ";
		cin >> rthorw;
		players[option].rThrow = rthorw;
		break;
	case 8:
		//obp
		cout << "What do you want to change the OBP to? ";
		cin >> obp2;
		players[option].obp = obp2;
		break;
	}
	updateStats(players, 4);
	// can't really change years active, na i mean?
}
void showStats(player player[],int x) {
	x -= 1;
	cout << player[x].fName << " " << player[x].lName << endl;
	cout << "Team: " << player[x].team << endl;	
	cout << "Position: " << player[x].position << endl;
	cout << "RBI: " << player[x].rbi <<endl;
	cout << "Wins: " << player[x].wins << endl;
	cout << "Home runs: " << player[x].hr << endl;
	cout << "Years active: " << player[x].yearsActive <<endl;
	cout << "Throws: " <<player[x].rThrow ;
	cout << "\tBats: " << player[x].rBat << "\n";
	cout << "OBP: " << player[x].obp << endl;
}
void printPlayers(player player[]) {
	
	for (int x = 0; x < 10; x++) 
		cout << "Player "<< x+1 << ": " << player[x].fName << " "<< player[x].lName << endl;
		
}
void readStats(player player[]) {
	ifstream in;
	in.open("players.txt");	
	for(int x=0;x<10;x++) {		
		in >> player[x].fName;		
		in >> player[x].lName;		
		in >> player[x].team;
		in >> player[x].position;
		in >> player[x].rbi;
		in >> player[x].wins;
		in >> player[x].hr;
		in >> player[x].yearsActive;
		in >> player[x].rThrow;
		in >> player[x].rBat;		
		in >> player[x].obp;		
	}
	in.close();	
}
void updateStats(player player[],int updatedStat) {
	ofstream out;
	out.open("players.txt"); 
	for (int x = 0; x<10; x++) {
		out << player[x].fName << " ";
		out << player[x].lName << " ";
		out << player[x].team<< " ";
		out << player[x].position << " ";
		out << player[x].rbi << " ";
		out << player[x].wins << " ";
		out << player[x].hr << " ";
		out << player[x].yearsActive << " ";
		out << player[x].rThrow << " ";
		out << player[x].rBat << " ";
		out << player[x].obp << endl;
	}
	out.close();
	readStats(player);
}
