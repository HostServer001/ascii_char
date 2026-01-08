#include <iostream>
#include <cstring>
#include <iomanip>
#include <getopt.h>
#include <vector>
#include <cctype>
using namespace std;

void sta(const char* arg);
void ats(const char* arg);
void printHelp();
void printVersion();
vector<string> split(string text, char seprator);

int main(int argc,char* argv[]){
  int opt;
  int option_idx = 0;
  static struct option long_options[] = {
    {"help",   no_argument      ,0,0},
    {"version",no_argument      ,0,0},
    {"sta",    required_argument,0,0},
    {"ats",    required_argument,0,0}
    
  };
  while ((opt = getopt_long(argc,argv,"hv",long_options,&option_idx)) != -1){
    switch (opt){
      
      case 'h':
        printHelp();
        return 0;
      
      case 'v':
        printVersion();
        return 0;
      
      case 0:
        switch (option_idx){
          case 0:
            printHelp();
            return 0;
          case 1:
            printVersion();
            return 0;
          case 2:
            sta(optarg);
            break;
          case 3:
            ats(optarg);
            break;
        }
        break;  
      default:
        printHelp();
        return 0;
    }
  }

  return 0;
};

// all functions :) 

void sta(const char* optarg){
  cout << "Char | ASCII" << endl;
  string s = optarg;
  for (size_t i = 0; i < s.size(); i++){
    cout << s[i] << "    | "<< setw(5) << int(s[i]) << endl;
  }
}

void ats(const char* optarg){
  cout <<"ASCII" << " | " <<"Char" << endl;
  string s = optarg;
  vector<string> nums_str = split(s,',');
  for (string i:nums_str){
    int code;
    try{
      code = stoi(i);
      char c = char(code);
    
      if (isprint(c)){
        cout << setw(5) << code  << " | " << c << endl;
      }
      else{
        cout << setw(5) << code << " | " << "<non-printable>"  << endl;
      }
    }
    catch(invalid_argument&){
      cout << i << " is not a valid number" << endl;
    }
  }
}

void printHelp() {
    cout << "Usage:\n"
         << "  --sta <string>   Convert string to ASCII codes\n"
         << "  --ats <codes>    Convert ASCII codes (comma-separated) to chars\n"
         << "  -h, --help       Show help\n"
         << "  -v, --version    Show version\n";
}


void printVersion(){
  const char* VERSION = "0.1.0";
  cout << VERSION << endl;
}

vector<string> split(string text, char seprator){
  vector<string> return_vector;
  string element;
  for (size_t i = 0; i < text.size(); i++){
    if (text[i] != seprator){
      element += text[i];
    }
    else{
      return_vector.push_back(element);
      element = "";
    }
  }
  return_vector.push_back(element); //for last element
  return return_vector;
}

//end of universe
