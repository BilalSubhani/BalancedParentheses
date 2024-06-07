class Solution {
public:
    bool isValid(string s) {
        multimap<char, int> myMultimap;
        myMultimap.insert(pair<char, int>('(', 0));
        myMultimap.insert(pair<char, int>('{', 0));
        myMultimap.insert(pair<char, int>('[', 0));

        for(int i=0; i<s.size(); i++){
            auto it = myMultimap.end();
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                switch (s[i]){
                    case ')':
                        it = myMultimap.find('(');

                        if (it != myMultimap.end()) {
                            if(it->second == 0)
                                return false;
                            else
                                it->second--;
                        }
                        break;
                    case '}':
                        it = myMultimap.find('{');
                        if (it != myMultimap.end()) {
                            if(it->second == 0)
                                return false;
                            else
                                it->second--;
                        }
                        break;
                    case ']':
                        it = myMultimap.find('[');
                        if (it != myMultimap.end()) {
                            if(it->second == 0)
                                return false;
                            else
                                it->second--;
                        }
                        break;
                }
            }
            else{
                it = myMultimap.find(s[i]);

                if (it != myMultimap.end())
                    it->second++;
            
            }
        }
        return true;
    }
};
