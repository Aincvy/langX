#ifdef WIN32
#include <time.h>
#else
#include <sys/time.h>  
#endif // WIN32


#include "../include/Utils.h"


namespace langX {



	long getTime()
	{
#ifdef WIN32

		return -1;
#else
		struct timeval tv;
		gettimeofday(&tv, NULL);
		return (long)((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
#endif // WIN32
		
	}

}