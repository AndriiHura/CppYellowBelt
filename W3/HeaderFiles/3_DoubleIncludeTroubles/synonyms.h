#pragma once

#include<set>
#include<string>
#include<map>

using namespace std;


using Synonyms = map<string, set<string>>;


void AddSynonyms(Synonyms& synonyms,
    const string& first_word, const string& second_word) {
    // ������ ����� ��������� � ������ ��������� �������...
    synonyms[first_word].insert(first_word);
    // � ��������
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
