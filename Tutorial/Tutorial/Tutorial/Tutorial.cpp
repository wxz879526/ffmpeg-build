// Tutorial.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <memory>

#ifdef __cplusplus
extern "C"
{
#endif
#include "libavformat/avformat.h"
#ifdef __cplusplus
}
#endif

char* urlprotocolInfo()
{
	char *pInfo = (char*)malloc(40000);
	memset(pInfo, 0, 40000);

	av_register_all();

	struct URLProtocol *pUp = nullptr;

	//input
	struct URLProtocol **pp = &pUp;
	avio_enum_protocols((void**)pp, 0);
	while ((*pp) != nullptr)
	{
		sprintf_s(pInfo, 40000, "%s[In ][%10s]\n", pInfo, avio_enum_protocols((void**)pp, 0));
	}

	//output
	pUp = nullptr;
	pp = &pUp;
	avio_enum_protocols((void**)pp, 1);
	while ((*pp) != nullptr)
	{
		sprintf_s(pInfo, 40000, "%s[Out ][%10s]\n", pInfo, avio_enum_protocols((void**)pp, 1));
	}

	return pInfo;
}

int main()
{
	char *pProtocolInfo = urlprotocolInfo();
	std::cout << pProtocolInfo << std::endl;
	free(pProtocolInfo);


	system("pause");
    return 0;
}

