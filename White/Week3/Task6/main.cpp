#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class ReversibleString{
public:
    ReversibleString(){
        this->str = "";
    }
    ReversibleString(const string& str){
        this->str = str;
    }
    void Reverse(){
        string helper;
        for (int i = str.size() - 1; i >= 0 ; --i) {
            helper += str[i];
        }
        str = helper;
    }
    string ToString() const{
        return str;
    }
private:
    string str;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
