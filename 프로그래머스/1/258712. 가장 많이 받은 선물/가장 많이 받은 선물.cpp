#include <algorithm>
#include <string>
#include <vector>
#include <map>

int solution(std::vector<std::string> Friends, std::vector<std::string> Gifts) 
{
    // Set Index
    std::map<std::string, int> FriendsIdx;
    for (int i = 0; i < Friends.size(); ++i)
    {
        FriendsIdx[Friends[i]] = i;
    }

    // Set GiftInfo, GiftIndex
    std::vector<int> GiftIdx(FriendsIdx.size(), 0);
    std::vector<std::vector<int>> GiftsInfo(FriendsIdx.size(), std::vector<int>(FriendsIdx.size(), 0));
    for (int i = 0; i < Gifts.size(); ++i)
    {
        std::string Sender = Gifts[i].substr(0, Gifts[i].find(' '));
        std::string Receiver = Gifts[i].substr(Gifts[i].find(' ') + 1);

        ++GiftsInfo[FriendsIdx[Sender]][FriendsIdx[Receiver]];
        
        --GiftIdx[FriendsIdx[Receiver]];
        ++GiftIdx[FriendsIdx[Sender]];
    }

    // Set Result
    std::vector<int> Result(FriendsIdx.size(), 0);
    for (int i = 0; i < Friends.size(); ++i)
    {
        int Sender = FriendsIdx[Friends[i]];
        for (int Receiver = 0; Receiver < GiftsInfo[Sender].size(); ++Receiver)
        {
            if (Sender == Receiver || GiftsInfo[Sender][Receiver] < GiftsInfo[Receiver][Sender])
            {
                continue;
            }

            if (GiftsInfo[Sender][Receiver] > GiftsInfo[Receiver][Sender] || GiftIdx[Sender] > GiftIdx[Receiver])
            {
                ++Result[Sender];
            }
        }
    }

    return *std::max_element(Result.begin(), Result.end());
}