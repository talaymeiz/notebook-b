#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("check write") {
    ariel::Notebook notebook;
	notebook.write(100, 100, 50, Direction::Horizontal, "abcd");
	CHECK(notebook.read(100, 99, 51, Direction::Vertical, 3) == nospaces("_b_\n"));
}

TEST_CASE("check read") {
    ariel::Notebook notebook;
    CHECK(notebook.read(100, 99, 51, Direction::Vertical, 3) == nospaces("___\n"));
	notebook.write(100, 100, 50, Direction::Horizontal, "acd");
	CHECK(notebook.read(100, 99, 51, Direction::Vertical, 3) == nospaces("_c_\n"));
}

TEST_CASE("check erase") {
    ariel::Notebook notebook;
	notebook.write(100, 100, 50, Direction::Horizontal, "abcd");
    notebook.erase(100, 100, 50, Direction::Horizontal, 3);
	CHECK(notebook.read(100, 100, 51, Direction::Horizontal, 4) == nospaces("~~d_\n"));
}


TEST_CASE("Bad input write") {
    ariel::Notebook notebook;
    CHECK_THROWS(notebook.write(-4, 100, 50, Direction::Horizontal, "abcd"));
    CHECK_THROWS(notebook.write(10, -3, 50, Direction::Horizontal, "abcd"));
    CHECK_THROWS(notebook.write(9, 100, -7, Direction::Horizontal, "abcd"));
    CHECK_THROWS(notebook.write(6, 100, 102, Direction::Horizontal, "abcd"));
    CHECK_THROWS(notebook.write(10, 100, 95, Direction::Horizontal, "abcdefghij"));
    notebook.write(10, 100, 50, Direction::Horizontal, "abcd");
    CHECK_THROWS(notebook.write(10, 100, 50, Direction::Horizontal, "efgh"));
}

TEST_CASE("Bad input read") {
    ariel::Notebook notebook;
    CHECK_THROWS(notebook.read(-4, 100, 50, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.read(10, -3, 50, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.read(9, 100, -7, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.read(6, 100, 102, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.read(10, 100, 95, Direction::Horizontal, -6));
}

TEST_CASE("Bad input erase") {
    ariel::Notebook notebook;
    CHECK_THROWS(notebook.erase(-4, 100, 50, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.erase(10, -3, 50, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.erase(9, 100, -7, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.erase(6, 100, 102, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.erase(10, 100, 95, Direction::Horizontal, -6));
    }
