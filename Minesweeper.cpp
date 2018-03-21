//Memory editing with the WriteProcessMemory function on Windows Minesweeper
//Works for consecutive games without the need of loading up the executable every time
//Reduced memory usage by 50% with a timed injector, should read memory and see changed instead
//Also, game has to be loaded up before program runs or else 20% of CPU will be wasted

#include <windows.h>//M=memory functions, handles, PID, etc.
#include <iostream>

using namespace std;

int main()
{
	  cout << "Minesweeper Injector 1.7\n";
	  
	  long address = 0x100579C;//address found with using Cheat Engine
	  int newvalue = 0;//new mem value 
 	  HWND hwnd;
	  HANDLE phandle;
	  DWORD pid;//Process ID
	  system("Title = Minesweeper Injector.exe");
	  system("CLS");
	  hwnd = FindWindow(NULL, "Minesweeper"); 
	  while(1)
	  {
	  if (hwnd != 0)
	  {
   	  //MessageBox(NULL, "Minesweeper has been detected!", "Detected", MB_OK + MB_ICONINFORMATION); 
      //cout << "Minesweeper has been detected!\n";
	  GetWindowThreadProcessId(hwnd, &pid);//gets process ID
      phandle = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);//the handle
	  }
	  else 
	  {
			main();
	  }
	  if (phandle !=0)//if handle works
	  {
	  WriteProcessMemory(phandle, (LPVOID)address, (LPVOID) &newvalue, 4, 0);//memory injection
	  //MessageBox(NULL, "Value has been injected!", "Success", MB_OK + MB_ICONINFORMATION); 
	  //cout << "Value has been injected!\n";
	  Sleep(3000);
	  }
	  else//if handle was not found, never happened so far
	  {
	   	  //MessageBox(NULL, "Could not see a handle", "Error!", MB_OK + MB_ICONERROR); 
	   	  cout << "Handle was not found!\n";
	  }
	  }
	  
	  system("PAUSE");
	  return 0;
}


