#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

bool is_digit_three(char c)
{
	return c == '3';
}

int main() {
	list<char> List;
	string input;
	cout << "Enter a sequence of characters: " << endl;
	getline(cin, input);
	

	for (char c : input)// fulling list container
	{
		List.push_back(c);
	}

	// finding first dot
	list<char>::iterator dot_iter = find(List.begin(), List.end(), '.');

	for (list<char>::iterator it = List.begin(); it != dot_iter;)
	{
		list<char>::iterator dot_iter = find(List.begin(), List.end(), '.');
		if (*it == ',')
		{
			it = List.erase(it);//if coma-delete
		}
		else //if not coma moving to next list elementі
		{
			it++;
		}
	}
	
	replace_if(dot_iter, List.end(), is_digit_three, '+');

	for (char c : List)
	{
		cout << c;
	}

	cout << endl;

}




//for (list<char>::iterator it = List.begin(); it != dot_iter; it++)
	//{
	//	if (*it == ',')
	//	{
	//	    List.erase(it);//if coma-delete
	//		dot_iter--;//змешуєм бо він більше не вказує на првильний елемет бо видалили кому
	//	}
	//	
	//}

//	list<char>::iterator it = List.begin();
//while (it != dot_iter) {
//    if (*it == ',') {
//        it = List.erase(it);
//        --dot_iter; // Decrement dot_iter to adjust for the removed comma
//    } else {
//        ++it;
//    }
//}