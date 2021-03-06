#include "StdAfx.h"
#include "DetectionSystemService.h"

//	the caller clean the stack.
int _cdecl _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
	// Create the service object
	DetectionSystemService RdsDetectionSystemService;

	UNREFERENCED_PARAMETER(envp);

	// Parse for standard arguments (install, uninstall, version etc.)
	if (FALSE == RdsDetectionSystemService.ParseStandardArgs(argc, argv))
	{
		// Didn't find any standard args so start the service
		// Uncomment the DebugBreak line below to enter the debugger
		// when the service is started.
		//DebugBreak();
		RdsDetectionSystemService.StartService();
	}

	// When we get here, the service has been stopped
	nRetCode = RdsDetectionSystemService.m_Status.dwWin32ExitCode;

	return nRetCode;
}