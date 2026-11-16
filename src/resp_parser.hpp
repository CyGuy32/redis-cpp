#ifndef RESP_PARSER_HPP
#define RESP_PARSER_HPP

#include <string>
#include <vector>
#include <cstddef>


enum class ParseStatus {
    Invalid, 
    Incomplete, 
    Complete
};

struct ParseResult {
    ParseStatus status = ParseStatus::Incomplete;
    std::vector<std::string> elements;
    std::size_t bytes_consumed = 0;
};

ParseResult resp_parser(const std::string& input);

#endif