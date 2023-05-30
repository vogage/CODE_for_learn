//
//  468_Validate IP Address.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/5/26.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

using  namespace std;

//Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.
//
//A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.
//
//A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:
//
//1 <= xi.length <= 4
//xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
//Leading zeros are allowed in xi.
//For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.

class Solution {
public:
    string validIPAddress(string queryIP) {
        vector<string> tokens;
        
        if(queryIP.find(".")!=queryIP.npos){
            return IsIpv4(queryIP);
        }
        if(queryIP.find(":")!=queryIP.npos){
            return IsIpv6(queryIP);
        }
        return "Neither";

        
    }
private:
    bool judgeIP4AdressSeg(const string& segstr){
        if(segstr.size()==0)return false;
        if(segstr[0]=='0'&&segstr.size()>1)return false;
        
        for(int i=0;i<segstr.size();i++){
           
            if(segstr[i]<'0'||segstr[i]>'9')return false;
        }
        int res=stoi(segstr);
        return res>=0&&res<=255;
    }
    
    string IsIpv4(const string & queryIp){
        stringstream sstr(queryIp);
        vector<string> segs;
        string temp;
        while(getline(sstr,temp,'.')){
            segs.push_back(temp);
        }
        if(segs.size()!=4||queryIp.back()=='.')return "Neither";
       
        for(int i=0;i<4;i++){
            if(!judgeIP4AdressSeg(segs[i])) return "Neither";;
        }
        return "IPv4";

        
    }
    
    bool judgeIP6AdressSeg(const string& segstr){
        if(segstr.size()<1||segstr.size()>4)return false;
        for(int i=0;i<segstr.size();i++){
            if(segstr[i]>='0'&&segstr[i]<='9') continue;
            if(segstr[i]>='a'&&segstr[i]<='f') continue;
            if(segstr[i]>='A'&&segstr[i]<='F') continue;
            return false;
        }
        return true;
    }
    
    string IsIpv6(const string & queryIp){
        stringstream sstr(queryIp);
        vector<string> segs;
        string temp;
        while(getline(sstr,temp,':')){
            segs.push_back(temp);
        }
       
        if(segs.size()!=8||queryIp.back()==':') return "Neither";
        bool IsAdress=true;
        for(int i=0;i<8;i++){
            if(!judgeIP6AdressSeg(segs[i])) return "Neither";
        }
        return "IPv6";
    }
};

int main(){
    Solution mysolu;
    string query="256.256.256.256";
    string query1="2001:0db8:85a3:0:0:8A2E:0370:7334:";
    string query2="1e1.4.5.6";
    string query3="2001:0db8:85a3:00000:0:8A2E:0370:7334";
    string query4="20EE:FGb8:85a3:0:0:8A2E:0370:7334";
    string query5="2001:0db8:85a3:0:0:8A2E:0370:7334";
    string res=mysolu.validIPAddress(query4);
    return 0;
}
