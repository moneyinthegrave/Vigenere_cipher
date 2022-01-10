#include <iostream>
#include <string>

using namespace std;

int main() {
	string input_message, encryption_key, decryption_key;
	cout << "Enter your message: " << endl;
	getline(cin, input_message);
	cout << "Enter your encryption_key: " << endl;
	getline(cin, encryption_key);

	char *new_input_message = new char[input_message.size() - 1];
	char *new_key = new char[encryption_key.size() - 1];

	int k = 0;
	for (int i = 0; i < input_message.size(); i++) {
		new_key[i] = encryption_key[k];
		k++;
		if (k == encryption_key.size()) {
			k = 0;
		}
	}
	for (int i = 0; i < input_message.size(); i++) {
		if ((int(input_message[i]) + int(new_key[i])) < 256) {
			new_input_message[i] = char((int(input_message[i]) + int(new_key[i])));
		} else {
			new_input_message[i] = char((int(input_message[i]) + int(new_key[i])) - 256);
		}
		k = 0;
	}

	cout << "Encrypted message :" << endl;
	cout << new_input_message << endl;
	cout << "Enter the decryption key: " << endl;
	getline(cin, decryption_key);

	cout << "Decrypted message: " << endl;
	for (int i = 0; i < input_message.size(); i++) {
		new_key[i] = decryption_key[k];
		k++;
		if (k == encryption_key.size()) {
			k = 0;
		}
	}
	for (int i = 0; i < input_message.size(); i++) {
		cout << new_key[i];
	}
	cout << endl;
	for (int i = 0; i < input_message.size(); i++) {
		if ((int(input_message[i]) - int(new_key[i])) < 0) {
			new_input_message[i] = char((int(new_input_message[i]) - int(new_key[i])));
		} else {
			new_input_message[i] = char((int(new_input_message[i]) - int(new_key[i])) + 256);
		}
	}
	for (int i = 0; i < input_message.size(); i++) {
		cout << new_input_message[i];
	}

	return (0);
}
