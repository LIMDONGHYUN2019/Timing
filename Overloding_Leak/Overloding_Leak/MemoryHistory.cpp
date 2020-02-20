#include"MemoryHistory.h"

CMemoryHistory::CMemoryHistory(const char* szLogFile)
{
	char szTime[17] = " ";
	time_t timer;
	struct tm TM;// 시간 구조체


	memset(_allocinfos, 0, sizeof(stALLOC_INFO) * ALLOC_INFO_MAX);
	memset(_logFileName, 0, 64);

	time(&timer);

	localtime_s(&TM, &timer);// 현재시간을 가져오는 함수

	sprintf_s(szTime, 17, "%04d%02d%02d_%02d%02d%02d",
		TM.tm_year + 1900,
		TM.tm_mon + 1,
		TM.tm_mday,
		TM.tm_hour,
		TM.tm_min,
		TM.tm_sec);

	strcat_s(_logFileName, 64, szLogFile);
	strcat_s(_logFileName, 64, szTime);
	strcat_s(_logFileName, 64, ".txt");

	cout << "wow....." << endl;
}

CMemoryHistory::~CMemoryHistory()
{
	SaveLogFile();
}

bool CMemoryHistory::SaveLogFile()
{
	FILE* pLogFile;
	errno_t err = fopen_s(&pLogFile, _logFileName, "a");
	if (err != 0)
	{
		return false;
	}

	for (int iCount = 0; iCount < ALLOC_INFO_MAX; iCount++)
	{
		if (_allocinfos[iCount].pAlloc != nullptr)
		{
			if (_allocinfos[iCount].bFree)
			{
				fprintf(pLogFile, "END     !!     ");
			}
			else
			{
				fprintf(pLogFile, "LEAK    !!     ");
			}

			fprintf(pLogFile, "[0x%p]   [%7d size]  %s  :  %d Line \n",
				_allocinfos[iCount].pAlloc,
				_allocinfos[iCount].iSize,
				_allocinfos[iCount].szFile,
				_allocinfos[iCount].iLine);
		}
	}
	
	fclose(pLogFile);
	return true;
}

bool CMemoryHistory::NewAlloc(void* ptr, const char* szFile, int iLine, int iSize, bool bArray)
{
	for (int iCount = 0; iCount < ALLOC_INFO_MAX; iCount++)
	{
		if (_allocinfos[iCount].pAlloc == nullptr || _allocinfos[iCount].pAlloc == ptr)
		{
			_allocinfos[iCount].bFree = false;
			_allocinfos[iCount].bArray = bArray;
			_allocinfos[iCount].pAlloc = ptr;
			_allocinfos[iCount].iLine = iLine;
			_allocinfos[iCount].iSize = iSize;
			strcpy_s(_allocinfos[iCount].szFile, FILE_NAME_LEN, szFile);

			return true;
		}
	}
	
	return false;
}

bool CMemoryHistory::Delete(void* ptr, bool bArray)
{

	FILE* pLogFile;

	for (int iCount = 0; iCount < ALLOC_INFO_MAX; iCount++)
	{
		if (_allocinfos[iCount].pAlloc == ptr)
		{
			if (_allocinfos[iCount].bFree)
			{
				errno_t err = fopen_s(&pLogFile, _logFileName, "a");
				if (err == 0)
				{
					fprintf(pLogFile, "REFREE!!!!!    [0x%x]  [%7d]  \n",
						_allocinfos[iCount].pAlloc, _allocinfos[iCount].iSize);
					fclose(pLogFile);
				}

				return false;
			}

			else if(_allocinfos[iCount].bArray != bArray)
			{
				errno_t err = fopen_s(&pLogFile, _logFileName, "a");
				if (err == 0)
				{
					fprintf(pLogFile, "NOT ARRAY  !!  [0x%x]   [%7d size]  \n",
						_allocinfos[iCount].pAlloc, _allocinfos[iCount].iSize);
					fclose(pLogFile);
				}
				_allocinfos[iCount].bFree = true;
				return true;
				//return false;
			}

			else
			{
				_allocinfos[iCount].bFree = true;
			}

			return true;
		}
	}
	errno_t err = fopen_s(&pLogFile, _logFileName, "a");
	if (err != 0)
	{
		return false;
	}

	fprintf(pLogFile, "NoALLOC   [0x%x]  \n", ptr);
	fclose(pLogFile);


	return false;
}
