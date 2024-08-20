#include <string>
#include <vector>

std::vector<int> solution(int N, std::vector<int> Slicer, std::vector<int> Num_list)
{
    std::vector<int> Result;

	int Start = 0, End = 0, InterVal = 0;
	switch (N)
	{
	case 1:
		Start = 0;
		End = Slicer[1];
		InterVal = 1;
		break;
	case 2:
		Start = Slicer[0];
		End = static_cast<int>(Num_list.size() - 1);
		InterVal = 1;
		break;
	case 3:
		Start = Slicer[0];
		End = Slicer[1];
		InterVal = 1;
		break;
	case 4:
		Start = Slicer[0];
		End = Slicer[1];
		InterVal = Slicer[2];
		break;
	}

	for (int i = Start; i <= End; i += InterVal)
	{
		Result.push_back(Num_list[i]);
	}

    return Result;
}