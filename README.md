# StringSimilarity.cpp - C++ Classes for Calculating String Similarity Using Character Embeddings

This repository contains C++ classes `CStringEmbedding` and `CStringEmbeddings` for calculating string similarity using character embeddings.

## Overview

The `CStringEmbedding` class is responsible for creating embeddings for individual strings by counting the occurrences of characters. The `CStringEmbeddings` class manages a collection of string embeddings and provides methods for finding similar strings based on their embeddings.

## Installation

To use this package, you can clone the repository and compile it using a C++ compiler:

```bash
git clone https://github.com/NIR3X/StringSimilarity.cpp
cd StringSimilarity.cpp
make
```

## Usage

To use these classes, follow these steps:

1. Include the header file `StringSimilarity.h` in your project.
2. Create a vector of strings or provide a list of strings.
3. Initialize a `CStringEmbeddings` object with the vector of strings.
4. Use the `FindSimilarsFor` method to find similar strings for a given input string.

Here's an example of how to use these classes:

```cpp
#include "StringSimilarity.h"
#include <iostream>

int main() {
	std::vector<std::string> words = {
		"apple", "banana", "orange", "grape", "pineapple", "strawberry", "watermelon", "kiwi", "pear", "peach",
		"blueberry", "raspberry", "blackberry", "melon", "cherry", "apricot", "mango", "papaya", "plum", "lemon"
	};

	CStringEmbeddings embeddings(words);

	std::string wordToFindSimilarsFor = "apple";
	for (const auto& [similar, distance] : embeddings.FindSimilarsFor(wordToFindSimilarsFor)) {
		std::cout << "Similar: " << similar << ", Distance: " << distance << std::endl;
	}

	return 0;
}
```

## License

[![GNU AGPLv3 Image](https://www.gnu.org/graphics/agplv3-155x51.png)](https://www.gnu.org/licenses/agpl-3.0.html)

This program is Free Software: You can use, study share and improve it at your
will. Specifically you can redistribute and/or modify it under the terms of the
[GNU Affero General Public License](https://www.gnu.org/licenses/agpl-3.0.html) as
published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
