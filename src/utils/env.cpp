#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using std::string;

int8_t load_env()
{

	std::ifstream envFile(".env");

	if (!envFile)
	{
		std::cerr << "Erro ao abrir arquivo .env" << std::endl;
		return 1;
	};

	string line;

	while (std::getline(envFile, line))
	{
		size_t pos = line.find('=');
		if (pos != string::npos)
		{
			string nome = line.substr(0, pos);
			string valor = line.substr(pos + 1);

			if (setenv(nome.c_str(), valor.c_str(), 1) != 0)
			{
				return 1;
			};
		}
	}

	return 0;
}
