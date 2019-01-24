#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

string sen, cat, dashedSen;
char guess;
int miss;
bool isGuessCorrect;

void newGame() {
	miss = 0;
	system("cls");
	cout << "Nowa Gra" << endl;
	cout << "Podaj kategorie hasla: ";
	getline(cin, cat);
	cout << endl << "Podaj haslo do odgadniecia: ";
	getline(cin, sen);
	//cout << cat << ", " << sen;
}

void draw(int k) {
	if (k == 0) {
		cout << endl <<  endl << endl << endl <<char(202) << endl;
	} else if (k == 1) {
		cout << char(201) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(202) << endl;
	} else if (k == 2) {
		cout << char(201) << char(205) << char(205) << char(187) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(202) << endl;
	} else if (k == 3) {
		cout << char(201) << char(205) << char(205) << char(187) << endl;
		cout << char(186) << "  " << char(147) << endl;
		cout << char(186) << endl;
		cout << char(186) << endl;
		cout << char(202) << endl;
	} else if (k == 4) {
		cout << char(201) << char(205) << char(205) << char(187) << endl;
		cout << char(186) << "  " << char(147) << endl;
		cout << char(186) << "  " << char(179) << endl;
		cout << char(186) << endl;
		cout << char(202) << endl;
	} else if (k == 5) {
		cout << char(201) << char(205) << char(205) << char(187) << endl;
		cout << char(186) << "  " << char(147) << endl;
		cout << char(186) << " " << char(218) << char(179) << char(191) << endl;
		cout << char(186) << endl;
		cout << char(202) << endl;
	} else if (k == 6) {
		cout << char(201) << char(205) << char(205) << char(187) << endl;
		cout << char(186) << "  " << char(147) << endl;
		cout << char(186) << " " << char(218) << char(179) << char(191) << endl;
		cout << char(186) << " / \\" << endl;
		cout << char(202) << endl;
	} 
}

void start() {
	dashedSen = "";
	
	for (int i = 0; i < sen.size(); i++) {
		if (sen[i] == ' ') {
			dashedSen += string(" ");
		} else {
			dashedSen += string("_");
		}
	}
	
	while(true) {
		system("cls");
		cout << "Kategoria hasla: " << cat << endl << endl;
		cout << dashedSen << endl << endl;
		draw(miss);
		cout << "Bledy: " << miss << "/6" << endl;
		cout << endl << "(aby zgadnac wcisnij litere...)";
		if (miss == 6) {
			break;
		} else if (dashedSen == sen) {
			break;
		}
		guess = getch();
		isGuessCorrect = false;
		for (int i = 0; i < sen.size(); i++) {
			if (toupper(guess) == toupper(sen[i])) {
				if (dashedSen[i] != sen[i]) {
					dashedSen[i] = sen[i];
					isGuessCorrect = true;
				}
			}
		}
		if (!isGuessCorrect) {
			miss++;
		}
	}
	
	if (dashedSen == sen) {
		cout << endl << endl << "UDALO CI SIE ZGADNAC HASLO: " << sen << endl << "GRATULACJE!!";
	} else {
		cout << endl << endl << "Niestety nie udalo ci sie zgadnac hasla: " << sen;
	}
	
	cout << endl << endl << "(wcisnij dowolny klawisz aby rozpoczac nowa gre...)";
	getch();
}

int main() {
	for(;;) {
		newGame();
		start();
	}
	return 0;
}
