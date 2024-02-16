#include "StringSimilarity.h"
#include <algorithm>
#include <cmath>

CStringEmbedding::CStringEmbedding(const std::string& str) : chars({}) {
	for (char c : str) {
		++chars[std::tolower(c)];
	}
}

std::unordered_map<std::string, CStringEmbedding> CStringEmbedding::MapFromStrings(const std::vector<std::string>& strings) {
	std::unordered_map<std::string, CStringEmbedding> embeddingMap;
	embeddingMap.reserve(strings.size());

	for (const auto& str : strings) {
		embeddingMap.emplace(str, CStringEmbedding(str));
	}

	return embeddingMap;
}

CStringEmbeddings::CStringEmbeddings(const std::unordered_map<std::string, CStringEmbedding>& embeddingMap) : embeddingMap(embeddingMap) {
}

CStringEmbeddings::CStringEmbeddings(const std::vector<std::string>& strings) : CStringEmbeddings(CStringEmbedding::MapFromStrings(strings)) {
}

std::vector<std::pair<std::string, double>> CStringEmbeddings::FindSimilarsFor(const CStringEmbedding& target) const {
	std::vector<std::pair<std::string, double>> similars = {};
	for (const auto& [stringKey, embedding] : embeddingMap) {
		double distance = 0;
		
		std::unordered_map<char, double> deltaMap = {};

		for (const auto& [charKey, charCount] : embedding.chars) {
			deltaMap[charKey] += charCount;
		}

		for (const auto& [charKey, charCount] : target.chars) {
			deltaMap[charKey] -= charCount;
		}

		for (const auto& [_, delta] : deltaMap) {
			distance += std::sqrt(delta * delta);
		}

		similars.push_back({stringKey, distance});
	}

	std::sort(similars.begin(), similars.end(), [](const auto& a, const auto& b) {
		return a.second < b.second;
	});

	return similars;
}

std::pair<typename std::unordered_map<std::string, CStringEmbedding>::iterator, bool> CStringEmbeddings::EmplaceEmbedding(
	const std::string& key, const CStringEmbedding& embedding
) {
	return embeddingMap.emplace(key, embedding);
}

std::pair<typename std::unordered_map<std::string, CStringEmbedding>::iterator, bool> CStringEmbeddings::EmplaceEmbedding(
	const std::string& key, const std::string& str
) {
	return embeddingMap.emplace(key, CStringEmbedding(str));
}

std::pair<typename std::unordered_map<std::string, CStringEmbedding>::iterator, bool> CStringEmbeddings::EmplaceEmbedding(const std::string& str) {
	return EmplaceEmbedding(str, CStringEmbedding(str));
}

size_t CStringEmbeddings::EraseEmbedding(const std::string& key) {
	return embeddingMap.erase(key);
}
