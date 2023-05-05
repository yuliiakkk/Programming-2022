// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//9.	Задано три слова, в кожному з яких від 1 до 6 малих латинських букв. Надрукувати ці слова за алфавітом.8

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool alphabetical_order_comparator(string& s1, string& s2) {
	int n = min(s1.length(), s2.length());

	for (int i = 0; i < n; i++) {
		if (s1[i] == s2[i]) {
			if (i == n - 1) {
				return s1.length() < s2.length();
			}
			else {
				continue;
			}
		}

		return s1[i] < s2[i];
	}
}

int main()
{
	int words_amount = 3;
	int max_word_length = 6;

	vector<string> words;
	cout << "Enter " << words_amount << " words:" << endl;

	string word;
	for (int i = 0; i < words_amount; i++)
	{
		cin >> word;
		while (word.length() > max_word_length) {
			cout << endl << "Only words of maximum lenth of " << max_word_length << " are allowed! Please, try again:" << endl;
			cin >> word;
		}
		words.push_back(word);
	}

	sort(words.begin(), words.end(), alphabetical_order_comparator);

	for (int i = 0; i < words.size(); i++) {
		cout << endl << words[i];
	}

	return 0;
}

