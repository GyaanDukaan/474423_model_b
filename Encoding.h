
#include <iostream>
#include <string>
#include <memory>

#ifndef ENCODING_H
#define ENCODING_H

enum class EncodingType {
    UTF8,
    UTF16,
    ASCII
};

class Encoder {
public:
    virtual ~Encoder() = default;

    virtual std::string encode(const std::string& input) const = 0;
    virtual std::string decode(const std::string& input) const = 0;
};

class UTF8Encoder : public Encoder {
public:
    std::string encode(const std::string& input) const override {
        // Implement UTF-8 encoding logic here
        // For simplicity, we'll return the input string as UTF-8 is the default encoding in C++
        return input;
    }

    std::string decode(const std::string& input) const override {
        // Implement UTF-8 decoding logic here
        // For simplicity, we'll return the input string
        return input;
    }
};

class UTF16Encoder : public Encoder {
public:
    std::string encode(const std::string& input) const override {
        // Implement UTF-16 encoding logic here
        return input;
    }

    std::string decode(const std::string& input) const override {
        // Implement UTF-16 decoding logic here
        return input;
    }
};

class ASCIIEncoder : public Encoder {
public:
    std::string encode(const std::string& input) const override {
        // Implement ASCII encoding logic here
        // Validate input to ensure it contains only ASCII characters
        return input;
    }

    std::string decode(const std::string& input) const override {
        // Implement ASCII decoding logic here
        return input;
    }
};

class EncoderFactory {
public:
    static std::unique_ptr<Encoder> createEncoder(EncodingType type) {
        switch (type) {
        case EncodingType::UTF8:
            return std::make_unique<UTF8Encoder>();
        case EncodingType::UTF16:
            return std::make_unique<UTF16Encoder>();
        case EncodingType::ASCII:
            return std::make_unique<ASCIIEncoder>();
        }
        throw std::runtime_error("Invalid encoding type");
    }
};

#endif  // ENCODING_H
