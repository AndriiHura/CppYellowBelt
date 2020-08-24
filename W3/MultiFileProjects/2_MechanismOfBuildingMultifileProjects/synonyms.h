#pragma once

#include<set>
#include<string>
#include<map>

using namespace std;


using Synonyms = map<string, set<string>>;

//Interface

void AddSynonyms(Synonyms& synonyms,
    const string& first_word, const string& second_word);
size_t GetSynonymsCount(Synonyms& synonyms,
    const string& first_word);
bool AreSynonyms(Synonyms& synonyms,
    const string& first_word, const string& second_word);


//Implementation


