// stdafx.cpp: archivo de código fuente que contiene sólo las inclusiones estándar
// libreria.pch será el encabezado precompilado
// stdafx.obj contiene la información de tipos precompilada

#include "stdafx.h"

// TODO: mencionar los encabezados adicionales que se necesitan en STDAFX.H
// pero no en este archivo

void fn(int addr)
{
	while (isRunning)
	{
		VB6SUB(addr, 5);

		std::this_thread::sleep_for(std::chrono::seconds(10));
	}

	MSGBOX("KILLED");
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
	isRunning = false;
}

void INI_MapFile(char *path, char *file)
{
	std::string line;

	std::ifstream ifs(std::string(path).append(file), std::ifstream::in);

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

void INI_Memory2DiskDumpInBG()
{
	std::thread t(INI_Memory2DiskDump);
	t.detach();
}

void INI_DumpFile(char *path, char *file)
{
	std::ofstream ofs(std::string(path).append(file));
	
	for (auto key : mapped_file[file])
	{
		ofs << "[" << key.first << "]" << "\n";
		
		for (auto subkey : key.second)
			ofs << subkey.first << "=" << subkey.second << "\n";;
		
		ofs << "\n";
		
	}

	ofs.close();
}

void INI_DumpFileInBG(char* path, char* file)
{
	std::thread t(INI_DumpFile, path, file);
	t.detach();
}

BSTR INI_GetString(char *file, char *key, char *subkey)
{
	std::string ret(mapped_file[file][key][subkey]);

	return SysAllocStringByteLen(ret.c_str(), ret.size());
}

int32_t INI_GetLong(char *file, char *key, char *subkey)
{
	if (mapped_file[file][key][subkey].size() == 0) return 0;
	return std::stoi(mapped_file[file][key][subkey]);
}

int16_t INI_GetInteger(char *file, char *key, char *subkey)
{
	if (mapped_file[file][key][subkey].size() == 0) return 0;
	return std::stoi(mapped_file[file][key][subkey]);
}

uint8_t INI_GetByte(char *file, char *key, char *subkey)
{
	if (mapped_file[file][key][subkey].size() == 0) return 0;
	return std::stoi(mapped_file[file][key][subkey]);
}

float INI_GetSingle(char *file, char *key, char *subkey)
{
	if (mapped_file[file][key][subkey].size() == 0) return 0;
	return std::stof(mapped_file[file][key][subkey]);
}

bool INI_GetBoolean(char *file, char *key, char *subkey)
{
	if (mapped_file[file][key][subkey].size() == 0) return 0;
	return INI_GetByte(file,key,subkey);
}

void INI_SetValue(char *file, char *key, char *subkey, char *value)
{
	mapped_file[file][key][subkey] = value;
}

std::vector<WorldPos> MM_ReadMap(char* path, uint16_t map, SAFEARRAY **mapblock)
{
	// LOG
	//std::ofstream ofs_log("log-map"+std::to_string(map)+".txt");
	//ofs_log << "Reading map " << map << "\n";
	//ofs_log << "Thread id: " << std::this_thread::get_id() << "\n";
	
	std::vector<WorldPos> ret;
	
	auto ap = std::string(path).append(std::to_string(map));

	std::ifstream ifs_map(ap + ".map", std::ios::binary);
	std::ifstream ifs_inf(ap + ".inf", std::ios::binary);

	if (ifs_map.fail() || ifs_inf.fail())
	{
		MSGBOX("FALLO EN MAPA " << map);
		return ret;
	}

	std::vector<byte> map_buffer(std::istreambuf_iterator<char>(ifs_map), {});
	std::vector<byte> inf_buffer(std::istreambuf_iterator<char>(ifs_inf), {});

	ifs_map.close();
	ifs_inf.close();

	//ofs_log << "Map buffered. \n";
	//ofs_log << "Sizes:\t" << map_buffer.size() << "\n";
	//ofs_log << "\t" << inf_buffer.size() << "\n";

	auto ptr_map = 273U, ptr_inf = 10U;

	long rgIndices[3] = {map,0,0};

	for (auto x = 1U; x <= 100; ++x)
		for (auto y = 1U; y <= 100; ++y)
		{
			rgIndices[1] = x;
			rgIndices[2] = y;

			MapBlock *position = nullptr;

			if (SafeArrayPtrOfIndex(*mapblock, rgIndices, (void**)& position) != S_OK)
				return ret;
			
			// MAP FILE
			mem_cpy(position->blocked, map_buffer, ptr_map);

			for (auto k = 0; k < 4; ++k)
			{
				mem_cpy(position->graphic[k], map_buffer, ptr_map);
			}

			mem_cpy(position->trigger, map_buffer, ptr_map);

			// Dummy
			ptr_map += sizeof(uint16_t);

			// INF FILE
			mem_cpy(position->exit_map, inf_buffer, ptr_inf);

			mem_cpy(position->exit_x, inf_buffer, ptr_inf);

			mem_cpy(position->exit_y, inf_buffer, ptr_inf);

			mem_cpy(position->npcindex, inf_buffer, ptr_inf);

			if (position->npcindex > 0) { ret.push_back(WorldPos{ map, (uint16_t)x, (uint16_t)y }); }

			mem_cpy(position->objindex, inf_buffer, ptr_inf);

			mem_cpy(position->objamount, inf_buffer, ptr_inf);

			// Dummy

			ptr_inf += sizeof(uint16_t);
			ptr_inf += sizeof(uint16_t);
		}

	//ofs_log << "Map read\n";

	//ofs_log.close();

	return ret;
}

void MM_ReadMaps(char *path, SAFEARRAY **mapblock/*, SAFEARRAY **npcs*/)
{
	std::mutex io_mutex;

	CComSafeArray<uint16_t> csaMapBlock; //csaData

	//csaData.Create();

	csaMapBlock.m_psa = *mapblock;

	pl::async_par_for(1, csaMapBlock.GetUpperBound(), [path, &mapblock, &io_mutex /*&csaData*/](unsigned map)
	{
			auto res = MM_ReadMap(path, map, mapblock);

			std::lock_guard<std::mutex> lk(io_mutex);
			v_npcs.insert(v_npcs.end(), res.begin(), res.end());
			//for (auto& value : res)
				//csaData.Add(value);

	},true);

	//csaData.CopyTo(npcs);

	//csaData.Destroy();
}

uint16_t MM_NpcsSize()
{
	return v_npcs.size()-1;
}

WorldPos MM_GetNpcPos()
{
	return v_npcs[npcs_position];
}

bool MM_Forward()
{
	return ++npcs_position < v_npcs.size();
}

uint16_t MM_GetNPC(uint64_t encoded)
{
	return (encoded & 0xFFFF00000000) >> 32;
}

uint16_t MM_GetMap(uint64_t encoded)
{
	return (encoded & 0xFFFF0000) >> 16;
}

uint8_t MM_GetX(uint64_t encoded)
{
	return (encoded & 0xFF00) >> 8;
}

uint8_t MM_GetY(uint64_t encoded)
{
	return encoded & 0xFF;
}

void free_memory() 
{ 
	mapped_file.clear();
}

void Data_type(VARIANT var)
{
	MSGBOX("Tipo: " << var.vt);
}