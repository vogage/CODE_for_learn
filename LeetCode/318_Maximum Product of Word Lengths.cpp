#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string> &words) {
        int res = 0;
        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (no_common_char(words[i], words[j])) {
                    res = max(res, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
    //["ffdeeabbccfaaeebfccaddcbd", "ddfcfbaf", "ffcdefefacdfbfdc", "fa", "fecfde", 
    //"efcedddafebcbbfaae", "efafbf", "ecbcbed", "aaec", "bdedcbfafccaafcfefeffdc", 
    //"ffdac", "cbefdffbbed", "dfaefdccaddaacbaca", "eda", "beedefdddafeedaffcafcabbe", 
    //"dbabfefaabdecbff", "adcccdcefaefdddd", "dafcdaebaafdeabcfeacbbbf", 
    //"eadeebfbcdacaabe", "cceaa", "dfbdccfecafbdeacbddaedf", "addbabd",
    //"aaaaacfc", "cddaacabfefbfcffecacaa", "ebcfeaf", "ecffcffbcadeefbabaccafda", "bbcbffefaeaccedeb",
    //"dcfabedbffbcdceacbcecdedf", "afbdebcbccfcfac", "eadcabedbcafadbefa", "fefeaddbcecaed", 
    //"fdeaacbcebacebadaeb", "ccddfafcbaffbeedfa", "edbc", "cabefdafe", "dadedfbabbfcbfeabcea", 
    //"feabba", "ddbdeeefcbdde", "acecdbeceabbdcee", "edf", "bbdcffdadfabefaddadd", 
    //"bcdbbedebafcfffeeca", "bceebbcffdabbee", "edcbfeabfbaeadea", "efabbcaafcbca",
    //"badcbfcecedbebbdaaaeddf", "cbbcfabbfdfebddcfffcbeebacf", "fbbfcdbdbeacdeeabb", 
    //"aaae", "adfefeb", "efcafdcaedebbc", "befcaeadefafdcec", "dddb", "ecccbbdceeecd", "def", 
    //"debdfddeeaddfdddabccabfe", "dbcabccedecadb", "bfbde", "ddddaeeacdeedcafbfabbc", 
    //"dbbefcfcbfcfbdccacffdaafd", "dcdcebfbefccebbaebafbdaffda", "ddeefdefdccedceecfcfbdeeeda", 
    //"acfcadcafcc", "eebeadacbeccedfffc", "fcaacdeaaca", "cecaebfcfbfeefcdbbfabdbcf", "ffcffdd", "babcbe", 
    //"abbfefaedfddeba", "fafafceeabcaefaddcccd", "bf", "bbceecebf", "bdfbfbfbeffbdeccb", "fcafdded", 
    //"afafecfcfecfd", "dcbebcfbafdaebbaaaae", "ecbceeecccfc", "eecffefc", "dedaffdcacbccadedafefebdb",
    //"afabaaacdbefffbe", "faf", "dfeccfefcbbbec", "cabddbdefddeafdb", "fcbbabfabccefcebeefaecdb",
    //"afbdfd", "ffafaadafeaabaadabb", "caffbddcafddbfcdfb", "dadaacfeaaebeda", "faedabdfafcafa", 
    //"fdcefefc", "afbfdadeaeeddceddeebeaaeac", "eeddeabaadbacddffedfbccdbed", "aecdbfeae",
    //"eddaabaabfeacbefbbdecdc", "aabcfefba", "ebaaedce", "faabcafcfebdcccfcd", "daefbbeccbebacffc",
    //"fecffce", "dedfcdebdeaddacaceabdccacec", "afeacaaffbebcefbcfeefefa", "caeaecbcb", "eabadbbde",
    //"fcdddeabc", "ceaa", "babbabeebebcaafacec", "bddfeedadefbbfbcecdc", "dadfeddfbb", 
    //"fefcacffdcabbdedafc", "eeaafabebbeadf", "cbefdcfbdd", "bffbdaddfbecfedcabd", 
    //"fdaa", "cbdcddfcaddebbac", "dfdfcaccefbbbedecabdaf", "aecaae", "cebebbafdfe", 
    //"aebedfafafcbfcacfdace", "aaeffe", "adbbeaeabe", "abbdcdaebeedddfcce", "edafcaeecdbec", "effabfcccbccefbfcefdc", "faecfcddff", "ddffcdaefc", "ffcbbdffcadfccedceaadbda", "bdcccefcbeafcdfa", "fcfcfabcb", "bfbacfbeeee", "becfbfcbbbbacafecdfabafcff", "eadfeffe", "ef", "caebbdedeccfcaaddcabadad", "feb", "aaaeeaebcbfbbcaccddfccde", "bafaadcdbbcffefbcecf", "baacc", "dffcbdbdaef", "aeffdbeebbeeeabcedefadefcea", "bcbdffd", "baaedcbceafbccebbebbeeeaffc", "afbbeafedffcfbafbcb", "bcbcbbdfcca", "cacaaafdeee", "eadcefdddddcd", "daaddaaeebeefbcec", "cedcfbdcdcadbb", "aafcfe", "edeaa", "bffadeddccaacdcaa", "acadbccfefab", "dcffaecdaebeecccdacdbde", "afdcccefaf", "eeacebdcbdbcccb", "faaecacaeceebcb", "ebcaeffdffacffabbabccefaa", "cbcdcadefdabbdcdafba", "cdadfacadafeabcecdacbaaccc", "dab", "ffaeffaccfefacfdafbaccbf", "fbcefcdbfabdbdabac", "cdfccfdef", "cedcfeaedddababdffdbabf", "cbdacdffcc", "bcfdc", "edfcbaecdbabcbcaecdc", "edadfcfadefcddbf", "dbedfdcdccbddaccaffabbdd", "deabbccdaaddf", "eeadc", "aefccfebeecabdfbda", "dccfcdacafebecbefebdfdebf", "fabbebdbaff", "bfdfbddaeeeaacfeca", "bafdfdfae", "fecfaadffbcfdabfac", "abcaaeefbbefcadeaceadffeb", "aaafdeefbfccafeaedaea", "ebafdfbcdfdddbbeedbfecbbcfb", "edfbeccdcaccf", "bbdceffbeabcafae", "eeadaaedd", "aeecbfecdeeadafded", "fbdbdbfadbcab", "dcdaadabfbb", "fccdcfffefbcdb", "dfbfcae", "beedccaafbadcacadfd", "bcfbdbfdcbfd", "aafedacbabfeddedaadcb", "acfdbfaccbcbac", "bfeaaaafcaeddaffccebacbbff", "fbdcacacbabddebdeecccba", "cdededefebaedb", "abeadffbacee", "aadabfddcaeadefdfefba", "edffcdd", "acceeaeacacaa", "cbeafbafccdbbdfbfccbe", "eeebbfceacbfdddfebf", "cd", "bebfbfcc", "dccfffcedaafbcbaccec", "facefddfaafaafddfcbdaf", "caedfcfbbede", "fdfcdaebefdaacbf", "deccabcfeabfebccfaafbe", "ea", "dbbabdcf", "adeaaaefcbffdccbf", "deacacddcbfeadcefdccbd", "ccebddbebacbecafcdaceeadbd", "decafccaaf", "cecbabcbffbfac", "effeeafbdbdfdcaaedbfadbaaba", "fcffccabafdafbdbbf", "fcaea", "eab", "cbcbcdbfdfcfeaacfd", "bebcdbbaeaccaebfaafac", "fdfdcebbadbba", "bb", "ababebaadadebc", "aeacecacffedfceeacdde", "feacdbcefbeaeddcdccdebee", "fafadacdedeebdafedccc", "dbffaedaebeaedbccfc", "ebdaabeefbaaa", "bacaaeebfaaeaabccbbfa", "cebacdbdaeeeddaacdefdbdc", "cfbbdf", "ffdbcdcfcdbfcebaaecbdfdbac", "ecdacadfdcbcdcdedbfaf", "cffcaeccac", "acceacbdfbedfddefeaedf", "fdbfdebcbfbeddefaaedfabcea", "ddaafbcfdadfbeacbcf", "dafa", "efbefeebddbaefafbed", "dffeff", "ffcedbb", "fefbeb", "aedffaebe", "dfdcfeeedaaecceebbabfcafeab", "bddcfedacfda", "dafdfeeebbdbbefbcceddbdfcdc", "dbdaaeddbafaeeeabdcbeafbfb", "dcbdfeabadcffebb", "cecbaccecfcbe", "fddfedbdadacdaadbdfeba", "bddebcfdbaeec", "cfaaabc", "eddbcbccab", "fafffecdcacedacacbcefddcfc", "fccbabfdeefceb", "cacddeceafeacdffffdccfddac", "dcdfbdacdbbadebbcdc", "dabde", "dbacaeca", "beefdbcc", "cedbbebbfabdbdbbba", "badedaadbbfacfafcedec", "fcdcabddcdaceddeaababebc", "efafbcfbeafaecee", "addcbafad", "efbdacbbf", "bbabbbcfaaffdbfcf", "abecfeaadaedff", "fe", "adfdfffdedbabfeffbffcbdfdbe", "edccafdadecbabdcfcfadd", "ddaddcedbbadccbfaebf", "fdcaaddaf", "fcdcbddebbecdbfce", "dfaecbbfccbbfddbfbfadfecbf", "defcdefbaffdcfdddaebed", "cadecbaecacefabcdea", "bcbdaebbdebbcdb", "dddd", "bcfecafefcbfacdecfc", "fbefeefa", "ffcacbd", "ffafebf", "dbfaddfadcfcdeddcebe", "babbcefcb", "aebfcddcdefadb", "baecddabbdecefdefdfc", "bebe", "ebbbfbcabfccbcacaccbcab", "ecffedefbbdccfdafbaddf", "bdbbbecfafb", "bfaeedcadcbdbddcbcaaeffbccd", "dbdcdffbb", "caee", "ccfcabecdaee", "abbecaeefc", "cdbfbcfbfeddcbcbadbceabede", "adddfddcebdcebdb", "cbfff", "cafafbcabbbcedd", "fedcebffdadfbcedbd", "fedbedcdbabbbcdadd", "fdfeddeaefadcffadadaf", "abaebbbaebebfa", "dcdbfdedad", "afdaebcdccfaadefdbeaddcabed", "bccbceffcdfefbcbd", "efeeecefdcbdabcb", "cdc", "cddadccadefbaccdcbfffedaa", "dacbcddabeddbbcaebdeca", "eccfaddaa", "daabba", "eceafbcadfdebfceda", "abddbaebeccacfdefbacdc", "cdcfdaeccdcfaadfdfdecba", "eacaffbdaabe", "acdbecfebbdbbebaaab", "faebacdafcecafbecca", "ccedcefaabfaa", "ecaebdb", "deeaeafbddfdafcfcd", "ef", "fceab", "cdbceecbbfbebadcddbcbfb", "cccafeecedbddfadedddadf", "abfbccafbcbddfcdaaeefffa", "dcdbdcdfbaffdcaafebddadf", "bdaaecccbdeccabbdaafcc", "addfeeedbeacffdcbfaadbdb", "effcbbeaaebeefbaeec", "adfcaa", "ebceffbaefbadfbfcefa", "aaefbaedddcdbbfabb", "aeadcfeaddabbffefdcadc", "ddbcfede", "cfeffaecb", "cddedebabefe", "ecdb", "aafddabfdadacafdfbbaba", "dfcadfaeddafafc", "daecbfbfaecfafadeacdedafdd", "baef", "afdfefdcacceaeebbeebd", "faa", "da", "dbddbfbdcaeececfcccdfa", "acff", "fdfafca", "ebbdebfffdcfdecffcbe", "bacbdfe", "afebcaceebaf", "deafafaafdaadddaacaacccb", "acdbaefabe", "aaeafdbbabbcdceda", "adfbafbdbcafbcb", "aabccc", "ddcadc", "aedcbdfcccdccabbabbaadf", "dbcfcdacad", "aacaceadafbdafaccfaaceb", "bbcdebdea", "bfaeedbacbabedefbfcadedcecd", "dccf", "caafbcabafffec", "cfcbebacbdcbabafdeeebcffda", "dbfcffcbadcfcacdcdbccfdfa", "bdc", "dadcfeaeaeeebcbd", "bffcbfdebccedb", "cccdceebfcfdacacdca", "aceddacdbfd", "aefdafcfccfbc", "cdba", "deaaeacabdcabffecbdacedeae", "ccdbeaefbcad", "ebfbaddaeeceedeacafd", "adabdefefaadaacabdcebfd", "cdddccadacbeeebceecb", "ededea", "cdfe", "afeafcefc", "ebddbcfebfefceffcc", "edcab", "abacacdbfcfcfdaaceeca", "dbaffc", "dabeddddbbbaaebb", "adcbecfdbbfe", "baacbbbfddacbabdaefecfc", "daadbafbaebe", "bedbbaaedcdafcfaabbbee", "dacbea", "ecbffbfb", "cdcbadbfacb", "fbceeccaffadeecddbdbee", "acafbedfccdfb", "dabdbfdeeeabdaafbafbecc", "bcfddddcbbbaebbaee", "bcaecbeafdeafdeadfbccf", "bebafeaddfedfcdbabcbeba", "fabeaafacdfcfcccacdfbadad", "eebdefbdacfbabcfeeffcfeeffa", "feeefdbaddccfdbcfc", "dafbbaccbefabfefdea", "fefdfebaaefbffcd", "eabcafbceebadaafe", "adbedea", "cdacfcccaeaadcbcefcf", "cfeacbdcceabaeedded", "bc", "ccbcdbaca", "abffcac", "eefadddfcebeaffdadcedbcbede", "aebacddeaedefdebeac", "efcacefcf", "aaebdbffd", "fffbdefadfabdeafbbabfbaabf", "dfddceaebfc", "ecbcabf", "deacadfbcffdcfaecacabcecf", "ccaabeaacba", "eaaabf", "eaabdfeaadbedbdbbbeec", "eddeceddfaeecbcbcefaaec", "eafeacecddafaeefedabdddbfea", "eda", "dbeeeeabbbfbdceed", "eab", "caddafbbe", "efcafcfecbbfdebeeedde", "cbeeffadfbbfa", "bffadcbccf", "dfacafacceaabebbaeb", "bbadbceffffbafafdbaacebce", "daedaaacbfbdbbeaeeddbedbdc", "fcbbd", "bbeffdddfee", "acaeacf", "aaabdedabcadafebcdeac", "ddbeabddbaeefadfcafbe", "bcabcbccdcefdacccfdbaebee", "dfebcefc", "eeeeecfbccbf", "bde", "bdedfebfccbedfbbeadaffdbaa", "ebacbaaaafbcdcbbdbcdaec", "cbeede", "fda", "cddfcf", "ffcaefdd", "aadbaaacbabb", "aefacadaaccbdebbef", "beedaaeccddfbdadbfafdbedaf", "dcfafcfdbfceefff", "dbcdf", "edfecd", "bcdac", "fceda", "edefbeabafcacc", "bcafeccb", "dccffb", "afdd", "ccbaecfe", "ebddebaaacfe", "cfffacdebdb", "dedbabcfb", "feefaadabd", "cbadfadabbecdda", "dfe", "beabcbeefcdbceaaececaccbed", "eae", "afaeaffbaecfcbfbdb", "bccbbddfbeea", "adccfeddaebddbcbedaddbdbccb", "ddabaeaacbcddabbaaaefcc", "cbe", "dcfbffbcebeedad", "adfadccabfabfadc", "fdfbaaaabccbffcfaebbcfcc", "efbcac", "aafdbbfbdabaebaa", "eefccdaabebfbaceeadebcacb", "bfeeecafefbdeeaadfbdfae", "fafbefbceacaeecdcddafbb", "dd", "bcbbaabdfdaeb", "ceedacfaddf", "cfabefcfeaeaecbeeabdfbcadb", "bfcfcafebcffbcf", "fbcdaddcacecbdbbdefdbadfaad", "eafdecedbafaadafbdf", "bbedffcedcaffdcbfdeeabdbf", "dcc", "eeeeaffebbef", "bfaddbbcbefbcaaebfd", "bdd", "cceecfbab", "ebacdfebafcf", "cab", "beeedffa"]

    bool no_common_char(string& s1, string& s2) {
        if (s1.size() + s2.size() > 26)return false;
        vector<int> dic(26, 0);
        for (auto c1 : s1) dic[c1 - 'a']++;
        for (auto c2 : s2) if (dic[c2 - 'a'])return false;
        return true;
    }
};

class Solution2 {
public:



    bool no_common_char(string& s1, string& s2) {
        // if (s1.size() + s2.size() > 26)return false;
        vector<int> dic(26, 0);
        for (auto c1 : s1) dic[c1 - 'a']++;
        for (auto c2 : s2) if (dic[c2 - 'a'])return false;
        return true;
    }

    int maxProduct(vector<string>& words) {
        int res = 0;

        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
             //   if ((int)(words[i].size() * words[j].size()) > res) {

                    if (no_common_char(words[i], words[j])) res = (int)(words[i].size() * words[j].size());
           //     }

            }
        }
        return res;
    }

};

class Solution3 {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> word_map;//int 32Î»ÕûÊý
        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            int mask = 0;
            for (int j = 0; j < words[i].size(); j++) {
                mask |= 1 << (words[i][j] - 'a');
            }
            word_map[mask] = max(word_map[mask], (int)words[i].size());
        }
        for (auto s1 : word_map) {
            for (auto s2 : word_map) {
                if ((s1.first & s2.first) == 0) {
                    result = max(result, s1.second * s2.second);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution3 mysolu;
    vector<string> s_input = { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
    int result = mysolu.maxProduct(s_input);
    return 0;
}
