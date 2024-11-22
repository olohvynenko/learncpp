#include<iostream>
#include<regex>

using namespace std;

int main() {
    string input { "AABB AAABBB AABB AaBb AABB" };
    regex pat { R"((^|\s+)(A{2}B{2})(\s+|$))" };
    smatch match;
    regex_search(input, match, pat);
    for (sregex_iterator p(input.begin(),input.end(),pat); p!=sregex_iterator{}; ++p) {
        smatch match = *p;
        cout << match.str() << "; sub: " << match[2] << " matched: " << match[0].matched << '\n'; 
        
    }
}
