#include "StringSimilarity.h"
#include <cassert>
#include <iostream>

int main() {
	std::vector<std::string> words = {
		"apple", "banana", "orange", "grape", "pineapple", "strawberry", "watermelon", "kiwi", "pear", "peach",
		"blueberry", "raspberry", "blackberry", "melon", "cherry", "apricot", "mango", "papaya", "plum", "lemon"
	};

	CStringEmbeddings embeddings(words);

	std::string wordToFindSimilarsFor = "apple";
	std::vector<std::pair<std::string, double>> similars = embeddings.FindSimilarsFor(wordToFindSimilarsFor);

	assert(words.size() == 20);
	assert(wordToFindSimilarsFor == "apple");
	assert(similars.size() == 20);

	assert(similars[0].first == "apple");
	assert(similars[0].second == 0);

	assert(similars[1].first == "pear");
	assert(similars[1].second == 3);

	assert(similars[2].first == "peach");
	assert(similars[2].second == 4);

	assert(similars[3].first == "grape");
	assert(similars[3].second == 4);

	assert(similars[4].first == "pineapple");
	assert(similars[4].second == 4);

	assert(similars[5].first == "papaya");
	assert(similars[5].second == 5);

	assert(similars[6].first == "plum");
	assert(similars[6].second == 5);

	assert(similars[7].first == "lemon");
	assert(similars[7].second == 6);

	assert(similars[8].first == "melon");
	assert(similars[8].second == 6);

	assert(similars[9].first == "orange");
	assert(similars[9].second == 7);

	assert(similars[10].first == "apricot");
	assert(similars[10].second == 8);

	assert(similars[11].first == "mango");
	assert(similars[11].second == 8);

	assert(similars[12].first == "raspberry");
	assert(similars[12].second == 8);

	assert(similars[13].first == "watermelon");
	assert(similars[13].second == 9);

	assert(similars[14].first == "blackberry");
	assert(similars[14].second == 9);

	assert(similars[15].first == "kiwi");
	assert(similars[15].second == 9);

	assert(similars[16].first == "banana");
	assert(similars[16].second == 9);

	assert(similars[17].first == "cherry");
	assert(similars[17].second == 9);

	assert(similars[18].first == "blueberry");
	assert(similars[18].second == 10);

	assert(similars[19].first == "strawberry");
	assert(similars[19].second == 11);

	std::cout << "PASS" << std::endl;

	return 0;
}
