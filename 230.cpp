/*
 * =====================================================================================
 *
 *       Filename:  230.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/17/2014 10:24:08
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int kMax = 180;

struct Book {
	int id;
	string title;
	string author;
	Book(string &t, string &a) : title{move(t)}, author{move(a)} {}
	void to_string() {
		printf("%s %s\n", title.c_str(), author.c_str());
	}
};

char input[kMax];
map<string, int> book_index;
vector<Book> books;
set<int> borrowed_books;
vector<int> returned_book;

int main() {
#ifdef Debug
	freopen("230.in", "r", stdin);
#endif
	while (fgets(input, kMax, stdin)) {
		if (input[0] == 'E' && input[1] == 'N' && input[2] == 'D') {
			break;
		}
		input[strlen(input)-1] = '\0';
		const char * pos = strstr(input, "by");
		string title {input, static_cast<size_t>(pos - input - 1)};
		string author {pos + 3};
		books.emplace_back(title, author);
	}
	sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
		if (a.author == b.author) {
			return a.title < b.title;
		} else {
			return a.author < b.author;		
		}
	});
	int count = 0;
	for (auto &a : books) {
		a.id = count++;
		book_index[a.title] = a.id;
		//a.to_string();
	}
	while (fgets(input, kMax, stdin)) {
		if (input[0] == 'E' && input[1] == 'N' && input[2] == 'D') {
			break;
		}
		if (input[0] == 'S') {
			sort(returned_book.begin(), returned_book.end(), [](const int &a, const int &b) {
				if (books[a].author == books[b].author) {
					return books[a].title < books[b].title;
				} else {
					return books[a].author < books[b].author;
				}
			});
			for (auto &v : returned_book) {
				int pos = v - 1;
				while (true) {
					if (pos < 0) break;
					if (borrowed_books.count(pos)) {
						--pos;
					} else {
						break;
					}
				}
				borrowed_books.erase(v);
				if (pos >= 0) {
					printf("Put %s after %s\n", books[v].title.c_str(), books[pos].title.c_str());
				} else {
					printf("Put %s first\n", books[v].title.c_str());
				}
			}
			returned_book.clear();
			printf("END\n");
		} else {
			input[strlen(input)-1] = '\0';
			const char * pos = strchr(input, ' ');
			string title {pos + 1};
			int index = book_index[title];
			if (input[0] == 'B') {
				//printf("Borrow %s\n", title.c_str());
				borrowed_books.insert(index);
			} else {
				returned_book.push_back(index);
				//printf("Return %s\n", title.c_str());
			}
		}
	}
	return 0;
}
