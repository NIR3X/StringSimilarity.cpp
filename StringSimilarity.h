#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class CStringEmbedding {
protected:
	std::unordered_map<char, size_t> chars;

public:
	CStringEmbedding(const std::string& str);

	friend class CStringEmbeddings;

	static std::unordered_map<std::string, CStringEmbedding> MapFromStrings(const std::vector<std::string>& strings);
};

class CStringEmbeddings {
protected:
	std::unordered_map<std::string, CStringEmbedding> embeddingMap;

public:
	CStringEmbeddings(const std::unordered_map<std::string, CStringEmbedding>& embeddings);
	CStringEmbeddings(const std::vector<std::string>& strings);

	std::vector<std::pair<std::string, double>> FindSimilarsFor(const CStringEmbedding& target) const;

	std::pair<typename std::unordered_map<std::string, CStringEmbedding>::iterator, bool> EmplaceEmbedding(
		const std::string& key, const CStringEmbedding& embedding
	);
	std::pair<typename std::unordered_map<std::string, CStringEmbedding>::iterator, bool> EmplaceEmbedding(
		const std::string& key, const std::string& str
	);
	std::pair<typename std::unordered_map<std::string, CStringEmbedding>::iterator, bool> EmplaceEmbedding(const std::string& str);

	size_t EraseEmbedding(const std::string& key);
};
