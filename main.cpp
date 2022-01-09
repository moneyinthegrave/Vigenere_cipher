#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "Enter your message: " << endl;
	string text;
	getline(cin, text);
	cout << "Enter your key: " << endl;
	string key;
	getline(cin, key);

	char *ntext = new char[text.size() - 1];
	char *nkey = new char[key.size() - 1];

	int k = 0;
	for (int i = 0; i < text.size(); i++) {
		nkey[i] = key[k];
		k++;
		if (k == key.size()) {
			k = 0;
		}
	}
	for (int i = 0; i < text.size(); i++) {
		if ((int(text[i]) + int(nkey[i])) < 256) {
			ntext[i] = char((int(text[i]) + int(nkey[i])));
		} else {
			ntext[i] = char((int(text[i]) + int(nkey[i])) - 256);
		}
		k = 0;
	}

	cout << "Encrypted message :" << endl;
	cout << ntext << endl;
	cout << "Enter the decryption key: " << endl;
	string skey;
	getline(cin, skey);

	cout << "Decrypted message: " << endl;
	for (int i = 0; i < text.size(); i++) {
		nkey[i] = skey[k];
		k++;
		if (k == key.size()) {
			k = 0;
		}
	}
	for (int i = 0; i < text.size(); i++) {
		cout << nkey[i];
	}
	cout << endl;
	for (int i = 0; i < text.size(); i++) {
		if ((int(text[i]) - int(nkey[i])) < 0) {
			ntext[i] = char((int(ntext[i]) - int(nkey[i])));
		} else {
			ntext[i] = char((int(ntext[i]) - int(nkey[i])) + 256);
		}
	}
	for (int i = 0; i < text.size(); i++) {
		cout << ntext[i];
	}
	cout << endl;

	return (0);
}
