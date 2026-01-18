#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <filesystem>
#include <thread>
#include <chrono>
#include <indicators/indeterminate_progress_bar.hpp>
#include <indicators/cursor_control.hpp>
#include <indicators/termcolor.hpp>

#define clr system("clear");

using namespace std;
namespace fs = std::filesystem;
using namespace indicators;


int i = 0;

void load_bak(const string& bak, const string& file){
	try{
		fs::copy_file(bak, file, fs::copy_options::overwrite_existing);
		cout << "Loaded backup " << bak << endl;
		int i = 1;
	 } catch (fs::filesystem_error const& ex){
		 cerr << "error backing up file: " << ex.what() << endl;
	 }
}

void bak(const string& src, const string& _bak){
	try{
		fs::copy_file(src, _bak, fs::copy_options::overwrite_existing);
		cout << "Backed up to " << _bak << endl;
		int i = 1;
	} catch (fs::filesystem_error const& ex){
		cerr << "Error backing up file: " << ex.what() << endl;
	}
}

int main(int argc, char *argv[], string s){
	fstream tmp(argv[1]);
	ifstream _tmp("./bak.bak");

	if (argc == 1){printf("No arguments."); exit(1);}
	if (argv[1] == NULL){printf("no filename"); exit(1);}
	

	if (tmp.fail()){cout << ("Error reading file ") << argv[1];}
	
	//Progress bar data
	indicators::IndeterminateProgressBar bar{
	indicators::option::BarWidth{40},
	indicators::option::Start{"["},
	indicators::option::Fill{"-"},
	indicators::option::Lead{"+"},
	indicators::option::End{"]"},
	indicators::option::PostfixText{"\n"},
	indicators::option::ForegroundColor{indicators::Color::white}
	};
	//END


	while(true){
		clr;
		bar.tick();
		bak(argv[1], "./bak.bak");
		if (i = 1){
			termcolor::reset;
			bar.is_completed();
			break;
		}
		
	}

	printf("# ");
	getline(cin, s);

	tmp << s;
	tmp.close();

	return 0;
}


