// stdafx.h: archivo de inclusión de los archivos de inclusión estándar del sistema
// o archivos de inclusión específicos de un proyecto utilizados frecuentemente,
// pero rara vez modificados
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Excluir material rara vez utilizado de encabezados de Windows
#define EXPORT __declspec( dllexport )
#define MSGBOX(x) \
{ \
   std::ostringstream oss; \
   oss << x; \
   MessageBoxA(0,oss.str().c_str(), "Alerta !!", MB_OK | MB_ICONQUESTION); \
}

#define VB6SUB(addr, value) \
{ \
	void (__stdcall *f)(int v) = (void (__stdcall *) (int v)) addr; \
	f(value); \
}

#define mem_cpy(dest, orig, ptr) \
{ \
	memcpy(&dest, &orig[ptr], sizeof(orig)); \
	ptr += sizeof(dest); \
}


// Archivos de encabezado de Windows:
#include <windows.h>
#include <filesystem>
#include <sstream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <thread>
#include <chrono>
#include <OAIdl.h>
#include <atomic>
#include <vector>
#include <functional>
#include <future>
#include <atlbase.h>
#include <atlsafe.h>


// Global namespaces
namespace fs = std::filesystem;

namespace pl {

	void thread_par_for(unsigned start, unsigned end, std::function<void(unsigned i)> fn, bool par = true) {

		//internal loop
		auto int_fn = [&fn](unsigned int_start, unsigned seg_size) {
			for (unsigned j = int_start; j < int_start + seg_size; j++) {
				fn(j);
			}
		};

		//sequenced for
		if (!par) {
			return int_fn(start, end);
		}

		//get number of threads
		unsigned nb_threads_hint = std::thread::hardware_concurrency();
		unsigned nb_threads = nb_threads_hint == 0 ? 8 : (nb_threads_hint);

		//calculate segments
		unsigned total_length = end - start;
		unsigned seg = total_length / nb_threads;
		unsigned last_seg = seg + total_length % nb_threads;

		//launch threads - parallel for
		auto threads_vec = std::vector<std::thread>();
		threads_vec.reserve(nb_threads);
		for (auto k = 0; k < nb_threads - 1; ++k) {
			unsigned current_start = seg * k;
			threads_vec.emplace_back(std::thread(int_fn, current_start, seg));
		}
		{
			unsigned current_start = seg * (nb_threads - 1);
			threads_vec.emplace_back(std::thread(int_fn, current_start, last_seg));
		}
		for (auto& th : threads_vec) {
			th.join();
		}
	}

	void async_par_for(unsigned start, unsigned end, std::function<void(unsigned i)> fn, bool par = true) {

		//internal loop
		auto int_fn = [&fn](unsigned int_start, unsigned seg_size) {
			for (unsigned j = int_start; j < int_start + seg_size; j++) {
				fn(j);
			}
		};

		//sequenced for
		if (!par) {
			return int_fn(start, end);
		}

		//get number of threads
		unsigned nb_threads_hint = std::thread::hardware_concurrency();
		unsigned nb_threads = nb_threads_hint == 0 ? 8 : (nb_threads_hint);

		//calculate segments
		unsigned total_length = end - start;
		unsigned seg = total_length / nb_threads;
		unsigned last_seg = seg + total_length % nb_threads;

		//launch threads - parallel for
		auto fut_vec = std::vector<std::future<void>>();
		fut_vec.reserve(nb_threads);
		for (auto k = 0; k < nb_threads - 1; ++k) {
			unsigned current_start = seg * k;
			fut_vec.emplace_back(std::async(int_fn, current_start, seg));
		}
		{
			unsigned current_start = seg * (nb_threads - 1);
			fut_vec.emplace_back(std::async(std::launch::async, int_fn, current_start, last_seg));
		}
		for (auto& th : fut_vec) {
			th.get();
		}
	}
}

namespace utilities
{
	// Convert from STL wstring to the ATL BSTR wrapper
	inline CComBSTR ToBstr(const std::wstring& s)
	{
		// Special case of empty string
		if (s.empty())
		{
			return CComBSTR();
		}
		return CComBSTR(static_cast<int>(s.size()), s.data());
	}
}

// Global data types
typedef struct 
{
	unsigned char blocked;
	unsigned short int graphics[4];
	unsigned short int trigger;
	unsigned short int t1;
} TileMap;

typedef struct 
{
	unsigned short int dest_map;
	unsigned short int dest_x;
	unsigned short int dest_y;

	unsigned short int npc;

	unsigned short int obj_ind;
	unsigned short int obj_amount;

	unsigned short int t1;
	unsigned short int t2;
} TileInf;

typedef struct 
{
	unsigned char blocked;
	short int graphic[4];
	short int userindex;
	short int userindex_under;
	short int npcindex;

	short int objindex;
	short int objamount;

	short int exit_map;
	short int exit_x;
	short int exit_y;

	short int trigger;

} MapBlock;

typedef struct
{
	uint16_t map;
	uint16_t x;
	uint16_t y;
} WorldPos;

// Global vars
std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<std::string, std::string> > > mapped_file;
std::atomic_bool isRunning = false;
std::vector<WorldPos> v_npcs;
uint32_t npcs_position = 0;

// Global methods
void free_memory();
void stop();