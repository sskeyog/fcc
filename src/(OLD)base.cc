#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>

using namespace std;

int main(int argc, char* argv[], string s){
	if (argc == 1){
		printf("No arguments.");
	} else {
		fstream tmp(argv[1]);

		if (!tmp.fail()){
			printf("^ ");
			getline(cin, s);

			tmp << s;
			tmp.close();

			return 0;
		} else {
			cout << ("Error reading file ") << argv[1];
			return 1;
		}
	}
	return 0;
}
