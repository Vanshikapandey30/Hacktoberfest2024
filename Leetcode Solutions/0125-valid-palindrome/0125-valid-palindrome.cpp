class Solution {
public:
   string tolowercase(string a) {
    int n = a.size();
    for(int i=0;i<n;i++){
         if(isalpha(a[i])){
            a[i]=tolower(a[i]);
        }
    }
return a;
}




bool isPalindrome(string s)
{   


    s=tolowercase(s);

    int n=s.length();
    int e=n-1;
    int b=0;

    while(b<e){

         if (!isalnum(s[b])) {
            b++;
        }
        else if (!isalnum(s[e])) {
            e--;
        }
        else if (s[b] != s[e]) {
            return false;
        } 
        else {
            b++;
            e--;
        }

    }
    return true;

}
};