// by CompiledCode#1234 @ https://github.com/Compiled-Code/StudioLuauCompiler

#include <Windows.h>
#include <thread>
#include <string>

inline void alloc_console()
{
	AllocConsole();
	FILE* v;
	freopen_s(&v, "CONIN$", "r", stdin);
	freopen_s(&v, "CONOUT$", "w", stdout);
	freopen_s(&v, "CONOUT$", "w", stderr);
	fclose(v);
	SetConsoleTitleA("Luau Studio Compiler | CompiledCode#1234");
}

struct luau_compiler_option
{
	std::uint32_t v1, v2, v3, v4;
};

const std::uint16_t key = 257;
using luau_compiler_t = std::string(__fastcall*)(const std::string&, const luau_compiler_option&, const std::uint16_t*, std::uint64_t);
const auto luau_compile = reinterpret_cast<luau_compiler_t>(reinterpret_cast<std::uintptr_t>(GetModuleHandleA(nullptr)) + 0x179EF00);

void core()
{
	alloc_console();
	const auto bytecode = luau_compile("warn'a'", { 1, 1, 1, 0 }, &key, 0);
}

bool __stdcall DllMain(const HMODULE dllHandle, const DWORD reason, const void*)
{
	if (reason == DLL_PROCESS_ATTACH)
		std::thread(core).detach();

	return true;
}
