/*
ofstream : output
ifstream : input
fstream : 둘다

find의 세번째 인자 

*/

#include <iostream>
#include <fstream>

void	replaceStr(char **argv, std::ifstream &readFile, std::ofstream &replaceFile)
{
	std::string	getlineStr;
	std::string const s1 = argv[2];
	std::string const s2 = argv[3];
	size_t		start_idx;
	int			flag = 1;

	while (!readFile.eof())
	{
		std::getline(readFile, getlineStr);
		start_idx = getlineStr.find(s1); //첫번째 문자 위치 반환
		if (start_idx == std::string::npos)
		{
			if (!flag)
			{
				replaceFile << std::endl;
				flag = 0;
			}
			replaceFile << getlineStr; //파일스트림 replaceFile에 등록된 파일에 getlineStr출력
		}
		else
		{
			if (!flag)
				replaceFile << std::endl;
			while (start_idx != std::string::npos)
			{
				replaceFile << getlineStr.substr(0, start_idx) << s2;
				start_idx = getlineStr.find(s1, start_idx + s1.length());
			}
		}
	}
	readFile.close();
	replaceFile.close();
}

int		main(int argc, char *argv[])
{
	if (argc != 4 || argv[2][0] == '\0')
	{
		std::cout << "ERROR: arguments" << std::endl;
		return (0);
	}
	std::string file_name = argv[1];
	std::ifstream readFile(file_name);
	if (readFile.fail())
	{
		std::cout << "File Error: " << file_name << std::endl;
		return (1);
	}
	std::ofstream replaceFile(file_name + ".replace");
	if (replaceFile.fail())
	{
		std::cout << "File Error: " << file_name << ".replace" << std::endl;
		return (1);
	}
	replaceStr(argv, readFile, replaceFile);
	readFile.close();
	replaceFile.close();
	return (0);
}
