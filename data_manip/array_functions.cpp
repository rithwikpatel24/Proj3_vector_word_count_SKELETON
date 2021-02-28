//author: Rithwik patel
#include "../includes/array_functions.h"
#include "../includes/constants.h"
#include "../includes/utilities.h"
#include <algorithm>

using namespace std;
using namespace constants;

namespace KP {
bool ascendComp(const entry &firstEntry, const entry &seconEntry);

bool descendComp(const entry &firstEntry, const entry &seconEntry);

bool numOfTimes(const entry &firstEntry, const entry &seconEntry);
void clear(std::vector<constants::entry> &entries) {
entries.clear();
}

int getSize(std::vector<constants::entry> &entries) {
return entries.size();
}

std::string getWordAt(std::vector<constants::entry> &entries, int i) {
return entries.at(i).word;
}

int getNumbOccurAt(std::vector<constants::entry> &entries, int i) {
if (entries.size() != 0) {
return entries.at(i).number_occurences;

}
return FAIL;
}

bool processFile(std::vector<constants::entry> &entries,
std::fstream &myfstream) {
if (!myfstream) {
return false;
}
string line1;
while (getline(myfstream, line1)) {
processLine(entries, line1);
}
return true;
}

void processLine(std::vector<constants::entry> &entries, std::string &myLine) {
string tokenTemp;
stringstream myStr(myLine);
while (getline(myStr, tokenTemp, CHAR_TO_SEARCH_FOR)) {
processToken(entries, tokenTemp);
}
}

void processToken(std::vector<constants::entry> &entries, std::string &token) {
if (strip_unwanted_chars(token) == false) {
return;
}
string str = token;
toUpper(str);
int count = -1;
for (unsigned int i = 0; i < entries.size(); i++) {
string user = entries[i].word_uppercase;
if (user == str) {
count = i;
break;
}
}
if (count != -1) {
entries[count].number_occurences++;
} else {
entry newEntry { token, str, 1 };
entries.push_back(newEntry);
}

}

void sort(std::vector<constants::entry> &entries, constants::sortOrder so) {
if (so == NONE) {
return;
}
if (so == ASCENDING) {
sort(entries.begin(), entries.end(), ascendComp);
}
if (so == DESCENDING) {
sort(entries.begin(), entries.end(), descendComp);
}
if (so == NUMBER_OCCURRENCES) {
sort(entries.begin(), entries.end(), numOfTimes);
}

}
bool ascendComp(const entry &firstEntry, const entry &seconEntry) {
return firstEntry.word_uppercase < seconEntry.word_uppercase;
}

bool descendComp(const entry &firstEntry, const entry &seconEntry) {
return firstEntry.word_uppercase > seconEntry.word_uppercase;
}

bool numOfTimes(const entry &firstEntry, const entry &seconEntry) {
return firstEntry.number_occurences > seconEntry.number_occurences;
}
}
