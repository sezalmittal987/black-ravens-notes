class Solution {
public:
    bool isValid(string s) {
       stack<char> c;
       for( int i = 0 ; i < s.length() ; i++ ){
           // opening
           if( s[i] == '(' or s[i] == '[' or s[i] == '{'){
               // add in the stack
               c.push(s[i]);
           }
           // closing
           else{
               // check if the stack is empty or not
               if(c.empty() == true) return false;
               // stack is not empty
               if(s[i] == ')' and c.top() == '(') c.pop();
               else if( s[i] == ']' and c.top() == '[') c.pop();
               else if( s[i] == '}' and c.top() == '{') c.pop();
               else return false;
           }
       } 
       if(c.empty() == true) return true;
       return false;
    }
};
