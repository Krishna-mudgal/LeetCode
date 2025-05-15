#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare(string s, string t) {
    
        stack<char> s1, s2;

        int i = 0, j = 0;

        while(i < s.size() && j < t.size()){
            
            if(s[i] == '#' && s1.size() > 0) s1.pop();
            else if(t[j] == '#' && s2.size() > 0) s2.pop();
            else if (s[i] != t[j]){
                cout << s[i] << " " << t[j] << endl;
                s1.push(s[i]);
                s2.push(t[j]);
            }

            i++;
            j++;
        }

        while(i < s.size()){
            if(s[i] == '#' && s1.size() > 0) s1.pop();
            else if(s[i] != t[t.size() - 1]) s1.push(t[j]);
            i++;
        }

        while(j < t.size()){
            if(t[j] == '#' && s2.size() > 0) s2.pop();
            else if(s[s.size() - 1] != t[j]) s2.push(t[j]);
            j++;
        }

        if(s1.size() > 0 || s2.size() > 0) return false;
        else return true;

    }

int main(){

    cout << backspaceCompare("xywrrmp", "xywrrmu#p");


    return 0;
}