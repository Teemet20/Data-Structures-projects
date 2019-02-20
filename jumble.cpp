#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>



void ssort(std::string &s) {

  std::sort(s.begin(), s.end());
}


int main(int argc, char *argv[]){
  std::unordered_map<std::string, std::vector<std::string>> jumbword;
  std::ifstream file;
  std::string word;
  
  if(argc != 2) {
    std::cout << "usage:  ./jumble <filename>\n";
    std::cout << "goodbye\n";
    return 1;
  }
  
  file.open(argv[1], std::ios::in);

  if(!file.is_open()){
    std::cout << "Error: could not open file '" <<
                     argv[1] << "'\n";
    std::cout << "goodbye\n";
    return 1;
  }
  
  std::cout << "reading input file...\n";

  while(file >> word) { 
    // file >> word; 
    ssort(word);
    if(jumbword.count(word) == 0){
       jumbword[word] = 1;
       jumbword[word].push_back(word);
    }
    else {
       jumbword[word]++;
       jumbword[word].push_back(word);
    }
  }
  
  std::cout << 
    "enter a word and I will tell you what I know about it\n";
  std::cout << 
    "  when you are done, type ctrl-d (ctrl-z on windows)\n\n";
  std::cout << "> ";


  while(std::cin >> word) {

    if(jumbword.count(word)==0) {
       std::cout << "sorry, '" << word << 
            "' does not appear in the input file '" <<
            argv[1] << "'\n";
    }
    else {
    	/*
       std::cout << "'" << word << "' appears " <<
           jumbword[word] << " times in the file '" <<
            argv[1] << "'\n";
        */
		for (int i = 0, i<jumbword.count(), i++){
			std::cout << jumbword[word].at(i) << "\n";
		}    
    }
  }
  // user has quit.  Let's dump the map contents

  std::cout << "jumbword contents:\n\n";

  printf("      WORD              #OCCURRENCES\n");
  printf("------------------------------------------\n\n");

  for(std::pair<std::string, int> entry : jumbword) {
     printf("  %10s     %10d\n", entry.first.c_str(), entry.second);
  }

  return 0;
}

