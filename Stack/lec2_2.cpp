#include<iostream>
#include<stack>
using namespace std;

bool solve(string &str){
    stack<char> st;

    for(int i=0 ; i<str.length() ; i++){
        char ch = str[i];
        if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            int opcnt = 0;

            while(!st.empty() && st.top() != '('){
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    opcnt++;
                }
                st.pop();
            }
            st.pop();
            if(opcnt == 0){
                return true;
            }
        }
    }
    //redundand bracket nahi mile

    return false;
}

int main(){
    string str = "(a+b + (c))";

    bool ans = solve(str);

    if(ans == false) cout<<"redundant bracket are not present"<<endl;
    else if(ans == true) cout<<"Redundant bracket are present"<<endl;
    return 0;
}