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

void AddSynonyms(Synonyms& synonyms,
    const string& first_word, const string& second_word) {
    // второе слово добавляем в список синонимов первого...
    synonyms[first_word].insert(first_word);
    // и наоборот
    synonyms[second_word].insert(first_word);
}

size_t GetSynonymsCount(Synonyms& synonyms,
    const string& first_word) {
    return synonyms[first_word].size();
}

bool AreSynonyms(Synonyms& synonyms,
    const string& first_word, const string& second_word) {
    return synonyms[first_word].count(second_word) == 1;
}
