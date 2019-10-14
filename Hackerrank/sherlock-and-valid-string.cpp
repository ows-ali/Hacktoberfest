string isValid(string s) {
    int a[26];
    int firstValue;
    int difference = 0;
    bool firstValueSet = false;
    for(int i = 0; i < 26; i++)
        a[i] = 0;
    for(int i = 0; i < s.length(); i++){
        a[(int)s[i] - 97]++;
    }
    for(int i = 0; i < 26; i++){
        if(a[i] != 0){
            if(!firstValueSet){
                firstValueSet = true;
                firstValue = a[i];
            }
            else{
                if(a[i] != firstValue)
                    difference++;
                if(difference > 1)
                    return "NO";
            }
        }
    }
    return "YES";
}