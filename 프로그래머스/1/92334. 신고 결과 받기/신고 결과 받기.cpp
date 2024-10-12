#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 중복 신고를 제거하기 위해 각 유저별로 신고한 유저를 저장하는 맵
    unordered_map<string, unordered_set<string>> user_reports;
    
    // 각 유저가 신고한 유저 집합을 초기화
    for(const string& user : id_list){
        user_reports[user] = unordered_set<string>();
    }
    
    // 신고 정보 처리: 중복 신고 제거
    for(const string& rep : report){
        int space_pos = rep.find(' ');
        string reporter = rep.substr(0, space_pos);
        string reportee = rep.substr(space_pos + 1);
        user_reports[reporter].insert(reportee);
    }
    
    // 각 유저별 신고당한 횟수를 저장할 맵
    unordered_map<string, int> report_count;
    for(const string& user : id_list){
        report_count[user] = 0;
    }
    
    // 신고당한 횟수 집계
    for(const auto& [reporter, reportees] : user_reports){
        for(const string& reportee : reportees){
            report_count[reportee]++;
        }
    }
    
    // 정지 대상 유저 집합
    unordered_set<string> suspended_users;
    for(const auto& [user, count] : report_count){
        if(count >= k){
            suspended_users.insert(user);
        }
    }
    
    // 각 유저별로 받은 메일 수 계산
    vector<int> answer;
    for(const string& user : id_list){
        int mails = 0;
        for(const string& reportee : user_reports[user]){
            if(suspended_users.find(reportee) != suspended_users.end()){
                mails++;
            }
        }
        answer.push_back(mails);
    }
    
    return answer;
}
