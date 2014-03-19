class Solution {
public:
    vector<string> generateParenthesis(int n) {
        char* str = new char[2 * n + 1];
        int i;
        for (i = 0; i < 2 * n + 1; i++)
        {
            str[i] = 0;
        }
        int lcount = n, rcount = n;
        i = 0;
        vector<string> results;
        bool end = false;
        while(!end)
        {
            switch(str[i])
            {
            case 0:
                if (i == 2 * n)
                {
                    results.push_back(str);
                    i--;
                    break;
                }
                if (lcount > 0)
                {
                    str[i] = '(';
                    lcount--;
                    i++;
                    break;
                }
                str[i] = ')';
                rcount--;
                i++;
                break;
                
            case '(':
                if (rcount > lcount + 1)
                {
                    str[i] = ')';
                    lcount++;
                    rcount--;
                    i++;
                    break;
                }
                if (i > 0)
                {
                    str[i] = 0;
                    lcount++;
                    i--;
                    break;
                }
                end = true;
                break;
            case ')':
                str[i] = 0;
                rcount++;
                i--;
                break;
            }
        }
        return results;
    }
   
};