class Solution {

public:
    bool isValid(string s) {
        
stack<char> stak;
char c;
   
int i =0;
while(i<s.length()){


stak.push(s[i]);

if(s[i] == '}'){
stak.pop();

if(stak.empty()){
    return false;}

if(stak.top() == '{'){
stak.pop();
i++;
continue;
}
else{
    stak.push('}');

}
}


if(s[i] == ')'){
stak.pop();

if(stak.empty()){
    return false;}

if(stak.top() == '('){
stak.pop();
i++;
continue;
}
else{
    stak.push(')');
}

}


if(s[i] == ']'){
stak.pop();

if(stak.empty()){
    return false;}

if(stak.top() == '['){
stak.pop();
i++;
continue;
}
else{
    stak.push(']');
}

}
  i++;      
} 
        
  if(stak.empty())
  return true;
  else
  return false;      
    

    }
};

