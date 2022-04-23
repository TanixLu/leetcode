#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=960 lang=cpp
 *
 * [960] Delete Columns to Make Sorted III
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int str_num = strs.size(), str_len = strs[0].size();
        int min_del = str_len - 1, dpi, lasti, stri;
        vector<int> dp(str_len, 1);  // dp[i]: longest increasing substring end with i'th char
        for(dpi = 1; dpi < str_len; dpi++){
            for(lasti = 0; lasti < dpi; lasti++){
                for(stri = 0; stri < str_num; stri++)
                    if(strs[stri][dpi] < strs[stri][lasti])break;
                if(stri == str_num)dp[dpi] = max(dp[dpi], dp[lasti] + 1);
            }
            min_del = min(min_del, str_len - dp[dpi]);
        }
        return min_del;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<string>> strss{
        {"babca", "bbazb"},//3
        {"edcba"},//4
        {"ghi", "def", "abc"},//0
        {"bbaaa","aaabb","bbaab","aabaa"},//3
        {"abcbcbc","cbacbcb"},//4
        //97
        {"bgfdbgfdegdgdccbfhbfdbfgcfefeacghgadedahbgcdabdegdbdfgaecbahhgedcfegeaegefddchfcefceeceehdffhehcddbe","cebaedfgbfadhheaafcabfdgfbdfabagfhhgbbaefcfhhbhhbababgdcagaddgadfbhgdfegggdhfbebacbcggebabheecbddcac","dbcdfbccabbheddaaggefegbbfegfdccheadbedaaabagdgbaebcahhaeaaffdfebhahcfebfgbfedcfedgdaacdecfhccccbacg","bghgadceachegaehfbfcbddefbadfbeaehegaafhbafhgedhhbcdedceeghhhbaffgbbfebfhfffcadchaaaeddabdhhgbffefah","hhhgdcggedfaeghabbfheabcdhdbhdabhcfdegacdfabgeaddaabddeaefdaaabgedfccbechhegfbcccffhagabdcecgfdggegg","fdafaabgcffdhbchcafghhgabbhbfebegfgdhaabeababfbdbbegacbaceeaceefdfgfdhahddhbaabcfcebhffehgccedbcgggb","efbbhfgefddfhbfhdhdecabhdbhchfabddefbggdhegcgahbebcgdachhggfeedfgahgahhfgfcdchdfcbdeabedbchehbhdhfeb","egbccfhhdeafgbefdahcagbghhffgachfffddffhcbgbhbhbdgeeebededdcbdcbedcgcdfcgffhfhdaaebcgdadhhdccfcgabbf","gbghhagbafadcbacefghhbffagehbfaahgabgdagbbhbcgagafffedhedhhchbbfgcefbedhgggchbcfbffhgfdgdgebdfdgcgaf","cfhcbbhhbefaaegfgfadbfbddhgcdbgaaffbcechbgbfddbfcfgeeeabcbdbbdggefedhgfcghggebfbeeghebbbfcbefegheeea"}
    };
    for(auto& strs: strss)
        cout << s.minDeletionSize(strs) << '\n';
}
