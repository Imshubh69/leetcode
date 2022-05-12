class Solution {
public:
    string shortestPalindrome(string s) {
        
        string temp = s ;
        reverse(temp.begin() , temp.end());
        string l = s + "#" + temp;
        
        int lps[l.length()];
        
        int i = 1 , len = 0 ;lps[0]= 0;
        while(i < l.length()){
            if(l[i] == l[len]){
                len++;
                lps[i] = len ;
                i++;
            }else {
                if(len == 0){
                    lps[i] = 0;
                    i++;
                }else {
                    len = lps[len - 1];
                }
            }
        }
        
        
       int x = lps[l.length() - 1];
        
       string y = s.substr(x);
        
        reverse(y.begin() , y.end());
        
        return y + s;
        
        
    }
};
