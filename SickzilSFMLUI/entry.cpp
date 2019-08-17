#include <main_window.hpp>

#ifdef _MSC_VER
#include <Windows.h>
#undef   min
#undef   max

int WINAPI wWinMain(
	_In_ HINSTANCE,
	_In_opt_ HINSTANCE,
	_In_ LPWSTR cmdline,
	_In_ int cmdshow)
#else
int main(int argc, char* argv[])
#endif
{
	ui_options  options;
	main_window window(options);

	return window.get_exit_code();
}