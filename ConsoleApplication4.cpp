#include "Encoding.h"

int main() {
    const std::string inputData = "© 2023 Example Inc.";

    // Example 1: UTF-8 to UTF-16 conversion
    {
        std::unique_ptr<Encoder> utf8Encoder = EncoderFactory::createEncoder(EncodingType::UTF8);
        std::unique_ptr<Encoder> utf16Encoder = EncoderFactory::createEncoder(EncodingType::UTF16);

        std::string utf8Encoded = utf8Encoder->encode(inputData);
        std::string utf16Encoded = utf16Encoder->encode(utf8Encoded);

        std::cout << "UTF-8 to UTF-16 Conversion:\n";
        std::cout << "Input: " << inputData << '\n';
        std::cout << "UTF-8 Encoded: " << utf8Encoded << '\n';
        std::cout << "UTF-16 Encoded: " << utf16Encoded << '\n';
    }

    // Example 2: Reading and Writing data to a file with specified encoding
    {
        std::string fileContent = "Hello, 🌍!";
        std::unique_ptr<Encoder> asciiEncoder = EncoderFactory::createEncoder(EncodingType::ASCII);

        // Best Practice: Use error handling when writing to files
        try {
            std::ofstream outputFile("example.txt");
            if (!outputFile.is_open()) {
                throw std::runtime_error("Error opening file.");
            }

            std::string encodedData = asciiEncoder->encode(fileContent);
            outputFile << encodedData;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}