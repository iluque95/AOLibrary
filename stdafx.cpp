// stdafx.cpp: archivo de código fuente que contiene sólo las inclusiones estándar
// libreria.pch será el encabezado precompilado
// stdafx.obj contiene la información de tipos precompilada

#include "stdafx.h"

// TODO: mencionar los encabezados adicionales que se necesitan en STDAFX.H
// pero no en este archivo

int path_exist(char *path)
{

	fs::path aPath{ path };

	//MSGBOX("Punto 1 " << path);

	auto ret = fs::exists(aPath);

	std::unordered_map<std::string, int> umap;

	umap["Judit"] = 23;
	umap["Itiel"] = 25;

	//for (auto x : umap)
	//	MSGBOX(x.first + " --> " << x.second);

	//return !(umap.find(path) == umap.end());


	auto i = 0U;
	std::string line;

	std::ifstream ifs("OBJs.dat", std::ifstream::in); // | std::ifstream::binary

	if (ifs.is_open())

		while (i < 25)
		{
			getline(ifs, line);
			MSGBOX(line);
			++i;
		}

	ifs.close();

	return ret;
}

void fn(int addr)
{
	while (isRunning)
	{
		void(*VBFunction)() = (void(*) ()) addr;

		VBFunction();

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

int thread_creation(int addr)
{
	isRunning = true;

	std::thread t1(fn, addr);

	t1.detach();

	return isRunning;
}

void stop()
{
	MSGBOX("STOOOP");
	isRunning = false;
}

void INI_MapFile(char *path, char *file)
{
	std::string line, fp(path);

	fp.append(file);

	std::ifstream ifs(fp, std::ifstream::in);

	if (ifs.is_open())
	{
		std::string key, subkey, value;

		while (!ifs.eof())
		{
			getline(ifs, line);

			if (line.size() > 0 && line[0] != '\'' && line[0] != '#' && !isblank(line[0]))
			{
				if (line[0] == '[')
				{
					auto pos = line.find_last_of(']');

					key = line.substr(1, pos - 1);
				}
				else if(key.size() > 0)
				{
					auto pos = line.find_first_of('=');

					subkey = line.substr(0, pos);
					value = line.substr(pos + 1, line.size() - 1);

					mapped_file[file][key][subkey] = value;
				}
			}
		}

		ifs.close();
	}
}

void INI_UnMapFile(char *file)
{
	mapped_file.erase(file);
}

void INI_Memory2DiskDump()
{
	for (auto file : mapped_file)
	{
		std::ofstream ofs("dump-" + file.first);
		for (auto key : file.second)
		{
			ofs << "[" << key.first << "]" << "\n";;
			for (auto subkey : key.second)
				ofs << subkey.first << "=" << subkey.second << "\n";;
			ofs << "\n";
		}
		ofs.close();
	}
}

EXPORT void CALLBACK INI_DumpFile(char *path, char *file)
{
	std::string dst(path);
	dst.append(file);

	std::ofstream ofs(dst);
	
	for (auto key : mapped_file[file])
	{
		ofs << "[" << key.first << "]" << "\n";
		
		for (auto subkey : key.second)
			ofs << subkey.first << "=" << subkey.second << "\n";;
		
		ofs << "\n";
		
	}

	ofs.close();
}

BSTR INI_GetString(char *file, char *key, char *subkey)
{
	std::string ret;

	ret = mapped_file[file][key][subkey];

	return SysAllocStringByteLen(ret.c_str(), ret.size());
}

int32_t INI_GetLong(char *file, char *key, char *subkey)
{
	return std::stoi(mapped_file[file][key][subkey]);
}

int16_t INI_GetInteger(char *file, char *key, char *subkey)
{
	return std::stoi(mapped_file[file][key][subkey]);
}

uint8_t INI_GetByte(char *file, char *key, char *subkey)
{
	return std::stoi(mapped_file[file][key][subkey]);
}

float INI_GetSingle(char *file, char *key, char *subkey)
{
	return std::stof(mapped_file[file][key][subkey]);
}

void INI_SetValue(char *file, char *key, char *subkey, char *value)
{
	mapped_file[file][key][subkey] = value;
}

void Data_type(VARIANT var)
{
	MSGBOX("Tipo: " << var.vt);
}